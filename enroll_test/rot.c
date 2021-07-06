#include <stdbool.h>
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

#define __DECLARE_BITS_PRINT(bits, type)                                       \
    static inline type print##bits(const type v) {                             \
        type tmp = v;                                                          \
        bool stack[bits] = {0};                                                \
        for (int i = 0; i < bits; i++) {                                       \
            stack[i] = tmp & 1;                                                \
            tmp >>= 1;                                                         \
        }                                                                      \
        for (int i = bits - 1; i >= 0; i--)                                    \
            printf("%d", stack[i]);                                            \
        printf("\n");                                                          \
    }
#define DECLARE_BITS_PRINT(bits) __DECLARE_BITS_PRINT(bits, uint##bits##_t)

DECLARE_ROTATE(32);
DECLARE_BITS_PRINT(32);
int main() {
    print32(-8);
    print32(rotl32(-8, 5));

    print32(7);
    print32(rotl32(7, 4));
}