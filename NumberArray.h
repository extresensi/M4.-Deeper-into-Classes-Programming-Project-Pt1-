// NumberArray.h
#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

#include <cstddef>

class NumberArray {
private:
    double *data;
    std::size_t size;
    static bool verbose;

public:
    // Constructors / Destructor
    NumberArray();                         // default (size 10)
    explicit NumberArray(std::size_t n);   // parameterized
    ~NumberArray();                        // destructor

    // Rule of Three
    NumberArray(const NumberArray &other);            // copy constructor
    NumberArray& operator=(const NumberArray &other);// assignment operator

    // Accessors / Mutators
    void setNumber(std::size_t index, double value);
    double getNumber(std::size_t index) const;
    std::size_t getSize() const noexcept;

    // Utilities
    double getMin() const;
    double getMax() const;
    double getAverage() const;
    void print() const;

    // Control verbose output for tests
    static void setVerbose(bool v);
};

#endif // NUMBERARRAY_H
