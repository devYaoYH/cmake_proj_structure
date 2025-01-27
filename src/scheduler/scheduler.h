#pragma once

#include <stdlib.h>
#include <stdbool.h>

#include "macros.h"
#include "slate.h"
#include "state_machine.h"

// Add required include files for states
#include "init.h"

/*
 * Must be a macro because it is used to initialize an array
 */
#define num_states (sizeof(all_states) / sizeof(sched_state_t *))

void sched_init(slate_t *slate);
void sched_dispatch(slate_t *slate);
