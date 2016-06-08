/**
 * @file hw_conf.h
 * 
 */

#ifndef HW_CONF_H
#define HW_CONF_H


/*********************
 *   PERPHRIA CONFIG
 *********************/

/*---------------
 *  PSP select
 *--------------*/
#define PSP_PIC24F_33F     0
#define PSP_PIC32MX        0
#define PSP_PIC32MZ        0
#define PSP_PC	       	   1

/*-----------
 *   Clock
 *----------*/
/*Unused on PC*/
#define CLOCK_CORE       100000000UL /*Hz*/
#define CLOCK_PERIPH     100000000UL /*Hz*/

/*-----------
 *   GPIO 
 *----------*/
#define USE_IO        0
#if USE_IO != 0
/*No settings*/
#endif /*USE_IO*/


/*-----------
 *   Timer 
 *----------*/
#define USE_TMR     1
#if USE_TMR != 0

/*TMR1*/
#define TMR1_EN     0
#if TMR1_EN     !=  0
#define TMR1_PRIO   HW_INT_PRIO_MID
#endif  /*DRV_TMR1_EN*/

/*TMR2 - Tick*/
#define TMR2_EN     1
#if TMR2_EN     !=  0
#define TMR2_PRIO   HW_INT_PRIO_HIGH
#endif  /*TMR2_EN*/

/*TMR3*/
#define TMR3_EN     0
#if TMR3_EN     !=  0
#define TMR3_PRIO   HW_INT_PRIO_MID
#endif  /*TMR3_EN*/

/*TMR4*/
#define TMR4_EN     0
#if TMR4_EN     !=  0
#define TMR4_PRIO   HW_INT_PRIO_MID
#endif  /*TMR4_EN*/

/*TMR5*/
#define TMR5_EN     0
#if TMR5_EN     !=  0
#define TMR5_PRIO   HW_INT_PRIO_MID
#endif  /*TMR5_EN*/

/*TMR6*/
#define TMR6_EN     0
#if TMR6_EN     !=  0
#define TMR6_PRIO   HW_INT_PRIO_MID
#endif  /*TMR6_EN*/
#endif  /*USE_TMR*/

/*----------------
 *     Tick
 *----------------*/
#define USE_TICK        1
#if USE_TICK != 0
#define TICK_FUNC_NUM   16
#define TICK_US_BASE    5  /*Adjust the 'tick_wait_us' functions */
#define TICK_TIMER		HW_TMR2
#endif /*USE_SYS*/

/*-----------------
 *      PWM
 *----------------*/
#define USE_PWM     0
#if USE_PWM != 0
#define PWM_DEF_PERIOD      100    /*us*/
#define PWM_DEF_DUTY_CYCLE  30     /*us*/
#define PWM1_EN     0
#define PWM2_EN     0
#define PWM3_EN     0
#define PWM4_EN     0
#define PWM5_EN     0
#define PWM6_EN     0
#define PWM7_EN     0
#define PWM8_EN     0
#endif

/*-----------------
 * SERIAL (UART)
 *----------------*/
#define USE_SRIAL        0
#if USE_SERIAL != 0

/*SERIAL1*/
#define SER1_PRIO       HW_INT_PRIO_OFF /*HW_INT_PRIO_OFF to disable module*/
#define SER1_BUF_SIZE   0				 /*0: disable module*/
#define SER1_MODE       (SER_MODE_BASIC)

/*SERAL2*/
#define SER2_PRIO       HW_INT_PRIO_OFF /*HW_INT_PRIO_OFF to disable module*/
#define SER2_BUF_SIZE   0
#define SER2_MODE       (SERIAL_MODE_BASIC)

/*SERIAL3*/
#define SER3_PRIO       HW_INT_PRIO_OFF /*HW_INT_PRIO_OFF to disable module*/
#define SER3_BUF_SIZE   0
#define SER3_MODE       (SERIAL_MODE_BASIC)

/*SERIAL4*/
#define SER4_PRIO       HW_INT_PRIO_OFF /*HW_INT_PRIO_OFF to disable*/
#define SER4_BUF_SIZE   0
#define SER4_MODE       (SERIAL_MODE_BASIC)
#endif /*USE_SERIAL*/


