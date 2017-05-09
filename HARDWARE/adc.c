#include "adc.h"
#include "delay.h"

const u16 temperature_table[100]={5145,5095,5043,4989,4933,4877,4819,4759,4699,4637,4574,4509,4444,4378,4310,4242,4173,4104,4034,3963,3891,3820,3748,3676,3603,3531,3458,3386,3314,3242,3171,3100,3029,2959,2890,2821,2753,2686,2619,2554,2489,2426,2363,2302,2241,2182,2123,2066,2010,1955,1902,1849,1798,1748,1698,1651,1604,1558,1514,1471,1429,1388,1348,1309,1217,1234,1198,1164,1130,1097,1065,1034,1004,975,947,919,893,867,842,817,794,771,749,771,749,727,706,686,667,648,629,611,594,577,561,545,530,515,501,487,474,461,448,436,424,412,401,390,380,370,360,350,341};

void Adc_Init(void)
{
	ADC_InitTypeDef ADC_InitStructure; 
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_ADC1	, ENABLE );	  //使能ADC1通道时钟
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;				 //set PWM output at PA1
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; 		 //模拟输入
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
        GPIO_Init(GPIOA, &GPIO_InitStructure);					 //set PWM output at PA1

	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	
	ADC_DeInit(ADC1);  //复位ADC1 
	
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	//ADC工作模式:ADC1和ADC2工作在独立模式
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;	//模数转换工作在单通道模式
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;	//模数转换工作在单次转换模式
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//转换由软件而不是外部触发启动
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	//ADC数据右对齐
	ADC_InitStructure.ADC_NbrOfChannel = 1;	//顺序进行规则转换的ADC通道的数目
	
	ADC_Init(ADC1, &ADC_InitStructure);	//根据ADC_InitStruct中指定的参数初始化外设ADCx的寄存器
	
	ADC_Cmd(ADC1, ENABLE);	//使能指定的ADC1
	
	ADC_ResetCalibration(ADC1);	//使能复位校准  
	 
	while(ADC_GetResetCalibrationStatus(ADC1));	//等待复位校准结束
	
	ADC_StartCalibration(ADC1);	 //开启AD校准
 
	while(ADC_GetCalibrationStatus(ADC1));	 //等待校准结束
	
	
}


u16  Get_Adc(u8 ch)
{
	//设置指定ADC的规则组通道，一个序列，采样时间
	ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5 );	//ADC1,ADC通道,采样时间为239.5周期	  			    
  
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//使能指定的ADC1的软件转换启动功能	
	 
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));//等待转换结束

	return ADC_GetConversionValue(ADC1);	//返回最近一次ADC1规则组的转换结果
	
	
}


u16 Get_Adc_Average(u8 ch,u8 times)
{
	u32 temp_val=0;
	u8 t;
	for(t=0;t<times;t++)
	{
		temp_val+=Get_Adc(ch);
		delay_ms(5);
	}
	return temp_val/times;
	
}

void Get_RTC_Temperature(void)
{
	
	
	
	
	
	
}

