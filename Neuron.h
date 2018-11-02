#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <cmath>
using namespace std;

struct Connection
{
    double weight;
    double deltaWeight;
};

class Neuron;
typedef vector<Neuron> Layer;

class Neuron
{
    public:
        Neuron(unsigned numOutputs, unsigned myIndex);
        void setOutputVal(double val);
        double getOutputVal(void) const;
        void feedForward(const Layer &prevLayer);
        void calcOutputGradients(double targetVal);
        void calcHiddenGradients(const Layer &nextLayer);
        void updateInputWeights(Layer &prevLayer);

    private:
        static double eta;
        static double alpha;
        static double transferFunction(double x);
        static double transferFunctionDerivative(double x);
        static double randomWeight(void);
        double sumDOW(const Layer &nextLayer) const;
        double m_outputVal;
        vector<Connection> m_outputWeights;
        unsigned m_myIndex;
        double m_gradient;

};

#endif