#include "init.h"

sched_state_t *init_get_next_state(slate_t *slate)
{
    return &init_state;
}

sched_state_t init_state = {.name = "init",
                            .num_tasks = 1,
                            .task_list = {&print_task},
                            .get_next_state = &init_get_next_state};
