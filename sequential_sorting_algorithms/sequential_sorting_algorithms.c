#include "sequential_sorting_algorithms.h"

#include <math.h>

size_t _min(size_t a, size_t b) {
    return a < b ? a : b;
}

void _copy_array(void *array1[static 1], size_t len1, void *array2[static 1], size_t len2) {
    size_t n = _min(len1, len2);

    for (size_t i = 0; i < n; i++) {
        array2[i] = array1[i];
    }
}

void _merge(
    void *array1[static 1],
    size_t bottom,
    size_t middle,
    size_t up,
    void *array2[static 1],
    sorting_callback_t callback
) {

    size_t i = bottom;
    size_t j = middle;

    for (size_t k = bottom; k < up; k++) {
        if (i < middle && (j >= up || callback(array1[i], array1[j]) < 0)) {
            array2[k] = array1[i++];
        } else {
            array2[k] = array1[j++];
        }
    }
}

err_t merge_sort(
    __in__  void *array[static 1],
    __in__  size_t array_length,
    __in__  sorting_callback_t callback,
    __out__ void* sorted
) {
    if (array_length <= 1) {
        sorted = array;
        return 0;
    }

    for (size_t j = 1; j < array_length; j *= 2) {
        for (size_t i = 0; i < array_length; i += (2 * j)) {
            _merge(array, i, _min(i + j, array_length), _min(i + 2 * j, array_length), sorted, callback);
        }

        _copy_array(sorted, array_length, array, array_length);
    }

    return 0;
}

void _swap(void *array[static 1], size_t i, size_t j) {
    void * tmp = array[j];
    array[j] = array[i];
    array[i] = tmp;
}

size_t _partition(
    void *array[static 1],
    size_t bottom,
    size_t up,
    sorting_callback_t callback
) {
    const char *pivot = array[(int)floor((bottom + up) / 2.0)];

    size_t i = bottom - 1;
    size_t j = up + 1;

    for(;;) {
        do i++; while (callback(array[i], pivot) < 0);
        do j--; while (callback(array[j], pivot) > 0);

        if (i >= j) return j;
        _swap(array, i, j);
    }
}

void _quick_sort(
    void *array[static 1],
    size_t bottom,
    size_t up,
    sorting_callback_t callback
) {
    if (bottom >= 0 && up >= 0 && bottom < up) {
        size_t p = _partition(array, bottom, up, callback);
        _quick_sort(array, bottom, p, callback);
        _quick_sort(array, p + 1, up, callback);
    }
}

err_t quick_sort(
    __in__  void *array[static 1],
    __in__  size_t array_length,
    __in__  sorting_callback_t callback,
    __out__ void* sorted
) {
    _copy_array(array, array_length, sorted, array_length);
    _quick_sort(sorted, 0, array_length - 1, callback);

    return 0;
}