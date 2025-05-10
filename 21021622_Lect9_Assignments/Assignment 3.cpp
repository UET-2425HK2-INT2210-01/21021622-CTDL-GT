#include <iostream> 

using namespace std;

// Hàm đệ quy cho bài toán Knapsack 0/1
// Trả về giá trị lớn nhất có thể đạt được
// weights: mảng trọng lượng của các đồ vật
// values: mảng giá trị của các đồ vật
// capacity: sức chứa tối đa của túi
// index: chỉ số của đồ vật hiện tại đang được xem xét
// n: tổng số đồ vật
int knapsack(int weights[], int values[], int capacity, int index, int n) {
    // Trường hợp cơ sở:
    // Nếu không còn đồ vật nào để xét (index == n) hoặc sức chứa bằng 0
    if (index == n || capacity == 0) {
        return 0; // Không thể thêm giá trị nào nữa
    }

    // Nếu trọng lượng của đồ vật hiện tại (weights[index]) lớn hơn sức chứa còn lại của túi (capacity),
    // thì không thể chọn đồ vật này. Chuyển sang xem xét đồ vật tiếp theo.
    if (weights[index] > capacity) {
        return knapsack(weights, values, capacity, index + 1, n);
    }

    // Trường hợp khác, có hai lựa chọn cho đồ vật tại 'index':
    // 1. Chọn đồ vật hiện tại:
    //    Giá trị thu được = giá trị của đồ vật này (values[index])
    //                      + giá trị tối đa từ các đồ vật còn lại (từ index + 1)
    //                        với sức chứa giảm đi (capacity - weights[index]).
    int include_item_value = values[index] + knapsack(weights, values, capacity - weights[index], index + 1, n);

    // 2. Không chọn đồ vật hiện tại:
    //    Giá trị thu được = giá trị tối đa từ các đồ vật còn lại (từ index + 1)
    //                      với sức chứa không đổi (capacity).
    int exclude_item_value = knapsack(weights, values, capacity, index + 1, n);

    // Trả về giá trị lớn hơn giữa hai lựa chọn trên.
    return (include_item_value > exclude_item_value) ? include_item_value : exclude_item_value;
}

void solve_problem3() {
    cout << "--- Giải Bài Toán 3: Cái Túi ---" << endl;
    int n, X; // n: số đồ vật, X: sức chứa tối đa của túi
    cout << "Nhập số lượng đồ vật (n) và sức chứa tối đa của túi (X): ";
    cin >> n >> X;

    if (n <= 0) {
        cout << "Số lượng đồ vật phải là số dương." << endl;
        return;
    }
    if (X < 0) {
        cout << "Sức chứa của túi không thể âm." << endl;
        // Nếu sức chứa là 0, giá trị tối đa cũng là 0 (trừ khi có vật nặng 0, giá trị > 0)
        // Hàm knapsack hiện tại xử lý đúng cho capacity = 0.
        return; 
    }


    int *weights = new int[n];
    int *values = new int[n];

    cout << "Nhập trọng lượng và giá trị cho " << n << " đồ vật (mỗi dòng một cặp w v, là số tự nhiên):" << endl;
    for (int i = 0; i < n; i++) {
        // cout << "Đồ vật " << i + 1 << " (trọng lượng giá trị): ";
        cin >> weights[i] >> values[i];
        if (weights[i] < 0 || values[i] < 0) {
            cout << "Trọng lượng và giá trị phải là số tự nhiên (không âm)." << endl;
            delete[] weights;
            delete[] values;
            return;
        }
    }

    // Gọi hàm knapsack, bắt đầu từ đồ vật đầu tiên (index 0)
    int max_value = knapsack(weights, values, X, 0, n);
    cout << "Tổng giá trị lớn nhất có thể lấy được: " << max_value << endl;

    delete[] weights;
    delete[] values;
    cout << "------------------------------------" << endl << endl;
}

int main() {
    solve_problem3();
    return 0;
}
