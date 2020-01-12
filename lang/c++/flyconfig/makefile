all:	$(patsubst %.cpp, %.out, $(wildcard *.cpp))

%.out:  %.cpp
	g++ $< -o $@ -std=c++11 -pthread
