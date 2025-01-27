#include "scheduler.h"

static const sched_state_t *all_states[] = {&init_state};
static sched_state_t *const initial_state = &init_state;
static size_t n_tasks = 0;
static sched_task_t *all_tasks[num_states * MAX_TASKS_PER_STATE];

/**
 * Initialize the state machine.
 *
 * @param slate     Pointer to the slate.
 */
void sched_init(slate_t *slate)
{
    /*
     * Check that each state has a valid number of tasks, and enumerate all
     * tasks.
     */
    for (size_t i = 0; i < num_states; i++)
    {
        ASSERT(all_states[i]->num_tasks <= MAX_TASKS_PER_STATE);
        for (size_t j = 0; j < all_states[i]->num_tasks; j++)
        {
            bool is_duplicate = 0;
            for (size_t k = 0; k < n_tasks; k++)
            {
                if (all_tasks[k] == all_states[i]->task_list[j])
                    is_duplicate = 1;
            }
            if (!is_duplicate)
            {
                all_tasks[n_tasks] = all_states[i]->task_list[j];
                n_tasks++;
            }
        }
    }

    LOG_INFO("sched: Init states with %zu tasks.", n_tasks);

    /*
     * Initialize all tasks.
     */
    for (size_t i = 0; i < n_tasks; i++)
    {
        LOG_INFO("sched: Initializing task %s", all_tasks[i]->name);
        all_tasks[i]->task_init(slate);
    }

    LOG_DEBUG("sched: Initial state: %s.", initial_state->name);

    /*
     * Enter the init state by default
     */
    slate->current_state = initial_state;
    slate->time_in_current_state_ms = 0;

    LOG_DEBUG("sched: Done initializing!");
}

/**
 * Dispatch the state machine. Runs any of the current state's tasks which are
 * due, and transitions into the next state.
 *
 * @param slate     Pointer to the slate.
 */
void sched_dispatch(slate_t *slate)
{
    sched_state_t *current_state_info = slate->current_state;
    
    LOG_DEBUG("sched: Current state: %s.", current_state_info->name);

    /*
     * Loop through all of this state's tasks
     */
    for (size_t i = 0; i < current_state_info->num_tasks; i++)
    {
        sched_task_t *task = current_state_info->task_list[i];
        task->task_dispatch(slate);
        slate->current_task = task;
    }

    slate->time_in_current_state_ms++;

    /*
     * Transition to the next state, if required.
     */
    sched_state_t *const next_state = current_state_info->get_next_state(slate);
    if (next_state != current_state_info)
    {
        LOG_INFO("sched: Transitioning to state %s", next_state->name);

        slate->current_state = next_state;
        slate->time_in_current_state_ms = 0;
    }
}
