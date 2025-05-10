#include <iostream> 

using namespace std;

// Hàm giải quyết bài toán 2 (duyệt tập con)
// ages: mảng tuổi
// n: số lượng học sinh
// X: tổng tuổi mục tiêu
// currentIndex: chỉ số của học sinh đang xét
// currentSum: tổng tuổi hiện tại của nhóm đang xây dựng
bool findSubsetSum(int ages[], int n, int X, int currentIndex, int currentSum) {
    // Nếu tổng hiện tại bằng X, đã tìm thấy
    if (currentSum == X) {
        return true;
    }
    // Nếu đã duyệt hết mảng hoặc tổng hiện tại vượt X (và X > 0, tuổi không âm)
    // Điều kiện currentSum > X chỉ là tối ưu nếu X dương và tuổi không âm.
    if (currentIndex == n || (X > 0 && currentSum > X && X >=0) ) { // Đảm bảo X không âm cho tối ưu này
        return false;
    }
     // Nếu X < 0 và currentSum > X thì vẫn có thể tìm được nếu có số âm (đề bài là tuổi nên không âm)
    if (X < 0 && currentSum > X && ages[currentIndex] < 0) {
        // Tiếp tục tìm kiếm nếu có thể giảm currentSum
    } else if (X < 0 && currentSum > X && ages[currentIndex] >=0) {
        return false; // Không thể giảm currentSum nếu chỉ thêm số không âm
    }


    // Trường hợp 1: Bao gồm phần tử hiện tại (học sinh tại currentIndex)
    // Chỉ bao gồm nếu tuổi của học sinh là hợp lệ (ví dụ: không âm, tùy theo yêu cầu bài toán)
    // Trong bài này, tuổi là số tự nhiên (>=0)
    if (findSubsetSum(ages, n, X, currentIndex + 1, currentSum + ages[currentIndex])) {
        return true;
    }

    // Trường hợp 2: Không bao gồm phần tử hiện tại
    if (findSubsetSum(ages, n, X, currentIndex + 1, currentSum)) {
        return true;
    }

    return false; // Không tìm thấy nhóm nào thỏa mãn sau khi thử cả hai trường hợp
}

void solve_problem2() {
    cout << "--- Giải Bài Toán 2: Tổng Tuổi ---" << endl;
    int n, X;
    cout << "Nhập số lượng học sinh (n) và tổng tuổi mục tiêu (X): ";
    cin >> n >> X;

    if (n <= 0) {
        cout << "Số lượng học sinh phải là số dương." << endl;
        return;
    }
     if (X < 0 && n > 0) { // Nếu X âm và có học sinh, mặc định là NO vì tuổi là số tự nhiên
        bool has_negative_age = false;
        // Nếu đề cho phép tuổi âm thì cần kiểm tra, nhưng đề là "natural numbers" (số tự nhiên)
        // Số tự nhiên thường được hiểu là {0, 1, 2, ...} hoặc {1, 2, 3, ...}
        // Giả sử số tự nhiên >= 0
        // Nếu X = 0, có thể có nhóm rỗng (tổng 0) hoặc nhóm có tuổi 0.
        // Nếu X = 0 và không có học sinh nào tuổi 0, thì là NO trừ khi nhóm rỗng được chấp nhận.
        // Hàm findSubsetSum hiện tại sẽ trả về YES cho X=0 nếu không chọn ai.
    }


    int *ages = new int[n];
    cout << "Nhập tuổi của " << n << " học sinh (số tự nhiên), cách nhau bởi dấu cách:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> ages[i];
        if (ages[i] < 0) {
            cout << "Tuổi phải là số tự nhiên (không âm). Vui lòng nhập lại." << endl;
            delete[] ages;
            return;
        }
    }

    // Gọi hàm đệ quy để tìm kiếm
    // Bắt đầu với index = 0, current_sum = 0
    if (findSubsetSum(ages, n, X, 0, 0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    delete[] ages;
    cout << "------------------------------------" << endl << endl;
}

int main() {
    solve_problem2();
    return 0;
}
