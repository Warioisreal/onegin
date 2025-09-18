#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>

#include "line_struct.h"

#include "comparator_func.h"
#include "color_lib.h"
#include "pointer_array.h"
#include "rectangle_array.h"
#include "swap_func.h"
#include "work_with_buffer.h"


void BubbleSort(void* base, size_t n, size_t size,
                int (*compar)(const void*, const void*));
size_t CalcLinesCount(size_t* lines_count, const char* data, const size_t size);
void PrintText(const struct OneginStr* text, const size_t lines_count);

int main(void) {

    /*
    const size_t strf_count = 10; // [368]
    const size_t strf_size = 14;
    const ssize_t line_size = 60;
    */

    const char* const filename = "test.txt";

    struct stat file_stat;
    if (stat(filename, &file_stat) != 0) {
        perror("filesize read error");          // special error output
        return 1;
    }

    const size_t filesize = (size_t)file_stat.st_size;

    FILE* file = fopen(filename, "r");
    if (file == nullptr) {
        perror("file open error");              // special error output
        return 1;
    }

    char* buffer = (char*)calloc(filesize + 1, sizeof(char));
    if (filesize > fread(buffer, sizeof(char), filesize, file)) {
        if (feof(file)) {                       // if reached EOF before filesize
            printf("reached EOF\n");
        } else if (ferror(file)) {              // if had readfile error
            perror("file read error");          // special error output
        } else {
            printf("fread.size != filesize\n"); // if fread.size mistake
        }
        return 1;
    }

    fclose(file);

    size_t lines_count = 0;

    lines_count = CalcLinesCount(&lines_count, buffer, filesize);

    struct OneginStr* text = (struct OneginStr*)calloc(lines_count + 1, sizeof(struct OneginStr));

    BufferToText(&text, buffer);

    BubbleSort(text, lines_count, sizeof(text[0]), ReverseComparator);

    PrintText(text, lines_count);

    free(text);
    text = nullptr;

    free(buffer);
    buffer = nullptr;
    /*
    char rect_text[strf_size * strf_count * line_size] = {'\0'};
    char*** ptr_text = (char***)calloc(strf_size, sizeof(char**));
    CreateRectArr(rect_text, line_size, strf_count, strf_size, filename);
    PrintRectArr(rect_text, line_size, strf_count, strf_size);
    //SortRectArr(text, line_size, strf_count, strf_size);
    CreatePtrArr(ptr_text, strf_count, strf_size, filename);
    PrintPtrArr(ptr_text, strf_count, strf_size);
    //SortPtrArr(text, line_size, strf_count, strf_size);
    ClearMemArr(ptr_text, strf_count, strf_size);
    */
    return 0;
}


void BubbleSort(void* base, size_t n, size_t size,
                int (*compar)(const void*, const void*)) {

    for (size_t line_1 = 0; line_1 < n - 1; line_1++) {
        for (size_t line_2 = 0; line_2 < n - line_1 - 1; line_2++) {
            if (compar((void*)((size_t)base + line_2 * size),
                        (void*)((size_t)base + (line_2 + 1) * size)) > 0) {
                Swap((void*)((size_t)base + line_2 * size),
                     (void*)((size_t)base + (line_2 + 1) * size));
            }
        }
    }
}


size_t CalcLinesCount(size_t* lines_count, const char* data, const size_t size) {
    size_t count = 0;

    for (size_t i = 0; i < size; i++) {
        if (data[i] == '\n') {
            count++;
        }
    }
    count = (count + 1) / 15 * 14;  // calculate correct count

    *lines_count = count;
    return count;
}


void PrintText(const struct OneginStr* text, const size_t lines_count) {
    for (size_t i = 0; i < lines_count; i++) {
        printf("%p | %s\n", text[i].ptr, text[i].ptr);
    }
}
