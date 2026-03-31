// main.cpp
#include "NumberArray.h"
#include <iostream>

int main() {
    NumberArray::setVerbose(true);

    std::cout << "=== Create original a (size 5) and set values ===\n";
    NumberArray a(5);
    for (std::size_t i = 0; i < a.getSize(); ++i) a.setNumber(i, static_cast<double>(i + 1) * 1.5);
    a.print();
    std::cout << "min=" << a.getMin() << " max=" << a.getMax() << " avg=" << a.getAverage() << "\n\n";

    std::cout << "=== Copy construct b from a ===\n";
    NumberArray b(a);           // copy constructor
    b.print();

    std::cout << "=== Modify original a[0] and show b unchanged ===\n";
    a.setNumber(0, 999.0);
    std::cout << "a: "; a.print();
    std::cout << "b: "; b.print();

    std::cout << "\n=== Assignment: c = a ===\n";
    NumberArray c(3);
    c = a;                      // assignment operator
    c.print();

    std::cout << "=== Modify c[1] and show a unchanged ===\n";
    c.setNumber(1, -42.0);
    std::cout << "a: "; a.print();
    std::cout << "c: "; c.print();

    std::cout << "\n=== Self-assignment test on c ===\n";
    c = c;
    c.print();

    std::cout << "\n=== Scope test: create temp inside block ===\n";
    {
        NumberArray temp(2);
        temp.setNumber(0, 7.7);
        temp.setNumber(1, 8.8);
        temp.print();
    } // destructor message should appear

    std::cout << "\nEnd of main, destructors will run for a, b, c\n";
    return 0;
}
