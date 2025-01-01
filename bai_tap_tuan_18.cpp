#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// =======================
// Cấu trúc lưu trữ Ma trận Lân cận
// =======================
class GraphMatrix {
private:
    int numVertices;
    vector<vector<int>> adjMatrix;

public:
    GraphMatrix(int vertices) {
        numVertices = vertices;
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }

    void addEdge(int src, int dest) {
        // Vì đồ thị không hướng
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }

    void BFS(int start) {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS (Ma trận lân cận): ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int i = 0; i < numVertices; ++i) {
                if (adjMatrix[current][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < numVertices; ++i) {
            if (adjMatrix[v][i] == 1 && !visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(numVertices, false);
        cout << "DFS (Ma trận lân cận): ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

// =======================
// Cấu trúc lưu trữ Danh sách Lân cận
// =======================
class GraphList {
private:
    int numVertices;
    vector<vector<int>> adjList;

public:
    GraphList(int vertices) {
        numVertices = vertices;
        adjList.resize(numVertices);
    }

    void addEdge(int src, int dest) {
        // Vì đồ thị không hướng
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void BFS(int start) {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS (Danh sách lân cận): ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (auto& neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (auto& neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(numVertices, false);
        cout << "DFS (Danh sách lân cận): ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

// =======================
// Hàm chính
// =======================
int main() {
    int numVertices, numEdges;
    cout << "Nhập số đỉnh của đồ thị: ";
    cin >> numVertices;
    cout << "Nhập số cạnh của đồ thị: ";
    cin >> numEdges;

    // Khởi tạo đồ thị bằng Ma trận lân cận
    GraphMatrix graphMatrix(numVertices);
    // Khởi tạo đồ thị bằng Danh sách lân cận
    GraphList graphList(numVertices);

    cout << "Nhập các cạnh (định dạng: src dest):\n";
    for (int i = 0; i < numEdges; ++i) {
        int src, dest;
        cin >> src >> dest;
        graphMatrix.addEdge(src, dest);
        graphList.addEdge(src, dest);
    }

    int startVertex;
    cout << "Nhập đỉnh bắt đầu duyệt: ";
    cin >> startVertex;

    // Duyệt BFS và DFS bằng Ma trận lân cận
    graphMatrix.BFS(startVertex);
    graphMatrix.DFS(startVertex);

    // Duyệt BFS và DFS bằng Danh sách lân cận
    graphList.BFS(startVertex);
    graphList.DFS(startVertex);

    return 0;
}
