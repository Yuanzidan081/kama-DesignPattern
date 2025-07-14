SHELL = cmd.exe
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

tag_factory = factory

# 工厂方法模式
factory: $(tag_factory).o
	$(CXX) $(CXXFLAGS) -o $(tag_factory) $(tag_factory).o

$(objects_lazy): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	del /F /Q *.exe *.o

.PHONY: all
all:
	make $(tag_factory)

