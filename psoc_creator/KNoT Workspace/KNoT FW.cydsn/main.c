#include "ad5940.h"
#include <project.h>
#include <stdio.h>
#include <stdlib.h>

#if defined (__GNUC__)
    asm (".global _printf_float");
#endif

#define USBFS_DEVICE    (0u)

#define USBUART_BUFFER_SIZE (64u)
#define LINE_STR_LENGTH (20u)

void DmaTxConfiguration(void);
void DmaRxConfiguration(void);

/* DMA Configuration for DMA_TX */
#define DMA_TX_BYTES_PER_BURST      (1u)
#define DMA_TX_REQUEST_PER_BURST    (1u)
#define DMA_TX_SRC_BASE             (CYDEV_SRAM_BASE)
#define DMA_TX_DST_BASE             (CYDEV_PERIPH_BASE)

/* DMA Configuration for DMA_RX */
#define DMA_RX_BYTES_PER_BURST      (1u)
#define DMA_RX_REQUEST_PER_BURST    (1u)
#define DMA_RX_SRC_BASE             (CYDEV_PERIPH_BASE)
#define DMA_RX_DST_BASE             (CYDEV_SRAM_BASE)

#define BUFFER_SIZE                 (8u)
#define STORE_TD_CFG_ONCMPLT        (1u)

uint16 count;
uint8 buffer[USBUART_BUFFER_SIZE];

/* Variable declarations for DMA_TX*/
uint8 txChannel;
uint8 txTD;

/* Variable declarations for DMA_RX */
uint8 rxChannel;
uint8 rxTD;

/* Data buffers */
uint8 txBuffer [BUFFER_SIZE] = {0x0u, 0x01u, 0x02u, 0x03u, 0x04u, 0x05u, 0x06u, 0x07u};
uint8 rxBuffer[BUFFER_SIZE];

char8* parity[] = {"None", "Odd", "Even", "Mark", "Space"};
char8* stop[]   = {"1", "1.5", "2"};

char a1 = 0, b1 = 0, c1 = 0, d1 = 0;
char a2 = 0, b2 = 0, c2 = 0, d2 = 0;
char a3 = 0, b3 = 0, c3 = 0, d3 = 0;
char pre_a2 = 0, pre_c2 = 0;

void AD5940_CsClr(){
}

void AD5940_CsSet(){
}

void AD5940_RstClr(){
}

void AD5940_RstSet(){
}

void AD5940_Delay10us(uint32_t time){
    CyDelayUs(10*time);
}

void AD5940_ReadWriteNBytes(unsigned char *pSendBuffer,unsigned char *pRecvBuff,unsigned long length){
    uint32_t tx_count=0, rx_count=0;
    CR_Write(6);
    SPIM_ClearRxBuffer();
    while(1){ 
        if(rx_count < length){
            int a= SPIM_GetRxBufferSize();
          if(a != 0u){//there is data in RX FIFO.
            uint8 b = SPIM_ReadRxData();
            *pRecvBuff++ = b;
            rx_count++;
          }
        }
        if(tx_count < length){
          if(SPIM_GetTxBufferSize() < 4){// there is space in TX FIFO.
            SPIM_WriteTxData(*pSendBuffer++);
            tx_count++;
          }
        }
        if(rx_count == length && tx_count==length)
          break;  //done
    }
    while(0u == (SPIM_ReadTxStatus() & SPIM_STS_SPI_DONE));//wait for transfer done.
}

void spi_tx(int a, int b, int c, int d){
    SPIM_Start();
    
    SPIM_WriteTxData(a);
    SPIM_WriteTxData(b);
    SPIM_WriteTxData(c);
    SPIM_WriteTxData(d);
    
    SPIM_Stop();
}

