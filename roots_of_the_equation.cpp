//3) Создать абстрактный базовый класс с виртуальной функцией — корни уравнения.
// Создать производные классы : класс линейных уравнений и класс квадратных уравнений.
//Определить функцию вычисления корней уравнений.


#include <iostream>
using namespace std;

class RootsEquation {
public:
    virtual void CalculateRoots() const = 0;
    virtual ~RootsEquation() {}
};

class LinearEquation : public RootsEquation {
protected:
    double a = 0, b = 0;

public:
    LinearEquation() {}

    LinearEquation(double a, double b) {
        SetA(a);
        SetB(b);
    }

    void SetA(double newA) {
        a = newA;
    }

    void SetB(double newB) {
        b = newB;
    }

    void CalculateRoots() const override {
        if (a != 0) {
            double root = -b / a;
            cout << "Линейное уравнение: x = " << root << "\n";
        }
        else {
            cout << "Уравнение не является линейным.\n";
        }
    }
};

class QuadraticEquation : public RootsEquation {
protected:
    double a = 0, b = 0, c = 0;

public:
    QuadraticEquation() {}

    QuadraticEquation(double a, double b, double c) {
        SetA(a);
        SetB(b);
        SetC(c);
    }

    void SetA(double newA) {
        a = newA;
    }

    void SetB(double newB) {
        b = newB;
    }

    void SetC(double newC) {
        c = newC;
    }

    void CalculateRoots() const override {
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Квадратное уравнение: x1 = " << root1 << ", x2 = " << root2 << endl;
        }
        else if (discriminant == 0) {
            double root = -b / (2 * a);
            cout << "Квадратное уравнение имеет один корень: x = " << root << endl;
        }
        else {
            cout << "Квадратное уравнение не имеет действительных корней." << endl;
        }
    }
};

int main() {
    setlocale(0, "");

    LinearEquation linear;
    linear.SetA(2);
    linear.SetB(-3);

    QuadraticEquation quadratic;
    quadratic.SetA(1);
    quadratic.SetB(-3);
    quadratic.SetC(2);

    cout << "Корни уравнения:\n";
    linear.CalculateRoots();
    quadratic.CalculateRoots();
}