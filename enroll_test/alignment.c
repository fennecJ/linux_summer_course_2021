#include <stdint.h>
#include <stdio.h>
static inline uintptr_t align_up(uintptr_t sz, size_t alignment) {
    uintptr_t mask = alignment - 1;
    if ((alignment & mask) == 0) { /* power of two? */
        return (sz + mask) >> __builtin_ctz(alignment)
                                  << __builtin_ctz(alignment);
    }
    return (((sz + mask) / alignment) * alignment);
}

int main() {
    printf("%ld\n", align_up(120, 4));
    printf("%ld\n", align_up(121, 4));
    printf("%ld\n", align_up(122, 4));
    printf("%ld\n", align_up(123, 4));
}