void mux_toggle(int channel, char output, int state){  
    output = toupper(output);
    pre_a2 = a2;
    pre_c2 = c2;
    
    if ((int)output == 65){ //Output == 'A'
        switch(channel){
        case 1:
            if (state && !(c1 & 0x01)){
                c1 = c1 + 1;
            }
            if (!state && (c1 & 0x01)){
                c1 = c1 - 1;
            }
            break;
        case 2:
            if (state && !(c1 & 0x02)){
                c1 = c1 + 2;
            }
            if (!state && (c1 & 0x02)){
                c1 = c1 - 2;
            }
            break;
        case 3:
            if (state && !(c1 & 0x04)){
                c1 = c1 + 4;
            }
            if (!state && (c1 & 0x04)){
                c1 = c1 - 4;
            }
            break;
        case 4:
            if (state && !(c1 & 0x08)){
                c1 = c1 + 8;
            }
            if (!state && (c1 & 0x08)){
                c1 = c1 - 8;
            }
            break;
        case 5:
            if (state && !(c1 & 0x10)){
                c1 = c1 + 16;
            }
            if (!state && (c1 & 0x10)){
                c1 = c1 - 16;
            }
            break;
        case 6:
            if (state && !(c1 & 0x20)){
                c1 = c1 + 32;
            }
            if (!state && (c1 & 0x20)){
                c1 = c1 - 32;
            }
            break;
        case 7:
            if (state && !(c1 & 0x40)){
                c1 = c1 + 64;
            }
            if (!state && (c1 & 0x40)){
                c1 = c1 - 64;
            }
            break;
        case 8:
            if (state && !(c1 & 0x80)){
                c1 = c1 + 128;
            }
            if (!state && (c1 & 0x80)){
                c1 = c1 - 128;
            }
            break;
        case 9:
            if (state && !(d1 & 0x80)){
                d1 = d1 + 128;
            }
            if (!state && (d1& 0x80)){
                d1 = d1 - 128;
            }
            break;
        case 10:
            if (state && !(d1 & 0x40)){
                d1 = d1 + 64;
            }
            if (!state && (d1 & 0x40)){
                d1 = d1 - 64;
            }
            break;
        case 11:
            if (state && !(d1 & 0x20)){
                d1 = d1 + 32;
            }
            if (!state && (d1 & 0x20)){
                d1 = d1 - 32;
            }
            break;
        case 12:
            if (state && !(d1 & 0x10)){
                d1 = d1 + 16;
            }
            if (!state && (d1 & 0x10)){
                d1 = d1 - 16;
            }
            break;
        case 13:
            if (state && !(d1 & 0x08)){
                d1 = d1 + 8;
            }
            if (!state && (d1 & 0x08)){
                d1 = d1 - 8;
            }
            break;
        case 14:
            if (state && !(d1 & 0x04)){
                d1 = d1 + 4;
            }
            if (!state && (d1 & 0x04)){
                d1 = d1 - 4;
            }
            break;
        case 15:
            if (state && !(d1 & 0x02)){
                d1 = d1 + 2;
            }
            if (!state && (d1 & 0x02)){
                d1 = d1 - 2;
            }
            break;
        case 16:
            if (state && !(d1 & 0x01)){
                d1 = d1 + 1;
            }
            if (!state && (d1 & 0x01)){
                d1 = d1 - 1;
            }
            break;
        case 17:
            if (state && !(c2 & 0x01)){
                c2 = c2 + 1;
            }
            if (!state && (c2 & 0x01)){
                c2 = c2 - 1;
            }
            break;
        case 18:
            if (state && !(c2 & 0x02)){
                c2 = c2 + 2;
            }
            if (!state && (c2 & 0x02)){
                c2 = c2 - 2;
            }
            break;
        case 19:
            if (state && !(c2 & 0x04)){
                c2 = c2 + 4;
            }
            if (!state && (c2 & 0x04)){
                c2 = c2 - 4;
            }
            break;
        case 20:
            if (state && !(c2 & 0x08)){
                c2 = c2 + 8;
            }
            if (!state && (c2 & 0x08)){
                c2 = c2 - 8;
            }
            break;
        case 21:
            if (state && !(c2 & 0x10)){
                c2 = c2 + 16;
            }
            if (!state && (c2 & 0x10)){
                c2 = c2 - 16;
            }
            break;
        case 22:
            if (state && !(c2 & 0x20)){
                c2 = c2 + 32;
            }
            if (!state && (c2 & 0x20)){
                c2 = c2 - 32;
            }
            break;
        case 23:
            if (state && !(c2 & 0x40)){
                c2 = c2 + 64;
            }
            if (!state && (c2 & 0x40)){
                c2 = c2 - 64;
            }
            break;
        case 24:
            if (state && !(d2 & 0x80)){
                d2 = d2 + 128;
            }
            if (!state && (d2 & 0x80)){
                d2 = d2 - 128;
            }
            break;
        case 25:
            if (state && !(d2 & 0x40)){
                d2 = d2 + 64;
            }
            if (!state && (d2 & 0x40)){
                d2 = d2 - 64;
            }
            break;
        case 26:
            if (state && !(d2 & 0x20)){
                d2 = d2 + 32;
            }
            if (!state && (d2 & 0x20)){
                d2 = d2 - 32;
            }
            break;
        case 27:
            if (state && !(d2 & 0x10)){
                d2 = d2 + 16;
            }
            if (!state && (d2 & 0x10)){
                d2 = d2 - 16;
            }
            break;
        case 28:
            if (state && !(d2 & 0x08)){
                d2 = d2 + 8;
            }
            if (!state && (d2 & 0x08)){
                d2 = d2 - 8;
            }
            break;
        case 29:
            if (state && !(d2 & 0x04)){
                d2 = d2 + 4;
            }
            if (!state && (d2 & 0x04)){
                d2 = d2 - 4;
            }
            break;
        case 30:
            if (state && !(d2 & 0x02)){
                d2 = d2 + 2;
            }
            if (!state && (d2 & 0x02)){
                d2 = d2 - 2;
            }
            break;
        case 31:
            if (state && !(d2 & 0x01)){
                d2 = d2 + 1;
            }
            if (!state && (d2 & 0x01)){
                d2 = d2 - 1;
            }
            break;
        case 32:
            if (state && !(a3 & 0x01)){
                a3 = a3 + 1;
                if(!(c2 & 0x80)){
                    c2 = c2 + 128;
                }
            }
            if (!state && (a3 & 0x01)){
                a3 = a3 - 1;
                if(!(a3 & 0xFF) && (c2 & 0x80)){
                    c2 = c2 - 128;
                }
            }
            break;
        case 33:
            if (state && !(a3 & 0x02)){
                a3 = a3 + 2;
                if(!(c2 & 0x80)){
                    c2 = c2 + 128;
                }
            }
            if (!state && (a3 & 0x02)){
                a3 = a3 - 2;
                if(!(a3 & 0xFF) && (c2 & 0x80)){
                    c2 = c2 - 128;
                }
            }
            break;
        case 34:
            if (state && !(a3 & 0x04)){
                a3 = a3 + 4;
                if(!(c2 & 0x80)){
                    c2 = c2 + 128;
                }
            }
            if (!state && (a3 & 0x04)){
                a3 = a3 - 4;
                if(!(a3 & 0xFF) && (c2 & 0x80)){
                    c2 = c2 - 128;
                }
            }
            break;
        case 35:
            if (state && !(a3 & 0x08)){
                a3 = a3 + 8;
                if(!(c2 & 0x80)){
                    c2 = c2 + 128;
                }
            }
            if (!state && (a3 & 0x08)){
                a3 = a3 - 8;
                if(!(a3 & 0xFF) && (c2 & 0x80)){
                    c2 = c2 - 128;
                }
            }
            break;
        case 36:
            if (state && !(a3 & 0x10)){
                a3 = a3 + 16;
                if(!(c2 & 0x80)){
                    c2 = c2 + 128;
                }
            }
            if (!state && (a3 & 0x10)){
                a3 = a3 - 16;
                if(!(a3 & 0xFF) && (c2 & 0x80)){
                    c2 = c2 - 128;
                }
            }
            break;
        case 37:
            if (state && !(a3 & 0x20)){
                a3 = a3 + 32;
                if(!(c2 & 0x80)){
                    c2 = c2 + 128;
                }
            }
            if (!state && (a3 & 0x20)){
                a3 = a3 - 32;
                if(!(a3 & 0xFF) && (c2 & 0x80)){
                    c2 = c2 - 128;
                }
            }
            break;
        case 38:
            if (state && !(a3 & 0x40)){
                a3 = a3 + 64;
                if(!(c2 & 0x80)){
                    c2 = c2 + 128;
                }
            }
            if (!state && (a3 & 0x40)){
                a3 = a3 - 64;
                if(!(a3 & 0xFF) && (c2 & 0x80)){
                    c2 = c2 - 128;
                }
            }
            break;
        case 39:
            if (state && !(a3 & 0x80)){
                a3 = a3 + 128;
                if(!(c2 & 0x80)){
                    c2 = c2 + 128;
                }
            }
            if (!state && (a3 & 0x80)){
                a3 = a3 - 128;
                if(!(a3 & 0xFF) && (c2 & 0x80)){
                    c2 = c2 - 128;
                }
            }
            break;
        case 40:
            if (state && !(b3 & 0x80)){
                b3 = b3 + 128;
                if(!(c2 & 0x80)){
                    c2 = c2 + 128;
                }
            }
            if (!state && (b3 & 0x80)){
                b3 = b3 - 128;
                if(!(b3 & 0xFF) && (c2 & 0x80)){
                    c2 = c2 - 128;
                }
            }
            break;
        case 41:
            if (state && !(b3 & 0x40)){
                b3 = b3 + 64;
                if(!(c2 & 0x80)){
                    c2 = c2 + 128;
                }
            }
            if (!state && (b3 & 0x40)){
                b3 = b3 - 64;
                if(!(b3 & 0xFF) && (c2 & 0x80)){
                    c2 = c2 - 128;
                }
            }
            break;
        case 42:
            if (state && !(b3 & 0x20)){
                b3 = b3 + 32;
                if(!(c2 & 0x80)){
                    c2 = c2 + 128;
                }
            }
            if (!state && (b3 & 0x20)){
                b3 = b3 - 32;
                if(!(b3 & 0xFF) && (c2 & 0x80)){
                    c2 = c2 - 128;
                }
            }
            break;
        case 43:
            if (state && !(b3 & 0x10)){
                b3 = b3 + 16;
                if(!(c2 & 0x80)){
                    c2 = c2 + 128;
                }
            }
            if (!state && (b3 & 0x10)){
                b3 = b3 - 16;
                if(!(b3 & 0xFF) && (c2 & 0x80)){
                    c2 = c2 - 128;
                }
            }
            break;
        case 44:
            if (state && !(b3 & 0x08)){
                b3 = b3 + 8;
                if(!(c2 & 0x80)){
                    c2 = c2 + 128;
                }
            }
            if (!state && (b3 & 0x08)){
                b3 = b3 - 8;
                if(!(b3 & 0xFF) && (c2 & 0x80)){
                    c2 = c2 - 128;
                }
            }
            break;
        case 45:
            if (state && !(b3 & 0x04)){
                b3 = b3 + 4;
                if(!(c2 & 0x80)){
                    c2 = c2 + 128;
                }
            }
            if (!state && (b3 & 0x04)){
                b3 = b3 - 4;
                if(!(b3 & 0xFF) && (c2 & 0x80)){
                    c2 = c2 - 128;
                }
            }
            break;
        case 46:
            if (state && !(b3 & 0x02)){
                b3 = b3 + 2;
                if(!(c2 & 0x80)){
                    c2 = c2 + 128;
                }
            }
            if (!state && (b3 & 0x02)){
                b3 = b3 - 2;
                if(!(b3 & 0xFF) && (c2 & 0x80)){
                    c2 = c2 - 128;
                }
            }
            break;
        case 47:
            if (state && !(b3 & 0x01)){
                b3 = b3 + 1;
                if(!(c2 & 0x80)){
                    c2 = c2 + 128;
                }
            }
            if (!state && (b3 & 0x01)){
                b3 = b3 - 1;
                if(!(b3 & 0xFF) && (c2 & 0x80)){
                    c2 = c2 - 128;
                }
            }
            break;
        }
    }
    else if ((int)output == 66){ //Output == 'B'
        switch(channel){
        case 1:
            if (state && !(a1 & 0x01)){
                a1 = a1 + 1;
            }
            if (!state && (a1 & 0x01)){
                a1 = a1 - 1;
            }
            break;
        case 2:
            if (state && !(a1 & 0x02)){
                a1 = a1 + 2;
            }
            if (!state && (a1 & 0x02)){
                a1 = a1 - 2;
            }
            break;
        case 3:
            if (state && !(a1 & 0x04)){
                a1 = a1 + 4;
            }
            if (!state && (a1 & 0x04)){
                a1 = a1 - 4;
            }
            break;
        case 4:
            if (state && !(a1 & 0x08)){
                a1 = a1 + 8;
            }
            if (!state && (a1 & 0x08)){
                a1 = a1 - 8;
            }
            break;
        case 5:
            if (state && !(a1 & 0x10)){
                a1 = a1 + 16;
            }
            if (!state && (a1 & 0x10)){
                a1 = a1 - 16;
            }
            break;
        case 6:
            if (state && !(a1 & 0x20)){
                a1 = a1 + 32;
            }
            if (!state && (a1 & 0x20)){
                a1 = a1 - 32;
            }
            break;
        case 7:
            if (state && !(a1 & 0x40)){
                a1 = a1 + 64;
            }
            if (!state && (a1 & 0x40)){
                a1 = a1 - 64;
            }
            break;
        case 8:
            if (state && !(a1 & 0x80)){
                a1 = a1 + 128;
            }
            if (!state && (a1 & 0x80)){
                a1 = a1 - 128;
            }
            break;
        case 9:
            if (state && !(b1 & 0x80)){
                b1 = b1 + 128;
            }
            if (!state && (b1& 0x80)){
                b1 = b1 - 128;
            }
            break;
        case 10:
            if (state && !(b1 & 0x40)){
                b1 = b1 + 64;
            }
            if (!state && (b1 & 0x40)){
                b1 = b1 - 64;
            }
            break;
        case 11:
            if (state && !(b1 & 0x20)){
                b1 = b1 + 32;
            }
            if (!state && (b1 & 0x20)){
                b1 = b1 - 32;
            }
            break;
        case 12:
            if (state && !(b1 & 0x10)){
                b1 = b1 + 16;
            }
            if (!state && (b1 & 0x10)){
                b1 = b1 - 16;
            }
            break;
        case 13:
            if (state && !(b1 & 0x08)){
                b1 = b1 + 8;
            }
            if (!state && (b1 & 0x08)){
                b1 = b1 - 8;
            }
            break;
        case 14:
            if (state && !(b1 & 0x04)){
                b1 = b1 + 4;
            }
            if (!state && (b1 & 0x04)){
                b1 = b1 - 4;
            }
            break;
        case 15:
            if (state && !(b1 & 0x02)){
                b1 = b1 + 2;
            }
            if (!state && (b1 & 0x02)){
                b1 = b1 - 2;
            }
            break;
        case 16:
            if (state && !(b1 & 0x01)){
                b1 = b1 + 1;
            }
            if (!state && (b1 & 0x01)){
                b1 = b1 - 1;
            }
            break;
        case 17:
            if (state && !(a2 & 0x01)){
                a2 = a2 + 1;
            }
            if (!state && (a2 & 0x01)){
                a2 = a2 - 1;
            }
            break;
        case 18:
            if (state && !(a2 & 0x02)){
                a2 = a2 + 2;
            }
            if (!state && (a2 & 0x02)){
                a2 = a2 - 2;
            }
            break;
        case 19:
            if (state && !(a2 & 0x04)){
                a2 = a2 + 4;
            }
            if (!state && (a2 & 0x04)){
                a2 = a2 - 4;
            }
            break;
        case 20:
            if (state && !(a2 & 0x08)){
                a2 = a2 + 8;
            }
            if (!state && (a2 & 0x08)){
                a2 = a2 - 8;
            }
            break;
        case 21:
            if (state && !(a2 & 0x10)){
                a2 = a2 + 16;
            }
            if (!state && (a2 & 0x10)){
                a2 = a2 - 16;
            }
            break;
        case 22:
            if (state && !(a2 & 0x20)){
                a2 = a2 + 32;
            }
            if (!state && (a2 & 0x20)){
                a2 = a2 - 32;
            }
            break;
        case 23:
            if (state && !(a2 & 0x40)){
                a2 = a2 + 64;
            }
            if (!state && (a2 & 0x40)){
                a2 = a2 - 64;
            }
            break;
        case 24:
            if (state && !(b2 & 0x80)){
                b2 = b2 + 128;
            }
            if (!state && (b2 & 0x80)){
                b2 = b2 - 128;
            }
            break;
        case 25:
            if (state && !(b2 & 0x40)){
                b2 = b2 + 64;
            }
            if (!state && (b2 & 0x40)){
                b2 = b2 - 64;
            }
            break;
        case 26:
            if (state && !(b2 & 0x20)){
                b2 = b2 + 32;
            }
            if (!state && (b2 & 0x20)){
                b2 = b2 - 32;
            }
            break;
        case 27:
            if (state && !(b2 & 0x10)){
                b2 = b2 + 16;
            }
            if (!state && (b2 & 0x10)){
                b2 = b2 - 16;
            }
            break;
        case 28:
            if (state && !(b2 & 0x08)){
                b2 = b2 + 8;
            }
            if (!state && (b2 & 0x08)){
                b2 = b2 - 8;
            }
            break;
        case 29:
            if (state && !(b2 & 0x04)){
                b2 = b2 + 4;
            }
            if (!state && (b2 & 0x04)){
                b2 = b2 - 4;
            }
            break;
        case 30:
            if (state && !(b2 & 0x02)){
                b2 = b2 + 2;
            }
            if (!state && (b2 & 0x02)){
                b2 = b2 - 2;
            }
            break;
        case 31:
            if (state && !(b2 & 0x01)){
                b2 = b2 + 1;
            }
            if (!state && (b2 & 0x01)){
                b2 = b2 - 1;
            }
            break;
        case 32:
            if (state && !(a3 & 0x01)){
                a3 = a3 + 1;
                if(!(a2 & 0x80)){
                    a2 = a2 + 128;
                }
            }
            if (!state && (a3 & 0x01)){
                a3 = a3 - 1;
                if(!(a3 & 0xFF) && (a2 & 0x80)){
                    a2 = a2 - 128;
                }
            }
            break;
        case 33:
            if (state && !(a3 & 0x02)){
                a3 = a3 + 2;
                if(!(a2 & 0x80)){
                    a2 = a2 + 128;
                }
            }
            if (!state && (a3 & 0x02)){
                a3 = a3 - 2;
                if(!(a3 & 0xFF) && (a2 & 0x80)){
                    a2 = a2 - 128;
                }
            }
            break;
        case 34:
            if (state && !(a3 & 0x04)){
                a3 = a3 + 4;
                if(!(a2 & 0x80)){
                    a2 = a2 + 128;
                }
            }
            if (!state && (a3 & 0x04)){
                a3 = a3 - 4;
                if(!(a3 & 0xFF) && (a2 & 0x80)){
                    a2 = a2 - 128;
                }
            }
            break;
        case 35:
            if (state && !(a3 & 0x08)){
                a3 = a3 + 8;
                if(!(a2 & 0x80)){
                    a2 = a2 + 128;
                }
            }
            if (!state && (a3 & 0x08)){
                a3 = a3 - 8;
                if(!(a3 & 0xFF) && (a2 & 0x80)){
                    a2 = a2 - 128;
                }
            }
            break;
        case 36:
            if (state && !(a3 & 0x10)){
                a3 = a3 + 16;
                if(!(a2 & 0x80)){
                    a2 = a2 + 128;
                }
            }
            if (!state && (a3 & 0x10)){
                a3 = a3 - 16;
                if(!(a3 & 0xFF) && (a2 & 0x80)){
                    a2 = a2 - 128;
                }
            }
            break;
        case 37:
            if (state && !(a3 & 0x20)){
                a3 = a3 + 32;
                if(!(a2 & 0x80)){
                    a2 = a2 + 128;
                }
            }
            if (!state && (a3 & 0x20)){
                a3 = a3 - 32;
                if(!(a3 & 0xFF) && (a2 & 0x80)){
                    a2 = a2 - 128;
                }
            }
            break;
        case 38:
            if (state && !(a3 & 0x40)){
                a3 = a3 + 64;
                if(!(a2 & 0x80)){
                    a2 = a2 + 128;
                }
            }
            if (!state && (a3 & 0x40)){
                a3 = a3 - 64;
                if(!(a3 & 0xFF) && (a2 & 0x80)){
                    a2 = a2 - 128;
                }
            }
            break;
        case 39:
            if (state && !(a3 & 0x80)){
                a3 = a3 + 128;
                if(!(a2 & 0x80)){
                    a2 = a2 + 128;
                }
            }
            if (!state && (a3 & 0x80)){
                a3 = a3 - 128;
                if(!(a3 & 0xFF) && (a2 & 0x80)){
                    a2 = a2 - 128;
                }
            }
            break;
        case 40:
            if (state && !(b3 & 0x80)){
                b3 = b3 + 128;
                if(!(a2 & 0x80)){
                    a2 = a2 + 128;
                }
            }
            if (!state && (b3 & 0x80)){
                b3 = b3 - 128;
                if(!(b3 & 0xFF) && (a2 & 0x80)){
                    a2 = a2 - 128;
                }
            }
            break;
        case 41:
            if (state && !(b3 & 0x40)){
                b3 = b3 + 64;
                if(!(a2 & 0x80)){
                    a2 = a2 + 128;
                }
            }
            if (!state && (b3 & 0x40)){
                b3 = b3 - 64;
                if(!(b3 & 0xFF) && (a2 & 0x80)){
                    a2 = a2 - 128;
                }
            }
            break;
        case 42:
            if (state && !(b3 & 0x20)){
                b3 = b3 + 32;
                if(!(a2 & 0x80)){
                    a2 = a2 + 128;
                }
            }
            if (!state && (b3 & 0x20)){
                b3 = b3 - 32;
                if(!(b3 & 0xFF) && (a2 & 0x80)){
                    a2 = a2 - 128;
                }
            }
            break;
        case 43:
            if (state && !(b3 & 0x10)){
                b3 = b3 + 16;
                if(!(a2 & 0x80)){
                    a2 = a2 + 128;
                }
            }
            if (!state && (b3 & 0x10)){
                b3 = b3 - 16;
                if(!(b3 & 0xFF) && (a2 & 0x80)){
                    a2 = a2 - 128;
                }
            }
            break;
        case 44:
            if (state && !(b3 & 0x08)){
                b3 = b3 + 8;
                if(!(a2 & 0x80)){
                    a2 = a2 + 128;
                }
            }
            if (!state && (b3 & 0x08)){
                b3 = b3 - 8;
                if(!(b3 & 0xFF) && (a2 & 0x80)){
                    a2 = a2 - 128;
                }
            }
            break;
        case 45:
            if (state && !(b3 & 0x04)){
                b3 = b3 + 4;
                if(!(a2 & 0x80)){
                    a2 = a2 + 128;
                }
            }
            if (!state && (b3 & 0x04)){
                b3 = b3 - 4;
                if(!(b3 & 0xFF) && (a2 & 0x80)){
                    a2 = a2 - 128;
                }
            }
            break;
        case 46:
            if (state && !(b3 & 0x02)){
                b3 = b3 + 2;
                if(!(a2 & 0x80)){
                    a2 = a2 + 128;
                }
            }
            if (!state && (b3 & 0x02)){
                b3 = b3 - 2;
                if(!(b3 & 0xFF) && (a2 & 0x80)){
                    a2 = a2 - 128;
                }
            }
            break;
        case 47:
            if (state && !(b3 & 0x01)){
                b3 = b3 + 1;
                if(!(a2 & 0x80)){
                    a2 = a2 + 128;
                }
            }
            if (!state && (b3 & 0x01)){
                b3 = b3 - 1;
                if(!(b3 & 0xFF) && (a2 & 0x80)){
                    a2 = a2 - 128;
                }
            }
            break;
        }
    }
    
    if (channel < 17){ //First pair of muxes
        CR_Write(0);
        spi_tx(a1, b1, c1, d1);
        while(0u == (SPIM_ReadTxStatus() & SPIM_STS_SPI_DONE));
        CR_Write(1);
        spi_tx(a1, b1, c1, d1);
        while(0u == (SPIM_ReadTxStatus() & SPIM_STS_SPI_DONE));
    }
    else if (channel > 16 && channel < 32){ //Middle pair of muxes
        CR_Write(2);
        spi_tx(a2, b2, c2, d2);
        while(0u == (SPIM_ReadTxStatus() & SPIM_STS_SPI_DONE));
        CR_Write(3);
        spi_tx(a2, b2, c2, d2);
        while(0u == (SPIM_ReadTxStatus() & SPIM_STS_SPI_DONE));
    }
    else if (channel > 31){ //Last pair of muxes
        CR_Write(4);
        spi_tx(a3, b3, c3, d3);
        while(0u == (SPIM_ReadTxStatus() & SPIM_STS_SPI_DONE));
        CR_Write(5);
        spi_tx(a3, b3, c3, d3);
        while(0u == (SPIM_ReadTxStatus() & SPIM_STS_SPI_DONE));
        if ( ((int)output == 65 && (!(pre_c2 & 0x80))) || ((int)output == 66 && (!(pre_a2 & 0x80))) ){
            CR_Write(2);
            spi_tx(a2, b2, c2, d2);
            while(0u == (SPIM_ReadTxStatus() & SPIM_STS_SPI_DONE));
            CR_Write(3);
            spi_tx(a2, b2, c2, d2);
            while(0u == (SPIM_ReadTxStatus() & SPIM_STS_SPI_DONE));
        }
    }
}

