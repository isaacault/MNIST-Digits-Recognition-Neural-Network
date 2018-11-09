OBJ = main.o Net.o Neuron.o Parser.o Digit.o NetManager.o

network: $(OBJ)
	g++ -o network $(OBJ)

main.o: main.cpp defs.h
	g++ -c main.cpp

Net.o: Net.cpp Net.h Neuron.o 
	g++ -c Net.cpp

Neuron.o: Neuron.cpp Neuron.h
	g++ -c Neuron.cpp

Parser.o: Parser.cpp Parser.h
	g++ -c Parser.cpp

NetManager.o: NetManager.cpp NetManager.h
	g++ -c NetManager.cpp

Digit.o: Digit.cpp Digit.h
	g++ -c Digit.cpp


clean:
	rm -rf $(OBJ) network