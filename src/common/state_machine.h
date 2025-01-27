#pragma once

#include <stdlib.h>

#include "slate.h"

#define MAX_TASKS_PER_STATE 10

typedef struct global_slate slate_t;

typedef struct sched_task
{
    /**
     * Friendly name for the task.
     */
    const char *name;

    /**
     * Called once when the task initializes.
     * @param slate     Pointer to the current satellite slate
     */
    void (*task_init)(slate_t *slate);

    /**
     * Called each time the task dispatches.
     * @param slate     Pointer to the current satellite slate
     */
    void (*task_dispatch)(slate_t *slate);

} sched_task_t;

/**
 * Holds the info for defining a state.
 */
typedef struct sched_state
{
    /**
     * Friendly name for the state.
     */
    const char *name;

    size_t num_tasks;
    sched_task_t *task_list[MAX_TASKS_PER_STATE];

    /**
     * Called each time the state dispatches.
     * @param slate     Pointer to the current satellite slate
     * @return The next state to transition to
     */
    struct sched_state *(*get_next_state)(slate_t *slate);
} sched_state_t;
