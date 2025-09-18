#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "text_structs.h"
#include "color_lib.h"

#include "comparator_func.h"
#include "output.h"
#include "sort_func.h"
#include "struct_pointer_array.h"
#include "work_with_buffer.h"

/*
-----------------testing different types of arrays------------------------
              ----------**trash coding**-------------
#include "test_pointer_array.h"
#include "test_srectangle_array.h"
--------------------------------------------------------------------------
*/


int main(void) {

    struct TextStorage textdata = {.filename = "onegin.txt"};
    char* buffer = nullptr;

    int error = MakeTextStorage(&buffer, &textdata);

    if (error) { return 1; }

    FILE* output_file = nullptr;
    output_file = StartOutput(&output_file);

    if (output_file == nullptr) { return 1; }

    BubbleSort(textdata.text, textdata.lines_count, sizeof(struct LineParams), Comparator);

    PrintText(output_file, textdata.text, textdata.lines_count);

    qsort(textdata.text, textdata.lines_count, sizeof(struct LineParams), ReverseComparator);

    PrintText(output_file, textdata.text, textdata.lines_count);

    PrintOrigText(output_file, buffer, textdata.lines_count);

    DestroyTextStorage(&textdata);

    EndOutput(output_file);

    FreeBuffer(&buffer);

/*
-----------------testing different types of arrays------------------------
              ----------**trash coding**-------------
    const size_t strf_count = 10; // [367]
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
