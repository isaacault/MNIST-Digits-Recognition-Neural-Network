#ifndef DEFS_H
#define DEFS_H

#define MNIST_DATA_DIRECTORY "MNIST"

#ifdef DEBUG
#include <unistd.h>
#define DEBUG_PRINT(x) cout << "PID " << getpid() << ": " << x << endl;
#else
#define DEBUG_PRINT(x) do {} while (0)
#endif

#endif