void mux_close_all(){
    a1 = 0, b1 = 0, c1 = 0, d1 = 0;
    a2 = 0, b2 = 0, c2 = 0, d2 = 0;
    a3 = 0, b3 = 0, c3 = 0, d3 = 0;
    
    CR_Write(0);
    spi_tx(a1, b1, c1, d1);
    while(0u == (SPIM_ReadTxStatus() & SPIM_STS_SPI_DONE)){}
    CR_Write(1);
    spi_tx(a1, b1, c1, d1);
    while(0u == (SPIM_ReadTxStatus() & SPIM_STS_SPI_DONE)){}
    CR_Write(2);
    spi_tx(a2, b2, c2, d2);
    while(0u == (SPIM_ReadTxStatus() & SPIM_STS_SPI_DONE)){}
    CR_Write(3);
    spi_tx(a2, b2, c2, d2);
    while(0u == (SPIM_ReadTxStatus() & SPIM_STS_SPI_DONE)){}
    CR_Write(4);
    spi_tx(a3, b3, c3, d3);
    while(0u == (SPIM_ReadTxStatus() & SPIM_STS_SPI_DONE)){}
    CR_Write(5);
    spi_tx(a3, b3, c3, d3);
    while(0u == (SPIM_ReadTxStatus() & SPIM_STS_SPI_DONE)){}
}

