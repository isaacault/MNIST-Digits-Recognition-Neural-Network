#ifndef DIGIT_H
#define DIGIT_H

#include <vector>
#include <iostream>
#include <semaphore.h>
#include "defs.h"

using namespace std;

class Digit
{
    public:
        Digit();
        void pushBack(const unsigned char pixel);
        
    private:
        vector<unsigned char> m_picture;
        
};


#endif