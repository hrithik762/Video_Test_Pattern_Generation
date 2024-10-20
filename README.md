# Video_Test_Pattern_Generation

The project involves the implementation of a high-performance Video Test Pattern Generator on the PYNQ-Z1 FPGA development board. The system was designed using Xilinx Vivado Design Suite and validated through a real-time display connection. 

## Key Features:
### 1. FPGA Platform: Designed for the PYNQ-Z1 FPGA kit.

2. Real-Time Display: Functionality was validated by connecting the FPGA to a display via HDMI, enabling real-time output of test patterns.

3. Vivado Design Suite: The project was engineered on Vivado, utilizing its robust design and simulation tools for FPGA development.

4. AXI Interconnect Architecture: The system leverages the ZYNQ Processing System along with several key components to enable video processing and HDMI output.

## Components:
1. ZYNQ Processing System: Core of the system, managing the overall control and processing.

2. Processing System Reset: Ensures proper initialization and synchronization of the system components.

3. AXI Interconnect: Facilitates communication between the ZYNQ Processing System and peripherals.

4. HDMI Output: Enables the system to send video signals to a display.

5. Video Timing Controller: Ensures synchronization of video frames.

6. AXI Stream to Video Out: Converts AXI stream data into video output compatible with HDMI.
