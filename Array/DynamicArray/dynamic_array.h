#pragma once

#include <iostream>
#include <cstddef> // for size_t


template <typename T>
class DynamicArray {
private:
    T* array;
    size_t arrSize;
    size_t arrCapacity;

    void set_capacity(size_t n);

public:
    DynamicArray();
    DynamicArray(size_t n, const T& value);
    ~DynamicArray();
    
    size_t size() const;
    size_t capacity() const;
    bool empty() const;
    
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    
    void push_back(const T& value); // 가장 뒤에 요소 추가
    void insert(size_t index, const T& value); // index에 value 삽입
    void pop_back(); // 가장 뒤에 있는 요소 삭제
    void erase(size_t index); // index번쨰 요소 삭제

    void resize(size_t n); // size, capacity n으로 조정
};


#include "dynamic_array_impl.h" 