#include <iostream>
#include <vector>
#include <queue>
#include <limits> 

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // Tăng tốc độ các thao tác I/O của C++
    cin.tie(NULL); // Tách cin khỏi cout

    int n, m, start_node, end_node;
    // Đọc số lượng đỉnh (n), cạnh (m), đỉnh bắt đầu (X), và đỉnh kết thúc (Y)
    cin >> n >> m >> start_node >> end_node;

    // Danh sách kề để biểu diễn đồ thị có hướng.
    // Các đỉnh được đánh số từ 1, vì vậy kích thước là n+1 cho tiện.
    vector<vector<int>> adj(n + 1);

    // Đọc m cạnh
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // Thêm cạnh có hướng từ u đến v
        adj[u].push_back(v);
    }

    // Hàng đợi cho BFS
    queue<pair<int, int>> q; // Lưu trữ {đỉnh, khoảng_cách_từ_đỉnh_bắt_đầu}

    // Vector để lưu trữ khoảng cách từ đỉnh bắt đầu.
    // Khởi tạo khoảng cách là -1 (hoặc một giá trị lớn) để biểu thị không thể đến được.
    vector<int> distance(n + 1, -1);

    // Bắt đầu BFS từ đỉnh bắt đầu
    q.push({start_node, 0});
    distance[start_node] = 0;

    int shortest_path_edges = -1; // Khởi tạo là -1 (không tìm thấy đường đi)

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int u = current.first;
        int d = current.second;

        // Nếu chúng ta đến được đỉnh kết thúc
        if (u == end_node) {
            shortest_path_edges = d;
            break; // Tìm thấy đường đi ngắn nhất, không cần duyệt thêm
        }

        // Duyệt các đỉnh kề
        for (int v : adj[u]) {
            // Nếu đỉnh kề v chưa được thăm (khoảng cách là -1)
            if (distance[v] == -1) {
                distance[v] = d + 1; // Cập nhật khoảng cách
                q.push({v, d + 1});   // Thêm vào hàng đợi
            }
        }
    }

    // Xuất ra số cạnh trong đường đi ngắn nhất
    // Nếu không đến được đỉnh kết thúc, shortest_path_edges sẽ vẫn là -1 (hoặc giá trị khởi tạo ban đầu)
    // Ví dụ trong đề bài ngụ ý rằng luôn tìm thấy đường đi.
    cout << shortest_path_edges << endl;

    return 0;
}
