#include "stm32f4xx.h"
#include "porting_delay.h"

/*delay************************************************************************/
static volatile uint32_t uwTimingDelay;
void TimingDelay_Decrement(void)
{
    if (uwTimingDelay != 0x00)
    { 
        uwTimingDelay--;
    }
}
void Delay_Ms(volatile uint32_t nTime)
{ 
    uwTimingDelay = nTime;
    
    while(uwTimingDelay != 0);
}

