/**
 * @file misc_conf.h
 * 
 */

#ifndef MISC_CONF_H
#define MISC_CONF_H

/*====================
 * Memory management
 *===================*/

/*----------------
 * Dynamic memory
 *----------------*/
#define USE_DYN_MEM     1
#if USE_DYN_MEM != 0
#define DM_AUTO_ZERO   0     /*Automatically fill-zero the allocated memory*/
#define DM_CUSTOM      0     /*1: use custom malloc/free, 0: use malloc/free provided by dyn_mem*/
#if DM_CUSTOM == 0
  #define DM_MEM_SIZE    (16U * 1024U) /*Size memory used by mem_alloc (in bytes)*/
  #define DM_MEM_ATTR                  /*Complier prefix for big array declaration*/
#else /*DM_CUSTOM != 0: Provide custom malloc/free functions*/
  #define DM_CUST_INCLUDE <stdlib.h>   /*Header for the dynamic memory function*/
  #define DM_CUST_ALLOC   malloc       /*Wrapper to malloc*/
  #define DM_CUST_FREE    free         /*Wrapper to free*/
#endif  /*DM_CUSTOM*/
#endif  /*USE_DYN_MEM*/

 /*--------------------------------------
  * Dynamic memory with always 0 % fragmentation
  * Not compatible with normal malloc/free
  *------------------------------------*/
 #define USE_DYN_MEM_DEFR     0
 #if USE_DYN_MEM_DEFR != 0
 #define DMD_MEM_SIZE    (16U * 1024U) /*Size memory used by mem_alloc (in bytes)*/
 #define DMD_AUTO_ZERO   1             /*Automatically fill-zero the allocated memory*/
 #define DMD_MEM_ATTR
 #endif  /*USE_DYN_MEM_DEFR*/

/*------------
 *   FIFO
 *-----------*/
#define USE_FIFO        1
#if USE_FIFO != 0
/* No settings*/
#endif /*USE_FIFO*/

/*----------------
 *   Linked list
 *----------------*/
#define USE_LINKED_LIST     1
#if USE_LINKED_LIST != 0
/* No settings*/
#endif /*USE_LINKED_LIST*/

/*====================
 * Operation system
 *===================*/

/*----------------
 * Periodic task
 *----------------*/
#define USE_PTASK       1
#if USE_PTASK != 0
/*No settings*/
#endif /*USE_PTASK*/

/*-----------------------
 * CPU Idle measurement
 *-----------------------*/
#define USE_IDLE        0
#if USE_IDLE != 0
#define IDLE_REFR_RATE  500 /*ms*/
#endif /*USE_IDLE*/

/*===================
 *   File system
 *==================*/

/*----------------
 *  FS interface
 *----------------*/
#define USE_FSINT   1
#if USE_FSINT != 0
/*No settings*/
#endif  /*USE_FSINT*/

/*----------------
 *     uFS
 *----------------*/
#define USE_UFS   1
#if USE_UFS != 0
#define UFS_LETTER 'U'
#endif  /*USE_UFS*/

/*------------------------
 * FAT32 - FatFS wrappers
 * (used on MCU)
 *-----------------------*/
#define USE_FAT32   0
#if USE_FAT32 != 0
#define FAT32_LETTER 'S'/
#endif  /*USE_FAT32*/

/*---------------------
 * Linux File system
 *---------------------*/
#define USE_LINUXFS   1
#if USE_LINUXFS != 0
#define LINUXFS_LETTER 'L'
#define LINUXFS_ROOT_DIR    "./" /*See this directory as root folder*/
#endif  /*USE_LINUXFS*/

/*================
 *     Math
 *================*/

/*-----------------
 *  Trigonometry
 *----------------*/
#define USE_TRIGO   1
#if USE_TRIGO != 0
/*No settings*/
#endif

/*-----------------
 *  Math basic
 *----------------*/
#define USE_MATH_BASE   1
#if USE_MATH_BASE != 0
/*No settings*/
#endif

/*===================
 *     Others
 *==================*/

/*----------------
 *     Color
 *----------------*/
#define  USE_COLOR      1
#if USE_COLOR != 0
#define COLOR_DEPTH     16
#endif

/*------------
 *    Slip
 *-----------*/
#define USE_SLIP        0
#if USE_SLIP != 0
#define SLIP_ESC        0x0C
#define SLIP_END        0xDB
#define SLIP_ESC_END    0xDC  /*Change END char in the stream to: ESC, ESC_END*/
#define SLIP_ESC_ESC    0xDD  /*Change ESC char in the stream to: ESC, ESC_ESC*/
#endif  /*USE_SLIP*/

/*----------------
 * String command
 *--------------*/
#define USE_STRCMD     0
#if USE_STRCMD != 0
/*No settings*/
#endif /*USE_STRCMD*/

#endif /* MISC_CONF_H */

