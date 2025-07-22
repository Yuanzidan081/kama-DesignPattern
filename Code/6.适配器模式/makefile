SHELL = cmd.exe
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

tag_adapter = adapter

# 建造者模式
adapter: $(tag_adapter).o
	$(CXX) $(CXXFLAGS) -o $(tag_adapter) $(tag_adapter).o

.PHONY: clean
clean:
	del /F /Q *.exe *.o

.PHONY: all
all:
	make $(tag_adapter)