void uart_bounce_back(){    
    if (0u != USBUART_IsConfigurationChanged())
    {
        if (0u != USBUART_GetConfiguration())
        {
            USBUART_CDC_Init();
        }
    }

    /* Service USB CDC when device is configured. */
    if (0u != USBUART_GetConfiguration())
    {
        /* Check for input data from host. */
        if (0u != USBUART_DataIsReady())
        {
            count = USBUART_GetAll(buffer);

            if (0u != count)
            {
                while (0u == USBUART_CDCIsReady()){}
                USBUART_PutData(buffer, count);

                if (USBUART_BUFFER_SIZE == count)
                {
                    while (0u == USBUART_CDCIsReady()){}
                    USBUART_PutData(NULL, 0u);
                }
            }
        }
    }
}

void uart_init(){
    USBUART_Start(USBFS_DEVICE, USBUART_5V_OPERATION);
    
    while(!USBUART_GetConfiguration());
    USBUART_CDC_Init();
    
    while (0u == USBUART_CDCIsReady());
    
    CyDelay(100);
    USBUART_PutString("COM Port Open \n\r");
    CyDelay(100);
}

void adc_cal(){   
    unsigned int i = 0;
    int32 avg = 0;
    
    mux_toggle(1, 'A', 1);
    
    for(i = 0; i < (ADC_DelSig_CFG1_SRATE); i++){ 
        ADC_DelSig_StartConvert();
		while(!(ADC_DelSig_IsEndConversion(ADC_DelSig_WAIT_FOR_RESULT)));  
		ADC_DelSig_StopConvert();  
		avg += ADC_DelSig_GetResult32();                 
    }
    
    avg = avg / ADC_DelSig_CFG1_SRATE;
    ADC_DelSig_SetOffset(avg);
    ADC_DelSig_SetGain(ADC_DelSig_DFLT_COUNTS_PER_VOLT);
    
    mux_toggle(1, 'A', 0);
    CyDelay(1);
}

