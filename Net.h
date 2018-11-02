#ifndef NET_H
#define NET_H

#include <vector>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include "Neuron.h"


class Net
{
    public:
        Net(const vector<unsigned> &topology);
        void feedForward(const vector<double> &inputVals);
        void backProp(const vector<double> &targetVals);
        void getResults(vector<double> &resultVals) const;

    private:
        vector<Layer> m_layers;
        double m_error;
        double m_recentAverageError;
        double m_recentAverageSmoothingFactor;

};

#endif