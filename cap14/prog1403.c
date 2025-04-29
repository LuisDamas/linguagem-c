#include <stdio.h>

int global_variable; // Uninitialized global variable

int main() {
    static int static_variable; // Uninitialized static variable
    printf("Hello, world!\n");
    return 0;
}
