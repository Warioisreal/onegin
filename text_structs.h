#ifndef _TEXT_STRUCTS_H_
#define _TEXT_STRUCTS_H_

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

#endif // _TEXT_STRUCTS_H_
