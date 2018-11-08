OBJ = main.o Net.o Neuron.o Parser.o

network: $(OBJ)
	g++ -o network $(OBJ)

main.o: main.cpp
	g++ -c main.cpp

Net.o: Net.cpp Net.h Neuron.o 
	g++ -c Net.cpp

Neuron.o: Neuron.cpp Neuron.h
	g++ -c Neuron.cpp

Parser.o: Parser.cpp Parser.h
	g++ -c Parser.cpp


clean:
	rm -rf $(OBJ) network