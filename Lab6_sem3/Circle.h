#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <iostream>

class Circle : public Shape {
public:
    void draw() const override;
    std::string getType() const override;
};

#endif // CIRCLE_H
