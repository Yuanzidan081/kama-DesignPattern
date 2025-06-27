#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
class ShoppingCart
{
private:
    static ShoppingCart *instance;
    unordered_map<string, int> shoppingList;
    vector<string> shoppingListOrder;
    ShoppingCart() = default;
    ~ShoppingCart() = default;
    ShoppingCart(const ShoppingCart &) = delete;
    ShoppingCart &operator=(const ShoppingCart &) = delete;

public:
    static ShoppingCart *GetInstance()
    {
        if (instance == nullptr)
            return instance = new ShoppingCart();
        return instance;
    }
    void AddList(const string &goodName, int goodNum)
    {
        if (!shoppingList.count(goodName))
            shoppingListOrder.push_back(goodName);
        shoppingList[goodName] += goodNum;
    }
    friend ostream &operator<<(ostream &os, const ShoppingCart &shoppingCart);
};

ostream &operator<<(ostream &os, const ShoppingCart &shoppingCart)
{
    for (auto &item : shoppingCart.shoppingListOrder)
        os << item << " " << shoppingCart.shoppingList.at(item) << endl;
    return os;
}

ShoppingCart *ShoppingCart::instance = nullptr;

int main()
{
    ShoppingCart *shoppingList = ShoppingCart::GetInstance();
    string goodName;
    int goodNum;
    while (cin >> goodName >> goodNum)
    {
        shoppingList->AddList(goodName, goodNum);
    }
    cout << (*shoppingList);
    return 0;
}
