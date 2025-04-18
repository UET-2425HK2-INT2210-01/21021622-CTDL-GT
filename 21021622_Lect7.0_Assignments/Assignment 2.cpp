#include <iostream>
using namespace std;

// Hàm đệ quy tính n!
long long factorial(int n) {
    if (n == 0)             // Trường hợp cơ sở: 0! = 1
        return 1;
    return n * factorial(n - 1);  // Tính n * (n-1)!
}

int main() {
    int n;
    cin >> n;               // Đọc n từ bàn phím
    cout << factorial(n);   // In kết quả n! ra màn hình
    return 0;
}
