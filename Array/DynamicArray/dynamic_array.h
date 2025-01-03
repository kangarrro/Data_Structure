#include <iostream>
#include <cstddef> // for size_t


template <typename T>
class DynamicArray {
private:
    T* array;
    size_t arrSize;
    size_t arrCapacity;

    void expand(size_t n);

public:
    DynamicArray();
    DynamicArray(size_t n, const T& value);
    ~DynamicArray();
    
    size_t size() const;
    size_t capacity() const;
    bool empty() const;
    
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    
    void push_back(const T& value);
    void insert(size_t index, const T& value);
    void pop_back();
    void erase(size_t index);

    void resize(size_t n);
};