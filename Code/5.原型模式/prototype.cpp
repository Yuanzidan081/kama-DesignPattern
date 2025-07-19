#include <iostream>
using namespace std;

class Prototype
{
public:
    virtual ~Prototype() = default;
    virtual Prototype *Clone() const = 0;
    virtual void ShowInfo() const = 0;
};

class RectanglePrototype : public Prototype
{
private:
    string m_color;
    int m_width;
    int m_height;

public:
    ~RectanglePrototype() = default;
    RectanglePrototype(const string &color, int width, int height)
        : m_color(color), m_width(width), m_height(height) {}
    Prototype *Clone() const override
    {
        return new RectanglePrototype(*this);
    }
    void ShowInfo() const override
    {
        cout << "Color: " << m_color << ", Width: " << m_width << ", Height: " << m_height << endl;
    }
};

int main()
{
    string shapeType;
    int width, height;
    cin >> shapeType >> width >> height;
    Prototype *prototype = new RectanglePrototype(shapeType, width, height);
    int N;
    cin >> N;
    while (N--)
    {
        Prototype *clone = prototype->Clone();
        clone->ShowInfo();
        delete clone;
    }
    delete prototype;
    return 0;
}