#ifndef DIGIT_H
#define DIGIT_H

#include <vector>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "defs.h"

using namespace std;

class Digit
{
    public:
        Digit();
        bool addPixel(const unsigned char pixel);
        Digit& operator=(const Digit &dig);

    private:
        int index; 
        unsigned char picture[PIXEL_COUNT];

        
};


#endif