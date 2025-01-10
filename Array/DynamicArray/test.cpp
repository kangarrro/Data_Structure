#include "dynamic_array.h"
#include "../../Test/test_utils.h"
#include <iostream>
using namespace std;

template <typename T>
void print_array(const T& array) {
    cout << "SIZE: " << array.size() << endl;
    cout << "CAPACITY: " << array.capacity() << endl;
    for (int i = 0; i < array.size(); cout << array[i++] << ' ') {}
    cout << endl;
}

int main() {
    DynamicArray<int> arr(10, 0);

    arr.resize(15);
    arr.resize(10);
    print_array(arr);

    for(int i = 0; i < arr.capacity(); i++)
        arr[i] = i;
    print_array(arr);

    arr.push_back(15);
    arr.push_back(11);
    print_array(arr);

    arr.push_back(16);
    arr.push_back(12);
    print_array(arr);

    arr.pop_back();
    print_array(arr);

    arr.insert(10, 10);
    print_array(arr);
    arr.erase(arr.size() - 1);

    // 최종 배열 상태 출력
    print_array(arr);

    return 0;
}