"""
Modified on April 24, 2023
add temperature compensation part
"""


"""
Modified on Feb 22, 2023
"""


"""
Created on Oct 4, 2022

This is a class file for process FBG rawdata

@author: Yangsheng XU
"""


import json
import os
import numpy as np

class FBG_process:


    def __init__(self, filename: str, total_reading_num: int, signal_each_ch: np.ndarray, ref_wavelength: np.ndarray):
        
        #self.Num_CH  # channel number (fbg property)
        #self.Num_AA  # Active Area number (fbg property)
        #self.cal_mats # main calibration matrix
        #self.cal_mats_TC # sub calibration matrix for temperature compensation
        #self.ch_config
        #self.Serial_Number # serial number

        self.total_reading_num = total_reading_num
        self.signal_each_ch = signal_each_ch
        self.dif_bound = 5
        self.load_params(filename)

        """
        ref_wavelength: ndarray,    CH1 AA1 AA2 AA3 AA4 CH2 AA1 AA2 ...

        """
        # check reading size and convert the input signal into list
        self.ref_wavelength,check_status = self.checkSignalSize(ref_wavelength,self.ch_config, 0)


    # __init__

    #properties
    
    #functions
    def checkSignalSize(self, raw_data: np.ndarray, ch_config_rev , var = 0) -> dict:
        # this function receive different ch_config to get raw data for different calibration matrix

        # create a dict
        raw_data_seperate_AA = {}

        """
        raw_data_seperate_AA
        form:
        {'AA1':[float,float,float...],'AA2':[]...}
        """

        check_status = 0

        for i in range(self.Num_AA):   
            raw_data_seperate_AA['AA'+str(i+1)] = np.array([])

        #end for

        #record current data position in rawdata
        counter = 0
        for i in range(self.Num_sm_CH):
            if ch_config_rev[i] <= self.signal_each_ch[i]:
                # how many data points are skipped for each ch
                ch_signal_diff = int(self.signal_each_ch[i] - ch_config_rev[i])
                for j in range(int(ch_config_rev[i])):
                    # if the reading for this channel is 0 then skip the following code
                    raw_data_seperate_AA['AA'+str(j+1)] = np.append(raw_data_seperate_AA['AA'+str(j+1)],raw_data[counter])
                    counter += 1
                #end for
                # skip some data points
                counter += ch_signal_diff

            else:
                # fail this check
                print("The Calibration Matrix Configuration is inconsistant with interrogator reading!")
                return {},check_status
            #end if
        #end for
        return raw_data_seperate_AA,1


    def getCurvatures( self, raw_signal: np.ndarray) -> np.ndarray:
        
        """
        calculate curvatures
        input: raw_signal, np.ndarray 1*N
        output: curvatures, Num_AA * 2
        """
        
        # check reading size and convert the input signal of raw_signal

        # get the curvature by general calibration matrix
        raw_signal_seperate_AA,check_status = self.checkSignalSize(raw_signal,self.ch_config,0)
        
        """
        form:
        raw_signal_seperate_AA
        {"AA1":list,"AA2":list...}
        """


        if self.if_temp_comp == 1:
            # convert the rawdata in form of sub mats
            self.sub_raw_signal = {}
            """
            form:
            {"A12":{"AA1":[],"AA2":[],...},"A13":{},...}
            """

            """
            # this part is replaced by E matrix
            for str_i in self.temp_A:
                # do not need to check the status since the sub mats is always meet the requirment
                sub_raw_signal_seperate_AA,check_status_temp = self.checkSignalSize(raw_signal,self.ch_config_TC[str_i],0)
                self.sub_raw_signal[str_i] = sub_raw_signal_seperate_AA
            # end for
           
            """

        # end if

        curvatures = np.zeros(self.Num_AA*2).reshape(self.Num_AA,2)


        if check_status == 1:

            aa_counter = 0
            for Cal_AA_names,Cal_AA_mats in self.general_cal_mats.items():
                diff_value = raw_signal_seperate_AA[Cal_AA_names] - self.ref_wavelength[Cal_AA_names]
                # diff is 1 by numAA
                # convert diff to numAA by 1


                max_dif = max(abs(diff_value))
                if max_dif >= self.dif_bound:
                    print("FBG value outbound, return empty list")
                    return []

                if self.if_temp_comp == 1:
                    # do temperatrue compensation
                    # self.temp_A: store the additional calibration matrix list
                    # self.temp_E: store the additional E matrix list

                    # curvature get by A
                    """
                    temp_A_cur
                    form:
                    list
                    """

                    temp_A_cur = Cal_AA_mats.T @ diff_value
                    temp_sub_A_cur = {}
                    A_aug = np.array([])
                    K_aug = np.array([])

                    for num in range(np.size(self.temp_A)):
                        str_A = self.temp_A[num]
                        str_E = self.temp_E[num]

                        temp_sub_A_cur[str_A] = self.sub_cal_mats_TC[str_A][Cal_AA_names].T @ self.additional_mats_E[str_E] @ diff_value
                        
                        if np.size(A_aug) == 0:
                            A_aug = Cal_AA_mats.T - self.sub_cal_mats_TC[str_A][Cal_AA_names].T @ self.additional_mats_E[str_E]
                            K_aug = np.array([temp_A_cur - temp_sub_A_cur[str_A]]).T

                        
                        else:
                            A_aug = np.vstack((A_aug,Cal_AA_mats.T - self.sub_cal_mats_TC[str_A][Cal_AA_names].T @ self.additional_mats_E[str_E]))
                            K_aug = np.vstack((K_aug,np.array([temp_A_cur - temp_sub_A_cur[str_A]]).T))
             
                        # end if
                    #end for
                    
                    alpha = np.linalg.pinv(A_aug@self.ch_ratio_seperateAA[Cal_AA_names]) @ K_aug
                    
                    diff_value = np.array([diff_value]) - (alpha * self.ch_ratio_seperateAA[Cal_AA_names]).T
                    
                    # now diff_value is row vector

                # end if

                #print(diff_value)
                #print(diff_value@ Cal_AA_mats)

                curvatures[aa_counter][0:2] = diff_value @ Cal_AA_mats
                aa_counter += 1


        # end if

        return curvatures
    

    
    def load_params(self, filename: str):
        """
        load a FBG_process class from a saved Json file
        return a FBG_process class
        """
        with open( filename, 'r') as json_file:
            content = json.load( json_file )
        

        self.Serial_Number = content.get("Serial Number")
        self.Num_CH = content.get("Num Needle Channel") # number of channel on needle
        self.Num_AA = content.get("Num Needle AA") # number of AA on needle
        self.Num_sm_CH = content.get("Num Interrogator Channel") # number of channel on interrogator
        self.if_temp_comp = content.get("Temperature Compensation")

        # get general calibration matrix

        self.general_cal_mats = {} #used to get curvatures
        self.ch_config = np.zeros(self.Num_sm_CH)

        """
        general_cal_mats
        form:
        {"AA1" : (Num_CH) * 2 , "AA2" : ...}
        """

        for AAnames,calvalues in content["Calibration Matrix A"].items():
            self.general_cal_mats[AAnames] = np.array(calvalues)
        # end for
       
        """
        cal_ch_config
        form:
        {"CH1_sm130":int, "CH2_sm130":...}
        """
        
        cal_ch_config = content["Calibration Matrix Configuration A"]
        

        """
        ch_config
        form:
        [int,int,int...]
        """
        for i in range(self.Num_sm_CH):
            self.ch_config[i] = cal_ch_config['CH'+str(i+1)+'_sm130']
        # end for

        # get sub calibration matrix for temperature compensation
        self.sub_cal_mats_TC = {}
        self.ch_config_TC = {}
        self.additional_mats_E = {}
        self.ch_ratio_seperateAA = {}

        """
        sub_cal_mats_TC
        form:
        {'A12':{'AA1':[],'AA2':[]...} ,'A13':{}...}
        """

        """
        ch_config_TC
        form:
        {'A12':[int,int,int...],'A13':[] ...}
        """
        
        """
        additional_mats_E
        form:
        {'E1':[],'E2':[],...}
        """

        """
        ch_ratio_seperateAA
        form:
        {"AA1":[],"AA2":[]...}
        """

        if self.if_temp_comp == 1:

            """
            temp
            form:
            [str,str...]
            """

            temp = content.get("Additional Calibration Matrix")
            # store the value in temp_A
            self.temp_A = temp

            for str_i in temp:

                cal_ch_config = content['Calibration Matrix Configuration '+str_i]
                temp_ch_config = np.zeros(self.Num_sm_CH);
                for i in range(self.Num_sm_CH):
                    temp_ch_config[i] = cal_ch_config['CH'+str(i+1)+'_sm130']
                # end for
                self.ch_config_TC[str_i] = temp_ch_config

                temp_sub_cal_mats = {}
                for AAnames,calvalues in content['Calibration Matrix ' + str_i].items():
                    temp_sub_cal_mats[AAnames] = np.array(calvalues)
                # end for
                self.sub_cal_mats_TC[str_i] = temp_sub_cal_mats

            # end for

            # get additional E matrix
            temp = content.get("Additional E Matrix")
            # store the value in temp_E
            self.temp_E = temp

            for str_i in temp:
                self.additional_mats_E[str_i] = content.get("Additional "+str_i+" Matrix")

            # end for

            # get ch_ratio_seperateAA
            for AAnames,ratios in content['Temperature Compensation Ratio'].items():
                self.ch_ratio_seperateAA[AAnames] = np.array(ratios)
            # end for

        # end if

    # load_params

    







