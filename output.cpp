#include <stdio.h>
#include <assert.h>

#include "color_lib.h"

#include "output.h"


FILE* StartOutput(FILE** file, const char* name) {

    assert (file != nullptr);
    assert (name != nullptr);

    *file = fopen(name, "wb");

    if (*file == nullptr) {
        PrintColorVar(RED, "output file open error: \'%s\'\n", name);
        return nullptr;
    }
    return *file;
}

void EndOutput(FILE* file) {
    fclose(file);
}
