#include <iostream>
 #include <vector>
 #include <queue>
 #include <climits>
 using namespace std;
 typedef pair<int, int> Pair; // (vertex, weight)
 void addEdge(vector<Pair> adj[], int u, int v, int w) {
 adj[u].push_back(make_pair(v, w));
 adj[v].push_back(make_pair(u, w)); // Undirected
 }
 void dijkstra(vector<Pair> adj[], int V, int src) {
 priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
 vector<int> dist(V, INT_MAX);
 dist[src] = 0;
 pq.push(make_pair(0, src)); // (distance, vertex)
 while (!pq.empty()) {
 int u = pq.top().second;
 pq.pop();
 for (int i = 0; i < adj[u].size(); i++) {
 int v = adj[u][i].first;
 int weight = adj[u][i].second;
 if (dist[v] > dist[u] + weight) {
 dist[v] = dist[u] + weight;
 pq.push(make_pair(dist[v], v));
 }
 }
 }
 cout << "\nShortest distances from City " << src << ":\n";
 for (int i = 0; i < V; i++)
 cout << "To City " << i << " = " << dist[i] << endl;
 }
 int main() {
 int V = 5;
 vector<Pair> adj[V];
 addEdge(adj, 0, 1, 2);
 addEdge(adj, 0, 2, 4);
 addEdge(adj, 1, 2, 1);
 addEdge(adj, 1, 3, 7);
 addEdge(adj, 2, 4, 3);
addEdge(adj, 3, 4, 2);
 int src = 0;
 dijkstra(adj, V, src);
 return 0;
 }
