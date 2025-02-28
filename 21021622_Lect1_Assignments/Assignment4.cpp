#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int numbers[100]; 
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << numbers[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}