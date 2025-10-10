# Labs | OOP 

## Задание:
Лабораторная работа № 2 - Класс Eleven (основание 11)

Реализация класса для работы с числами в 11-ричной системе счисления:
- Конструкторы для создания объектов из различных типов данных
- Арифметические операции: сложение, вычитание
- Операции сравнения
- Преобразование в строку и обратно
- Иммутабельные объекты (неизменяемые после создания)

## Сборка | запуск программы

### Требования
- CMake ≥ 3.10
- Компилятор C++ (Clang/GCC) с поддержкой C++17
- GoogleTest 

### Сборка
```bash
mkdir -p build
cd build
cmake ..
cmake --build .
```

### Запуск приложения
```bash
./lab2
# пример вывода:
# === Демонстрация класса Eleven ===
# Созданные числа:
# a = A0
# b = 1A
# c = 0
# d = 123
# 
#  Арифметические операции
# A0 + 1A = 10A
# 0 + 123 = 123
# A0 - 1A = 81
# 123 - 0 = 123
# 
# Операции сравнения
# A0 compare 1A = 1
# 1A compare A0 = -1
# A0 compare A0 = 0
# 
# === Иммутабельные операции ===
# A0 added 1A = 10A
# A0 subtracted 1A = 81
# 
# === Создание из строки ===
# fromString("A9") = A9
```

### Запуск тестов
```bash
./tests
# ожидаемый результат:
# [==========] Running 23 tests from 5 test suites.
# [----------] Global test environment set-up.
# [----------] 4 tests from ElevenBasics
# [ RUN      ] ElevenBasics.DefaultConstructor
# [       OK ] ElevenBasics.DefaultConstructor (0 ms)
# ...
# [==========] 23 tests from 5 test suites ran. (0 ms total)
# [  PASSED  ] 23 tests.
```

### Альтернативная сборка через Makefile
```bash
# Сборка и запуск тестов
make test

# Сборка и запуск демо-программы
make run

# Сборка только библиотеки
make lib

# Сборка всего (библиотека + тесты + примеры)
make all

# Очистка build директории
make clean
```

### Очистка сборки
```bash
rm -rf build
```

## Быстрый старт
```bash
# Полный пайплайн в одной команде
cd "/Users/klade/Desktop/UNI/LABS/OOP/2'nd_lab_Rakhimov" && \
mkdir -p build && cd build && \
cmake .. && cmake --build . && \
echo "=== ТЕСТЫ ===" && ./tests && \
echo "=== ДЕМО ===" && ./lab2
```
