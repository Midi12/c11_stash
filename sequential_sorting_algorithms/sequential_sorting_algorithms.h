#ifndef SEQUENTIAL_SORTING_ALGORITHMS_H
#define SEQUENTIAL_SORTING_ALGORITHMS_H

#include <stddef.h>
#include <stdint.h>

#include "../shared/defines.h"

#define array_size(x)    \
    sizeof(x) / sizeof(x[0])

typedef int32_t err_t;
typedef int32_t (*sorting_callback_t)(const char *, const char *);

err_t merge_sort(
    __in__  void *array[static 1],
    __in__  size_t array_length,
    __in__  sorting_callback_t callback,
    __out__ void* sorted
);

err_t quick_sort(
    __in__  void *array[static 1],
    __in__  size_t array_length,
    __in__  sorting_callback_t callback,
    __out__ void* sorted
);

#endif // SEQUENTIAL_SORTING_ALGORITHMS_H