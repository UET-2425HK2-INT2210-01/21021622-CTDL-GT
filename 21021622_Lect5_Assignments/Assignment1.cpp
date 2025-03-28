#include <iostream>
using namespace std;

/*
 * Cấu trúc Node đại diện cho 1 nút trong cây
 * - value: Giá trị số nguyên của nút
 * - firstChild: Con trỏ tới nút con đầu tiên (con trái nhất)
 * - nextSibling: Con trỏ tới nút anh em kế tiếp (cùng cha)
 * - parent: Con trỏ tới nút cha (dùng để xác định gốc cây)
 */
struct Node {
    int value;
    Node* firstChild;
    Node* nextSibling; 
    Node* parent;
};

/*
 * Hàm tạo mới một nút
 * - Nhận vào giá trị value
 * - Khởi tạo tất cả con trỏ là nullptr
 * - Trả về con trỏ tới nút mới tạo
 */
Node* createNode(int value) {
    Node* newNode = new Node();  // Cấp phát bộ nhớ động
    newNode->value = value;      // Gán giá trị
    newNode->firstChild = nullptr; // Chưa có con
    newNode->nextSibling = nullptr; // Chưa có anh em
    newNode->parent = nullptr;   // Chưa có cha
    return newNode;
}

/*
 * Hàm thêm một nút con vào nút cha
 * - parent: Nút cha cần thêm con
 * - child: Nút con cần thêm vào
 * - Logic: Thêm vào cuối danh sách con của parent
 */
void addChild(Node* parent, Node* child) {
    // Thiết lập quan hệ cha-con
    child->parent = parent;
    
    // Nếu parent chưa có con nào
    if (parent->firstChild == nullptr) {
        parent->firstChild = child; // Thêm làm con đầu tiên
    } 
    // Nếu đã có con, tìm đến cuối danh sách con
    else {
        Node* current = parent->firstChild;
        // Duyệt đến cuối danh sách liên kết các con
        while (current->nextSibling != nullptr) {
            current = current->nextSibling;
        }
        // Thêm child vào vị trí cuối cùng
        current->nextSibling = child;
    }
}

/*
 * Hàm tính chiều cao của cây
 * - Chiều cao tính từ gốc đến lá xa nhất
 * - Sử dụng đệ quy để tính chiều cao các nhánh con
 */
int calculateHeight(Node* node) {
    // Nếu node rỗng, chiều cao là 0
    if (node == nullptr) return 0;
    
    int maxH = 0; // Lưu chiều cao lớn nhất của các nhánh con
    Node* child = node->firstChild;
    
    // Duyệt qua tất cả các con của node hiện tại
    while (child != nullptr) {
        // Tính chiều cao của cây con
        int h = calculateHeight(child);
        // Cập nhật chiều cao lớn nhất
        if (h > maxH) maxH = h;
        child = child->nextSibling;
    }
    
    // Chiều cao tại node hiện tại = chiều cao lớn nhất của các con + 1
    return maxH + 1;
}

/*
 * Hàm duyệt cây theo thứ tự trước (Preorder)
 * - Thứ tự: Gốc -> Con trái -> Con phải
 * - Sử dụng đệ quy
 */
void preorder(Node* node) {
    if (node == nullptr) return;
    
    // 1. Xử lý nút gốc trước (in giá trị)
    cout << node->value << " ";
    
    // 2. Duyệt các con từ trái sang phải
    Node* child = node->firstChild;
    while (child != nullptr) {
        preorder(child);
        child = child->nextSibling;
    }
}

/*
 * Hàm duyệt cây theo thứ tự sau (Postorder)
 * - Thứ tự: Con trái -> Con phải -> Gốc
 * - Sử dụng đệ quy
 */
void postorder(Node* node) {
    if (node == nullptr) return;
    
    // 1. Duyệt các con từ trái sang phải trước
    Node* child = node->firstChild;
    while (child != nullptr) {
        postorder(child);
        child = child->nextSibling;
    }
    
    // 2. Xử lý nút gốc sau (in giá trị)
    cout << node->value << " ";
}

/*
 * Hàm kiểm tra cây có phải là cây nhị phân không
 * - Cây nhị phân: Mỗi nút có tối đa 2 con
 * - Sử dụng đệ quy kiểm tra từng nút
 */
bool isBinary(Node* node) {
    if (node == nullptr) return true;
    
    int childCount = 0;
    Node* child = node->firstChild;
    
    // Đếm số con của node hiện tại
    while (child != nullptr) {
        childCount++;
        // Nếu có nhiều hơn 2 con -> không phải nhị phân
        if (childCount > 2) return false;
        child = child->nextSibling;
    }
    
    // Kiểm tra đệ quy cho từng con
    child = node->firstChild;
    while (child != nullptr) {
        if (!isBinary(child)) return false;
        child = child->nextSibling;
    }
    
    return true;
}

/*
 * Hàm duyệt cây theo thứ tự giữa (Inorder)
 * - Chỉ áp dụng cho cây nhị phân
 * - Thứ tự: Con trái -> Gốc -> Con phải
 */
void inorder(Node* node) {
    if (node == nullptr) return;
    
    // Xác định con trái (con đầu tiên)
    Node* left = node->firstChild;
    // Xác định con phải (con thứ hai nếu có)
    Node* right = (left != nullptr) ? left->nextSibling : nullptr;
    
    // 1. Duyệt con trái trước
    inorder(left);
    // 2. Xử lý nút gốc
    cout << node->value << " ";
    // 3. Duyệt con phải sau
    inorder(right);
}

int main() {
    int N, M;
    cin >> N >> M;
    
    // Mảng lưu các nút theo giá trị (index từ 1 đến N)
    Node* nodes[10001] = {nullptr};
    Node* root = nullptr;
    
    // Đọc M cặp quan hệ cha-con
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        
        // Tạo nút cha nếu chưa tồn tại
        if (nodes[u] == nullptr) {
            nodes[u] = createNode(u);
        }
        // Tạo nút con nếu chưa tồn tại
        if (nodes[v] == nullptr) {
            nodes[v] = createNode(v);
        }
        
        // Thêm quan hệ cha-con
        addChild(nodes[u], nodes[v]);
    }
    
    // Tìm nút gốc (nút không có cha)
    for (int i = 1; i <= N; ++i) {
        if (nodes[i] != nullptr && nodes[i]->parent == nullptr) {
            root = nodes[i];
            break;
        }
    }
    
    // In chiều cao cây (trừ 1 vì tính từ 0)
    cout << calculateHeight(root) - 1 << endl;
    
    // Duyệt tiền thứ tự
    preorder(root);
    cout << endl;
    
    // Duyệt hậu thứ tự
    postorder(root);
    cout << endl;
    
    // Kiểm tra và in kết quả duyệt trung thứ tự
    if (isBinary(root)) {
        inorder(root);
        cout << endl;
    } else {
        cout << "NOT BINARY TREE" << endl;
    }
    
    // Giải phóng bộ nhớ
    for (int i = 1; i <= N; ++i) {
        delete nodes[i];
    }
    
    return 0;
}
