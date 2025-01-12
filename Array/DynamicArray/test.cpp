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
    DynamicArray<int> arr(5, 0);

    arr.resize(10);

    for(int i = 0; i < arr.capacity(); i++)
        arr[i] = i;

    arr.push_back(11);
    arr.push_back(12);

    arr.pop_back();

    arr.insert(10, 10);
    arr.erase(arr.size() - 1);

    // 최종 배열 상태 출력
    print_array(arr);

    return 0;
}