#include <iostream>
using namespace std;

class Chair
{
public:
    virtual ~Chair() = default;
    virtual void ShowInfo() = 0;
};

class ClassicChair : public Chair
{
public:
    virtual void ShowInfo() override
    {
        cout << "classic chair" << endl;
    }
};

class ModernChair : public Chair
{
public:
    virtual void ShowInfo() override
    {
        cout << "modern chair" << endl;
    }
};

class Sofa
{
public:
    virtual ~Sofa() = default;
    virtual void ShowInfo() = 0;
};

class ClassicSofa : public Sofa
{
public:
    virtual void ShowInfo() override
    {
        cout << "classic sofa" << endl;
    }
};

class ModernSofa : public Sofa
{
public:
    virtual void ShowInfo() override
    {
        cout << "modern sofa" << endl;
    }
};

class FurnitureFactory
{
public:
    virtual ~FurnitureFactory() = default;
    virtual Chair *CreateChair() = 0;
    virtual Sofa *CreateSofa() = 0;
};

class ClassicFurnitureFactory : public FurnitureFactory
{
public:
    virtual Chair *CreateChair() override
    {
        return new ClassicChair();
    }

    virtual Sofa *CreateSofa() override
    {
        return new ClassicSofa();
    }
};

class ModernFurnitureFactory : public FurnitureFactory
{
public:
    virtual Chair *CreateChair() override
    {
        return new ModernChair();
    }

    virtual Sofa *CreateSofa() override
    {
        return new ModernSofa();
    }
};

class FurnitureFactorySystem
{
private:
    FurnitureFactory *classicFurnitureFactory;
    FurnitureFactory *modernFurnitureFactory;

public:
    FurnitureFactorySystem()
    {
        classicFurnitureFactory = new ClassicFurnitureFactory();
        modernFurnitureFactory = new ModernFurnitureFactory();
    }
    FurnitureFactory *GetClassicFurnitureFactory()
    {
        return classicFurnitureFactory;
    }
    FurnitureFactory *GetModernFurnitureFactory()
    {
        return modernFurnitureFactory;
    }

    void CreateFurniture(FurnitureFactory *furnitureFactory)
    {
        Chair *chair = furnitureFactory->CreateChair();
        Sofa *sofa = furnitureFactory->CreateSofa();
        chair->ShowInfo();
        sofa->ShowInfo();
        delete chair;
        delete sofa;
    }

    ~FurnitureFactorySystem()
    {
        delete classicFurnitureFactory;
        delete modernFurnitureFactory;
    }
};

int main()
{
    int N;
    cin >> N;
    FurnitureFactorySystem furnitureFactorySystem;
    string type;

    while (N--)
    {
        cin >> type;
        if (type == "modern")
            furnitureFactorySystem.CreateFurniture(furnitureFactorySystem.GetModernFurnitureFactory());
        else if (type == "classical")
            furnitureFactorySystem.CreateFurniture(furnitureFactorySystem.GetClassicFurnitureFactory());
    }
    return 0;
}