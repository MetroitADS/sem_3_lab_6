#include "Document.h"
#include <iostream>

void Document::createNewDocument() {
    shapes.clear(); //очистить предыдущие фигуры
    std::cout << "Created a new document." << std::endl;
}

void Document::addShape(std::unique_ptr<Shape> shape) {
    shapes.push_back(std::move(shape));
    std::cout << "Added a shape." << std::endl;
}

void Document::importFromFile(const std::string& filename) {
    std::cout << "Imported from file: " << filename << std::endl;
    //реализация чтения из файла будет здесь
}

void Document::exportToFile(const std::string& filename) {
    std::cout << "Exported to file: " << filename << std::endl;
    //реализация записи в файл будет здесь
}

void Document::removeShape(size_t index) {
    if (index < shapes.size()) {
        shapes.erase(shapes.begin() + index);
        std::cout << "Removed shape at index: " << index << std::endl;
    }
    else {
        std::cout << "Index out of range!" << std::endl;
    }
}