void AD5940_Main(void)
{
    unsigned long temp, i;
    char str[64];
    /**
    * Hardware reset can always put AD5940 to default state. 
    * We recommend to use hardware reset rather than software reset
    * because there are some situations that SPI won't work, for example, AD59840 is in hibernate mode, 
    * or AD5940 system clock is 32kHz that SPI bus clock should also be limited..
    * */
    //AD5940_HWReset();
    /**
    * @note MUST call this function whenever there is reset happened. This function will put AD5940 to right state.
    *       The reset can be software reset or hardware reset or power up reset.
    */
    AD5940_Initialize();
    /**
    * Normal application code starts here.
    */
    /**
    * Read register test.
    */
    temp = AD5940_ReadReg(REG_AFECON_ADIID);
    snprintf(str, 64, "Read ADIID register, got: 0x%04lx\n", temp);
    while (0u == USBUART_CDCIsReady());
    USBUART_PutString(str);
    
    if(temp != AD5940_ADIID){
        while (0u == USBUART_CDCIsReady());
        USBUART_PutString("Read register test failed.\n");
    }
    else{
        while (0u == USBUART_CDCIsReady());
        USBUART_PutString("Read register test pass\n");
    }

    /**
    * Write register test.
    * */
    srand(0x1234);
    i =10000;
    while(i--)
    {
        static unsigned long count;
        static unsigned long data;
        /* Generate a 32bit random data */
        data = rand()&0xffff;
        data <<= 16;
        data |= rand()&0xffff;
        count ++;	/* Read write count */
        /**
         * Register CALDATLOCK is 32-bit width, it's readable and writable.
         * We use it to test SPI register access.
        */
        AD5940_WriteReg(REG_AFE_CALDATLOCK, data);
        temp = AD5940_ReadReg(REG_AFE_CALDATLOCK);
        if(temp != data){
            snprintf(str, 64, "Write register test failed @0x%08lx \n", data);
            while (0u == USBUART_CDCIsReady());
            USBUART_PutString(str);
        }
        if(!(count%1000)){
            snprintf(str, 64, "Read/Write has been done %ld times, latest data is 0x%08lx \n", count, data);
            while (0u == USBUART_CDCIsReady());
            USBUART_PutString(str);
        }
    }
    while (0u == USBUART_CDCIsReady());
    USBUART_PutString("SPI read/write test completed");
    while(1);
}

