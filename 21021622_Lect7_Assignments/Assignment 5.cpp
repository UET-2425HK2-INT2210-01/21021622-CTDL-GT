#include <iostream>
using namespace std;

// Sinh hoán vị bằng đệ quy
void generate(int a[], bool used[], int pos, int n) {
    if (pos == n) {
        // In ra một hoán vị khi đủ n phần tử
        for (int i = 0; i < n; ++i)
            cout << a[i];
        cout << "\n";
        return;
    }

    // Thử gán các số từ 1 đến n nếu chưa dùng
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            a[pos] = i;        // Gán số i vào vị trí pos
            used[i] = true;    // Đánh dấu đã dùng
            generate(a, used, pos + 1, n); // Gọi tiếp
            used[i] = false;   // Backtrack: bỏ đánh dấu
        }
    }
}

int main() {
    int n;
    cin >> n;             // Nhập độ dài hoán vị
    int a[10];            // Mảng lưu hoán vị
    bool used[11] = {};   // Mảng đánh dấu số đã dùng (1-indexed)
    generate(a, used, 0, n); // Bắt đầu từ vị trí 0
    return 0;
}
