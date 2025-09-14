#include <stdio.h>

#include "color_lib.h"
#include "pointer_array.h"
#include "rectangle_array.h"


int main(void) {

    const size_t strf_count = 3;
    const size_t strf_size = 14;
    const ssize_t line_size = 50;

    char text[strf_size * strf_count * line_size];

    CreateRectArr(text, line_size, strf_count, strf_size);

    PrintRectArr(text, line_size, strf_count, strf_size);

    return 0;
}
