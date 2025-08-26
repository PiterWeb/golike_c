#include "../src/lib.h"
#include <stdio.h>

int main() {
    byte hola = 'c';
    
    Array(byte) arr = new(byte, 4);
    printf("Arr len: %d\n", arr.len);
    
    for (int i = 0; i < arr.len; i++) {
        arr.value[i] = 4;
    }
    
    for (int i = 0; i < arr.len; i++) {
        printf("Arr[%d] = %d\n", i, arr.value[i]);
    }
    
    
    
    free_array(arr);
}