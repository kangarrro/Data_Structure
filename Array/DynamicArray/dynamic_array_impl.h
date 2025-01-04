#include "dynamic_array.h"

// public method

// 생성자
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
// 소멸자
template <typename T>
DynamicArray<T>::~DynamicArray() {
    if(array) delete[] array;
}
// arrSize ; 크기 반환
template <typename T>
size_t DynamicArray<T>::size() const {
    return arrSize;
}
// arrCapacity ; 용량 반환
template <typename T>
size_t DynamicArray<T>::capacity() const {
    return arrCapacity;
}
// arrSize == 0? ; 비어있는지 검사 후 반환(bool)
template <typename T>
bool DynamicArray<T>::empty() const {
    return arrSize == 0 ? true : false;
}
// DynamicArray[index] 반환 ; 쓰기
template <typename T>
T& DynamicArray<T>::operator[](size_t index) {
    if(index >= arrSize) throw std::out_of_range("Index out of range");
    return array[index];
}
// DynamicArray[index] 반환 ; 읽기
template <typename T>
const T& DynamicArray<T>::operator[](size_t index) const {
    if(index >= arrSize) throw std::out_of_range("Index out of range");
    return array[index];
}
// DynamicArray[arrSize] = value ; 가장 마지막에 새 요소(value) 추가
template <typename T>
void DynamicArray<T>::push_back(const T& value) {
    if(arrSize == arrCapacity) set_capacity(arrCapacity == 0 ? 1 : arrCapacity*2);
    array[arrSize++] = value;
}
// DynamicArray[index] = value ; index에 새 요소(value) 삽입
template <typename T>
void DynamicArray<T>::insert(size_t index, const T& value) {
    if(index > arrSize) throw std::out_of_range("Index out of range");
    if(arrSize == arrCapacity) set_capacity(arrSize == 0 ? 1 : arrCapacity*2);
    for(size_t i = arrSize; i > index; i--)
        array[i] = array[i - 1];
    array[index] = value;
    arrSize++;
}
// arrSize-- ; 가장 마지막 요소 삭제
template <typename T>
void DynamicArray<T>::pop_back() {
    if(!arrSize) throw std::underflow_error("Cannot pop_back, Array is empty");
    array[arrSize - 1].~T();
    arrSize--;
}
// DynamicArray[index+1:] -> [index:] ; (index삭제) [index+1:]을 [index:]로 복사
template <typename T>
void DynamicArray<T>::erase(size_t index) {
    if(index >= arrSize) throw std::out_of_range("Index out of range");
    for(size_t i = index; i < arrSize - 1; i--)
        array[i] = array[i + 1];
    arrSize--;
}
// set_capacit(n) ; 새로운 크기 n으로 설정, arrSize도 n으로 설정
template <typename T>
void DynamicArray<T>::resize(size_t n) {
    if(n > arrSize) set_capacity(n);
    arrSize = n;
}

// private method

// array[arrCapacity] -> array[n] ; 새로운 용량 n배열 선언 후 복사
template <typename T>
void DynamicArray<T>::set_capacity(size_t n) {
    T* new_array = new T[n];
    for(size_t i = 0; i < arrSize; i++)
        new_array[i] = array[i];
    delete[] array;
    array = new_array;
    arrCapacity = n;
}