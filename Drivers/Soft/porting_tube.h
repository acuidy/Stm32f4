#ifndef PORTING_TUBE_H__
#define PORTING_TUBE_H__

/*595 OUT PIN-----------------------------------------------------------------*/
/*
    595      pin         arr
    Qh <-->  none   <--> [0]
    Qg <-->  none   <--> [1]
    Qf <-->  none   <--> [2]
    Qe <-->  LED_B  <--> [3]
    Qd <-->  LED_R  <--> [4]
    Qc <-->  LED_G  <--> [5]
    Qb <-->  LED_17 <--> [6]
    Qa <-->  PSHOLD <--> [7]
*/
#define GPIO_LED_QA_PIN      0X07
#define GPIO_LED_QB_PIN      0X06
#define GPIO_LED_QC_PIN      0X05
#define GPIO_LED_QD_PIN      0X04
#define GPIO_LED_QE_PIN      0X03
#define GPIO_LED_QF_PIN      0X02
#define GPIO_LED_QG_PIN      0X01
#define GPIO_LED_QH_PIN      0X00

#define LED_NO_3      		0X02
#define LED_NO_2      		0X01
#define LED_NO_1      		0X00

void ledLight_Reset(void);
int ledLight(uint16_t ui16LightNum);

#endif
