#include <iostream>

using namespace std;

// Định nghĩa cấu trúc Item để lưu trọng lượng và giá trị của đồ vật
struct Item {
    int weight;
    int value;
};

// Hàm tự định nghĩa để tìm giá trị lớn hơn giữa hai số nguyên
// a: số thứ nhất
// b: số thứ hai
// Trả về giá trị lớn hơn
int max_int(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n; // Số lượng đồ vật
    int X; // Trọng lượng tối đa của túi

    // Đọc n và X từ dòng đầu tiên
    cin >> n >> X;

    // Kiểm tra nếu n hoặc X không hợp lệ
    if (n <= 0 || X < 0) {
         // Nếu không có đồ vật hoặc túi không có sức chứa, tổng giá trị tối đa là 0
        cout << 0 << endl;
        return 0;
    }

    // Khởi tạo mảng C-style để lưu trữ các đồ vật
    // Lưu ý: Sử dụng Variable Length Array (VLA)
    Item items[n];
    // Đọc thông tin của n đồ vật
    for (int i = 0; i < n; ++i) {
        cin >> items[i].weight >> items[i].value;
    }

    // Sử dụng Quy hoạch động (Dynamic Programming) với mảng C-style
    // dp[w] sẽ lưu trữ giá trị lớn nhất có thể đạt được với trọng lượng tối đa là w
    // Kích thước của mảng dp là X+1 (từ 0 đến X)
    // Lưu ý: Cần cấp phát động nếu X quá lớn hoặc để tuân thủ C++ chuẩn hơn VLA.
    // int* dp = new int[X + 1]; // Cách cấp phát động
    int dp[X + 1]; // Sử dụng VLA

    // Khởi tạo mảng dp với tất cả giá trị bằng 0
    for (int w = 0; w <= X; ++w) {
        dp[w] = 0;
    }

    // Duyệt qua từng đồ vật
    for (int i = 0; i < n; ++i) {
        int current_weight = items[i].weight;
        int current_value = items[i].value;

        // Chỉ xử lý đồ vật nếu trọng lượng của nó không âm và có thể nằm trong túi
        if (current_weight < 0) continue; // Bỏ qua đồ vật có trọng lượng âm

        // Duyệt qua các trọng lượng có thể có của túi, từ X về trọng lượng của đồ vật hiện tại
        // Phải duyệt ngược để đảm bảo mỗi đồ vật chỉ được chọn một lần (tính chất 0/1)
        for (int w = X; w >= current_weight; --w) {
            // Quyết định:
            // 1. Không chọn đồ vật thứ i: giá trị vẫn là dp[w]
            // 2. Chọn đồ vật thứ i (nếu có thể, tức là w >= current_weight):
            //    giá trị sẽ là giá trị của túi với trọng lượng (w - current_weight) cộng với giá trị của đồ vật i (dp[w - current_weight] + current_value)
            // Chọn phương án cho giá trị lớn hơn bằng hàm tự viết max_int
            dp[w] = max_int(dp[w], dp[w - current_weight] + current_value);
        }
    }

    // Giá trị lớn nhất có thể đạt được với trọng lượng tối đa X chính là dp[X]
    cout << dp[X] << endl;

    // Nếu dùng cấp phát động, cần giải phóng bộ nhớ:
    // delete[] dp;

    return 0;
}