int main(void)
{
    CyGlobalIntEnable;
   // IDAC8_Start();
    ADC_DelSig_Start();
    uart_init(); /* Will hang waiting for UART. (or not?) */
    
    //DmaTxConfiguration();
    //DmaRxConfiguration();
    
    SPIM_Start();
    
    //CyDmaChEnable(rxChannel, STORE_TD_CFG_ONCMPLT);
    //CyDmaChEnable(txChannel, STORE_TD_CFG_ONCMPLT);
    
    CyDelay(10000);

    int result = 0;
    char str[32];
    
    AD5940_Main();
    
    //for(int i = 0; i < 3; i++){
        /*
        if (i == 0){
            IDAC8_SetRange(IDAC8_RANGE_32uA);
            IDAC8_SetValue(8);
        }
        if (i == 1){
            IDAC8_SetRange(IDAC8_RANGE_32uA);
            IDAC8_SetValue(80);
        }
        if (i == 2){
            IDAC8_SetRange(IDAC8_RANGE_255uA);
            IDAC8_SetValue(100);
        }
        */
        
        CyDelay(1);
        adc_cal();
        
        for (int j = 0; j < 1;  j++){
            
            mux_toggle((j+8), 'A', 1);
            CyDelay(1);
            
            /*if (j==2)
                IDAC8_Stop();
            
            CyDelay(100);*/
        
            for (int k = 0; k < 5000; k++){
                ADC_DelSig_StartConvert();
        		while(!(ADC_DelSig_IsEndConversion(ADC_DelSig_WAIT_FOR_RESULT)));  
        		ADC_DelSig_StopConvert();  
        		result = ADC_DelSig_GetResult32();
                result = ADC_DelSig_CountsTo_uVolts(result);
                result = result / (int)ADC_DelSig_CFG1_BUFFER_GAIN;
                snprintf(str, 10, "$%d;", result);
                while (0u == USBUART_CDCIsReady()){}
                USBUART_PutString(str);
            }
            
            mux_toggle((j+5), 'A', 0);
            /*
            if (j==2)
                IDAC8_Start();
            CyDelay(100);
            */
        
        }
        /*
        mux_toggle(5, 'A', 1);
        CyDelay(1);
    
        for (int k = 0; k < 5000; k++){
            ADC_DelSig_StartConvert();
    		while(!(ADC_DelSig_IsEndConversion(ADC_DelSig_WAIT_FOR_RESULT)));  
    		ADC_DelSig_StopConvert();  
    		result = ADC_DelSig_GetResult32();
            result = ADC_DelSig_CountsTo_uVolts(result);
            result = result / (int)ADC_DelSig_CFG1_BUFFER_GAIN;
            snprintf(str, 10, "$%d;", result);
            while (0u == USBUART_CDCIsReady());
            USBUART_PutString(str);
        }
        
        mux_toggle(5, 'A', 0);
        CyDelay(1);*/
    //}
}

