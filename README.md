# Abstract:

A minimalistic real time kernel developed for ARM Cortex-M4 based
processors with priority based preemptive scheduling which can be used to efficiently manage
processes in complex embedded systems. Synchronization primitives like semaphore and mutex are implemented to avoid race conditions among processes during resource aquisition.
The Kernel is developed to be highly portable with minimal processor specific code.

Further information regarding the kernel can be found in the pdf linked below.
           https://drive.google.com/file/d/1pQBJ9RPU2pcw9ahSNhtHSXkG6u7cOH3S/view?usp=sharing
           
 (This is not the full documentation of the kernel. Documentation development is still in progrss)          

# Execution:

To see the kernel working you can open the project in Keil IDE and start a debug session using the simulator. By stepping through the code you can see the tasks getting executed based on their priority
