#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
public:
    virtual void draw() const = 0; // Чисто виртуальная функция для отрисовки фигуры
    virtual std::string getType() const = 0; // Чисто виртуальная функция для получения типа фигуры
    virtual ~Shape() {} // Виртуальный деструктор
};

#endif // SHAPE_H
