#ifndef _STRUCT_POINTER_ARRAY_H_
#define _STRUCT_POINTER_ARRAY_H_


int MakeTextStorage(char** buf, struct TextStorage* data);
void PrintText(FILE* file, const struct LineParams* text, const size_t lines_count);
void PrintOrigText(FILE* file, const char* buf, const size_t lines_count);
void DestroyTextStorage(struct TextStorage* data);

#endif // _STRUCT_POINTER_ARRAY_H_
