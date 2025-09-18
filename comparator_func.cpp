#include <ctype.h>

#include "line_struct.h"


int ReverseComparator(const void* ptr1, const void* ptr2) {
    const struct OneginStr* line1 = (const struct OneginStr*)(ptr1);
    const struct OneginStr* line2 = (const struct OneginStr*)(ptr2);

    char* str1 = line1 -> ptr;
    char* str2 = line2 -> ptr;
    int pos1 = (int)(line1 -> str_size);
    int pos2 = (int)(line2 -> str_size);

    int cmpres = 0;

    while (pos1 >= 0 && pos2 >= 0) {
        while (!isalpha(*(str1 + pos1)) && pos1 >= 0) { pos1--; }
        while (!isalpha(*(str2 + pos2)) && pos2 >= 0) { pos2--; }

        cmpres = *(str1 + pos1) - *(str2 + pos2);

        if (cmpres != 0) { return cmpres; }
        else {
            pos1--;
            pos2--;
        }
    }
    return cmpres;
}
