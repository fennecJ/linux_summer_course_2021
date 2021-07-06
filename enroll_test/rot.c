#include <stdint.h>
#include <stdio.h>
#define __DECLARE_ROTATE(bits, type)                                           \
    static inline type rotl##bits(const type v, int c) {                       \
        const int mask = (bits) - (1);                                         \
        c &= mask;                                                             \
                                                                               \
        return ((v << c) | (v >> (bits - c)));                                 \
    }
#define DECLARE_ROTATE(bits) __DECLARE_ROTATE(bits, uint##bits##_t)
DECLARE_ROTATE(32);
int main() {}