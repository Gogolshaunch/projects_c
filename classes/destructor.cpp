#include <iostream>

using namespace std;

class Device {
public:
    virtual void turnOn() = 0;
    virtual ~Device() = 0;
};

Device::~Device() { cout << "Деструктор Device" << endl; };

class Smartphone : public Device {
public:
    void turnOn() override {
        cout << "Телефон включен" << endl;
    }
    ~Smartphone() override {
        cout << "Деструктор Smartphone" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "RU");
    Device* obj1 = new Smartphone;
    delete obj1;
    obj1 = nullptr;
    return 0;
}
