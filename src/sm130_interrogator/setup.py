from setuptools import setup,find_packages

package_name = 'sm130_interrogator'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    #packages = find_packages(exclude=['sm130_member_function']) ,
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='yangshengxu',
    maintainer_email='yxu168@jhu.edu',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'talker = sm130_interrogator.talker:main',
            'listener = sm130_interrogator.listener:main', 
        ],
    },
)
