#include "sort_func.h"
#include "line_struct.h"

static void Swap(void* ptr1, void* ptr2);

typedef int (*comparator)(const void*, const void*);


void BubbleSort(void* base, size_t n, size_t size,
                comparator comp) {

    for (size_t line_1 = 0; line_1 < n - 1; line_1++) {
        for (size_t line_2 = 0; line_2 < n - line_1 - 1; line_2++) {
            if (comp((void*)((size_t)base + line_2 * size),
                        (void*)((size_t)base + (line_2 + 1) * size)) > 0) {
                Swap((void*)((size_t)base + line_2 * size),
                     (void*)((size_t)base + (line_2 + 1) * size));
            }
        }
    }
}


static void Swap(void* ptr1, void* ptr2) {
    struct Str* p1 = (struct Str*)(ptr1);
    struct Str* p2 = (struct Str*)(ptr2);
    struct Str buf_ptr;
    buf_ptr = *p1;
    *p1 = *p2;
    *p2 = buf_ptr;
}
