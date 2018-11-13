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
        vector<double> getPicture() const;
        void setLabel(const unsigned char label);
        vector<double> getLabel();
        void clean();

    private:
        int m_currentIndex; 
        vector<double> m_picture; // change this to a vector
        vector<double> m_label;        
};


#endif