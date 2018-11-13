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
        Digit& operator=(const Digit &dig);
        bool addPixel(const unsigned char pixel);
        vector<unsigned char> getPicture();
        void setLabel(const unsigned char label);
        void clean();

    private:
        int m_currentIndex; 
        vector<unsigned char> m_picture; // change this to a vector
        int m_label;        
};


#endif