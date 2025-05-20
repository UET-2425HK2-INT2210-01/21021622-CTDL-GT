#include <iostream>
#include <vector>

using namespace std;

// Hàm thực hiện Tìm kiếm theo chiều sâu (DFS)
void dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true; // Đánh dấu đỉnh hiện tại đã được thăm
    // Duyệt qua tất cả các đỉnh kề
    for (int v : adj[u]) {
        if (!visited[v]) { // Nếu một đỉnh kề chưa được thăm
            dfs(v, adj, visited); // Gọi đệ quy DFS trên đỉnh đó
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // Tăng tốc độ các thao tác I/O của C++
    cin.tie(NULL); // Tách cin khỏi cout

    int n, m;
    // Đọc số lượng đỉnh (n) và cạnh (m)
    cin >> n >> m;

    // Danh sách kề để biểu diễn đồ thị.
    // Các đỉnh được đánh số từ 1 theo đề bài, vì vậy kích thước là n+1 cho tiện.
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false); // Để theo dõi các đỉnh đã thăm

    // Đọc m cạnh
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // Thêm các cạnh vào danh sách kề (đồ thị vô hướng)
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int connected_components = 0; // Biến đếm số thành phần liên thông
    // Duyệt qua tất cả các đỉnh từ 1 đến n
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) { // Nếu đỉnh i chưa được thăm
            dfs(i, adj, visited); // Bắt đầu DFS từ đỉnh này
            connected_components++; // Tăng số lượng thành phần liên thông
        }
    }

    // Xuất ra tổng số thành phần liên thông
    cout << connected_components << endl;

    return 0;
}
