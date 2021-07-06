#include <stdio.h>
#include <unistd.h>

int main(void) {
    for (int i = 0; i < 4; i++) {
        fork();
        printf("-");
    }

    fflush(stdout);
    return 0;
}
/*
1     2               //1*2^1
2     8               //2*2^2
3     24              //3*2^3
4     64              //4*2^4
*/