/*******************************************************************************
* Function Name: DmaTxConfiguration
********************************************************************************
* Summary:
*  Configures the DMA transfer for TX direction
*   
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void DmaTxConfiguration()
{
    /* Init DMA, 1 byte bursts, each burst requires a request */ 
    txChannel = DMA_TX_DmaInitialize(DMA_TX_BYTES_PER_BURST, DMA_TX_REQUEST_PER_BURST, 
                                        HI16(DMA_TX_SRC_BASE), HI16(DMA_TX_DST_BASE));

    txTD = CyDmaTdAllocate();

    /* Configure this Td as follows:
    *  - Increment the source address, but not the destination address   
    */
    CyDmaTdSetConfiguration(txTD, BUFFER_SIZE, CY_DMA_DISABLE_TD, TD_INC_SRC_ADR);

    /* From the memory to the SPIM */
    CyDmaTdSetAddress(txTD, LO16((uint32)txBuffer), LO16((uint32) SPIM_TXDATA_PTR));
    
    /* Associate the TD with the channel */
    CyDmaChSetInitialTd(txChannel, txTD); 
}

/*******************************************************************************
* Function Name: DmaRxConfiguration
********************************************************************************
* Summary:
*  Configures the DMA transfer for RX direction
*   
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void DmaRxConfiguration()
{ 
    /* Init DMA, 1 byte bursts, each burst requires a request */ 
    rxChannel = DMA_RX_DmaInitialize(DMA_RX_BYTES_PER_BURST, DMA_RX_REQUEST_PER_BURST,
                                     HI16(DMA_RX_SRC_BASE), HI16(DMA_RX_DST_BASE));

    rxTD = CyDmaTdAllocate();
    
    /* Configure this Td as follows:
    *  - Increment the destination address, but not the source address
    */
    CyDmaTdSetConfiguration(rxTD, BUFFER_SIZE, CY_DMA_DISABLE_TD, TD_INC_DST_ADR);

    /* From the SPIM to the memory */
    CyDmaTdSetAddress(rxTD, LO16((uint32)SPIM_RXDATA_PTR), LO16((uint32)rxBuffer));

    /* Associate the TD with the channel */
    CyDmaChSetInitialTd(rxChannel, rxTD);
}