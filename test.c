#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// should only be called once
// returns a pseudo-random integer between 0 and RAND_MAX
int main()
{
    int div = 0;
    //scanf("%i", &div);
    srand(time(NULL));
    int r = (rand() % (10 - 1)) + 1;
    printf("tu numero 1 es %d\n", (rand() % (3 - 0)) + 0);
    printf("tu numero 2 es %d\n", (rand() % (3 - 0)) + 0);
    printf("tu numero 3 es %d\n", (rand() % (3 - 0)) + 0);
    printf("tu numero 4 es %d\n", (rand() % (3 - 0)) + 0);

    if((div%2)==0 ){
        printf("el numero es par la division es %d", div/2);
    }else{
        printf("el numero es inpar la division es %d", div/2+1);
    }

}
