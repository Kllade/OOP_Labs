# Labs | OOP 

## Задание:
15 вариант   
Поиск максимального числа N, удовлетворяющего условиям:
- N > 0
- N делится на делитель
- N меньше или равно границе 

## Сборка | запуск программы

### Требования
- CMake ≥ 3.10
- Компилятор C++ (Clang/GCC) с поддержкой C++17
- GoogleTest (для запуска тестов). На macOS можно установить: `brew install googletest`

### Сборка
```bash
mkdir -p build
cd build
cmake ..
cmake --build .
```

### Запуск приложения
```bash
./lab1
# пример диалога:
# enter divider:2
# enter bound:7
# result: 6
```

### Запуск тестов
```bash
./tests
```

### Очистка сборки
```bash
rm -rf build
```
