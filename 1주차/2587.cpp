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

    sort(array, array+5); //�⺻������ ���� ����, sort(first, last, compare) => �� �ɼ� ������ ���� ����

    cout << total / 5 << '\n' << array[2] << '\n';

    return 0;
}
