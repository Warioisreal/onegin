#include <stdio.h>
#include <assert.h>

#include "color_lib.h"

#include "output.h"


FILE* StartOutput(FILE** file) {

    assert (file != nullptr);

    *file = fopen("output.txt", "w");

    if (*file == nullptr) {
        PrintColor(RED, "output file open error\n");
        return nullptr;
    }
    return *file;
}

void EndOutput(FILE* file) {
    fclose(file);
}
