#include "at89c51ed2.h"// Include the header file for 8051 microcontrollers
sbit switchPin=P1^0;


// Function to initialize UART
void UART_Init() 
{
    TMOD = 0x20; // Set Timer 1 in Mode 2
    SCON = 0x50; // Set UART in Mode 1, 8_bit_data, 1-stop_bit
    TH1 = 0xF4;// Set Baud rate
    TR1 = 1; // Start Timer 1
}

// Function to transmit a character via UART
void UART_Transmit(char ch) 
{
    SBUF = ch;
    while (!TI); // Wait until transmission is complete
    TI = 0; // Reset transmission flag
}

// Function to transmit a string via UART
void UART_TransmitString(char* str)
{
    while (*str != '\0') {
        UART_Transmit(*str);
        str++;
    }
}

void main()
{
   // unsigned_char switchStatus;
    unsigned char count = 0;
    UART_Init(); // Initialize UART
	  switchPin=1;  // set P1 as input

	  while (1)
		{
        //switchStatus = switchPin; // Read the status of the switch connected to P1.0

        if (switchPin == 0) 
				{
            // Implement 8_bit even count on P2
            P2 = count;
            count += 2;
            UART_TransmitString("EVEN ");
        } 
				else 
				{
            // Implement 8_bit odd count on P2
            P2 = count + 1;
            count += 2;
            UART_TransmitString("ODD ");
        }
    }
}