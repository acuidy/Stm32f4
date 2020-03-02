/**
 ******************************************************************************
 * @file         porting_tube.c
 * @data        2019/12/13
 * @author      xt.cui
 * @version     v0.1
 * @brief       Tube Porting
 ******************************************************************************
**/

#include "stm32f4xx.h"
#include "bsp.h"
#include "porting_tube.h"
#include "porting_delay.h"

static BitAction eArrSftRegQa_Qh[3][8];
static void shiftRegQa_Qh_Out(BitAction peRegStat[3][8])
{
    uint8_t i,j;
    
    GPIO_ResetBits(RCLK_PORT, RCLK_PIN);//RCL=0
    GPIO_ResetBits(SER_PORT, SER_PIN);//SER=0
    GPIO_ResetBits(SRCLK_PORT, SRCLK_PIN);//SRCL=0
    
    for(j = 0; j < 3; j++){
        for(i = 0; i < 8; i++){
            /*output SER register --> Qa_Qh*/
            GPIO_ResetBits(SRCLK_PORT, SRCLK_PIN);//SRCL=0
            /*write SER register*/
            GPIO_WriteBit(SER_PORT,SER_PIN,peRegStat[j][i]);
            GPIO_WriteBit(SRCLK_PORT,SRCLK_PIN,Bit_SET);//SRCL=1
        }
    }
    GPIO_WriteBit(RCLK_PORT,RCLK_PIN,Bit_RESET);//RCL=0
    GPIO_WriteBit(RCLK_PORT,RCLK_PIN,Bit_SET);//RCL=1
}
static void shiftRegQa_Qh_Init_Set(void)
{
    uint8_t i,j;
	
    for(j = 0; j < 3; j++){
        for(i = 0; i < 8; i++){
            eArrSftRegQa_Qh[j][i] = Bit_SET;
        }
    }
}

static void shiftReg_PinSet(BitAction eStat, uint8_t ui8Pin, uint8_t ui8No)
{
    if(ui8Pin > 7 || ui8No > 2)
        return;
	
    if(eStat == Bit_SET){
        eArrSftRegQa_Qh[ui8No][ui8Pin] = Bit_SET;
    }else{
        eArrSftRegQa_Qh[ui8No][ui8Pin] = Bit_RESET;
    }
}

static void ledLight_Set(uint8_t ui8Num, uint8_t ui8No)
{	
    if(ui8Num > 9)
            return;
    
    switch(ui8Num){
    case 0:
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QA_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QB_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QC_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QD_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QE_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QF_PIN, ui8No);
        break;
    case 1:
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QE_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QF_PIN, ui8No);
        break;
    case 2:
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QA_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QB_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QG_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QE_PIN, ui8No);	
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QD_PIN, ui8No);
        break;	
    case 3:
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QA_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QB_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QG_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QC_PIN, ui8No);	
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QD_PIN, ui8No);			
        break;
    case 4:
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QF_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QG_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QB_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QC_PIN, ui8No);	
        break;
    case 5:
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QA_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QF_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QG_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QC_PIN, ui8No);	
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QD_PIN, ui8No);
        break;
    case 6:
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QA_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QF_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QG_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QC_PIN, ui8No);	
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QD_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QE_PIN, ui8No);
        break;
    case 7:
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QA_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QB_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QC_PIN, ui8No);
        break;	
    case 8:
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QA_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QB_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QC_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QD_PIN, ui8No);	
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QE_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QF_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QG_PIN, ui8No);			
        break;
    case 9:
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QG_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QF_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QA_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QB_PIN, ui8No);
        shiftReg_PinSet(Bit_RESET, GPIO_LED_QC_PIN, ui8No);	
        break;
    default:
        break;
    }
}

int ledLight(uint16_t ui16LightNum)
{
	uint8_t ui8ge,ui8shi,ui8bai;
	
	if(ui16LightNum > 999)
		return 1;
	
	ui8bai = ui16LightNum/100;
	ui8shi = (ui16LightNum%100)/10;
	ui8ge = (ui16LightNum%100)%10;
	
	ledLight_Set(ui8ge, LED_NO_1);
	ledLight_Set(ui8shi, LED_NO_2);
	ledLight_Set(ui8bai, LED_NO_3);

	shiftRegQa_Qh_Out(eArrSftRegQa_Qh);	
        shiftRegQa_Qh_Init_Set();
        
        return 0;
}
void ledLight_Reset(void)
{
    /*74hc Init*/
    Sn74hc_Srclk_Init();
    Sn74hc_Rclk_Init();
    Sn74hc_Ser_Init();
    GPIO_SetBits(RCLK_PORT, RCLK_PIN);//RCL=0 !!!
    
    shiftRegQa_Qh_Init_Set();
    shiftRegQa_Qh_Out(eArrSftRegQa_Qh);
}