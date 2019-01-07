#ifndef DEFS_H
#define DEFS_H

#define MNIST_DATA_DIRECTORY "MNIST_data/"

#define PIXEL_COUNT 28*28
#define OUTPUT_RANGE 10

#ifdef DEBUG
#include <unistd.h>
#define DEBUG_PRINT(x) cout << "PID " << getpid() << ": " << x << endl;
#else
#define DEBUG_PRINT(x) do {} while (0)
#endif

#endif