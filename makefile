# build nfa from nfa.cpp
all: nfa.cpp
	g++ -g -Wall -o nfa nfa.cpp

clean:
	$(RM) nfa
