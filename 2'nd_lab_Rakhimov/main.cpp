#include <iostream>
#include "include/Eleven.hpp"

using namespace std;

int main()
{
    cout << "Демонстрация класса Eleven" << endl;
    
    // Создание объектов различными способами
    Eleven a{"A0"};  // 10*11 + 0 = 110 в десятичной
    Eleven b{"1A"};  // 1*11 + 10 = 21 в десятичной
    Eleven c{"0"};   // ноль
    Eleven d{"123"}; // 1*11² + 2*11 + 3 = 146 в десятичной
    
    cout << "Созданные числа:" << endl;
    cout << "a = " << a.toString() << endl;
    cout << "b = " << b.toString() << endl;
    cout << "c = " << c.toString() << endl;
    cout << "d = " << d.toString() << endl;
    
    cout << "\n Арифметические операции" << endl;
    
    // Сложение
    Eleven sum1 = a.add(b);
    Eleven sum2 = c.add(d);
    cout << a.toString() << " + " << b.toString() << " = " << sum1.toString() << endl;
    cout << c.toString() << " + " << d.toString() << " = " << sum2.toString() << endl;
    
    // Вычитание
    Eleven diff1 = a.sub(b);
    Eleven diff2 = d.sub(c);
    cout << a.toString() << " - " << b.toString() << " = " << diff1.toString() << endl;
    cout << d.toString() << " - " << c.toString() << " = " << diff2.toString() << endl;
    
    cout << "\nОперации сравнения" << endl;
    
    // Сравнение
    int cmp1 = a.compare(b);
    int cmp2 = b.compare(a);
    int cmp3 = a.compare(a);
    
    cout << a.toString() << " compare " << b.toString() << " = " << cmp1 << endl;
    cout << b.toString() << " compare " << a.toString() << " = " << cmp2 << endl;
    cout << a.toString() << " compare " << a.toString() << " = " << cmp3 << endl;
    
    cout << "\nИммутабельные операции" << endl;
    
    // Иммутабельные операции (аналоги += и -=)
    Eleven added = a.added(b);
    Eleven subtracted = a.subtracted(b);
    
    cout << a.toString() << " added " << b.toString() << " = " << added.toString() << endl;
    cout << a.toString() << " subtracted " << b.toString() << " = " << subtracted.toString() << endl;
    
    cout << "\nСоздание из строки" << endl;
    
    // Создание через фабричный метод
    Eleven fromStr = Eleven::fromString("A9");
    cout << "fromString(\"A9\") = " << fromStr.toString() << endl;
    
    return 0;
}
