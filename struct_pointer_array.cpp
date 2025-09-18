#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "text_structs.h"

#include "calc_textdata.h"
#include "struct_pointer_array.h"
#include "work_with_buffer.h"


int MakeTextStorage(char** buf, struct TextStorage* data) {

    struct stat file_stat;
    if (stat(data -> filename, &file_stat) != 0) {
        printf("filesize read error\n");
        return 1;
    }

    data -> filesize = (size_t)(file_stat.st_size);

    FILE* file = fopen(data -> filename, "rb");
    if (file == nullptr) {
        printf("file open error\n");
        return 1;
    }

    *buf = (char*)calloc((data -> filesize) + 1, sizeof(char));

    if (*buf == nullptr) {
        printf("buffer calloc error\n");
        return 1;
    }

    size_t fread_filesize = fread(*buf, sizeof(char), data -> filesize, file);

    if (data -> filesize > fread_filesize) {
        if (feof(file)) {                       // if reached EOF before filesize
            printf("reached EOF\n");
        } else if (ferror(file)) {              // if had readfile error
            printf("file read error");
        } else {
            printf("filesize error: fread.size != filesize\n"); // if fread.size mistake
        }
        return 1;
    }

    fclose(file);

    data -> lines_count = CalcLinesCount(&(data -> lines_count), *buf, data -> filesize);

    data -> text = (struct Str*)calloc((data -> lines_count) + 1, sizeof(struct Str));

    if (data -> text == nullptr) {
        printf("data -> text calloc error\n");
        return 1;
    }

    BufferToText(&(data -> text), *buf);

    return 0;
}


void PrintText(const struct Str* text, const size_t lines_count) {
    for (size_t i = 0; i < lines_count; i++) {
        printf("%s\n", text[i].ptr);
    }
}


void PrintOrigText(const char* buf, const size_t lines_count) {
    for (size_t line = 0; line < lines_count / LINES_COUNT_IN_STRF * ENTERS_COUNT_IN_STRF - 1; line++) {
        while (*buf != 0) {
            printf("%c", *buf);
            buf++;
        }
        if (*buf == 0) {
            printf("\n");
            buf++;
        }
    }
}
