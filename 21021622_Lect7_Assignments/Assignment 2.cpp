#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("matrix.txt"); // Mở file input
    int m, n;
    fin >> m >> n;              // Đọc số dòng và số cột

    int A[100][100];            // Ma trận lưu dữ liệu, tối đa 100x100
    for (int i = 0; i < m; ++i) // Đọc từng hàng
        for (int j = 0; j < n; ++j)
            fin >> A[i][j];
    fin.close();                // Đóng file

    // Khởi tạo tổng lớn nhất với giá trị âm rất lớn
    int maxSum = -1000000000;
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0;

    // Duyệt tất cả các cặp hàng trên - dưới
    for (int top = 0; top < m; ++top) {
        int temp[100] = {0}; // Mảng lưu tổng từng cột giữa top và bottom

        for (int bottom = top; bottom < m; ++bottom) {
            for (int i = 0; i < n; ++i)
                temp[i] += A[bottom][i]; // Cộng dồn từng cột

            // Áp dụng thuật toán Kadane 1 chiều trên mảng temp[]
            int currSum = temp[0];
            int tempC1 = 0;
            for (int i = 1, start = 0; i < n; ++i) {
                if (currSum < 0) {
                    currSum = temp[i];
                    start = i;
                } else {
                    currSum += temp[i];
                }

                // Nếu tìm được tổng lớn hơn, lưu lại tọa độ
                if (currSum > maxSum) {
                    maxSum = currSum;
                    r1 = top + 1;        // Cộng 1 vì đề yêu cầu đánh số từ 1
                    r2 = bottom + 1;
                    c1 = start + 1;
                    c2 = i + 1;
                }
            }
        }
    }

    ofstream fout("matrix.out"); // Mở file kết quả
    fout << r1 << " " << c1 << " " << r2 << " " << c2 << " " << maxSum;
    fout.close(); // Đóng file
    return 0;
}
