OBJ = main.o Net.o Neuron.o

network: $(OBJ)
	g++ -o network $(OBJ)

main.o: main.cpp
	g++ -c main.cpp

Net.o: Net.cpp Net.h Neuron.o 
	g++ -c Net.cpp

Neuron.o: Neuron.cpp Neuron.h
	g++ -c Neuron.cpp


clean:
	rm -rf $(OBJ) network