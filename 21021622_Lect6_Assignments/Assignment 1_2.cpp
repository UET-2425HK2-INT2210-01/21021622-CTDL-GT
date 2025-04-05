#include <iostream>
using namespace std;

// Cấu trúc một nút trong cây nhị phân tìm kiếm (Binary Search Tree - BST)
struct BSTNode {
    int data;               // Giá trị của nút
    BSTNode* left;          // Con trỏ tới con trái
    BSTNode* right;         // Con trỏ tới con phải
    BSTNode(int val) : data(val), left(nullptr), right(nullptr) {} // Khởi tạo nút mới
};

// Hàm chèn một giá trị vào BST
BSTNode* insertBST(BSTNode* root, int val) {
    if (!root) return new BSTNode(val); // Nếu cây rỗng, tạo nút mới
    if (val < root->data)
        root->left = insertBST(root->left, val);  // Chèn vào cây con bên trái
    else
        root->right = insertBST(root->right, val); // Chèn vào cây con bên phải
    return root;
}

// Hàm tìm nút có giá trị nhỏ nhất trong cây (dùng khi xóa nút có 2 con)
BSTNode* minValueNode(BSTNode* root) {
    while (root->left) root = root->left; // Duyệt tới cực trái
    return root;
}

// Hàm xóa một nút trong BST
BSTNode* deleteBST(BSTNode* root, int val) {
    if (!root) return root; // Trường hợp cây rỗng
    if (val < root->data)
        root->left = deleteBST(root->left, val);  // Xóa trong cây con bên trái
    else if (val > root->data)
        root->right = deleteBST(root->right, val); // Xóa trong cây con bên phải
    else {
        // Trường hợp nút có 1 hoặc 0 con
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        // Trường hợp có 2 con: tìm giá trị nhỏ nhất ở cây con phải
        BSTNode* temp = minValueNode(root->right);
        root->data = temp->data; // Gán giá trị mới
        root->right = deleteBST(root->right, temp->data); // Xóa nút thay thế
    }
    return root;
}

// Duyệt cây theo thứ tự trung tố (inorder): Trái - Gốc - Phải
void inorder(BSTNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Cấu trúc Heap dạng Max-Heap
struct Heap {
    int arr[100]; // Mảng lưu trữ Heap
    int size;     // Số lượng phần tử hiện tại
    Heap() : size(0) {}

    // Hàm chèn một phần tử vào Heap
    void insert(int val) {
        int i = size++;
        // Duyệt lên trên để đảm bảo tính chất Heap
        while (i > 0 && arr[(i - 1) / 2] < val) {
            arr[i] = arr[(i - 1) / 2]; // Đẩy cha xuống
            i = (i - 1) / 2;           // Di chuyển lên cha
        }
        arr[i] = val; // Gán giá trị vào vị trí đúng
    }

    // Hàm đảm bảo tính chất Heap sau khi chèn hoặc xóa (Heapify)
    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        // So sánh với con trái
        if (left < size && arr[left] > arr[largest]) largest = left;
        // So sánh với con phải
        if (right < size && arr[right] > arr[largest]) largest = right;
        // Nếu cần hoán đổi, tiếp tục heapify
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    // Hàm xóa phần tử trong Heap
    void remove(int val) {
        int i;
        // Tìm phần tử cần xóa
        for (i = 0; i < size; i++) if (arr[i] == val) break;
        if (i == size) return; // Không tìm thấy
        arr[i] = arr[--size];  // Thay thế bằng phần tử cuối cùng
        heapify(i);           // Khôi phục lại Heap
    }

    // In toàn bộ phần tử trong Heap
    void print() {
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    // Dãy số ban đầu
    int values[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    BSTNode* root = nullptr;

    // Chèn các giá trị vào BST
    for (int val : values) root = insertBST(root, val);
    cout << "BST Inorder: ";
    inorder(root);
    cout << endl;

    // Chèn thêm vào BST các giá trị mới
    root = insertBST(root, 14);
    root = insertBST(root, 0);
    root = insertBST(root, 35);
    cout << "BST after insertions: ";
    inorder(root);
    cout << endl;

    // Xóa một số giá trị khỏi BST
    root = deleteBST(root, 6);
    root = deleteBST(root, 13);
    root = deleteBST(root, 35);
    cout << "BST after deletions: ";
    inorder(root);
    cout << endl;

    // Khởi tạo Heap và chèn các giá trị ban đầu
    Heap heap;
    for (int val : values) heap.insert(val);
    cout << "Heap: ";
    heap.print();

    // Chèn thêm giá trị vào Heap
    heap.insert(14);
    heap.insert(0);
    heap.insert(35);
    cout << "Heap after insertions: ";
    heap.print();

    // Xóa các phần tử khỏi Heap
    heap.remove(6);
    heap.remove(13);
    heap.remove(35);
    cout << "Heap after deletions: ";
    heap.print();

    return 0;
}
