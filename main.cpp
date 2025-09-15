#include <stdio.h>
#include <stdlib.h>

#include "color_lib.h"
#include "pointer_array.h"
#include "rectangle_array.h"


int main(void) {

    const size_t strf_count = 368; //368
    const size_t strf_size = 14;
    const ssize_t line_size = 60;
    const char* const filename = "onegin.txt";

    char rect_text[strf_size * strf_count * line_size] = {'\0'};
    char*** ptr_text = (char***)calloc(strf_size, sizeof(char**));

    CreateRectArr(rect_text, line_size, strf_count, strf_size, filename);

    PrintRectArr(rect_text, line_size, strf_count, strf_size);

    //SortRectArr(text, line_size, strf_count, strf_size);

    CreatePtrArr(ptr_text, strf_count, strf_size, filename);

    PrintPtrArr(ptr_text, strf_count, strf_size);

    //SortPtrArr(text, line_size, strf_count, strf_size);

    ClearMemArr(ptr_text, strf_count, strf_size);

    return 0;
}
