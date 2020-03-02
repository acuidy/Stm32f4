#include "main.h"
#include "stm32f4xx.h"
#include "porting_delay.h"
#include "bsp.h"
#include "usbd_cdc_if.h"
#include "usb_device.h"
#include "porting_tube.h"

int main(void)
{
    RCC_ClocksTypeDef RCC_Clocks;
  
    /* SysTick end of count event each 1ms */
    RCC_GetClocksFreq(&RCC_Clocks);
    SysTick_Config(RCC_Clocks.HCLK_Frequency / 1000);

#if 0
    /*USB Init*/
    USB_DEVICE_Init();
    /* Insert 5 ms delay */
    Delay_Ms(5);
    /* Infinite loop */
    while (1)
    {
        CDC_Transmit_FS("VCP_TEST\r\n",sizeof("VCP_TEST\r\n"));
        Delay_Ms(500);
    }
#endif
    ledLight_Reset();
    while(1){
        Delay_Ms(500);
        ledLight(10);
        Delay_Ms(500);
        ledLight(27);
    }
    
}

