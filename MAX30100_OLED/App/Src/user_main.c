/**
  ******************************************************************************
  * @file    user_main.c
  * @author  张东
  * @version V1.0.0
  * @date    2019-12-27
  * @brief   应用程序逻辑入口
  ******************************************************************************
  */
/*--Include-start-------------------------------------------------------------*/
#include "user_main.h"
#include "stm32f1xx_hal.h"
#include "spi.h"
#include "dma.h"
#include "stm32f1xx_hal_dma.h"
#include "gui.h"
#include "stdio.h"
#include "blood.h"
#include "MAX30100.h"
#include "OLED_IIC.h"
#include "tim.h"
/*Include end ----------------------------------------------------------------*/

/*Global Data Space ----------------------------------------------------------*/

//程序初始化
void User_Setup(void)
{
	//chip init
	//__HAL_SPI_ENABLE(&hspi2);
	//__HAL_DMA_ENABLE_IT(&hdma_spi2_tx,DMA_IT_TC);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);

	

	max30100_init();

	OLED_Init();

	//app init 
	blood_Setup();
}

//程序循环
void User_Loop(void)
{
	blood_Loop();
}

//程序中断
void User_Interrupt(void)
{
	blood_Interrupt();
}







