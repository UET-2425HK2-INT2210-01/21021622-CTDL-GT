#include <iostream>
using namespace std;

// Hàm phụ đệ quy, rev lưu kết quả tạm thời
int reverseHelper(int n, int rev) {
    if (n == 0)             // Khi n = 0, đã xử lý hết
        return rev;         // Trả về kết quả đư­ợc lưu trong rev
    // Lấy chữ số cuối của n gắn vào rev, rồi gọi tiếp với n/10
    return reverseHelper(n / 10, rev * 10 + (n % 10));
}

// Hàm chính gọi helper với rev khởi đầu = 0
int reverseNumber(int n) {
    return reverseHelper(n, 0);
}

int main() {
    int n;
    cin >> n;               // Đọc số nguyên dương cần đảo ngược
    cout << reverseNumber(n); // In kết quả
    return 0;
}
