#pragma once

#include "state_machine.h"

typedef struct sched_state sched_state_t;
typedef struct sched_task sched_task_t;

typedef struct global_slate
{
    /*
     * State machine info.
     */
    sched_state_t *current_state;
    sched_task_t *current_task;
    uint64_t time_in_current_state_ms;
} slate_t;
