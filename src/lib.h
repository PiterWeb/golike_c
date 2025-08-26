#ifndef GOLIKE_C

#define GOLIKE_C 1

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "macro_overloading.h"

typedef unsigned int uint;
typedef char byte;

#define Array(TYPE) \
    struct {\
        TYPE* value;\
        size_t len;\
    }

#define new(...) VA_SELECT(new, __VA_ARGS__ )
#define new_1(TYPE) {.value = (TYPE*)(malloc(sizeof(TYPE))), .len = 1}
#define new_2(TYPE, LEN) {.value = (TYPE*)(malloc(sizeof(TYPE) * (LEN))), .len = (LEN)}

#define free_array(ARR) do {\
    free((ARR).value);\
    (ARR).value = NULL;\
    (ARR).len = (size_t)-1;\
} while(0)

#define append(NEW_ARR, ARR, VAL) do {\
    (NEW_ARR) = new_2(__typeof__((ARR).value[0]), (ARR).len + 1);\
    if ((ARR).len > 0) {\
        memcpy((NEW_ARR).value, (ARR).value, (size_t)(ARR).len * sizeof((ARR).value[0]));\
    }\
    (NEW_ARR).value[(NEW_ARR).len - 1] = (VAL);\
} while(0)

#endif