/*-----------
 *   SPI 
 *----------*/
#define USE_SPI         0
#if USE_SPI != 0

/*SPI1*/
#define SPI1_EN        0
#define SPI1_CS1_PORT  IO_PORTX
#define SPI1_CS1_PIN   IO_PINX
#define SPI1_CS2_PORT  IO_PORTX
#define SPI1_CS2_PIN   IO_PINX
#define SPI1_CS3_PORT  IO_PORTX
#define SPI1_CS3_PIN   IO_PINX
#define SPI1_CS4_PORT  IO_PORTX
#define SPI1_CS4_PIN   IO_PINX

/*SPI2*/
#define SPI2_EN        0
#define SPI2_CS1_PORT  IO_PORTX
#define SPI2_CS1_PIN   IO_PINX
#define SPI2_CS2_PORT  IO_PORTX
#define SPI2_CS2_PIN   IO_PINX
#define SPI2_CS3_PORT  IO_PORTX
#define SPI2_CS3_PIN   IO_PINX
#define SPI2_CS4_PORT  IO_PORTX
#define SPI2_CS4_PIN   IO_PINX

/*SPI3*/
#define SPI3_EN        0
#define SPI3_CS1_PORT  IO_PORTX
#define SPI3_CS1_PIN   IO_PINX
#define SPI3_CS2_PORT  IO_PORTX
#define SPI3_CS2_PIN   IO_PINX
#define SPI3_CS3_PORT  IO_PORTX
#define SPI3_CS3_PIN   IO_PINX
#define SPI3_CS4_PORT  IO_PORTX
#define SPI3_CS4_PIN   IO_PINX

/*SPI4*/
#define SPI4_EN        0
#define SPI4_CS1_PORT  IO_PORTX
#define SPI4_CS1_PIN   IO_PINX
#define SPI4_CS2_PORT  IO_PORTX
#define SPI4_CS2_PIN   IO_PINX
#define SPI4_CS3_PORT  IO_PORTX
#define SPI4_CS3_PIN   IO_PINX
#define SPI4_CS4_PORT  IO_PORTX
#define SPI4_CS4_PIN   IO_PINX

/*SPI5*/
#define SPI5_EN        0
#define SPI5_CS1_PORT  IO_PORTX
#define SPI5_CS1_PIN   IO_PINX
#define SPI5_CS2_PORT  IO_PORTX
#define SPI5_CS2_PIN   IO_PINX
#define SPI5_CS3_PORT  IO_PORTX
#define SPI5_CS3_PIN   IO_PINX
#define SPI5_CS4_PORT  IO_PORTX
#define SPI5_CS4_PIN   IO_PINX

/*SPI_SW*/
#define SPISW_SCK_PORT  IO_PORTX
#define SPISW_SCK_PIN   IO_PINX
#define SPISW_SDO_PORT  IO_PORTX
#define SPISW_SDO_PIN   IO_PINX
#define SPISW_SDI_PORT  IO_PORTX
#define SPISW_SDI_PIN   IO_PINX
#define SPISW_CS1_PORT  IO_PORTX
#define SPISW_CS1_PIN   IO_PINX
#define SPISW_CS2_PORT  IO_PORTX
#define SPISW_CS2_PIN   IO_PINX
#define SPISW_CS3_PORT  IO_PORTX
#define SPISW_CS3_PIN   IO_PINX
#define SPISW_CS4_PORT  IO_PORTX
#define SPISW_CS4_PIN   IO_PINX

#endif  /*USE_SPI*/

/*---------------
 *   Multi SPI 
 *--------------*/
