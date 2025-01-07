#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <iostream>

class Rectangle : public Shape {
public:
    void draw() const override;
    std::string getType() const override;
};

#endif // RECTANGLE_H
