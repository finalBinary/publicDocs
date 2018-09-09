#include <stdio.h>


int main()
{
    extern start();

    printf("Hello?\n");
    start();
    return 0;
}
