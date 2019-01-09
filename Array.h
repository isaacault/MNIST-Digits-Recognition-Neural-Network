#ifndef ARRAY_H
#define ARRAY_H

/******************************************************************************
 * Array.h is used as a replacement for vectors in the IPC of this network. 
 * This was done to eliminate the pointers and the issues that follow with 
 * them when using vectors in shared memory.
******************************************************************************/

#include "defs.h"
#include <unistd.h>
#include <sys/mman.h>

using namespace std;

template <class T>
class Array
{
    public:
        Array(int size) : m_size(size) {
            DEBUG_PRINT("Array constructor");
            m_index = 0;
            void * address =  mmap(NULL, sizeof(T)*size, 
                                    PROT_READ|PROT_WRITE, 
                                    MAP_SHARED|MAP_ANONYMOUS, -1, 0);
            m_ints = new(address) T[m_size];
        }


        T getInt(int index){ return m_ints[index]; }
        void push_back(const T a) { m_ints[m_index++] = a; }
        T* getInts() { return m_ints; }
        int size() const { return m_index; }
        void clear() { 
            m_index = 0;
        }

        T& operator[](unsigned int i) {
            if (i < 0 || i > m_index - 1) { 
                exit(0);
            }
            return m_ints[i];
        }

        const T& operator[](unsigned int i) const {
            if (i < 0 || i > m_index - 1) { 
                exit(0);
            }
            return m_ints[i];
        }

        Array& operator=(const Array<T> &arr) {
            if (m_size != arr.m_size) {
                exit(0);
            } else {
                memcpy(m_ints, arr.m_ints, m_size*sizeof(*m_ints));
                m_index = arr.m_index;
            }
            return *this;
        }
/*
        operator vector<T> const {
            return vector<T>(m_ints, m_ints[m_index - 1] - m_ints[0] / sizeof(T) ); 
        }
*/ // want to learn how to do this (implicit conversion)

    private:
        T * m_ints;
        int m_index;
        const int m_size;

};

#endif
