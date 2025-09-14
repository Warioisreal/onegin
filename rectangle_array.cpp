#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "color_lib.h"
#include "rectangle_array.h"


char* CreateRectArr(char* text,
                    const size_t line_size,
                    const size_t strf_count,
                    const size_t strf_size)
{
    assert (text != nullptr);

    const char* const filename = "test.txt";
    FILE* file = fopen(filename, "r");

    char* buffer_line = nullptr;
    size_t buffer_line_size = 0;

    for (size_t strf_number = 0; strf_number < strf_count; strf_number++) {
        for (size_t line_number = 0; line_number < strf_size + 1; line_number++) {
            PrintColorVar(YELLOW, "count char: %-5zd", getline(&buffer_line, &buffer_line_size, file));
            if (line_number < 14) {
                strncpy(&text[(strf_number * strf_size + line_number) * line_size], buffer_line, (size_t)line_size);
                PrintColorVar(GREEN, "%s\n", &text[(strf_number * strf_size + line_number) * line_size]);
            }
        }
        printf("-------------------------------------------------------------------\n\n");
    }

    fclose(file);

    return text;
}

void PrintRectArr(char* text,
                    const size_t line_size,
                    const size_t strf_count,
                    const size_t strf_size)
{
    for (size_t strf_number = 0; strf_number < strf_count; strf_number++) {
        for (size_t line_number = 0; line_number < strf_size; line_number++) {
            PrintColorVar(CYAN, "%-3zu", strf_number);
            printf(" | ");
            PrintColorVar(CYAN, "%-3zu", line_number);
            printf(" | ");
            PrintColorVar(BLUE, "%-10p", &text[(strf_number * strf_size + line_number) * line_size]);
            PrintColor(YELLOW, "   ->   ");
            printf("%s", &text[(strf_number * strf_size + line_number) * line_size]);
        }
        PrintColorVar(YELLOW, "strf_number: %zu -> %zu\n", strf_number, strf_number + 1);
    }
}
