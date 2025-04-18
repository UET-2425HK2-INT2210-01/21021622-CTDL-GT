#include <iostream>
using namespace std;

// Hàm đệ quy đếm chữ số
int countDigits(int n) {
    if (n < 10)             // Khi n là 1 chữ số
        return 1;           // Đếm được 1 chữ số
    // Chia 10 để bỏ đi 1 chữ số, cộng thêm 1
    return 1 + countDigits(n / 10);
}

int main() {
    int n;
    cin >> n;               // Đọc số nguyên dương
    cout << countDigits(n);// In số chữ số của n
    return 0;
}
