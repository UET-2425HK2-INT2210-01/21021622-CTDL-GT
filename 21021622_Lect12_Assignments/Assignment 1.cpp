#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm> 
#include <queue>     


using namespace std;

int main() {
    // Mở file input và output
    ifstream fin("jobs.txt");
    ofstream fout("jobs.out");

    if (!fin.is_open()) {
        cerr << "Loi: Khong the mo file jobs.txt" << endl;
        return 1;
    }
    if (!fout.is_open()) {
        cerr << "Loi: Khong the mo file jobs.out" << endl;
        return 1;
    }

    int n, m; // n: số công việc, m: số yêu cầu thứ tự
    fin >> n >> m;

    vector<vector<int>> adj(n + 1); // Danh sách kề (adj[u] chứa các công việc v mà u phải làm trước v)
    vector<int> in_degree(n + 1, 0); // Mảng lưu trữ bậc vào của mỗi công việc

    // Đọc m yêu cầu thứ tự
    for (int i = 0; i < m; ++i) {
        int u, v;
        fin >> u >> v; // Công việc u phải làm trước công việc v
        adj[u].push_back(v); // Thêm cạnh từ u đến v
        in_degree[v]++;      // Tăng bậc vào của v
    }

    // Hàng đợi để lưu các công việc có bậc vào bằng 0
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> sorted_jobs; // Danh sách lưu trữ các công việc đã được sắp xếp

    // Xử lý các công việc trong hàng đợi
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        sorted_jobs.push_back(u);

        // Duyệt qua các công việc v kề với u (u phải làm trước v)
        for (int v : adj[u]) {
            in_degree[v]--; // Giảm bậc vào của v vì u đã được thực hiện
            if (in_degree[v] == 0) { // Nếu bậc vào của v trở thành 0
                q.push(v);          // Thêm v vào hàng đợi
            }
        }
    }

    // Kiểm tra xem có chu trình hay không (nếu sorted_jobs.size() < n thì có chu trình)
    if (sorted_jobs.size() != (size_t)n) {
        fout << "Khong the sap xep do co chu trinh trong cac yeu cau." << endl;
    } else {
        // Ghi kết quả ra file jobs.out
        for (size_t i = 0; i < sorted_jobs.size(); ++i) {
            fout << sorted_jobs[i] << (i == sorted_jobs.size() - 1 ? "" : " ");
        }
        fout << endl;
    }

    // Đóng file
    fin.close();
    fout.close();

    return 0;
}
