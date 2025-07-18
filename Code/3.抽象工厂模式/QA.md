# 1. 家具工厂（抽象工厂模式）

## 题目描述
小明家新开了两个工厂用来生产家具，一个生产现代风格的沙发和椅子，一个生产古典风格的沙发和椅子，现在工厂收到了一笔订单，请你帮他设计一个系统，描述订单需要生产家具的信息。

## 输入描述

输入的第一行是一个整数 N（1 ≤ N ≤ 100），表示订单的数量。 

接下来的 N 行，每行输入一个字符串，字符串表示家具的类型。家具类型分为 "modern" 和 "classical" 两种。

## 输出描述
对于每笔订单，输出字符串表示该订单需要生产家具的信息。 

modern订单会输出下面两行字符串 

modern chair 
modern sofa

classical订单会输出下面两行字符串 

classical chair 
classical sofa

## 输入示例

3
modern
classical
modern

## 输出示例

modern chair
modern sofa
classical chair
classical sofa
modern chair
modern sofa

## 提示信息
在示例中，工厂收到了3笔订单，其中有2笔要求生产modern风格，1笔要求生产classical风格。根据输入的类型，每次订单生产的家具信息被输出到控制台上。

# 2. 设计UML图参考

```mermaid
classDiagram
    class Chair {
        +virtual ~Chair()
        +virtual void ShowInfo() = 0
    }
    
    class ClassicChair {
        +void ShowInfo()
    }
    
    class ModernChair {
        +void ShowInfo()
    }
    
    class Sofa {
        +virtual ~Sofa()
        +virtual void ShowInfo() = 0
    }
    
    class ClassicSofa {
        +void ShowInfo()
    }
    
    class ModernSofa {
        +void ShowInfo()
    }
    
    class FurnitureFactory {
        +virtual ~FurnitureFactory()
        +virtual Chair* CreateChair() = 0
        +virtual Sofa* CreateSofa() = 0
    }
    
    class ClassicFurnitureFactory {
        +Chair* CreateChair()
        +Sofa* CreateSofa()
    }
    
    class ModernFurnitureFactory {
        +Chair* CreateChair()
        +Sofa* CreateSofa()
    }
    
    class FurnitureFactorySystem {
        -FurnitureFactory* classicFurnitureFactory
        -FurnitureFactory* modernFurnitureFactory
        +FurnitureFactorySystem()
        +FurnitureFactory* GetClassicFurnitureFactory()
        +FurnitureFactory* GetModernFurnitureFactory()
        +void CreateFurniture(FurnitureFactory*)
        +~FurnitureFactorySystem()
    }
    
    Chair <|-- ClassicChair : 继承
    Chair <|-- ModernChair : 继承
    Sofa <|-- ClassicSofa : 继承
    Sofa <|-- ModernSofa : 继承
    
    FurnitureFactory <|-- ClassicFurnitureFactory : 继承
    FurnitureFactory <|-- ModernFurnitureFactory : 继承
    
    ClassicFurnitureFactory --> ClassicChair : 创建
    ClassicFurnitureFactory --> ClassicSofa : 创建
    ModernFurnitureFactory --> ModernChair : 创建
    ModernFurnitureFactory --> ModernSofa : 创建
    FurnitureFactorySystem ..> FurnitureFactory : 使用
```

# 3. 代码实现说明
+ `abstractFactory.cpp`: 抽象工厂模式实现。

