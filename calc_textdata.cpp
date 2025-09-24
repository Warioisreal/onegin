#include <assert.h>

#include "calc_textdata.h"


size_t CalcLinesCount(size_t* lines_count, const char* data, const size_t size) {

    assert (lines_count != nullptr);
    assert (data        != nullptr);

    size_t count = 0;

    for (size_t i = 0; i < size; i++) {
        if (data[i] == '\n') {
            count++;
        }
    }
    count = (count + 1) / ENTERS_COUNT_IN_STRF * LINES_COUNT_IN_STRF;  // calculate correct count

    *lines_count = count;
    return count;
}
