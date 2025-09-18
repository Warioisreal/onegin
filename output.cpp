#include <stdio.h>
#include <assert.h>

#include "color_lib.h"

#include "output.h"


FILE* StartOutput(FILE** file) {

    assert (file != nullptr);

    const char* filename = "output.txt";

    *file = fopen(filename, "wb");

    if (*file == nullptr) {
        PrintColorVar(RED, "output file open error: \'%s\'\n", filename);
        return nullptr;
    }
    return *file;
}

void EndOutput(FILE* file) {
    fclose(file);
}
