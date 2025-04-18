#include <iostream>
using namespace std;

// Đệ quy sinh chuỗi nhị phân
void binary(int a[], int i, int n) {
    if (i == n) {
        // Khi đủ độ dài thì in chuỗi
        for (int j = 0; j < n; ++j)
            cout << a[j];
        cout << "\n";
        return;
    }

    // Gán bit 0 ở vị trí i rồi tiếp tục
    a[i] = 0;
    binary(a, i + 1, n);

    // Gán bit 1 ở vị trí i rồi tiếp tục
    a[i] = 1;
    binary(a, i + 1, n);
}

int main() {
    int n;
    cin >> n;         // Nhập độ dài chuỗi nhị phân
    int a[20];        // Mảng lưu chuỗi nhị phân (tối đa n=20)
    binary(a, 0, n);  // Bắt đầu từ vị trí 0
    return 0;
}
