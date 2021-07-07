#include <stdio.h>
#include <unistd.h>

int main(void) {
    for (int i = 0; i < 12; i++) {
        fork();
        puts("-");
    }

    fflush(stdout);
    return 0;
}
/*    printf:
1     2               //1*2^1
2     8               //2*2^2
3     24              //3*2^3
4     64              //4*2^4
*/

/*    puts:
1     4               //1*2^2
2     16              //2*2^3
3     48              //3*2^4
4     128             //4*2^5
*/