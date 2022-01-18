#include <stdio.h>
#include <string.h>

#include "../eztest/eztest/eztest.h"

#include "sequential_sorting_algorithms.h"

// compile with : cc -g -std=c11 ../eztest/eztest/runner.c sequential_sorting_algorithms_test.c sequential_sorting_algorithms.c

static const char *s_array[] = {
    "bonjour",
    "le V",
    "V4LD",
    "C11",
    "deviens génial, s'ils ne peuvent pas t'utiliser que peuvent t'il faire ?",
    "Sullyvan",
    "J'suis vite stone, avec mes histoires, ma weed et puis mes Winston"
};

static const char *s_sorted[] = {
    "C11",
    "J'suis vite stone, avec mes histoires, ma weed et puis mes Winston",
    "Sullyvan",
    "V4LD",
    "bonjour",
    "deviens génial, s'ils ne peuvent pas t'utiliser que peuvent t'il faire ?",
    "le V"
};

TEST(SequentialSorting, MergeSort)
{
    sorting_callback_t callback = (sorting_callback_t)strcmp;

    const char **sorted = (const char **)malloc(array_size(s_array) * sizeof(const char *));

    err_t err = merge_sort((void *)s_array, array_size(s_array), callback, (void *)sorted);

    for (int i = 0; i < array_size(s_sorted); i++) {
        ASSERT_EQUAL_MEM(s_sorted[i], sorted[i], strlen(s_sorted[i]));
    }

    free((void *)sorted);
}

TEST(SequentialSorting, QuickSort)
{
    sorting_callback_t callback = (sorting_callback_t)strcmp;

    const char **sorted = (const char **)malloc(array_size(s_array) * sizeof(const char *));

    err_t err = quick_sort((void *)s_array, array_size(s_array), callback, (void *)sorted);

    for (int i = 0; i < array_size(s_sorted); i++) {
        ASSERT_EQUAL_MEM(s_sorted[i], sorted[i], strlen(s_sorted[i]));
    }

    free((void *)sorted);
}