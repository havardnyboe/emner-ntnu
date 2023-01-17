#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2)
    {
        printf("Hello World\n");
    }
    else
    {
        printf("Hello %s, nice to meet you!\n", argv[1]);
    }
    return 0;
}
