#include <iostream>
using namespace std;

// Hàm tính GCD bằng đệ quy Euclid
int gcd(int a, int b) {
    if (b == 0)
        return a;         // Khi b = 0 thì a là GCD
    return gcd(b, a % b); // Gọi đệ quy với (b, a mod b)
}

int main() {
    int x, y;
    cin >> x >> y;         // Nhập từ bàn phím
    cout << gcd(x, y);     // In kết quả GCD ra màn hình
    return 0;
}
