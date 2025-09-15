#ifndef _POINTER_ARRAY_H_
#define _POINTER_ARRAY_H_


char*** CreatePtrArr(char*** text,
                     const size_t strf_count,
                     const size_t strf_size,
                     const char* filename);

void PrintPtrArr(char*** text,
                 const size_t strf_count,
                 const size_t strf_size);

void SortPtrArr(char*** text,
                const size_t strf_count,
                const size_t strf_size);

void ClearMemArr(char*** text,
                 const size_t strf_count,
                 const size_t strf_size);

#endif // _POINTER_ARRAY_H_
