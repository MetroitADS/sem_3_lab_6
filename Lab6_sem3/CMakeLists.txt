# CMakeList.txt: проект CMake для Lab6_sem3; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Lab6_sem3 "main.cpp"  "Document.h" "Circle.h" "Rectangle.h" "Controller.h" "Controller.cpp" "Circle.cpp" "Document.cpp" "Rectangle.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Lab6_sem3 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
