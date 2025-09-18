#ifndef _LINE_STRUCT_H_
#define _LINE_STRUCT_H_

#include <stdio.h>

struct TextStorage {
    const char* const filename = nullptr;
    size_t filesize = 0;
    size_t lines_count = 0;
    struct Str* text = nullptr;
};

struct Str {
    char* ptr = nullptr;
    size_t str_size = 0;
};

#endif // _LINE_STRUCT_H_
