#include "Controller.h"
#include "Circle.h"
#include "Rectangle.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

void Controller::createDocument(const std::string& filename) {
    std::ofstream outFile(filename);

    if (outFile.is_open()) {
        outFile << "Это новый документ: " << filename << "\n";
        outFile.close();
        std::cout << "Создан новый документ: " << filename << std::endl;
        shapes.clear(); //очистка списка фигур
    }
    else {
        std::cerr << "Ошибка при создании документа: " << filename << std::endl;
    }
}

void Controller::importDocument(const std::string& filename) {
    std::cout << "Импорт документа из файла: " << filename << std::endl;
    //здесь должна быть логика для импорта фигур из файла
}

void Controller::exportDocument(const std::string& filename) {
    std::cout << "Экспорт документа в файл: " << filename << std::endl;
    //здесь должна быть логика для экспорта фигур в файл
}

void Controller::addShape(const std::string& shapeType) {
    Shape* shape = nullptr;

    if (shapeType == "Circle") {
        shape = new Circle();
    }
    else if (shapeType == "Rectangle") {
        shape = new Rectangle();
    }

    if (shape) {
        shapes.push_back(shape);
        std::cout << shapeType << " добавлен в документ." << std::endl;
    }
    else {
        std::cout << "Неизвестный тип графического примитива: " << shapeType << std::endl;
    }
}

void Controller::removeShape(int index) {
    if (index >= 0 && index < shapes.size()) {
        delete shapes[index]; //освобождение памяти
        shapes.erase(shapes.begin() + index);
        std::cout << "Графический примитив с индексом " << index << " успешно удален." << std::endl;
    }
    else {
        std::cout << "Некорректный индекс для удаления." << std::endl;
    }
}

void Controller::listDocuments() {
    std::cout << "Существующие документы:" << std::endl;
    for (const auto& entry : std::filesystem::directory_iterator("данные")) {
        std::cout << "- " << entry.path().filename().string() << std::endl;
    }
}
