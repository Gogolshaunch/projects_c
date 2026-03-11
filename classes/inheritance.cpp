#include <iostream>

using namespace std;

class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Круг нарисован" << "\n";
    }
    double calculatearea(double radius) {
        return 3.14 * radius * radius;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Квадрат нарисован" << "\n";
    }
    double calculatearea(double a) {
        return a*a;
    }
};


int main()
{
    setlocale(LC_ALL, "ru");
    Circle circ1;
    cout << circ1.calculatearea(15) << "\n";
    circ1.draw();

    Square sq1;
    cout << sq1.calculatearea(5) << "\n";
    sq1.draw();
    return 0 ;
}
