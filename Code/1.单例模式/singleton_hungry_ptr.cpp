/*
 * Author: Lin Siyuan
 * Data: 2025-07-06
 * singleton_hungry_ptr.cpp
 * 单例模式饿汉式实现：一开始就分配资源，静态变量使用指针，多线程安全
 */
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
class ShoppingCart
{
private:
    static ShoppingCart *s_instance;
    unordered_map<string, int> m_shoppingList;
    vector<string> m_goodNameListByOrder;
    ShoppingCart() = default;
    ~ShoppingCart() = default;
    ShoppingCart(const ShoppingCart &) = delete;
    ShoppingCart &operator=(const ShoppingCart &) = delete;

public:
    static ShoppingCart *GetInstance()
    {
        return s_instance;
    }
    void AddGoodToShoppingList(const string &goodName, int goodNum)
    {
        if (!m_shoppingList.count(goodName))
            m_goodNameListByOrder.push_back(goodName);
        m_shoppingList[goodName] += goodNum;
    }
    friend ostream &operator<<(ostream &os, const ShoppingCart &shoppingCart);
};

ostream &operator<<(ostream &os, const ShoppingCart &shoppingCart)
{
    for (auto &item : shoppingCart.m_goodNameListByOrder)
        os << item << " " << shoppingCart.m_shoppingList.at(item) << endl;
    return os;
}

ShoppingCart *ShoppingCart::s_instance = new ShoppingCart();

int main()
{
    string goodName;
    int goodNum;
    while (cin >> goodName >> goodNum)
    {
        ShoppingCart::GetInstance()->AddGoodToShoppingList(goodName, goodNum);
    }
    cout << (*ShoppingCart::GetInstance());
    return 0;
}
