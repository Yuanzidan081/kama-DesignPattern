SHELL = cmd.exe
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

tag_hungry_ptr = singleton_hungry_ptr
tag_hungry_noPtr = singleton_hungry_noPtr
tag_lazy_unsafe = singleton_lazy_unsafe
tag_lazy_safe_doubleCheck = singleton_lazy_safe_doubleCheck
tag_lazy_safe_funcStaticVariablePtr = singleton_lazy_safe_funcStaticVariablePtr
tag_lazy_safe_funcStaticVariableRef = singleton_lazy_safe_funcStaticVariableRef

# 饿汉式单例模式-static变量使用指针
singleton_hungry_ptr: $(tag_hungry_ptr).o
	$(CXX) $(CXXFLAGS) -o $(tag_hungry_ptr) $(tag_hungry_ptr).o

# 饿汉式单例模式-static变量不使用指针
singleton_hungry_noPtr: $(tag_hungry_noPtr).o
	$(CXX) $(CXXFLAGS) -o $(tag_hungry_noPtr) $(tag_hungry_noPtr).o

# 懒汉式单例模式-线程不安全版
singleton_lazy_unsafe: $(tag_lazy_unsafe).o
	$(CXX) $(CXXFLAGS) -o $(tag_lazy_unsafe) $(tag_lazy_unsafe).o

# 懒汉式单例模式-线程安全版-双重检查锁
singleton_lazy_safe_doubleCheck: $(tag_lazy_safe_doubleCheck).o
	$(CXX) $(CXXFLAGS) -o $(tag_lazy_safe_doubleCheck) $(tag_lazy_safe_doubleCheck).o

# 懒汉式单例模式-static变量使用在函数内-指针
singleton_lazy_funcStaticVariablePtr: $(tag_lazy_funcStaticVariablePtr).o
	$(CXX) $(CXXFLAGS) -o $(tag_lazy_funcStaticVariablePtr) $(tag_lazy_funcStaticVariablePtr).o

# 懒汉式单例模式-static变量使用在函数内-引用
singleton_lazy_funcStaticVariableRef: $(tag_lazy_funcStaticVariableRef).o
	$(CXX) $(CXXFLAGS) -o $(tag_lazy_funcStaticVariableRef) $(tag_lazy_funcStaticVariableRef).o



$(objects): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	del /F /Q *.exe *.o

.PHONY: all
all:
	make $(tag_hungry_ptr)
	make $(tag_hungry_noPtr)
	make $(tag_lazy_unsafe)
	make $(tag_lazy_safe_doubleCheck)
	make $(tag_lazy_safe_funcStaticVariablePtr)
	make $(tag_lazy_safe_funcStaticVariableRef)

