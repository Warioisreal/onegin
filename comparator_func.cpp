#include <ctype.h>
#include <assert.h>

#include "text_structs.h"

int Comparator(const void* ptr1, const void* ptr2) {

    assert (ptr1 != nullptr);
    assert (ptr2 != nullptr);

    const struct Str* line1 = (const struct Str*)(ptr1);
    const struct Str* line2 = (const struct Str*)(ptr2);

    char* str1 = line1 -> ptr;
    char* str2 = line2 -> ptr;
    int size1 = (int)(line1 -> str_size);
    int size2 = (int)(line2 -> str_size);

    int pos1 = 0;
    int pos2 = 0;

    int cmpres = 0;

    while (pos1 < size1 && pos2 < size2) {
        while (!isalpha(*(str1 + pos1)) && pos1 < size1) { pos1++; }
        while (!isalpha(*(str2 + pos2)) && pos2 < size2) { pos2++; }

        cmpres = str1[pos1] - str2[pos2];

        if (cmpres != 0) { return cmpres; }
        else {
            pos1++;
            pos2++;
        }
    }
    return cmpres;
}


int ReverseComparator(const void* ptr1, const void* ptr2) {

    assert (ptr1 != nullptr);
    assert (ptr2 != nullptr);

    const struct Str* line1 = (const struct Str*)(ptr1);
    const struct Str* line2 = (const struct Str*)(ptr2);

    char* str1 = line1 -> ptr;
    char* str2 = line2 -> ptr;
    int pos1 = (int)(line1 -> str_size);
    int pos2 = (int)(line2 -> str_size);

    int cmpres = 0;

    while (pos1 >= 0 && pos2 >= 0) {
        while (!isalpha(*(str1 + pos1)) && pos1 >= 0) { pos1--; }
        while (!isalpha(*(str2 + pos2)) && pos2 >= 0) { pos2--; }

        cmpres = str1[pos1] - str2[pos2];

        if (cmpres != 0) { return cmpres; }
        else {
            pos1--;
            pos2--;
        }
    }
    return cmpres;
}
