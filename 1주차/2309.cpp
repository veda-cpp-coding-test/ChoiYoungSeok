#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[9];
    int total = 0;

    //input
    for (int i = 0; i < 9; i++){
        cin >> arr[i];
        total += arr[i];
    }

    //sorting
    sort(arr, arr+9);

    //���� 20�� �Ǵ� ��¥���� ã�Ƽ� ���ܽ����ش�
    bool found = false;
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (total - (arr[i] + arr[j]) == 100) { //���� 100�� �Ǵ� ���
                arr[i] = arr[j] = -1;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    //output
    for (int i = 0; i < 9; i++) {
        if (arr[i] > 0) {
            cout << arr[i] << '\n';
        }
    }

    return 0;
}
