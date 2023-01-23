#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    (argc > 1) ? printf("Hello %s, nice to meet you!\n", argv[1]) : printf("Hello World\n");
    return 0;
}
