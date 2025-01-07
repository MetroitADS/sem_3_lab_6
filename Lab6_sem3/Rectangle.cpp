#include "Rectangle.h"

void Rectangle::draw() const {
    std::cout << "Drawing a rectangle." << std::endl;
}

std::string Rectangle::getType() const {
    return "Rectangle";
}
