#include <iostream>

using namespace std;

class Weapons {
private:
    static int count;
protected:
    int count_patron;
public:

    int Get() {
        return count;
    }

    Weapons(int count_patron_) {
        count_patron = count_patron_;
        cout << "Оружие изготовлено" << "\n";
        count++;
    }

    virtual void sound() = 0;

    virtual ~Weapons() {
        count--;
        cout << "Оружие уничтожено" << "\n";
    }
};

int Weapons::count = 0;

class Knife : public Weapons {
public:
    void sound() override {
        cout << "вжух" << "\n";
    }
    Knife(int count_patron_) : Weapons(count_patron_) {
        cout << "Нож изготовлен" << "\n";
    }
    ~Knife() override {
        cout << "Нож уничтожен" << "\n";
    }
};

class Gun : public Weapons {
public:
    void sound() override {
        cout << "пиу" << "\n";
    }
    Gun(int count_patron_) : Weapons(count_patron_) {
        cout << "Пистолет изготовлен" << "\n";
    }
    ~Gun() override {
        cout << "Пистолет уничтожен" << "\n";
    }
};

class Auto : public Weapons {
public:
    void sound() override {
        cout << "пиу-пиу" << "\n";
    }
    Auto(int count_patron_) : Weapons(count_patron_) {
        cout << "Автомат изготовлен" << "\n";
    }
    ~Auto() override {
        cout << "Автомат уничтожен" << "\n";
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    Weapons* knife = new Knife(0);
    knife->sound();
    cout << knife->Get() << "\n";
    delete knife;
    cout << knife->Get() << "\n";
    knife = nullptr;
    
    return 0;
}
