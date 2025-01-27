#pragma once

#include "macros.h"
#include "slate.h"
#include "state_machine.h"

void print_task_init(slate_t *slate);
void print_task_dispatch(slate_t *slate);

extern sched_task_t print_task;
