#include <string.h>
#include <assert.h>

#include "line_struct.h"


void BufferToText(struct Str** text, char* buffer) {

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
    }
}
