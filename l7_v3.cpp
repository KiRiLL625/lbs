#include <iostream>
#include <string>

// Абстрактный класс Shape
class Shape {
public:
    virtual void draw() const = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void info() const = 0;
    virtual ~Shape() = default;
};

// Класс Square
class Square : public Shape {
private:
    double x, y;
    double side;

public:
    Square(double x, double y, double side) : x(x), y(y), side(side) {}

    void draw() const override {
        std::cout << "Drawing Square at (" << x << ", " << y << ") with side " << side << std::endl;
    }

    void move(double dx, double dy) override {
        x += dx;
        y += dy;
        std::cout << "Moved Square to (" << x << ", " << y << ")" << std::endl;
    }

    void info() const override {
        std::cout << "Square: Top-left corner=(" << x << ", " << y << "), Side=" << side << std::endl;
    }
};

// Класс Circle
class Circle : public Shape {
private:
    double x, y;
    double radius;

public:
    Circle(double x, double y, double radius) : x(x), y(y), radius(radius) {}

    void draw() const override {
        std::cout << "Drawing Circle at (" << x << ", " << y << ") with radius " << radius << std::endl;
    }

    void move(double dx, double dy) override {
        x += dx;
        y += dy;
        std::cout << "Moved Circle to (" << x << ", " << y << ")" << std::endl;
    }

    void info() const override {
        std::cout << "Circle: Center=(" << x << ", " << y << "), Radius=" << radius << std::endl;
    }
};

// Класс Ellipse
class Ellipse : public Shape {
private:
    double x1, y1; // Координаты верхнего левого угла описанного прямоугольника
    double x2, y2; // Координаты нижнего правого угла описанного прямоугольника

public:
    Ellipse(double x1, double y1, double x2, double y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}

    void draw() const override {
        std::cout << "Drawing Ellipse with bounding box [("
                  << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")]" << std::endl;
    }

    void move(double dx, double dy) override {
        x1 += dx;
        y1 += dy;
        x2 += dx;
        y2 += dy;
        std::cout << "Moved Ellipse to bounding box [("
                  << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")]" << std::endl;
    }

    void info() const override {
        std::cout << "Ellipse: Bounding box [("
                  << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")]" << std::endl;
    }
};

// Главная функция
int main() {
    Shape* shapes[] = {
        new Square(0, 0, 5),
        new Circle(10, 10, 3),
        new Ellipse(2, 3, 8, 6)
    };

    for (Shape* shape : shapes) {
        shape->info();
        shape->draw();
        shape->move(2, 2); // Передвигаем фигуры на (2, 2)
        shape->info();
        std::cout << std::endl;
    }

    // Удаляем объекты
    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
