#include <iostream>
using namespace std;

// Hàm đệ quy tính tổng chữ số
int sumDigits(int n) {
    if (n == 0)             // Khi n = 0, không còn chữ số nào
        return 0;
    // Lấy chữ số cuối (n%10) cộng với tổng chữ số còn lại
    return (n % 10) + sumDigits(n / 10);
}

int main() {
    int n;
    cin >> n;               // Đọc số nguyên dương
    cout << sumDigits(n);   // In tổng các chữ số
    return 0;
}
