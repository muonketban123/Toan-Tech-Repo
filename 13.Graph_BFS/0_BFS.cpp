#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>> &graph, vector<bool> &visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int cur = q.front();
        cout << cur << " "; // In ra đỉnh hiện tại
        q.pop(); 
        for(int neighbor : graph[cur]) {
            if(!visited[neighbor]) {
                q.push(neighbor); // Thêm các đỉnh kề của đỉnh hiện tại vào hàng đợi
                visited[neighbor] = true; // Đánh dấu các đỉnh kề đã được thăm
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; // Nhập số đỉnh (n) và số cạnh (m) của đồ thị
    vector<vector<int>> graph(n+1); // Khởi tạo đồ thị dưới dạng danh sách kề
    vector<bool> visited(n+1, false); // Mảng đánh dấu các đỉnh đã được thăm, ban đầu tất cả là false
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v; // Nhập cạnh (u, v)
        graph[u].push_back(v); // Thêm v vào danh sách kề của u
        graph[v].push_back(u); // Thêm u vào danh sách kề của v (đồ thị vô hướng)
    }
    int startNode;
    cin >> startNode; // Nhập đỉnh bắt đầu của BFS
    bfs(startNode, graph, visited); // Gọi hàm BFS
    return 0;
}
