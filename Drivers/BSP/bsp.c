/**
 ******************************************************************************
 * @file         bsp.c
 * @data        2019/12/13
 * @author      xt.cui
 * @version     v0.1
 * @brief       ST Hardware  Driver Init
 ******************************************************************************
**/
#include "stm32f4xx.h"
#include "bsp.h"
#include "usb_device.h"


/*74hc Init********************************************************************/
void Sn74hc_Rclk_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    RCC_AHB1PeriphClockCmd(RCLK_RCC,ENABLE);
    
    GPIO_InitStruct.GPIO_Mode   = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_OType  = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_Pin    = RCLK_PIN;
    GPIO_InitStruct.GPIO_PuPd   = GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_Speed  = GPIO_Fast_Speed;
    
    GPIO_Init(RCLK_PORT, &GPIO_InitStruct);
}
void Sn74hc_Srclk_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    RCC_AHB1PeriphClockCmd(SRCLK_RCC,ENABLE);
    
    GPIO_InitStruct.GPIO_Mode   = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_OType  = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_Pin    = SRCLK_PIN;
    GPIO_InitStruct.GPIO_PuPd   = GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_Speed  = GPIO_Fast_Speed;
    
    GPIO_Init(SRCLK_PORT, &GPIO_InitStruct);
}
void Sn74hc_Ser_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    RCC_AHB1PeriphClockCmd(SER_RCC,ENABLE);
    
    GPIO_InitStruct.GPIO_Mode   = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_OType  = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_Pin    = SER_PIN;
    GPIO_InitStruct.GPIO_PuPd   = GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_Speed  = GPIO_Fast_Speed;
    
    GPIO_Init(SER_PORT, &GPIO_InitStruct);
}