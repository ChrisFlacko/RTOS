/*
*   File: task.h
*   Author: 2024-06-17 Christian Eberhardt
*   Description: Header file for task management
*/

#ifndef TASK_H
#define TASK_H

/************************************/
/* Includes */
#include "basic_includes.h"

/************************************/
/* Defines */  

/************************************/
/* Type Definitions */

// Enum for different states of the task
typedef enum
{
    TASK_READY,
    TASK_RUNNING,
    TASK_BLOCKED,
}Task_State_T;

// TCB: Task control block for each task
typedef struct TCB
{
    uint32_t *psp;
    struct TCB *next;
    uint8_t priority;
    Task_State_T state;
} TCB_t;

/************************************/
/* Local variables */

/************************************/
/* Local Static Functions: Definitions */

/************************************/
/* Local Static Functions: Implementations */

/************************************/
/* Public functions: Definitions */
void createTask(void (*taskFunction)(void), uint16_t u16StackSize, uint8_t u8Priority);

/************************************/
/* Public functions: Implementations */

#endif 