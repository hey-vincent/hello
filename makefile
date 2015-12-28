
#build helloworld
helloworld = ./src/helloworld.h ./src/helloworld.cpp
CXXFLAGS = -Isrc -lpthread
RM = rm -f

build: main.o helloworld.o
	clear
	g++ -o main.out main.o helloworld.o $(CXXFLAGS) 
	./main.out



helloworld.o:$(helloworld)
	g++ -c -o helloworld.o ./src/helloworld.cpp

main.o: src/helloworld.h main.cpp
	g++ -c -o main.o main.cpp -lpthread


clean:
	$(RM) main.o  helloworld.o main.out
