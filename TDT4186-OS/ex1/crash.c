#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>
#include <unistd.h>

typedef struct {
  int x;
  int y;
  int z;
} Point;

Point *init(int elems) {
    int size = elems * sizeof(Point);

    // allocating memory using syscalls directly
	int fd = open("/dev/zero", O_RDWR);
    Point *array = mmap(0, size, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
	close(fd);

    if ((Point *) -1 == array) {
        printf("Could not map memory: %s\n", strerror(errno));
		return NULL;
    }    
	
	for (int i = 0; i < size*3; ++i) {
        array[i].x = i;
        array[i].y = -i;
        array[i].z = i*i;
    }

    return array;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: crash hello [NUM ELEMS]\n");
    }
    if (!strcmp(argv[1], "hello")) {
        fprintf(stderr, "Second argument must be hello\n");
    }

    char *p;
    int elems = strtol(argv[2], &p, 10);
    Point *points = init(elems);
    for(int i = 0; i < ((int)argv[2]); i++) {
        printf("Point(%d, %d, %d)\n",points[i].x, points[i].y, points[i].z);
    }
    return 0;
}
