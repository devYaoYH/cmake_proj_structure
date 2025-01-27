#include "main.h"

slate_t slate;

int main() {
    sched_init(&slate);
    sched_dispatch(&slate);
    return 0;
}
