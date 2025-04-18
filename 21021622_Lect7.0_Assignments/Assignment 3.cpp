#include <iostream>
using namespace std;

// Hàm đệ quy tính F(n)
int fibonacci(int n) {
    if (n == 0)             // F(0) = 0
        return 0;
    if (n == 1)             // F(1) = 1
        return 1;
    // F(n) = F(n-1) + F(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cin >> n;               // Đọc chỉ số Fibonacci cần tính
    cout << fibonacci(n);   // In F(n)
    return 0;
}
