#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm> 
#include <numeric>   

using namespace std;

// Cấu trúc để lưu trữ một cạnh và trọng số của nó
struct Edge {
    int u, v;
    long long cost;
    // Toán tử so sánh để sắp xếp các cạnh theo chi phí
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

// Cấu trúc dữ liệu Disjoint Set Union (DSU)
struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0); // Khởi tạo mỗi nút là cha của chính nó
    }

    // Tìm tập hợp chứa nút u (với nén đường đi)
    int find(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }

    // Hợp nhất hai tập hợp chứa u và v
    // Trả về true nếu hợp nhất thành công (u và v thuộc các tập khác nhau)
    // Trả về false nếu u và v đã thuộc cùng một tập hợp
    bool unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            parent[rootU] = rootV; // Gán cha của một tập hợp cho tập hợp kia
            return true;
        }
        return false;
    }
};

int main() {
    // Mở file input và output
    ifstream fin("connection.txt");
    ofstream fout("connection.out");

    if (!fin.is_open()) {
        cerr << "Loi: Khong the mo file connection.txt" << endl;
        return 1;
    }
    if (!fout.is_open()) {
        cerr << "Loi: Khong the mo file connection.out" << endl;
        return 1;
    }

    int n, m; // n: số máy tính, m: số kết nối khả thi
    fin >> n >> m;

    vector<Edge> edges; // Danh sách tất cả các kết nối khả thi

    // Đọc m kết nối khả thi
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long d;
        fin >> u >> v >> d;
        edges.push_back({u, v, d});
    }

    // Sắp xếp các cạnh theo chi phí tăng dần
    sort(edges.begin(), edges.end());

    DSU dsu(n); // Khởi tạo DSU với n máy tính
    long long total_min_cost = 0;
    vector<Edge> mst_edges; // Danh sách các cạnh trong Cây Khung Nhỏ Nhất
    int edges_in_mst = 0;

    // Duyệt qua các cạnh đã sắp xếp
    for (const auto& edge : edges) {
        // Nếu việc thêm cạnh này không tạo ra chu trình
        if (dsu.unite(edge.u, edge.v)) {
            total_min_cost += edge.cost; // Cộng chi phí vào tổng
            mst_edges.push_back(edge);   // Thêm cạnh vào MST
            edges_in_mst++;
            if (edges_in_mst == n - 1) { // Nếu đã đủ n-1 cạnh cho MST
                break;
            }
        }
    }

    // Ghi kết quả ra file connection.out
    fout << total_min_cost << endl;
    for (const auto& edge : mst_edges) {
        fout << edge.u << " " << edge.v << " " << edge.cost << endl;
    }

    // Đóng file
    fin.close();
    fout.close();

    return 0;
}
