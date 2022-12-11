#include "ligra.h"

template <class vertex>
void Compute(graph<vertex>& GA, commandLine P) {
    long n = GA.n, num = 1L << 24;
    
    srand(time(NULL));
    long* buff = newA(long, num);
    for(int i = 0; i < num; i++)
    {
        long v = rand() * n / RAND_MAX;
        while(!GA.V[v].getOutDegree() && !GA.V[v].getInDegree())
            v = rand() * n / RAND_MAX;
        buff[i] = v;
    }

    char* fname = "randSample.bin";
    int fd = open(fname, O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("open");
        exit(-1);
    }
    write(fd, buff, sizeof(long) * num);
    free(buff);
}
