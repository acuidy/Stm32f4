#ifndef _BSP_H__
#define _BSP_H__


void LED_Init(void);

/*74hc Init********************************************************************/
#define SER_PORT                GPIOC
#define SER_PIN                 GPIO_Pin_15
#define SER_RCC                 RCC_AHB1Periph_GPIOC

#define SRCLK_PORT              GPIOC
#define SRCLK_PIN               GPIO_Pin_13
#define SRCLK_RCC               RCC_AHB1Periph_GPIOC

#define RCLK_PORT               GPIOC
#define RCLK_PIN                GPIO_Pin_14
#define RCLK_RCC                RCC_AHB1Periph_GPIOC

void Sn74hc_Rclk_Init(void);
void Sn74hc_Srclk_Init(void);
void Sn74hc_Ser_Init(void);

#endif
