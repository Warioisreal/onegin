#ifndef _TEXT_STRUCTS_H_
#define _TEXT_STRUCTS_H_

#include <stdio.h>


struct LineParams {
    char* ptr = nullptr;
    size_t str_size = 0;
};

struct TextStorage {
    const char* filename = nullptr;
    size_t filesize = 0;
    size_t lines_count = 0;
    struct LineParams* text = nullptr;
};

#endif // _TEXT_STRUCTS_H_
