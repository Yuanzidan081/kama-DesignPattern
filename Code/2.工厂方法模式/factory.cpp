#include <iostream>
#include <vector>
using namespace std;

class Block
{
public:
    virtual ~Block() = default;
    virtual void ShowMessage() = 0;
};

class CircleBlock : public Block
{
public:
    void ShowMessage() override
    {
        cout << "Circle Block" << endl;
    }
};

class SquareBlock : public Block
{
public:
    void ShowMessage() override
    {
        cout << "Square Block" << endl;
    }
};

class BlockFactory
{
public:
    virtual ~BlockFactory() = default;
    virtual Block *CreateBlock() = 0;
};

class CircleBlockFactory : public BlockFactory
{
public:
    Block *CreateBlock() override
    {
        return new CircleBlock();
    }
};

class SquareBlockFactory : public BlockFactory
{
public:
    Block *CreateBlock() override
    {
        return new SquareBlock();
    }
};

class BlockFactorySystem
{
private:
    vector<Block *> blocks;
    BlockFactory *circleFactory;
    BlockFactory *squareFactory;

public:
    BlockFactory *GetCircleFactory()
    {
        return circleFactory;
    }

    BlockFactory *GetSquareFactory()
    {
        return squareFactory;
    }

    BlockFactorySystem()
    {
        circleFactory = new CircleBlockFactory();
        squareFactory = new SquareBlockFactory();
    }
    void ProducesBlocks(BlockFactory *blockFactory, int blockNumber)
    {
        for (int i = 0; i < blockNumber; i++)
        {
            Block *block = blockFactory->CreateBlock();
            blocks.push_back(block);
            block->ShowMessage();
        }
    }

    ~BlockFactorySystem()
    {
        delete circleFactory;
        delete squareFactory;

        for (auto &block : blocks)
        {
            delete block;
        }
    }
};
int main()
{
    int N;
    cin >> N;

    BlockFactorySystem blockFactorySystem;
    string blockType;
    int blockNumber;
    while (N--)
    {
        cin >> blockType >> blockNumber;

        if (blockType == "Circle")
            blockFactorySystem.ProducesBlocks(blockFactorySystem.GetCircleFactory(), blockNumber);
        else if (blockType == "Square")
            blockFactorySystem.ProducesBlocks(blockFactorySystem.GetSquareFactory(), blockNumber);
    }

    return 0;
}