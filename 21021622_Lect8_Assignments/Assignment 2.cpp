#include <iostream>

using namespace std;

int main() {
    int n; // Số lượng sinh viên
    int X; // Tổng số tuổi cần tìm

    // Đọc n và X từ dòng đầu tiên
    cin >> n >> X;

    // Kiểm tra nếu n hoặc X không hợp lệ (ví dụ: âm hoặc quá lớn tùy vào giới hạn bài toán)
    // Ở đây chỉ kiểm tra trường hợp cơ bản n <= 0
    if (n <= 0) {
        // Nếu không có sinh viên nào, chỉ có thể tạo tổng 0.
        if (X == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return 0;
    }

    // Khởi tạo mảng C-style để lưu tuổi của n sinh viên
    // Lưu ý: Sử dụng Variable Length Array (VLA)
    int ages[n];
    // Đọc tuổi của n sinh viên từ dòng thứ hai
    for (int i = 0; i < n; ++i) {
        cin >> ages[i];
    }

    // Sử dụng Quy hoạch động (Dynamic Programming) với mảng C-style
    // dp[s] sẽ là true nếu có thể tạo ra tổng s từ các tuổi đã xét, ngược lại là false.
    // Kích thước của mảng dp là X+1 (từ 0 đến X)
    // Lưu ý: Cần cấp phát động nếu X quá lớn hoặc để tuân thủ C++ chuẩn hơn VLA.
    // bool* dp = new bool[X + 1]; // Cách cấp phát động
    bool dp[X + 1]; // Sử dụng VLA cho đơn giản

    // Khởi tạo mảng dp
    dp[0] = true; // Luôn có thể tạo ra tổng 0
    for (int s = 1; s <= X; ++s) {
        dp[s] = false; // Các tổng khác ban đầu chưa thể tạo được
    }

    // Duyệt qua từng tuổi của sinh viên
    for (int i = 0; i < n; ++i) {
        int current_age = ages[i];
        // Duyệt qua các tổng có thể có từ X về current_age
        // Phải duyệt ngược để tránh việc sử dụng cùng một tuổi nhiều lần trong một lần lặp
        for (int s = X; s >= current_age; --s) {
            // Nếu có thể tạo ra tổng (s - current_age) trước đó
            // thì cũng có thể tạo ra tổng s bằng cách thêm sinh viên có tuổi 'current_age' vào
            if (dp[s - current_age]) {
                dp[s] = true;
            }
        }
         // Tối ưu: Nếu đã tìm được cách tạo tổng X thì có thể dừng sớm
         // if (dp[X]) break; 
    }

    // Kiểm tra xem có thể tạo ra tổng X hay không
    if (dp[X]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    // Nếu dùng cấp phát động, cần giải phóng bộ nhớ:
    // delete[] dp;

    return 0;
}
