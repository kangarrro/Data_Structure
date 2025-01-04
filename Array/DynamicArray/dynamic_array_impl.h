#include "dynamic_array.h"

// public method
template <typename T>
DynamicArray<T>::DynamicArray() : arrSize(0), arrCapacity(1) {
    array = new T[arrCapacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(size_t n, const T& value) : arrSize(n), arrCapacity(n) {
    array = new T[arrCapacity];
    for (size_t i = 0; i < n; ++i)
        array[i] = value;
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    if(array) delete[] array;
}

template <typename T>
size_t DynamicArray<T>::size() const {
    return arrSize;
}

template <typename T>
size_t DynamicArray<T>::capacity() const {
    return arrCapacity;
}

template <typename T>
bool DynamicArray<T>::empty() const {
    return arrSize == 0 ? true : false;
}

template <typename T>
T& DynamicArray<T>::operator[](size_t index) {
    if(index >= arrSize) throw std::out_of_range("Index out of range");
    return array[index];
}

template <typename T>
const T& DynamicArray<T>::operator[](size_t index) const {
    if(index >= arrSize) throw std::out_of_range("Index out of range");
    return array[index];
}

template <typename T>
void DynamicArray<T>::push_back(const T& value) {
    if(arrSize == arrCapacity) set_capacity(arrCapacity == 0 ? 1 : arrCapacity*2);
    array[arrSize++] = value;
}

template <typename T>
void DynamicArray<T>::insert(size_t index, const T& value) {
    if(index > arrSize) return;
    if(arrSize == arrCapacity) set_capacity(arrSize == 0 ? 1 : arrCapacity*2);

    for(size_t i = arrSize; i > index; i--)
        array[i] = array[i - 1];
    array[index] = value;
    arrSize++;
}

template <typename T>
void DynamicArray<T>::pop_back() {
    if(!arrSize) return;
    array[arrSize - 1].~T();
    arrSize--;
}

template <typename T>
void DynamicArray<T>::erase(size_t index) {
    if(!arrSize) return;
    for(size_t i = index; i < arrSize - 1; i--)
        array[i] = array[i + 1];
    arrSize--;
}

template <typename T>
void DynamicArray<T>::resize(size_t n) {
    if(n > arrSize) set_capacity(n);
    arrSize = n;
}

// private method
template <typename T>
void DynamicArray<T>::set_capacity(size_t n) {
    T* new_array = new T[n];
    for(size_t i = 0; i < arrSize; i++)
        new_array[i] = array[i];
    delete[] array;
    array = new_array;
    arrCapacity = n;
}