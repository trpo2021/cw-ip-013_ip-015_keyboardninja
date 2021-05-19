CXX = g++
CFLAG = -Wall -Werror
CPPFLAGS = -MMD
LDLIBS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

all: ./bin/ninja

./bin/ninja:  ./obj/src/ninja/main.o ./obj/src/libninja/libninja.a
	$(CXX) $(CFLAG)   obj/src/ninja/main.o obj/src/libninja/libninja.a -o bin/ninja $(LDLIBS)

./obj/src/ninja/main.o: src/ninja/main.cpp
	$(CXX) $(CFLAG) $(CPPFLAGS) -o obj/src/ninja/main.o  -c  -I src/ src/ninja/main.cpp $(LDLIBS)

./obj/src/libninja/libninja.a: ./obj/src/libninja/readingfile.o
	ar rcs obj/src/libninja/libninja.a  obj/src/libninja/readingfile.o

./obj/src/libninja/readingfile.o: src/libninja/readingfile.cpp
	$(CXX) $(CFLAG) $(CPPFLAGS)  -o obj/src/libninja/readingfile.o -c -I src/ src/libninja/readingfile.cpp



-include obj/src/libninja/readingfile.d obj/src/ninja/main.d

.PHONY: clean
clean:
	rm ./bin/ninja ./obj/src/libninja/*.o ./obj/src/ninja/*.o
	rm ./obj/src/libninja/*.d ./obj/src/ninja/*.d ./obj/src/libninja/libninja.a
