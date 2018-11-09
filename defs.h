#ifndef DEFS_H
#define DEFS_H

#define MNIST_DATA_DIRECTORY "MNIST"

#ifdef DEBUG
#define DEBUG_PRINT(x) cout << x << endl;
#else
#define DEBUG_PRINT(x) do {} while (0)
#endif

#endif