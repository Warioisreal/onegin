#include <string.h>
#include <assert.h>

#include "text_structs.h"

#include "work_with_buffer.h"


int BufferToText(struct LineParams** text, char* buffer, const size_t buf_size) {

    assert (text != nullptr);
    assert (buffer != nullptr);

    char* str_start = buffer;
    char* str_end = strchr(str_start, '\n');

    size_t pos = 0;

    size_t dif = 0;
    while (str_end != nullptr) {
        dif = (size_t)(str_end - str_start);

        if (dif > 1) {
            (*text)[pos] = {str_start, dif};
            pos++;
        }
        *str_end = '\0';  // replace: \n -> \0
        str_start = str_end + 1;
        str_end   = strchr(str_start, '\n');

        if (str_end > &buffer[buf_size - 1]) { return 0; }
    }
    return 1;
}


void FreeBuffer(char** buffer) {

    assert (buffer != nullptr);

    free(*buffer);
    *buffer = nullptr;
}

