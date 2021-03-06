#ifndef NET_H
#define NET_H

/******************************************************************************
 * Net is used to manage the neurons closely. This includes forward
 * propogation, backward propogation, and interacting with the neurons on any 
 * level.
******************************************************************************/


#include <vector>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include "Neuron.h"
#include "defs.h"
#include "Array.h"


class Net
{
    friend ostream& operator<<(ostream& output, Net& n);
    
    public:
        Net(const vector<unsigned> &topology);
        void feedForward(const Array<double> &inputVals);
        void backProp(const Array<double> &targetVals);
        void getResults(Array<double> &resultVals) const;

    private:
        vector<Layer> m_layers;
        double m_error;
        double m_recentAverageError;
        double m_recentAverageSmoothingFactor;

};

#endif