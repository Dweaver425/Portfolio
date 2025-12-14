#ifndef TIMER_H
#define TIMER_H

#include <omp.h>

/* Wall-clock time, as required by the textbook */
#define GET_TIME(now) do { (now) = omp_get_wtime(); } while (0)

#endif
