#include <iostream>   // Thư viện nhập xuất
#include <fstream>    // Thư viện xử lý file
using namespace std;

int main() {
    ifstream fin("numbers.txt"); // Mở file để đọc dữ liệu
    double arr[1000];            // Mảng tĩnh để lưu tối đa 1000 số thực
    int n = 0;                   // Biến đếm số lượng phần tử

    // Đọc từng số thực từ file cho đến khi hết
    while (fin >> arr[n])
        n++;                     // Tăng số lượng mỗi khi đọc được một số
    fin.close();                 // Đóng file

    // Sắp xếp mảng bằng thuật toán selection sort
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i; // Gán vị trí nhỏ nhất tạm thời là i
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx])
                minIdx = j;     // Cập nhật vị trí nhỏ nhất
        }
        // Hoán đổi giá trị nhỏ nhất về đầu đoạn chưa sắp xếp
        double tmp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = tmp;
    }

    ofstream fout("numbers.sorted"); // Mở file để ghi kết quả
    for (int i = 0; i < n; ++i) {
        fout << arr[i];              // Ghi số vào file
        if (i < n - 1) fout << " ";  // Thêm khoảng trắng (trừ số cuối)
    }
    fout.close();                    // Đóng file

    return 0;
}
