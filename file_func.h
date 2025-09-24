#ifndef _FILE_FUNC_H_
#define _FILE_FUNC_H_

const size_t MAX_FILENAME_LEN = 128;

static const char* DEFAULT_FILENAME_INPUT  = "onegin.txt";
static const char* DEFAULT_FILENAME_OUTPUT = "output.txt";


void GetFileName(char* filename, const char* def);

#endif // _FILE_FUNC_H_
