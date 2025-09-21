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

    const char* file_name = data->filename;

    struct stat file_stat;
    if (stat(file_name, &file_stat) != 0) {
        PrintColor(RED, "filesize read error\n");
        return 1;
    }

    data->filesize = (size_t)(file_stat.st_size);


    size_t file_size = data->filesize;

    FILE* file = fopen(file_name, "rb");
    if (file == nullptr) {
        PrintColorVar(RED, "file open error: \'%s\'\n", file_name);
        return 1;
    }

    char* buf_ = (char*)calloc(file_size + 1, sizeof(char));
    if (buf_ == nullptr) {
        PrintColor(RED, "buffer calloc error\n");
        return 1;
    }
    *buf = buf_;

    size_t fread_filesize = fread(*buf, sizeof(char), file_size, file);
    if (file_size > fread_filesize) {
        if (feof(file)) {                       // if reached EOF before filesize
            PrintColor(RED, "reached EOF\n");
        } else if (ferror(file)) {              // if had readfile error
            PrintColor(RED, "file read error\n");
        } else {
            PrintColor(RED, "filesize error: fread.size != filesize\n"); // if fread.size mistake
        }
        return 1;
    }

    fclose(file);

    data->lines_count = CalcLinesCount(&(data->lines_count), *buf, file_size);

    struct LineParams* text_ = (struct LineParams*)calloc((data->lines_count) + 1, sizeof(struct LineParams));
    if (text_ == nullptr) {
        PrintColor(RED, "data -> text calloc error\n");
        return 1;
    }
    data->text = text_;

    int transfer_result = BufferToText(&(data->text), *buf, file_size);
    if (transfer_result == 0) {
        PrintColor(RED, "transfer_result error\n");
        return 1;
    }

    return 0;
}


void PrintText(FILE* file, const struct LineParams* text, const size_t lines_count) {

    assert (file != nullptr);
    assert (text != nullptr);

    fprintf(file, "-------------------------------\n");
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
            fputc(*buf, file);
            buf++;
        }
        if (*buf == 0) {
            fputc('\n', file);
            buf++;
        }
    }
    fprintf(file, "-------------------------------\n");
}


void DestroyTextStorage(struct TextStorage* data) {

    assert (data != nullptr);

    data->filename    = nullptr;
    data->filesize    = 0;
    data->lines_count = 0;

    free(data->text);

    data->text = nullptr;
}
