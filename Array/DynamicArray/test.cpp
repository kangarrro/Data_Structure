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
    // DynamicArray 생성
    DynamicArray<int> arr(5, 0);

    // DS_Tester 생성
    DS_Tester<DynamicArray<int>> tester(arr);

    // resize 테스트
    tester.addOperation<void>(
        [](DynamicArray<int>& obj, size_t newSize) { obj.resize(newSize); },
        10 // 매개변수
    );

    // push_back 테스트
    tester.addOperation<void>(
        [](DynamicArray<int>& obj, int value) { obj.push_back(value); },
        11 // 매개변수
    );

    tester.addOperation<void>(
        [](DynamicArray<int>& obj, int value) { obj.push_back(value); },
        12 // 매개변수
    );

    // pop_back 테스트
    tester.addOperation<void>(
        [](DynamicArray<int>& obj) { obj.pop_back(); }
    );

    // 테스트 실행
    tester.runTest();
    tester.printResult();

    // 최종 배열 상태 출력
    print_array(arr);

    return 0;
}