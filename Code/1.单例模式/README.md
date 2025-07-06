# 1. 单例模式

## 1.1 概述

单例模式相当于一个全局变量，且只有一个实例。实现时单例模式实现的重点在于静态变量（一般命名为instance，类型为单例类的指针），静态变量相当于所有类共享一个变量，这个变量设置为private属性，为了防止用户建立多个实例破坏单例的初衷，将单例类的构造函数和析构函数都设置为private类型。然后提供一个静态函数（一般命名为GetInstance）来获取单例。

```mermaid
classDiagram
    Singleton: - s_instance
    Singleton: - Singleton()
    Singleton: + GetInstance()
```

一般的单例模式的代码形式是：

```cpp
class Singleton
{
public:
    static Singleton* GetInstance()
    {
        /* code: get instance */
    }
private:
    Singleton() {}
    ~Singleton() {}
    static Singleton* s_instance;
};
/* code: init static variable: instance */
```

## 1.2 实现

下面来看看单例模式的不同的实现方式。

### 1.2.1 饿汉式实现

饿汉式指在程序启动时就完成初始化，这需要一开始就分配一段内存来进行初始化。虽然可能初始化会带来一定的性能问题，但是多线程访问是安全的。核心代码的实现：

```cpp
class Singleton
{
public:
    static Singleton* GetInstance()
    {
        /* code: get instance */
        if (s_instance == nullptr)
        {
            s_instance = new Singleton();
        }
        return s_instance;
    }
private:
    Singleton() {}
    ~Singleton() {}
    static Singleton* s_instance;
};
Singleton* Singleton::s_instance = nullptr;
```

上面的实现中，instance是一个Singleton*类型，我们也可以让instance是一个Singleton类型：

```cpp
class Singleton
{
public:
    static Singleton* GetInstance()
    {
        /* code: get instance */
        return &s_instance;
    }
private:
    Singleton() {}
    ~Singleton() {}
    static Singleton s_instance;
};
Singleton* Singleton::s_instance;
```







### 1.2.2 懒汉式实现（非线程安全版）

懒汉式指在第一次获取实例时才进行初始化，也就是需要时才加载，这样可以提高性能。核心代码的实现：

```cpp
class Singleton
{
public:
    static Singleton* GetInstance()
    {
        /* code: get instance */
        if (s_instance == nullptr)
        {
            s_instance = new Singleton();
        }
        return s_instance;
    }
private:
    Singleton() {}
    ~Singleton() {}
    static Singleton* s_instance;
};
Singleton* Singleton::s_instance = nullptr;
```

懒汉式的实现是在需要的时候才初始化的，如果在多线程环境下可能会产生多个实例，这是有风险的。

### 1.2.3 懒汉式实现（线程安全版）

我们可以使用互斥锁双重检查来尝试解决上面的线程安全的问题。下面是使用lock_guard双重检查的代码：


```cpp
class Singleton
{
public:
    static Singleton* GetInstance()
    {
        /* code: get instance */
        if (s_instance == nullptr)
        {
            std::lock_guard<std::mutex> lock(s_mutex);
            if (s_instance == nullptr)
            {
                s_instance = new Singleton();
            }
        }
        return s_instance;
    }
private:
    Singleton() {}
    ~Singleton() {}
    static Singleton* s_instance;
    static mutex s_mutex;
};
Singleton* Singleton::s_instance = nullptr;
mutex Singleton::s_mutex;
```

我们也可以在静态函数里定义静态变量s_instance，C++保证了函数内的静态变量是线程安全的，所以我们可以直接在静态函数里返回s_instance：

```cpp
class Singleton
{
public:
    static Singleton* GetInstance()
    {
        static s_instance;
        return &s_instance;
    }
private:
    Singleton() {}
    ~Singleton() {}
};
```

上面返回的是s_instance的指针，我们也可以向外面返回引用：

```cpp
class Singleton
{
public:
    static Singleton& GetInstance()
    {
        static s_instance;
        return s_instance;
    }
private:
    Singleton() {}
    ~Singleton() {}
};
```

#  参考资料

1. [Singleton Pattern | C++ Design Patterns](https://www.geeksforgeeks.org/system-design/singleton-pattern-c-design-patterns/)
2. [Singleton Pattern & its implementation with C++](https://www.codeproject.com/Articles/1921/Singleton-Pattern-its-implementation-with-C-)




