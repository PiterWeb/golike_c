#ifndef GOLIKE_C

#define GOLIKE_C 1

#include <stdint.h>
#include <stdlib.h>
#include "macro_overloading.h"

typedef unsigned int uint;
typedef char byte;

#define Array(TYPE) \
    struct {\
        TYPE* value;\
        int len;\
        unsigned int cap;\
    }

#define new(...) VA_SELECT(new, __VA_ARGS__ )
#define new_1(TYPE) {.value = (TYPE*)(malloc(sizeof(TYPE))), .len = 1}
#define new_2(TYPE, LEN) {.value = (TYPE*)(malloc(sizeof(TYPE))), .len = LEN}

#define free_array(ARR) \
    free(ARR.value);\
    ARR.len = -1;

inline int append(void *arr) {
    Array(void) temp_arr = arr;
    return 0;
} 

#define append(ARR, ...) \
    do {\
        \
    } while(0)

#endif