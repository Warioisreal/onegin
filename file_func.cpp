#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "color_lib.h"
#include "filename_lib.h"


void GetFileName(char* filename, const char* def) {

    assert (filename != nullptr);
    assert (def     != nullptr);

    PrintColorVar(YELLOW, "\nEnter filename or press [enter] to use %s\n", def);

    if (fgets(filename, MAX_FILENAME_LEN, stdin) != nullptr) {

        size_t len = strnlen(filename, MAX_FILENAME_LEN);

        if (len == 1) {
            strncpy(filename, def, MAX_FILENAME_LEN);
        } else if (len > 0 && (filename[len - 1] == '\n')) {
            filename[len - 1] = '\0';
        }
    } else {
        PrintColor(RED, "\nfgets ERROR\n");
        PrintColor(YELLOW, "\nused default filename\n");
        strncpy(filename, def, MAX_FILENAME_LEN);
    }
    PrintColorVar(GREEN, "filename: %s\n", filename);
}
