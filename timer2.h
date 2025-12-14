#ifndef TIMER2_H
#define TIMER2_H

#include <sys/time.h>

#define GET_TIME(now) do { \
    struct timeval t; \
    gettimeofday(&t, NULL); \
    (now) = t.tv_sec + t.tv_usec/1000000.0; \
} while (0)

#endif
