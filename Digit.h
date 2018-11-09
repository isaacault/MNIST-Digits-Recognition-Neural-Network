#ifndef DIGIT_H
#define DIGIT_H

#include <vector>
#include <iostream>
#include "defs.h"

using namespace std;

class Digit
{
    public:
        Digit();
        void pushBack(const unsigned char pixel);
        bool isReady();
        
    private:
        vector<unsigned char> m_picture;
        bool ready;
};


#endif