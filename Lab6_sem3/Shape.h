#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
public:
    virtual void draw() const = 0; // ����� ����������� ������� ��� ��������� ������
    virtual std::string getType() const = 0; // ����� ����������� ������� ��� ��������� ���� ������
    virtual ~Shape() {} // ����������� ����������
};

#endif // SHAPE_H
