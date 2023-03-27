#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char* argv[])
{
  if (argc < 2) {
    printf("Usage: vatopa virtual_address [pid]\n");
    exit(1);
  }

  if (argc == 3) {
    printf("0x%x\n", va2pa(atoi(argv[1]), atoi(argv[2])));
  } else {
    printf("0x%x\n", va2pa(atoi(argv[1]), getpid()));
  }

  exit(0);
}
