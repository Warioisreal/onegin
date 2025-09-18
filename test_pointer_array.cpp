#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "color_lib.h"
#include "test_pointer_array.h"


char*** CreatePtrArr(char*** text,
                     const size_t strf_count,
                     const size_t strf_size,
                     const char* filename)
{
    assert (text != nullptr);

    FILE* file = fopen(filename, "rb");

    char* buffer_line = nullptr;
    size_t buffer_line_size = 0;

    for (size_t i = 0; i < strf_size; i++) { // аллоцирование 14 массивов под n-ую линию
        text[i] = (char**)calloc(strf_count, sizeof(char*));
    }

    for (size_t strf_number = 0; strf_number < strf_count; strf_number++) {
        for (size_t line_number = 0; line_number < strf_size + 1; line_number++) {
            PrintColor(YELLOW, "string size: ");
            PrintColorVar(MAGENTA, "%-2zd ", getline(&buffer_line, &buffer_line_size, file));

            if (line_number < 14) {
                *(text[line_number] + strf_number) = strdup(buffer_line); // аллоцируем n-ую линию и сохраняем её в n-ый массив
                PrintColorVar(GREEN, "%s", *(text[line_number] + strf_number));
            }
        }
        PrintColor(GREY, "---------------------------------------------\n");
    }

    fclose(file);

    return text;
}


void PrintPtrArr(char*** text,
                 const size_t strf_count,
                 const size_t strf_size)
{
    for (size_t line_number = 0; line_number < strf_size; line_number++) {
        for (size_t strf_number = 0; strf_number < strf_count; strf_number++) {
            PrintColorVar(MAGENTA, "%-2zu", line_number);
            PrintColor(GREY, " | ");
            PrintColorVar(MAGENTA, "%-3zu", strf_number);
            PrintColor(GREY, " | ");
            PrintColorVar(BLUE, "%-10p", *(text[line_number] + strf_number));
            PrintColor(GREY, " | ");
            PrintColorVar(CYAN, "%-10zu", (size_t)(*(text[line_number] + strf_number)));
            PrintColor(GREY, "   ->   ");
            printf("%s", *(text[line_number] + strf_number));
        }
        PrintColorVar(YELLOW, "line_number: %zu -> %zu\n", line_number, line_number + 1);
    }
}
/*
void SortPtrArr(char*** text,
                const size_t line_size,
                const size_t strf_count,
                const size_t strf_size)
{

}
*/
void ClearMemArr(char*** text,
                 const size_t strf_count,
                 const size_t strf_size)
{
    for (size_t line_number = 0; line_number < strf_size; line_number++) {
        for (size_t strf_number = 0; strf_number < strf_count; strf_number++) {
            PrintColorVar(MAGENTA, "%-2zu", line_number);
            PrintColor(GREY, " | ");
            PrintColorVar(MAGENTA, "%-3zu", strf_number);
            PrintColor(GREY, " | ");
            PrintColorVar(BLUE, "%p", *(text[line_number] + strf_number));
            PrintColor(GREY, " -> ");

            free(*(text[line_number] + strf_number));
            *(text[line_number] + strf_number) = nullptr;

            PrintColorVar(RED, "%p\n", *(text[line_number] + strf_number));
        }
        PrintColorVar(YELLOW, "\n%-2zu line clear: ", line_number);
        PrintColorVar(MAGENTA, "%-2zu", line_number);
        PrintColor(GREY, " | ");
        PrintColorVar(BLUE, "%p", text[line_number]);
        PrintColor(GREY, " -> ");

        free(text[line_number]);
        text[line_number] = nullptr;

        PrintColorVar(RED, "%p\n\n", text[line_number]);
    }
    PrintColor(YELLOW, "array clear: ");
    PrintColorVar(BLUE, "%p", text);
    PrintColor(GREY, " -> ");

    free(text);
    text = nullptr;

    PrintColorVar(RED, "%p\n\n", text);
}
