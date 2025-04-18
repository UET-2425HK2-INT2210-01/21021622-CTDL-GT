#include <iostream>
using namespace std;

// Hàm đệ quy tính x^n, với n có thể âm
double power(double x, int n) {
    if (n == 0)               // x^0 = 1 dù x có giá trị gì
        return 1.0;
    else if (n > 0)           // với n dương: nhân dần x
        return x * power(x, n - 1);
    else                      // với n âm: x^(-n) = 1 / x^n
        return 1.0 / power(x, -n);
}

int main() {
    double x;
    int n;
    cin >> x >> n;            // Đọc cơ số x (double) và số mũ n (int)
    cout << power(x, n);      // In kết quả x^n (có thể là phân số nếu n<0)
    return 0;
}
