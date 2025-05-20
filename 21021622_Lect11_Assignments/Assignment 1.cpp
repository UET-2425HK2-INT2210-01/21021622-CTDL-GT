#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm> 


using namespace std;

// Sử dụng một giá trị lớn để đại diện cho vô cực
const long long INF = 1e18; // 10^18, đủ lớn cho hầu hết các trường hợp

// Cấu trúc để lưu trữ một cạnh và trọng số của nó
struct Edge {
    int u, v;
    long long weight;
};

int main() {
    // Mở file input và output
    ifstream fin("dirty.txt");
    ofstream fout("dirty.out");

    if (!fin.is_open()) {
        cerr << "Loi: Khong the mo file dirty.txt" << endl;
        return 1;
    }
    if (!fout.is_open()) {
        cerr << "Loi: Khong the mo file dirty.out" << endl;
        return 1;
    }

    int n, m, s, e; // n: số thành phố, m: số con đường, s: điểm bắt đầu, e: điểm kết thúc
    fin >> n >> m >> s >> e;

    vector<Edge> edges; // Danh sách các cạnh cho thuật toán Bellman-Ford
    // Ma trận kề cho thuật toán Floyd-Warshall
    // Khởi tạo với INF, đường đi từ một đỉnh đến chính nó là 0
    vector<vector<long long>> dist_fw(n + 1, vector<long long>(n + 1, INF));

    for (int i = 1; i <= n; ++i) {
        dist_fw[i][i] = 0;
    }

    // Đọc m con đường
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long d;
        fin >> u >> v >> d;
        edges.push_back({u, v, d});
        // Cập nhật ma trận kề cho Floyd-Warshall (chỉ cạnh trực tiếp)
        // Nếu có nhiều đường giữa u và v, chọn đường có trọng số nhỏ nhất
        dist_fw[u][v] = std::min(dist_fw[u][v], d);
    }

    // Phần a: Tìm đường đi ngắn nhất từ s đến e dùng Bellman-Ford 
    vector<long long> dist_bf(n + 1, INF);
    vector<int> parent(n + 1, 0); // Lưu trữ đỉnh cha để truy vết đường đi
    dist_bf[s] = 0;

    // Lặp n-1 lần
    for (int i = 0; i < n - 1; ++i) {
        for (const auto& edge : edges) {
            if (dist_bf[edge.u] != INF && dist_bf[edge.u] + edge.weight < dist_bf[edge.v]) {
                dist_bf[edge.v] = dist_bf[edge.u] + edge.weight;
                parent[edge.v] = edge.u;
            }
        }
    }
    
    // (Tùy chọn) Kiểm tra chu trình âm có thể ảnh hưởng đến đường đi s-e.
    // Trong bài này, ta giả định đường đi s-e là xác định theo ví dụ.
    // Nếu dist_bf[e] là INF, không có đường đi từ s đến e.

    // Ghi kết quả phần a ra file
    if (dist_bf[e] == INF) {
        fout << "INF" << endl; // Hoặc thông báo lỗi phù hợp nếu đề bài yêu cầu
        fout << "Khong co duong di" << endl;
    } else {
        fout << dist_bf[e] << endl;

        // Truy vết đường đi từ e về s
        vector<int> path;
        int current_node = e;
        while (current_node != 0) { // parent[s] có thể là 0 hoặc s (nếu s là gốc)
            path.push_back(current_node);
            if (current_node == s) break; // Đã đến điểm bắt đầu
            current_node = parent[current_node];
            if (current_node == 0 && e !=s) { // Lỗi: không tìm thấy đường đi đầy đủ về s
                 // Điều này không nên xảy ra nếu dist_bf[e] không phải INF và không có lỗi logic
                path.clear(); // Xóa đường đi không hợp lệ
                path.push_back(e); // Chỉ có điểm cuối nếu không truy vết được
                path.push_back(s); // Giả định lỗi và chỉ in s, e
                std::reverse(path.begin(), path.end());
                break;
            }
        }
        std::reverse(path.begin(), path.end());

        for (size_t i = 0; i < path.size(); ++i) {
            fout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        fout << endl;
    }


    // Phần b: Tìm đường đi ngắn nhất giữa tất cả các cặp đỉnh dùng Floyd-Warshall
    // Ma trận dist_fw đã được khởi tạo với các cạnh trực tiếp và dist_fw[i][i] = 0.

    for (int k = 1; k <= n; ++k) {        // Đỉnh trung gian
        for (int i = 1; i <= n; ++i) {    // Đỉnh bắt đầu
            for (int j = 1; j <= n; ++j) { // Đỉnh kết thúc
                if (dist_fw[i][k] != INF && dist_fw[k][j] != INF) { // Tránh tràn số với INF
                    if (dist_fw[i][k] + dist_fw[k][j] < dist_fw[i][j]) {
                        dist_fw[i][j] = dist_fw[i][k] + dist_fw[k][j];
                    }
                }
            }
        }
    }

    // Ghi kết quả phần b ra file
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist_fw[i][j] == INF) {
                fout << "INF";
            } else {
                fout << dist_fw[i][j];
            }
            fout << (j == n ? "" : " ");
        }
        fout << endl;
    }

    // Đóng file
    fin.close();
    fout.close();

    return 0;
}
