#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Bike
{
public:
    Bike() = default;
    void SetFrame(const string &frame)
    {
        m_frame = frame;
    }
    void SetTires(const string &tires)
    {
        m_tires = tires;
    }
    friend ostream &operator<<(ostream &os, const Bike &bike)
    {
        os << bike.m_frame << " " << bike.m_tires;
        return os;
    }

private:
    string m_frame;
    string m_tires;
};

class BikeBuilder
{
public:
    virtual ~BikeBuilder() = default;
    virtual shared_ptr<Bike> GetBike() = 0;
    virtual void BuildFrame() = 0;
    virtual void BuildTires() = 0;
};

class MoutainBikeBuilder : public BikeBuilder
{
public:
    MoutainBikeBuilder()
    {
        m_bike = make_shared<Bike>();
    }
    virtual shared_ptr<Bike> GetBike() override
    {
        return m_bike;
    }
    virtual void BuildFrame() override
    {
        m_bike->SetFrame("Aluminum Frame");
    }
    virtual void BuildTires() override
    {
        m_bike->SetTires("Knobby Tires");
    }

private:
    shared_ptr<Bike> m_bike;
};

class RoadBikeBuilder : public BikeBuilder
{
public:
    RoadBikeBuilder()
    {
        m_bike = make_shared<Bike>();
    }
    virtual shared_ptr<Bike> GetBike() override
    {
        return m_bike;
    }
    virtual void BuildFrame() override
    {
        m_bike->SetFrame("Carbon Frame");
    }
    virtual void BuildTires() override
    {
        m_bike->SetTires("Slim Tires");
    }

private:
    shared_ptr<Bike> m_bike;
};

class BikeDirector
{
public:
    BikeDirector() = default;
    void SetBuilder(shared_ptr<BikeBuilder> bikeBuilder)
    {
        m_bikeBuilder = bikeBuilder;
    }

    shared_ptr<Bike> Construct()
    {
        m_bikeBuilder->BuildFrame();
        m_bikeBuilder->BuildTires();
        return m_bikeBuilder->GetBike();
    }

private:
    shared_ptr<BikeBuilder> m_bikeBuilder;
};

int main()
{
    BikeDirector bikeDirector;
    int N;
    cin >> N;
    while (N--)
    {
        string bikeType;
        cin >> bikeType;

        shared_ptr<BikeBuilder> bikeBuilder;
        if (bikeType == "mountain")
            bikeBuilder = make_shared<MoutainBikeBuilder>();
        else if (bikeType == "road")
            bikeBuilder = make_shared<RoadBikeBuilder>();

        bikeDirector.SetBuilder(bikeBuilder);
        auto bike = bikeDirector.Construct();
        cout << *bike << endl;
    }
    return 0;
}