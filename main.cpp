#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "text_structs.h"

#include "color_lib.h"
#include "comparator_func.h"
#include "sort_func.h"
#include "struct_pointer_array.h"

/*
-----------------testing different types of arrays------------------------
#include "test_pointer_array.h"
#include "test_srectangle_array.h"
--------------------------------------------------------------------------
*/


int main(void) {

    struct TextStorage textdata = {.filename = "test.txt"};
    char* buffer = nullptr;

    int error = MakeTextStorage(&buffer, &textdata);

    if (error) { return 1; }

    BubbleSort(textdata.text, textdata.lines_count, sizeof(struct Str), Comparator);

    PrintText(textdata.text, textdata.lines_count);

    printf("\n");

    qsort(textdata.text, textdata.lines_count, sizeof(struct Str), ReverseComparator);

    PrintText(textdata.text, textdata.lines_count);

    printf("\n");

    PrintOrigText(buffer, textdata.lines_count);

    //DestroyTextStorage();

    free(textdata.text);
    textdata.text = nullptr;

    free(buffer);
    buffer = nullptr;

/*
-----------------testing different types of arrays------------------------
    const size_t strf_count = 10; // [368]
    const size_t strf_size = 14;
    const ssize_t line_size = 60;

    char rect_text[strf_size * strf_count * line_size] = {'\0'};
    char*** ptr_text = (char***)calloc(strf_size, sizeof(char**));

    CreateRectArr(rect_text, line_size, strf_count, strf_size, filename);
    PrintRectArr(rect_text, line_size, strf_count, strf_size);
    //SortRectArr(text, line_size, strf_count, strf_size);
    CreatePtrArr(ptr_text, strf_count, strf_size, filename);
    PrintPtrArr(ptr_text, strf_count, strf_size);
    //SortPtrArr(text, line_size, strf_count, strf_size);
    ClearMemArr(ptr_text, strf_count, strf_size);
--------------------------------------------------------------------------
*/
    return 0;
}
