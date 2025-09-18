#ifndef _CALC_TEXTDATA_H_
#define _CALC_TEXTDATA_H_

#include <ctype.h>

static const size_t LINES_COUNT_IN_STRF = 14;
static const size_t ENTERS_COUNT_IN_STRF = 15;


size_t CalcLinesCount(size_t* lines_count, const char* data, const size_t size);


#endif // _CALC_TEXTDATA_H_
