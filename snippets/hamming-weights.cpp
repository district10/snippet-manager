#include <stdio.h>

int popcount_4(int x) {
    int count;
    for (count=0; x; count++)
        x &= x-1;
    return count;
}

int main(int argc, char **argv)
{
    int i = 0;

    scanf("%d", &i);
    do {
        printf("%d has %d '1's.\n", i, popcount_4(i));
    } while( 1 == scanf("%d", &i) );

    return 0;
}
