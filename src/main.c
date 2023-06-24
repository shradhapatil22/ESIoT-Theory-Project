#include "at89c51ed2.h"// Include the header file for 8051 microcontrollers
sbit switchPin=P1^0;

// Function to initialize UART
void UART_Init() {
    TMOD = 0x20; // Set Timer 1 in Mode 2
    SCON = 0x50; // Set UART in Mode 1, 8-bit data, 1-stop bit
    TH1 = 0xF4;// Set Baud rate
    TR1 = 1; // Start Timer 1
}

//Main
void main()
{
    unsigned char count = 0;
    UART_Init(); // Initialize UART
	  switchPin=1;  // set P1 as input

    while (1)
    {
        if (switchPin == 1) 
        {
            // Implement 8-bit odd count on P2
            P2 = count + 1;
            count += 2;
            UART_TransmitString("ODD ");
        }
    }
}
