#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "color_lib.h"
#include "rectangle_array.h"


char* CreateRectArr(char* text,
                    const size_t line_size,
                    const size_t strf_count,
                    const size_t strf_size,
                    const char* filename)
{
    assert (text != nullptr);

    FILE* file = fopen(filename, "r");

    char* buffer_line = nullptr;
    size_t buffer_line_size = 0;

    for (size_t strf_number = 0; strf_number < strf_count; strf_number++) {
        for (size_t line_number = 0; line_number < strf_size + 1; line_number++) {
            PrintColor(YELLOW, "string size: ");
            PrintColorVar(MAGENTA, "%-2zd ", getline(&buffer_line, &buffer_line_size, file));

            if (line_number < 14) {
                strncpy(&text[(line_number * strf_count + strf_number) * line_size], buffer_line, (size_t)line_size);
                PrintColorVar(GREEN, "%s", &text[(line_number * strf_count + strf_number) * line_size]);
            }
        }
        PrintColor(GREY, "---------------------------------------------\n");
    }

    fclose(file);

    return text;
}


void PrintRectArr(char* text,
                  const size_t line_size,
                  const size_t strf_count,
                  const size_t strf_size)
{
    for (size_t line_number = 0; line_number < strf_size; line_number++) {
        for (size_t strf_number = 0; strf_number < strf_count; strf_number++) {
            PrintColorVar(MAGENTA, "%-2zu", line_number);
            PrintColor(GREY, " | ");
            PrintColorVar(MAGENTA, "%-3zu", strf_number);
            PrintColor(GREY, " | ");
            PrintColorVar(BLUE, "%-10p", &text[(line_number * strf_count + strf_number) * line_size]);
            PrintColor(GREY, " | ");
            PrintColorVar(CYAN, "%-10zu", (size_t)(&text[(line_number * strf_count + strf_number) * line_size]));
            PrintColor(GREY, "   ->   ");
            printf("%s", &text[(line_number * strf_count + strf_number) * line_size]);
        }
        PrintColorVar(YELLOW, "line_number: %zu -> %zu\n", line_number, line_number + 1);
    }
}
/*
void SortRectArr(char* text,
                 const size_t line_size,
                 const size_t strf_count,
                 const size_t strf_size)
{
    for (size_t line_number = 0; line_number < strf_size; line_number++) {
        for (size_t strf_number_1 = 0;
             strf_number_1 < strf_count - 1;
             strf_number_1++)
        {
            for (size_t strf_number_2 = 0;
                 strf_number_2 < strf_count - strf_number_1 - 1;
                 strf_number_2++)
            {
                char* s1 = &text[(line_number * strf_count + strf_number_2) * line_size];
                char* s2 = &text[(line_number * strf_count + strf_number_2 + 1) * line_size];

                if (s1 > s2) {
                    size_t buffer = 0;
                    SwapZU(&s1, &s2, &buffer);
                }
            }
        }
    }
}
*/
