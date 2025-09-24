#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "sort_func.h"
#include "text_structs.h"

static void Swap(void* ptr1, void* ptr2, size_t value_size);

typedef int (*comparator)(const void*, const void*);


void BubbleSort(void* base, size_t n, size_t size,
                comparator comp) {

    assert (base != nullptr);

    void* ptr1 = nullptr;
    void* ptr2 = nullptr;

    for (size_t line_1 = 0; line_1 < n - 1; line_1++) {
        for (size_t line_2 = 0; line_2 < n - line_1 - 1; line_2++) {
            ptr1 = (void*)((size_t)base + line_2 * size);
            ptr2 = (void*)((size_t)base + (line_2 + 1) * size);

            if (comp(ptr1, ptr2) > 0) { Swap(ptr1, ptr2, size); }
        }
    }
}


static void Swap(void* ptr1, void* ptr2, size_t value_size) {

    assert (ptr1 != nullptr);
    assert (ptr2 != nullptr);

    if (value_size == 0) {
        return;
    }

    void* buf_ptr = (void*)calloc(1, value_size);
    if (buf_ptr == nullptr) {
        return;
    }

    memcpy(buf_ptr, ptr1,    value_size);
    memcpy(ptr1,    ptr2,    value_size);
    memcpy(ptr2,    buf_ptr, value_size);

    free(buf_ptr);
    buf_ptr = nullptr;
}
