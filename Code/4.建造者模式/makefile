SHELL = cmd.exe
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

tag_builder = builder

# 建造者模式
builder: $(tag_builder).o
	$(CXX) $(CXXFLAGS) -o $(tag_builder) $(tag_builder).o

$(objects): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


.PHONY: clean
clean:
	del /F /Q *.exe *.o

.PHONY: all
all:
	make $(tag_builder)

