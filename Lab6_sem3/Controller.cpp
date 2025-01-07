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
        outFile << "��� ����� ��������: " << filename << "\n";
        outFile.close();
        std::cout << "������ ����� ��������: " << filename << std::endl;
        shapes.clear(); //������� ������ �����
    }
    else {
        std::cerr << "������ ��� �������� ���������: " << filename << std::endl;
    }
}

void Controller::importDocument(const std::string& filename) {
    std::cout << "������ ��������� �� �����: " << filename << std::endl;
    //����� ������ ���� ������ ��� ������� ����� �� �����
}

void Controller::exportDocument(const std::string& filename) {
    std::cout << "������� ��������� � ����: " << filename << std::endl;
    //����� ������ ���� ������ ��� �������� ����� � ����
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
        std::cout << shapeType << " �������� � ��������." << std::endl;
    }
    else {
        std::cout << "����������� ��� ������������ ���������: " << shapeType << std::endl;
    }
}

void Controller::removeShape(int index) {
    if (index >= 0 && index < shapes.size()) {
        delete shapes[index]; //������������ ������
        shapes.erase(shapes.begin() + index);
        std::cout << "����������� �������� � �������� " << index << " ������� ������." << std::endl;
    }
    else {
        std::cout << "������������ ������ ��� ��������." << std::endl;
    }
}

void Controller::listDocuments() {
    std::cout << "������������ ���������:" << std::endl;
    for (const auto& entry : std::filesystem::directory_iterator("������")) {
        std::cout << "- " << entry.path().filename().string() << std::endl;
    }
}
