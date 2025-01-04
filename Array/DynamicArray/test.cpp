#include "dynamic_array.h"
using namespace std;

template <typename T>
void print_array(const T& array) {
    cout << "SIZE: "<< array.size() << endl;
    cout << "CAPACITY: " << array.capacity() << endl;
    for(int i = 0; i < array.size(); cout << array[i++] << ' ') {}
    cout << endl;
}


int main(){
    DynamicArray<int> arr(10, 0);

    arr.resize(15);
    print_array(arr);

    for(int i = 0; i < arr.capacity(); i++)
        arr[i] = i;
    print_array(arr);

    arr.push_back(15);
    print_array(arr);

    arr.push_back(16);
    print_array(arr);
    
    arr.pop_back();
    print_array(arr);

    return 0;
}

// 테스트 및 성능 측정

// 테스트 코드 별도 구현

// 동적배열 코드 전체 주석추가