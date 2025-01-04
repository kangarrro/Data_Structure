#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    std::cout << "Initial size: " << vec.size() << "\n"; // 출력: 0
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    vec[7] = 1;
    std::cout << "Size: " << vec.size() << "\n"; // 출력: 5
    std::cout << "Capacity: " << vec.capacity() << "\n"; // 출력: 8

    vec.push_back(6);
    std::cout << "Size after push_back: " << vec.size() << "\n"; // 출력: 5

    for(auto i : vec) std::cout << i << ' ';

    return 0;
}