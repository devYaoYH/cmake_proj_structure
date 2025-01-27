#include "print.h"

void print_task_init(slate_t *slate)
{
    LOG_INFO("Test task is initializing...");
}

void print_task_dispatch(slate_t *slate)
{
    LOG_INFO("Test task is dispatching...");
}

sched_task_t print_task = {.name = "print",
                           .task_init = &print_task_init,
                           .task_dispatch = &print_task_dispatch};
