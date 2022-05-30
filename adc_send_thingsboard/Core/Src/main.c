/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "string.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_USART1_UART_Init();
  HAL_ADC_Start(&hadc1);

  /* USER CODE BEGIN 2 */

 char ATcommand [80];
  uint16_t readValue;
  char charData[200];


  //char* pub = "{\"id\":15,\"info\":\"1110102\"}";
  char str[300];
  char* pub ="{\"clientid1\":\"charData\"}";
  char* ptopic = "v1/devices/me/attributes";
 // char* topic = "v1/devices/me/attributes/request/1";
 // char* stopic = "v1/devices/me/attributes/response/+";
////
 uint8_t buffer[50] = {0};

  uint8_t q = strlen(ptopic);
 // uint8_t n = strlen(topic);
 // uint8_t  p = strlen(stopic);
  uint8_t  r = 0;
  uint8_t  m = 0;
  r = strlen(pub);
  //m = strlen(str);







//  sprintf(ATcommand, "AT+CMQTTSUBTOPIC=0,%d,0\r\n", p);
//  HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
//  HAL_Delay(1000);
//  sprintf(ATcommand, stopic);
//  HAL_Delay(1000);
//
//  sprintf(ATcommand, "AT+CMQTTSUB=0\r\n ");
//  HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
//  HAL_Delay(1000);
//  /* USER CODE END 2 */
//
//  /* Infinite loop */
//  /* USER CODE BEGIN WHILE */
  while (1)
  {
//    /* USER CODE END WHILE */
//

	  HAL_ADC_Start(&hadc1);
	  HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	  readValue = HAL_ADC_GetValue(&hadc1);
	  sprintf(charData,"%d\n",readValue);
	  //HAL_UART_Transmit(&huart1,(uint8_t *)charData,strlen(charData),HAL_MAX_DELAY);


	  //HAL_UART_Receive (&huart1, buffer, 30, 100);
	  HAL_ADC_Stop(&hadc1);


	  strcpy(str, "{\"clientKeys1\":");
	  strcat(str, (char*) charData);
	  strcat(str, ",");
	  strcat(str,"\"clientKeys2\":");
	  strcat(str, (char*) charData);
	  strcat(str,"}");



	  HAL_UART_Transmit(&huart1, (uint16_t *) str, strlen(str), HAL_MAX_DELAY);
	  HAL_UART_Receive (&huart1, buffer, strlen(str), 100);
//	  HAL_Delay (100);
	  sprintf(ATcommand, "Modem Started...");
	    HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 100);
	    HAL_UART_Receive(&huart1, buffer, 30, 100);
	    HAL_Delay(10);
	    sprintf(ATcommand, "AT\r\n");
	    //AT Commands for Status Control
	    //HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand,strlen(ATcommand),1000);
	    HAL_UART_Receive(&huart1, buffer, 30, 100);
	    HAL_Delay(10);
	    memset(buffer, 0, sizeof(buffer));

	    sprintf(ATcommand, "AT+CSQ\r\n");
	    HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
	    HAL_Delay(10);

	    sprintf(ATcommand, "AT+CPIN?\r\n");
	    HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
	    HAL_Delay(10);

	    sprintf(ATcommand, "AT+COPS?\r\n");
	    HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
	    HAL_Delay(10);

	    sprintf(ATcommand, "AT+CREG=1\r\n");
	    HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
	    HAL_Delay(10);

	    sprintf(ATcommand, "AT+CREG?\r\n");
	    HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
	    HAL_Delay(10);

	    sprintf(ATcommand, "AT+CGMI\r\n");
	    HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
	    HAL_Delay(10);

	    sprintf(ATcommand, "AT+CNMP=2\r\n");
	    HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
	    HAL_Delay(1000);
	    sprintf(ATcommand, "AT+CMQTTSTART\r\n");
	     HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
	     HAL_Delay(2000);

	     sprintf(ATcommand, "AT+CMQTTACCQ=0,\"test\"\r\n");
	     HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
	     HAL_Delay(1000);

	     sprintf(ATcommand, "AT+CMQTTCONNECT=0,\"tcp://thinkiot.com.bd\",60,1,\"test101\",\"test101\"\r\n ");
	     HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
	     HAL_Delay(1000);

	  sprintf(ATcommand, "AT+CMQTTTOPIC=0,%d\r\n", q); //publish topic
		  HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
		  HAL_UART_Receive(&huart1, buffer, 100, 100);
		  HAL_Delay(1000);

		  sprintf(ATcommand, ptopic); //SET topic
		  HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
		  HAL_UART_Receive(&huart1, buffer, 30, 100);
		  HAL_Delay(5000);

		  sprintf(ATcommand, "AT+CMQTTPAYLOAD=0,%d\r\n", strlen(str)); //Set publishing message
		  HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
		  HAL_UART_Receive(&huart1, buffer, 30, 100);
		  HAL_Delay(1000);



		  sprintf(ATcommand, str); //Set publishing message
		 		  HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
		 		  HAL_UART_Receive(&huart1, buffer, 30, 100);
		 		  HAL_Delay(1000);


		  sprintf(ATcommand, "AT+CMQTTPUB=0,0,60\r\n"); //Send a PUBLISH message to server
		  HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
		  HAL_UART_Receive(&huart1, buffer, 30, 100);
		  HAL_Delay(5000);
		  sprintf(ATcommand, "AT+CMQTTDISC=0,120\r\n");
		   HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
		   HAL_Delay(1000);

		   sprintf(ATcommand, "AT+CMQTTREL\r\n");
		   HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
		   HAL_Delay(1000);


		   sprintf(ATcommand, "AT+CMQTTSTOP\r\n");
		   HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
		   HAL_Delay(5000);
//		  sprintf(ATcommand, "AT+CMQTTTOPIC=0,%d\r\n", n); //publish topic
//		  HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
//		  HAL_UART_Receive(&huart1, buffer, 30, 100);
//		  HAL_Delay(1000);
//
//		  sprintf(ATcommand, topic); //SET topic
//		  HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
//		  HAL_UART_Receive(&huart1, buffer, 30, 100);
//		  HAL_Delay(1000);
//
//		  sprintf(ATcommand, "AT+CMQTTPAYLOAD=0,%d\r\n", m); //Set publishing message
//		  HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
//		  HAL_UART_Receive(&huart1, buffer, 30, 100);
//		  HAL_Delay(1000);

//
//		  sprintf(ATcommand, "AT+CMQTTPUB=0,0,60\r\n"); //Send a PUBLISH message to server
//		  HAL_UART_Transmit(&huart1, (uint8_t *)ATcommand, strlen(ATcommand), 1000);
//		  HAL_UART_Receive(&huart1, buffer, 30, 100);
//		  HAL_Delay(1000);

}
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = ENABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_9;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
