#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <vector>
#include "Shape.h"

class Controller {
public:
    void createDocument(const std::string& filename);
    void importDocument(const std::string& filename);
    void exportDocument(const std::string& filename);
    void addShape(const std::string& shapeType);
    void removeShape(int index);
    void listDocuments(); //метод для отображения документов

private:
    std::vector<Shape*> shapes; //список фигур
};

#endif // CONTROLLER_H