#define USE_SPIM    0
#if USE_SPIM    !=  0
#define SPIM_IN_NUM 4   /* Max 4 */
#define SPIM_CS_PORT    IO_PORTX
#define SPIM_CS_PIN     IO_PINX
#define SPIM_SCK_PORT   IO_PORTX
#define SPIM_SCK_PIN    IO_PINX
#define SPIM_SDO_PORT   IO_PORTX
#define SPIM_SDO_PIN    IO_PINX
#define SPIM_SDI1_PORT  IO_PORTX
#define SPIM_SDI1_PIN   IO_PINX
#define SPIM_SDI2_PORT  IO_PORTX
#define SPIM_SDI2_PIN   IO_PINX
#define SPIM_SDI3_PORT  IO_PORTX
#define SPIM_SDI3_PIN   IO_PINX
#define SPIM_SDI4_PORT  IO_PORTX
#define SPIM_SDI4_PIN   IO_PINX
#endif /*USE_SPIM*/

/*-----------
 *   I2C 
 *----------*/
#define USE_I2C         0
#if USE_I2C != 0

/*I2C1*/
#define I2C1_BAUD       0 /* 0: disable the module */

/*I2C2*/
#define I2C2_BAUD       0
#endif /*USE_I2C*/

/*--------------
 *   Parallel 
 *-------------*/
#define USE_PARALLEL     0
#if USE_PARALLEL != 0
#define PAR_CS1_PORT     IO_PORTX
#define PAR_CS1_PIN      IO_PINX
#define PAR_CS2_PORT     IO_PORTX
#define PAR_CS2_PIN      IO_PINX
#define PAR_SW           0
#if PAR_SW != 0
#define PARSW_DATA_PORT   IO_PORTX
#define PARSW_ADR_PORT    IO_PORTX
#define PARSW_WR_PORT     IO_PORTX
#define PARSW_WR_PIN      IO_PINX
#define PARSW_RD_PORT     IO_PORTX
#define PARSW_RD_PIN      IO_PINX
#define PARSW_RS_PORT     IO_PORTX
#define PARSW_RS_PIN      IO_PINX
//#define PARSW_WR_DATA(data) {}  /*Parallel wr data*/
//#define PARSW_RD_DATA(data) {}  /*Parallel rd data*/
//#define PARSW_WR_STROBE {}  /*Parallel wr strobe*/
//#define PARSW_RD_STROBE {}  /*Parallel rd data*/
#endif  /*PAR_SW*/
#endif  /*USE_PARALLEL*/


/*-----------------------------
 *  Internal TFT or PC monitor
 *----------------------------*/
#define USE_TFT     1
#if USE_TFT != 0
#define TFT_HOR_RES   480
#define TFT_HSL       30     /*HSYNC length*/
#define TFT_HBP       38     /*Hor. Back proach*/
#define TFT_HFP       12     /*Hor Front proach*/

#define TFT_VER_RES  320
#define TFT_VSL      3       /*VSYNC length*/
#define TFT_VBP      26      /*Ver. Back proach*/
#define TFT_VFP      3       /*Ver. Front proach*/

#define TFT_COLOR_DEPTH 16
#define TFT_BL_PORT IO_PORTX
#define TFT_BL_PIN  IO_PINX

#endif


/*********************
 *   DEVICE CONFIG
 *********************/

/*===================
 *   User interface
 *==================*/

/*----------
 *   LED
 *---------*/
#define USE_LED         0
#if USE_LED != 0
#define LED_LIFE        LED1
#define LED_ERR         LED2
#define LED_BUSY        LED3
#define LED1_PORT       IO_PORTX
#define LED1_PIN        IO_PINX
#define LED2_PORT       IO_PORTX
#define LED2_PIN        IO_PINX
#define LED3_PORT       IO_PORTX
#define LED3_PIN        IO_PINX
#define LED4_PORT       IO_PORTX
#define LED4_PIN        IO_PINX
#define LED5_PORT       IO_PORTX
#define LED5_PIN        IO_PINX
#define LED6_PORT       IO_PORTX
#define LED6_PIN        IO_PINX
#define LED7_PORT       IO_PORTX
#define LED7_PIN        IO_PINX
#define LED8_PORT       IO_PORTX
#define LED8_PIN        IO_PINX
#endif /*USE_LED*/


/*----------
 *  Switch
 *---------*/
