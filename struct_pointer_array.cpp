#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <assert.h>

#include "text_structs.h"
#include "color_lib.h"

#include "calc_textdata.h"
#include "struct_pointer_array.h"
#include "work_with_buffer.h"


int MakeTextStorage(char** buf, struct TextStorage* data) {

    assert (buf  != nullptr);
    assert (data != nullptr);

    struct stat file_stat;
    if (stat(data -> filename, &file_stat) != 0) {
        PrintColor(RED, "filesize read error\n");
        return 1;
    }

    data -> filesize = (size_t)(file_stat.st_size);

    FILE* file = fopen(data -> filename, "rb");
    if (file == nullptr) {
        PrintColor(RED, "file open error\n");
        return 1;
    }

    *buf = (char*)calloc((data -> filesize) + 1, sizeof(char));

    if (*buf == nullptr) {
        PrintColor(RED, "buffer calloc error\n");
        return 1;
    }

    size_t fread_filesize = fread(*buf, sizeof(char), data -> filesize, file);

    if (data -> filesize > fread_filesize) {
        if (feof(file)) {                       // if reached EOF before filesize
            PrintColor(RED, "reached EOF\n");
        } else if (ferror(file)) {              // if had readfile error
            PrintColor(RED, "file read error");
        } else {
            PrintColor(RED, "filesize error: fread.size != filesize\n"); // if fread.size mistake
        }
        return 1;
    }

    fclose(file);

    data -> lines_count = CalcLinesCount(&(data -> lines_count), *buf, data -> filesize);

    data -> text = (struct Str*)calloc((data -> lines_count) + 1, sizeof(struct Str));

    if (data -> text == nullptr) {
        PrintColor(RED, "data -> text calloc error\n");
        return 1;
    }

    int transfer_result = BufferToText(&(data -> text), *buf, data -> filesize);

    if (transfer_result == 0) {
        PrintColor(RED, "transfer_result error\n");
        return 1;
    }

    return 0;
}


void PrintText(FILE* file, const struct Str* text, const size_t lines_count) {

    assert (file != nullptr);
    assert (text != nullptr);

    fprintf(file, "---------sorted text-----------\n");
    for (size_t i = 0; i < lines_count; i++) {
        fprintf(file, "%s\n", text[i].ptr);
    }
    fprintf(file, "-------------------------------\n");
    fprintf(file, "\n");
}


void PrintOrigText(FILE* file, const char* buf, const size_t lines_count) {

    assert (buf  != nullptr);
    assert (file != nullptr);

    fprintf(file, "---------original text---------\n");
    for (size_t line = 0; line < lines_count / LINES_COUNT_IN_STRF * ENTERS_COUNT_IN_STRF - 1; line++) {
        while (*buf != 0) {
            fprintf(file, "%c", *buf);
            buf++;
        }
        if (*buf == 0) {
            fprintf(file, "\n");
            buf++;
        }
    }
    fprintf(file, "-------------------------------\n");
}


void DestroyTextStorage(struct TextStorage* data, size_t size) {

    assert (data != nullptr);

    free(data -> text);

    memset(data, 0, size);
}
