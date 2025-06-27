SHELL = cmd.exe
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
objects1 = singleton1.o

final: $(objects1)
	$(CXX) $(CXXFLAGS) -o final $(objects1)

$(objects1): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	del /F /Q final.exe *.o