#define USE_SW         0
#if USE_SW != 0
#define SW1_PORT       IO_PORTX
#define SW1_PIN        IO_PINX
#define SW2_PORT       IO_PORTX
#define SW2_PIN        IO_PINX
#define SW3_PORT       IO_PORTX
#define SW3_PIN        IO_PINX
#define SW4_PORT       IO_PORTX
#define SW4_PIN        IO_PINX
#define SW5_PORT       IO_PORTX
#define SW5_PIN        IO_PINX
#define SW6_PORT       IO_PORTX
#define SW6_PIN        IO_PINX
#define SW7_PORT       IO_PORTX
#define SW7_PIN        IO_PINX
#define SW8_PORT       IO_PORTX
#define SW8_PIN        IO_PINX
#endif


/*-------------
 *   Buzzer
 *------------*/
#define USE_BUZZER  0
#if USE_BUZZER != 0
#define BUZZER_PORT IO_PORTX
#define BUZZER_PIN  IO_PINX
#define BUZZER_INV  0
#define BUZZER_BEEP_ON_TIME 200
#define BUZZER_BEEP_OFF_TIME 100
#define BUZZER_EXT_DRIVE    0  /*Not supported yet*/
#endif

/*-----------
 *    Log
 *----------*/
#define USE_LOG     0
#if USE_LOG     !=  0
/*  0: none, 1: err, 2: err + warn, 3: err + warn + msg,  will be logged*/
#define LOG_LEVEL   3
#define LOG_SYM_MSG  ""
#define LOG_SYM_WARN ">"
#define LOG_SYM_ERR  "#"
#define LOG_LENGTH_MAX  512

#define LOG_FILE        ""
#define LOG_USE_PRINTF  0
#define LOG_USE_SERIAL  0
#define LOG_SERIAL_DRV  HW_SERIAL1
#define LOG_SERIAL_BAUD 115200
#endif /*USE_LOG*/
/*=============================
 *   Analog-digital converter
 *============================*/

/*--------------------
        ADS1256
 *-------------------*/
#define USE_ADS1256     0
#if USE_ADS1256     !=  0
#define ADS1256_DRV          HW_SPIX_CSX
#define ADS1256_DRDY_PORT    IO_PORTX
#define ADS1256_DRDY_PIN     IO_PINX
#define ADS1256_PGA          0   /*0=x1, 1=x2, 2=x4, 3=x8, 4=x16, 5=x32, 6=x64*/
#define ADS1256_BUFEN        1
#define ADS1256_CLK_OUT    /*0: clk off, 1: clk_in, 2: clk_in/2. 3 clk_in/4*/
/*SMPS: 0x03=2.5,0x13=5, 0x23=10, 0x33=15, 0x43=25, 0x53=30, 0x63=50,
 *      0x72=60, 0x82=100, 0x92=500, 0xA1=1000, 0xB0 = 2000, 0xC0 = 3750,
 *      0xD0=7500, 0xE0=15000, 0xF0 = 30000 */
#define ADS1256_SAMPLE_RATE      0xA1
#endif /*USE_ADS1256*/

/*--------------------
   ADS1256 Multi
 *-------------------*/
#define USE_ADS1256_M     0
#if USE_ADS1256_M != 0
#define ADS1256_M_DRDY_PORT    IO_PORTX
#define ADS1256_M_DRDY_PIN     IO_PINX
#define ADS1256_M_PGA          0   /*0=x1, 1=x2, 2=x4, 3=x8, 4=x16, 5=x32, 6=x64*/
#define ADS1256_M_BUFEN        0x82
#define ADS1256_M_CLK_OUT    /*0: clk off, 1: clk_in, 2: clk_in/2. 3 clk_in/4*/
/*SMPS: 0x03=2.5,0x13=5, 0x23=10, 0x33=15, 0x43=25, 0x53=30, 0x63=50,
 *      0x72=60, 0x82=100, 0x92=500, 0xA1=1000, 0xB0 = 2000, 0xC0 = 3750,
 *      0xD0=7500, 0xE0=15000, 0xF0 = 30000 */
#define ADS1256_M_SAMPLE_RATE      0xA1
#endif /*USE_ADS1256_M*/

/*=============================
 *   Digital-analog converter
 *============================*/

/*=================
 *    BlueTooth
 *=================*/

