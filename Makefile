OBJ = main.o Net.o Neuron.o Parser.o Digit.o NetManager.o SharedMem.o
DEBUG = -pthread -DDEBUG -g

network: $(OBJ)
	g++ $(DEBUG) -o network $(OBJ)

main.o: main.cpp defs.h
	g++ $(DEBUG) -c main.cpp

Net.o: Net.cpp Net.h Neuron.o 
	g++ $(DEBUG) -c Net.cpp

Neuron.o: Neuron.cpp Neuron.h
	g++ $(DEBUG) -c Neuron.cpp

Parser.o: Parser.cpp Parser.h
	g++ $(DEBUG) -c Parser.cpp

NetManager.o: NetManager.cpp NetManager.h
	g++ $(DEBUG) -c NetManager.cpp

SharedMem.o: SharedMem.cpp SharedMem.h
	g++ $(DEBUG) -c SharedMem.cpp

Digit.o: Digit.cpp Digit.h
	g++ $(DEBUG) -c Digit.cpp


clean:
	rm -rf $(OBJ) network