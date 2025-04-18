#include <iostream>   
using namespace std;

// Hàm đệ quy tính tổng 1 + 2 + ... + n
int sumUpTo(int n) {
    if (n == 1)             // Trường hợp cơ sở: n = 1
        return 1;           // Tổng đến 1 là 1
    return n + sumUpTo(n - 1);  // Tính n + tổng từ 1 đến (n-1)
}

int main() {
    int n;
    cin >> n;               
    cout << sumUpTo(n);     
    return 0;               
}
