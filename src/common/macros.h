#pragma once

#include <stdio.h>
#include "error/error.h"

#define LOG_DEBUG(fmt, ...)                                                    \
    printf("[DEBUG]   " fmt "\n" __VA_OPT__(, ) __VA_ARGS__)

#define LOG_INFO(fmt, ...)                                                     \
    printf("[INFO]    " fmt "\n" __VA_OPT__(, ) __VA_ARGS__)

#define LOG_ERROR(fmt, ...)                                                    \
    printf("[ERROR]   " fmt "\n" __VA_OPT__(, ) __VA_ARGS__)

#define ERROR(message)                                                         \
    LOG_ERROR("%s:%d %s\n", __FILE__, __LINE__, message);                      \
    fatal_error(); 

#define ASSERT(condition)                                                      \
    if (!(condition))                                                          \
    {                                                                          \
        ERROR("Assertion failed: " #condition);                                \
    }
