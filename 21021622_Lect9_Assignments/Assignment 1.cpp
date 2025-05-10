#include <iostream> 

using namespace std;

// Hàm hoán đổi hai số thực
void swap_double(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

// Hàm phân hoạch (partition) cho Quick Sort
// Chọn phần tử cuối cùng làm pivot
// Đặt pivot vào đúng vị trí trong mảng đã sắp xếp
// Đặt tất cả các phần tử nhỏ hơn pivot sang trái pivot
// Và tất cả các phần tử lớn hơn pivot sang phải pivot
int partition(double arr[], int low, int high) {
    double pivot = arr[high]; // Chọn pivot là phần tử cuối
    int i = (low - 1);      // Index của phần tử nhỏ hơn

    for (int j = low; j <= high - 1; j++) {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (arr[j] <= pivot) {
            i++; // Tăng index của phần tử nhỏ hơn
            swap_double(arr[i], arr[j]);
        }
    }
    swap_double(arr[i + 1], arr[high]);
    return (i + 1);
}

// Hàm thực hiện Quick Sort
void quickSort(double arr[], int low, int high) {
    if (low < high) {
        // pi là chỉ số phân hoạch, arr[pi] bây giờ đã ở đúng vị trí
        int pi = partition(arr, low, high);

        // Sắp xếp đệ quy các phần tử trước và sau phân hoạch
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void solve_problem1() {
    cout << "--- Giải Bài Toán 1: Quick Sort ---" << endl;
    int n;
    cout << "Nhập số lượng phần tử (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Số lượng phần tử phải là số dương." << endl;
        return;
    }

    // Cấp phát động mảng để lưu các số thực
    double *numbers = new double[n];

    cout << "Nhập " << n << " số thực, cách nhau bởi dấu cách hoặc xuống dòng:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    quickSort(numbers, 0, n - 1);

    cout << "Các số sau khi sắp xếp:" << endl;
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    // Giải phóng bộ nhớ đã cấp phát
    delete[] numbers;
    cout << "------------------------------------" << endl << endl;
}

int main() {
    solve_problem1();
    return 0;
}
