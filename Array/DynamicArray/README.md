# 동적배열(Dynamic Array)

동적배열은 배열의 크기를 동적으로 변경할 수 있는 배열을 의미합니다.

---

## 1. 개념

-   기본 개녕
    C언어 등에서 지원하는 배열은 기본적으로 정적배열입니다. 정적배열은 크기를 변경할 수 없습니다(C의 realloc()을 이용할 수 있습니다).<br>
    이점을 보완하기 위해, 재할당 및 복사를 지원하는 동적배열을 사용합니다.
    기본적인 특성은 배열과 동일하지만, 재할당정책이 평균성능에 큰 영향을 미치므로, 사용환경에 따라 조절해야합니다.

-   재할당 정책에 따른 성능

---

## 2. 특징

-   앞서 설명한 배열의 특징을 모두 계승합니다.
-   재할당 정책에 따라 평균적인 성능이 달라집니다.

## 3. 시간복잡도

| 연산             | best | worst |
| ---------------- | ---- | ----- |
| 접근(Access)     | O(1) | O(1)  |
| 검색(Search)     | O(n) | O(n)  |
| 삽입(Insertion)  | O(1) | O(n)  |
| 삭제(Deletion)   | O(1) | O(n)  |
| 크기변경(resize) | O(n) | O(n)  |

---

## 4. 사용예제

```C++
#include <iostream>
#include "dynamic_array.h"

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

    return 0;

}

```

---

## 5. 기타

-   Python에서

-   C++ STL vector에서

-   Java에서
