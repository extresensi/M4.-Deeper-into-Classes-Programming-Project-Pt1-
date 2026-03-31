// NumberArray.cpp
#include "NumberArray.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>

bool NumberArray::verbose = true;

void NumberArray::setVerbose(bool v) { verbose = v; }

NumberArray::NumberArray() : data(nullptr), size(10) {
    data = new double[size];
    for (std::size_t i = 0; i < size; ++i) data[i] = 0.0;
    if (verbose) std::cout << "[Ctor] default size=" << size << '\n';
}

NumberArray::NumberArray(std::size_t n) : data(nullptr), size(n ? n : 1) {
    data = new double[size];
    for (std::size_t i = 0; i < size; ++i) data[i] = 0.0;
    if (verbose) std::cout << "[Ctor] size=" << size << '\n';
}

NumberArray::~NumberArray() {
    delete[] data;
    if (verbose) std::cout << "[Dtor] released memory for size=" << size << '\n';
}

NumberArray::NumberArray(const NumberArray &other) : data(nullptr), size(other.size) {
    data = new double[size];
    for (std::size_t i = 0; i < size; ++i) data[i] = other.data[i];
    if (verbose) std::cout << "[CopyCtor] deep-copied size=" << size << '\n';
}

NumberArray& NumberArray::operator=(const NumberArray &other) {
    if (this == &other) {
        if (verbose) std::cout << "[Assign] self-assignment detected; no action\n";
        return *this;
    }
    // release old memory
    delete[] data;
    // allocate and copy
    size = other.size;
    data = new double[size];
    for (std::size_t i = 0; i < size; ++i) data[i] = other.data[i];
    if (verbose) std::cout << "[Assign] deep-copied size=" << size << '\n';
    return *this;
}

void NumberArray::setNumber(std::size_t index, double value) {
    if (index >= size) {
        std::cerr << "setNumber: index out of bounds\n";
        return;
    }
    data[index] = value;
}

double NumberArray::getNumber(std::size_t index) const {
    if (index >= size) {
        std::cerr << "getNumber: index out of bounds\n";
        return std::numeric_limits<double>::quiet_NaN();
    }
    return data[index];
}

std::size_t NumberArray::getSize() const noexcept { return size; }

double NumberArray::getMin() const {
    if (size == 0) return 0.0;
    double m = data[0];
    for (std::size_t i = 1; i < size; ++i) if (data[i] < m) m = data[i];
    return m;
}

double NumberArray::getMax() const {
    if (size == 0) return 0.0;
    double m = data[0];
    for (std::size_t i = 1; i < size; ++i) if (data[i] > m) m = data[i];
    return m;
}

double NumberArray::getAverage() const {
    if (size == 0) return 0.0;
    double sum = 0.0;
    for (std::size_t i = 0; i < size; ++i) sum += data[i];
    return sum / static_cast<double>(size);
}

void NumberArray::print() const {
    std::cout << "NumberArray(size=" << size << "): ";
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << std::fixed << std::setprecision(2) << data[i];
        if (i + 1 < size) std::cout << ", ";
    }
    std::cout << '\n';
}
