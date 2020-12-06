// this is to answer Q2 and Q3 for assignment05
// this is based on code provided from class
// most of the code remain unchanged compared to class provided version
// only portions were added to test divAsm.s
// as well as write swapCharsAsm

/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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
#include "print.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
PRINT_DEFINEBUFFER();           /* required for lightweight sprintf */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);


uint32_t sqrAsm(int val); // declare sqrAsm
uint32_t divAsm(int val); // declare divAsm
const char* myCstr = "\nHello from assembly! ";

int fah_to_cel_asm(int temperature); // declare fah_to_cel_asm function
void swapCharsAsm(char* c1, char* c2); // declare swapCharsAsm function

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

// Change [My name] to your name      //
uint8_t myTxData[] = "EMBSYS310: UW Test Application - Zhe Li's STM32L475 IoT node is alive!!!\r\n";
uint8_t endOfProgram[] = "\n******** THE END ******** \r\n";

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
    MX_USART1_UART_Init();
    /* USER CODE BEGIN 2 */

    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);

    uint8_t counter = 1;
    // uint8_t sqrResult; // to store sqrAsm result
    // uint8_t divResult; // to store divAsm result

    HAL_UART_Transmit(&huart1, myTxData, sizeof(myTxData), 10);

    while (counter)
    {
        /* USER CODE END WHILE */

        /* USER CODE BEGIN 3 */

//        PrintString("\nx = ");
//        Print_uint32(counter);
//        
//        /*this block of code is from class to demonstrate divAsm*/
//        // this is based on sqrAsm test code
//        divResult = divAsm(counter);
//        PrintString(" x/2 = ");
//        Print_uint32(divResult);
//        PrintString("\n");
//        counter--;

        /*this block of code is from class to demonstrate sqrAsm*/
//        sqrResult = sqrAsm(counter);
//        PrintString(" x^2 = ");
//        Print_uint32(sqrResult);
//        PrintString("\n");

        /*this block of code is from class to demonstrate swapCharsAsm*/
        // declare two char variables
        char y = 'y';
        char x = 'x';
        PrintString("\nBefore calling the the function, two chars are: ");
        PrintString(&x);
        PrintString(" ");
        PrintString(&y);
        PrintString("\n");
        
        swapCharsAsm(&x, &y);
        
        PrintString("\nAfter calling the the function, two chars are: ");
        PrintString(&x);
        PrintString(" ");
        PrintString(&y);
        PrintString("\n");
            
        
        
        counter--;

        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_14);

        HAL_Delay(1000);
    }
    
    
    
    /*this block of code is from class to demonstrate fah_to_cel_asm*/
    // Testing fah_to_cel_asm
//    int tempC;
//    PrintString("\n********** Fahrenheit to Celsius **********\n");
//    
//    for(uint32_t tempF=0; tempF <= 100; tempF++)
//    {
//        tempC = fah_to_cel_asm(tempF);
//        RETAILMSG(1, ("\t%d Fahrenheit = %d Celsius\r\n", tempF, tempC));
//    }
    
    HAL_UART_Transmit(&huart1, endOfProgram, sizeof(endOfProgram), 10);

    /* USER CODE END 3 */
}

void swapCharsAsm(char* c1, char* c2)
{
    // actually using assembly code
    
/*
the assembly codes looks like this below
    LDRB R2, [R0, #0]       // Load the address pointed to by R0 into R2
    LDRB R3, [R1, #0]       // Load the address pointed to by R1 into R3
    STRB R2, [R1, #0]       // Store the content of R2 on the stack at [R1]
    STRB R3, [R0, #0]       // Store the content of R3 on the stack at [R0]
    MOV R0, #1              // Move constant value of one into R0 since they are equal
    BX LR                   // Branch exchange instructions to LR (leave the function)
*/    
    asm(
    "LDRB R2, [R0, #0]\n"
    "LDRB R3, [R1, #0]\n"
    "STRB R2, [R1, #0]\n"
    "STRB R3, [R0, #0]\n"
    "MOV R0, #1\n"
    "BX LR\n");
}

#if 0
int fah_to_cel_asm(int temperature)
{
    // Formula:
    // Subtract 32, then multiply by 5, then divide by 9
    // EX: (50F - 32) x 5/9 = 10C
    
    asm("SUB R0, R0, #32\n"
        "MOV R1, #5\n"
        "MUL R0, R0, R1\n"
        "MOV R2, #9\n"
        "SDIV R0, R0, R2\n"
        );
    
    return temperature;
}
#endif

#if 0
int fah_to_cel_asm(int temp)
{
    // Deduct 32, then multiply by 5, then divide by 9
    asm("SUB R0, R0, #32");
    asm("MOV R1, #5");
    asm("MUL R0, R0, R1");
    asm("MOV R2, #9");
    asm("SDIV R0, R0, R2");

    return temp;
}
#endif

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the main internal regulator output voltage 
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
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
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
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
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);

  /*Configure GPIO pin : PA5 */
  GPIO_InitStruct.Pin = GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB14 */
  GPIO_InitStruct.Pin = GPIO_PIN_14;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
