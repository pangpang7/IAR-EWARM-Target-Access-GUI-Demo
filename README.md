# IAR-EWARM-Target-Access-GUI-Demo
How to leverage IAR EWARM Target Access mechanism to implement remote data collection and analysis 

IAR EWARM Target Access part based on https://github.com/IARSystems/cspy-target-access-demo
GUI part based on https://github.com/CieNTi/serial_port_plotter

Successfully built by QT 5.11.1 and MSVC2017_64bit

IAR target access mechanism:
![image](https://github.com/pangpang7/IAR-EWARM-Target-Access-GUI-Demo/blob/main/IAR%20Target%20Access.png)

Target Access Demo:
![image](https://github.com/pangpang7/IAR-EWARM-Target-Access-GUI-Demo/blob/main/DEMO.gif)

How to setup:
1. setup in EWARM
Open project option dialogue in EWARM(project->options), select Target Access Server in Debugger->Plugins
![image](https://github.com/pangpang7/IAR-EWARM-Target-Access-GUI-Demo/blob/main/setup_EWARM.png)

2. setup in GUI for target access control
Target access control options are located in the red box of below picture :
• IP: The IP address of the host running EWARM (default localhost)
• PORT: Port (default 9931)
• DATA: The data address to be displayed, currently only supports 32-bit data display. Configure the format (addr1, addr2). Example: 0x1fffa77c, 0x1fffa780 represents 32 bits of data to be collected for addresses of 0x1fffa77c and 0x1fffa780, the data of the first address will be Channel 0 and the second will be Channel 1.
• Int: Interval, the interval between the acquired data, in ms. The default is 50ms.
![image](https://github.com/pangpang7/IAR-EWARM-Target-Access-GUI-Demo/blob/main/setup_GUI.png)

Enjoy!!!
