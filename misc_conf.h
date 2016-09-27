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
#define DM_MEM_SIZE    (16U * 1024U) /*Size memory used by mem_alloc (in bytes)*/
#define DM_AUTO_ZERO   1             /*Automatically fill-zero the allocated memory*/
#define DM_MEM_ATTR					 /*Complier prefix for big array declaration*/
#endif  /*USE_DYN_MEM*/

 /*----------------------------
  * Dynamic memory with Defrag
  *--------------------------*/
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
#define USE_LINKED_LIST 1
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
 *   Communication
 *==================*/

/*------------
 *    Slip
 *-----------*/
#define USE_SLIP    0
#if USE_SLIP != 0
#define SLIP_ESC        0x0C
#define SLIP_END        0xDB
#define SLIP_ESC_END    0xDC  /*Change END char in the stream to: ESC, ESC_END*/
#define SLIP_ESC_ESC    0xDD  /*Change ESC char in the stream to: ESC, ESC_ESC*/
#endif  /*USE_SLIP*/

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

/*----------------
 *     FAT32
 *----------------*/
#define USE_FAT32   0
#if USE_FAT32 != 0
#define FAT32_LETTER 'S'
#endif  /*USE_FAT32*/

/*===================
 *     Others
 *==================*/

/*----------------
 *     Color
 *----------------*/
#define  USE_COLOR 		1
#if USE_COLOR != 0
#define COLOR_DEPTH		24
#endif

#endif /*#ifndef MISC_CONF_H*/