/*--------------
 *    BTM41X
 *--------------*/
#define USE_BTM41X  0
#if USE_BTM41X != 0
#define BTM41X_NAME     	"My Bluetooth name"
#define BTM41X_SERIAL_DRV   HW_SERIALX
#define BTM41X_RST_PORT     IO_PORTX
#define BTM41X_RST_PIN      IO_PINX
#endif

/*=======================
 *   Real time clock
 *=======================*/


/*=======================
 *   Display controllers
 *======================*/

/*----------------
 *    SSD1963
 *--------------*/
#define USE_SSD1963   0
#if USE_SSD1963 != 0
#define SSD1963_PAR_CS    PAR_CSX
#define SSD1963_RST_PORT  IO_PORTX
#define SSD1963_RST_PIN   IO_PINX
#define SSD1963_BL_PORT   IO_PORTX
#define SSD1963_BL_PIN    IO_PINX
/*Display settings*/
#define SSD1963_HDP     479
#define SSD1963_HT      531
#define SSD1963_HPS     43
#define SSD1963_LPS     8
#define SSD1963_HPW     10
#define SSD1963_VDP     271
#define SSD1963_VT      288
#define SSD1963_VPS     12
#define SSD1963_FPS     4
#define SSD1963_VPW     10
#define SSD1963_HS_NEG  0   /*Negative hsync*/
#define SSD1963_VS_NEG  0   /*Negative vsync*/
#define SSD1963_ORI     0   /*0, 90, 180, 270*/
#define SSD1963_COLOR_DEPTH 16
#endif


/*----------------
 *    R61581
 *--------------*/
#define USE_R61581   0
#if USE_R61581 != 0
#define R61581_PAR_CS    PAR_CSX
#define R61581_RST_PORT  IO_PORTX
#define R61581_RST_PIN   IO_PINX
#define R61581_BL_PORT   IO_PORTX
#define R61581_BL_PIN    IO_PINX
/*Display settings*/
#define R61581_HOR_RES     480
#define R61581_VER_RES     320
#define R61581_HDP     479
#define R61581_HT      531
#define R61581_HPS     43
#define R61581_LPS     8
#define R61581_HPW     10
#define R61581_VDP     271
#define R61581_VT      319
#define R61581_VPS     12
#define R61581_FPS     4
#define R61581_VPW     10
#define R61581_HS_NEG  0   /*Negative hsync*/
#define R61581_VS_NEG  0   /*Negative vsync*/
#define R61581_ORI     180   /*0, 90, 180, 270*/
#define R61581_COLOR_DEPTH 16
#endif

/*------------------------------
 *  ST7565 (Monochrome, low res.)
 *-----------------------------*/
#define USE_ST7565  0
#if USE_ST7565 != 0
#define ST7565_DRV      HW_SPIX_CSX
#define ST7565_RST_PORT IO_PORTX
#define ST7565_RST_PIN  IO_PINX
#define ST7565_RS_PORT  IO_PORTX
#define ST7565_RS_PIN   IO_PINX
#endif  /*USE_ST7565*/

/*====================
 * Display input
 *===================*/

/*--------------
 *    XPT2046
 *--------------*/
#define USE_XPT2046     0
#if USE_XPT2046 != 0
#define XPT2046_SPI_DRV     SPISW_CSX
#define XPT2046_IRQ_PORT    IO_PORTX
#define XPT2046_IRQ_PIN     IO_PINX
#endif

/*-----------------
 *    FT5406EE8
 *-----------------*/
#define USE_FT5406EE8    0
#if USE_FT5406EE8 != 0
#define FT540EE8_I2C_DRV    HW_I2C1
#endif

/*-------------------------------
 *    Mouse or touchpad on PC
 *------------------------------*/
#define USE_MOUSE 1
#if USE_MOUSE != 0
/*No settings*/
#endif


/*====================
 *   Data storage
 *===================*/

/*------------
 *  SD card
 *------------*/
#define USE_SDCARD     0
#if USE_SDCARD !=0
#define SDCARD_SPI_DRV     SPIX_CSX
#endif

#endif
