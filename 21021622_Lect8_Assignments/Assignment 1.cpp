#include <iostream>

using namespace std;

// Hàm tự định nghĩa để hoán đổi giá trị của hai số thực
// a: tham chiếu đến số thứ nhất
// b: tham chiếu đến số thứ hai
void swap_doubles(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

// Hàm phân hoạch (partition) mảng xung quanh một pivot
// arr[] --> Mảng C-style cần phân hoạch
// low   --> Chỉ số bắt đầu
// high  --> Chỉ số kết thúc
// Trả về chỉ số của pivot sau khi phân hoạch
int partition(double arr[], int low, int high) {
    // Chọn phần tử cuối cùng làm pivot
    double pivot = arr[high];
    // Chỉ số của phần tử nhỏ hơn pivot
    int i = (low - 1);

    // Duyệt qua các phần tử từ low đến high-1
    for (int j = low; j <= high - 1; j++) {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (arr[j] <= pivot) {
            i++; // Tăng chỉ số của phần tử nhỏ hơn
            swap_doubles(arr[i], arr[j]); // Đổi chỗ arr[i] và arr[j] bằng hàm tự viết
        }
    }
    // Đưa pivot về đúng vị trí của nó trong mảng đã sắp xếp
    swap_doubles(arr[i + 1], arr[high]);
    // Trả về vị trí của pivot
    return (i + 1);
}

// Hàm thực hiện thuật toán Quick Sort
// arr[] --> Mảng C-style cần sắp xếp
// low   --> Chỉ số bắt đầu
// high  --> Chỉ số kết thúc
void quickSort(double arr[], int low, int high) {
    // Điều kiện dừng đệ quy: khi mảng con có ít nhất 2 phần tử
    if (low < high) {
        // pi là chỉ số của pivot sau khi phân hoạch
        int pi = partition(arr, low, high);

        // Đệ quy sắp xếp các phần tử trước pivot
        quickSort(arr, low, pi - 1);
        // Đệ quy sắp xếp các phần tử sau pivot
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    // Đọc số lượng phần tử
    cin >> n; 

    // Kiểm tra nếu n <= 0 thì không cần làm gì thêm
    if (n <= 0) {
        return 0;
    }

    // Khởi tạo mảng C-style để lưu trữ các số thực
    double numbers[n];

    // Đọc n số thực từ input vào mảng
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i]; 
    }

    // Gọi hàm quickSort để sắp xếp mảng
    quickSort(numbers, 0, n - 1);

    // In ra mảng đã sắp xếp
    for (int i = 0; i < n; ++i) {
        cout << numbers[i] << (i == n - 1 ? "" : " "); 
    }
    cout << endl; 

    return 0;
}
