#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <vector>
#include <memory>
#include "Shape.h"

class Document {
public:
    void createNewDocument();
    void addShape(std::unique_ptr<Shape> shape);
    void importFromFile(const std::string& filename);
    void exportToFile(const std::string& filename);
    void removeShape(size_t index);

private:
    std::vector<std::unique_ptr<Shape>> shapes; //вектор для хранения фигур
};

#endif // DOCUMENT_H
