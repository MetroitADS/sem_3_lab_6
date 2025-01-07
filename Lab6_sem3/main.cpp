#include <iostream>
#include <filesystem>
#include "Controller.h"

void Menu() {
    std::cout << "Выберите действие:\n";
    std::cout << "1 - Импорт документа из файла\n";
    std::cout << "2 - Экспорт документа в файл\n";
    std::cout << "3 - Создание графического примитива\n";
    std::cout << "4 - Удаление графического примитива\n";
    std::cout << "5 - Создание нового документа\n";
    std::cout << "6 - Просмотр существующих документов\n";
    std::cout << "0 - Выход\n";
}

void createDataDirectory() {
    const std::string dirName = "document";
    std::filesystem::create_directory(dirName);
}

int main() {
    setlocale(LC_ALL, "Russian");
    createDataDirectory();  // Создаем папку "данные"
    Controller controller;
    int choice;

    while (true) {
        Menu();
        std::cout << "Введите номер действия: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            controller.listDocuments();
            std::string filename;
            std::cout << "Введите имя документа для импорта: ";
            std::cin >> filename;
            controller.importDocument("данные/" + filename); 
            break;
        }
        case 2: {
            controller.listDocuments();
            std::string filename;
            std::cout << "Введите имя документа для экспорта: ";
            std::cin >> filename;
            controller.exportDocument("данные/" + filename);
            break;
        }
        case 3: {
            std::string shapeType;
            std::cout << "Введите тип графического примитива (Circle или Rectangle): ";
            std::cin >> shapeType;
            controller.addShape(shapeType);
            break;
        }
        case 4: {
            int index;
            std::cout << "Введите индекс графического примитива для удаления: ";
            std::cin >> index;
            controller.removeShape(index);
            break;
        }
        case 5: {
            std::string filename;
            std::cout << "Введите имя нового документа: ";
            std::cin >> filename;
            controller.createDocument("данные/" + filename); // Сохраняем документы в папке "данные"
            break;
        }
        case 6: {
            controller.listDocuments();
            break;
        }
        case 0:
            std::cout << "Выход из программы." << std::endl;
            return 0; // Завершение программы
        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова." << std::endl;
        }
    }

    return 0;
}
