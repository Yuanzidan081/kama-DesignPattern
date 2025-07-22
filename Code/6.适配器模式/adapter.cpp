#include <iostream>
using namespace std;

// 原接口USB
// 目标接口 TypeC

class TypeCInterface
{
public:
    virtual ~TypeCInterface() = default;
    virtual void Charge() = 0;
};

class TypeCChargerOriginal : public TypeCInterface
{
public:
    void Charge() override
    {
        cout << "TypeC" << endl;
    }
};

class USBInterfaceOriginal
{
public:
    void ChargeWithUSB()
    {
    }
};
class TypeCAdapterFromUSB : public TypeCInterface
{
    USBInterfaceOriginal *m_usbInterfaceOriginal;

public:
    TypeCAdapterFromUSB()
    {
        m_usbInterfaceOriginal = new USBInterfaceOriginal();
    }
    ~TypeCAdapterFromUSB()
    {
        delete m_usbInterfaceOriginal;
    }
    void Charge() override
    {
        cout << "USB Adapter" << endl;
        m_usbInterfaceOriginal->ChargeWithUSB(); // 实际使用USB充电
    }
};

class Computer
{
public:
    void Charge(TypeCInterface *typeCInterface)
    {
        typeCInterface->Charge();
    }
};

int main()
{
    TypeCInterface *typeCAdapterFromUSB = new TypeCAdapterFromUSB();
    TypeCInterface *typeCChargerOriginal = new TypeCChargerOriginal();
    Computer computer;
    int N;
    cin >> N;
    while (N--)
    {
        int typeCInterfaceType;
        cin >> typeCInterfaceType;
        if (typeCInterfaceType == 1)
            computer.Charge(typeCChargerOriginal);
        else if (typeCInterfaceType == 2)
            computer.Charge(typeCAdapterFromUSB);
    }
    delete typeCAdapterFromUSB;
    delete typeCChargerOriginal;
    return 0;
}