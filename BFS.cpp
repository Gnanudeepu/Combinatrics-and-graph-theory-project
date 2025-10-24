#include <iostream>
 #include <vector>
 #include <queue>
 using namespace std;
 void addEdge(vector<int> adj[], int u, int v) {
 adj[u].push_back(v);
 adj[v].push_back(u); // Undirected road
 }
 bool isReachable(vector<int> adj[], int V, int src, int dest) {
 vector<bool> visited(V, false);
 queue<int> q;
 visited[src] = true;
 q.push(src);
 while (!q.empty()) {
 int city = q.front();
 q.pop();
 if (city == dest)
 return true; // destination found
 for (int neighbor : adj[city]) {
 if (!visited[neighbor]) {
 visited[neighbor] = true;
 q.push(neighbor);
 }
 }
 }
 return false;
 }
 int main() {
 int V = 6; // number of cities
 vector<int> adj[V];
 addEdge(adj, 0, 1);
 addEdge(adj, 0, 2);
 addEdge(adj, 1, 3);
 addEdge(adj, 2, 4);
 addEdge(adj, 3, 5);
 int src = 0, dest = 5;
 if (isReachable(adj, V, src, dest))
 cout << "City " << dest << " is reachable from City " << src << endl;
 else
 cout << "City " << dest << " is NOT reachable from City " << src << endl;
 return 0;
 }
