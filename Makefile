OBJ = main.o Net.o Neuron.o Parser.o Digit.o NetManager.o SharedMem.o
FLAGS = -pthread -g

network: $(OBJ)
	g++ $(FLAGS) -o network $(OBJ)

main.o: main.cpp defs.h
	g++ $(FLAGS) -c main.cpp

Net.o: Net.cpp Net.h Neuron.o 
	g++ $(FLAGS) -c Net.cpp

Neuron.o: Neuron.cpp Neuron.h
	g++ $(FLAGS) -c Neuron.cpp

Parser.o: Parser.cpp Parser.h
	g++ $(FLAGS) -c Parser.cpp

NetManager.o: NetManager.cpp NetManager.h
	g++ $(FLAGS) -c NetManager.cpp

SharedMem.o: SharedMem.cpp SharedMem.h
	g++ $(FLAGS) -c SharedMem.cpp

Digit.o: Digit.cpp Digit.h Array.h
	g++ $(FLAGS) -c Digit.cpp


clean:
	rm -rf $(OBJ) network