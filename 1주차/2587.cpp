#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int array[5];
    int total = 0;
    for (int i = 0; i < 5; i++) {
        cin >> array[i];
        total += array[i];
    }

    sort(array, array+5); //기본적으로 오름 차순, sort(first, last, compare) => 비교 옵션 변경을 위한 형태, compare false면 swap

    cout << total / 5 << '\n' << array[2] << '\n';

    return 0;
}
