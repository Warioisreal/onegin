#ifndef _RECTANGLE_ARRAY_H_
#define _RECTANGLE_ARRAY_H_


char* CreateRectArr(char* text,
                    const size_t line_size,
                    const size_t strf_count,
                    const size_t strf_size,
                    const char* filename);

void PrintRectArr(char* text,
                  const size_t line_size,
                  const size_t strf_count,
                  const size_t strf_size);

void SortRectArr(char* text,
                 const size_t line_size,
                 const size_t strf_count,
                 const size_t strf_size);

#endif // _RECTANGLE_ARRAY_H_
