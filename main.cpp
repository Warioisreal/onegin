#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "text_structs.h"
#include "color_lib.h"

#include "comparator_func.h"
#include "file_func.h"
#include "output.h"
#include "sort_func.h"
#include "struct_pointer_array.h"
#include "work_with_buffer.h"


int main(void) {

    char inp_filename[MAX_FILENAME_LEN] = "";
    GetFileName(inp_filename, DEFAULT_FILENAME_INPUT);

    struct TextStorage textdata = {.filename = inp_filename};
    char* buffer = nullptr;

    int error = MakeTextStorage(&buffer, &textdata);

    if (error) { return 1; }

    FILE* output_file = nullptr;

    char output_filename[MAX_FILENAME_LEN] = "";
    GetFileName(output_filename, DEFAULT_FILENAME_OUTPUT);

    output_file = StartOutput(&output_file, output_filename);

    if (output_file == nullptr) { return 1; }

    BubbleSort(textdata.text, textdata.lines_count, sizeof(struct LineParams), FromStartComparator);

    PrintText(output_file, textdata.text, textdata.lines_count);

    qsort(textdata.text, textdata.lines_count, sizeof(struct LineParams), FromEndComparator);

    PrintText(output_file, textdata.text, textdata.lines_count);

    PrintOriginalText(output_file, buffer, textdata.lines_count);

    DestroyTextStorage(&textdata);

    EndOutput(output_file);

    FreeBuffer(&buffer);

    return 0;
}
