#ifndef _SORT_FUNC_H_
#define _SORT_FUNC_H_

#include <ctype.h>


void BubbleSort(void* base, size_t n, size_t size,
                int (*compare)(const void*, const void*));

#endif // _SORT_FUNC_H_
