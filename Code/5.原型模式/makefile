SHELL = cmd.exe
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

tag_prototype = prototype

# 建造者模式
prototype: $(tag_prototype).o
	$(CXX) $(CXXFLAGS) -o $(tag_prototype) $(tag_prototype).o

.PHONY: clean
clean:
	del /F /Q *.exe *.o

.PHONY: all
all:
	make $(tag_prototype)

