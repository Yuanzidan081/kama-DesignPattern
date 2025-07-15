SHELL = cmd.exe
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

tag_abstractFactory = abstractFactory

# 抽象工厂方法模式
abstractFactory: $(tag_abstractFactory).o
	$(CXX) $(CXXFLAGS) -o $(tag_abstractFactory) $(tag_abstractFactory).o

$(objects_lazy): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	del /F /Q *.exe *.o

.PHONY: all
all:
	make $(tag_abstractFactory)

