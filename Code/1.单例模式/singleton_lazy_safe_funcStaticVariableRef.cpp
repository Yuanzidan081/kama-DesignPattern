/*
 * Author: Lin Siyuan
 * Data: 2025-07-06
 * singleton_lazy_safe_funcStaticVariableRef.cpp
 * 单例模式懒汉式实现：在函数内使用静态变量，最终返回引用
 */
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <mutex>
using namespace std;
class ShoppingCart
{
private:
    unordered_map<string, int> m_shoppingList;
    vector<string> m_shoppingListOrder;
    ShoppingCart() = default;
    ~ShoppingCart() = default;
    ShoppingCart(const ShoppingCart &) = delete;
    ShoppingCart &operator=(const ShoppingCart &) = delete;

public:
    static ShoppingCart &GetInstance()
    {
        static ShoppingCart s_instance;
        return s_instance;
    }
    void AddGoodToShoppingList(const string &goodName, int goodNum)
    {
        if (!m_shoppingList.count(goodName))
            m_shoppingListOrder.push_back(goodName);
        m_shoppingList[goodName] += goodNum;
    }
    friend ostream &operator<<(ostream &os, const ShoppingCart &shoppingCart);
};

ostream &operator<<(ostream &os, const ShoppingCart &shoppingCart)
{
    for (auto &item : shoppingCart.m_shoppingListOrder)
        os << item << " " << shoppingCart.m_shoppingList.at(item) << endl;
    return os;
}

int main()
{
    ShoppingCart &shoppingList = ShoppingCart::GetInstance();
    string goodName;
    int goodNum;
    while (cin >> goodName >> goodNum)
    {
        shoppingList.AddGoodToShoppingList(goodName, goodNum);
    }
    cout << shoppingList;
    return 0;
}
