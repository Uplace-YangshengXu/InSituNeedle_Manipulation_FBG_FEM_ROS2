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
        
        #self.Num_CH  # channel number
        #self.Num_AA  # Active Area number
        #self.cal_mats # calibration matrix
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
        self.ref_wavelength,check_status = self.checkSignalSize(ref_wavelength, 0)


    # __init__

    #properties
    
    #functions
    def checkSignalSize(self, raw_data: np.ndarray, var = 0) -> dict:
        # create a dict
        raw_data_seperate_AA = {}
        check_status = 0

        for i in range(self.Num_AA):   
            raw_data_seperate_AA['AA'+str(i+1)] = np.array([])

        #end for

        counter = 0

        for i in range(self.Num_CH):
            if self.ch_config[i] <= self.signal_each_ch[i]:
                
                for j in range(int(self.ch_config[i])):
                    # if the reading for this channel is 0 then skip the following code
                    raw_data_seperate_AA['AA'+str(j+1)] = np.append(raw_data_seperate_AA['AA'+str(j+1)],raw_data[counter])
                    counter += 1
                #end for
            else:
                
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
        raw_signal_seperate_AA,check_status = self.checkSignalSize(raw_signal)


        curvatures = np.zeros(self.Num_AA*2).reshape(self.Num_AA,2)
        
        if check_status == 1:
            

            aa_counter = 0
            for Cal_AA_names,Cal_AA_mats in self.cal_mats.items():
                diff_value = raw_signal_seperate_AA[Cal_AA_names] - self.ref_wavelength[Cal_AA_names]
                # diff is 1 by numAA

                max_dif = max(abs(diff_value))

                if max_dif >= self.dif_bound:
                    print("FBG value outbound, return empty list")
                    return []

                curvatures[aa_counter][0:2] = diff_value @ Cal_AA_mats
                aa_counter += 1

        # end for
        return curvatures
    

    
    def load_params(self, filename: str):
        """
        load a FBG_process class from a saved Json file
        return a FBG_process class
        """
        with open( filename, 'r') as json_file:
            content = json.load( json_file )
        

        self.Serial_Number = content.get("Serial Number")
        self.Num_CH = content.get("Num Channel")
        self.Num_AA = content.get("Num AA")
        self.cal_mats = {}
        self.ch_config = np.zeros(self.Num_AA)
        """
        form:
        {"AA1" : (Num_CH + 1) * 2 , "AA2" : ...}
        """

        for AAnames,calvalues in content["Calibration Matrix"].items():
            self.cal_mats[AAnames] = np.array(calvalues)
        # end for
       
        """
        form:
        {"CH1_sm130":int, "CH2_sm130":...}
        """
        
        cal_ch_config = content["Calibration Matrix Configuration"]

        for i in range(self.Num_CH):
            self.ch_config[i] = cal_ch_config['CH'+str(i+1)+'_sm130']
        # end for

    # load_params

    







