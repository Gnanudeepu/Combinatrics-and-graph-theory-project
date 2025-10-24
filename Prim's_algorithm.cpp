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
 void primMST(vector<Pair> adj[], int V) {
 priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
 vector<int> key(V, INT_MAX);
 vector<int> parent(V,-1);
 vector<bool> inMST(V, false);
 key[0] = 0;
 pq.push(make_pair(0, 0)); // (weight, vertex)
 while (!pq.empty()) {
 int u = pq.top().second;
 pq.pop();
 if (inMST[u])
 continue;
 inMST[u] = true;
 for (int i = 0; i < adj[u].size(); i++) {
 int v = adj[u][i].first;
 int weight = adj[u][i].second;
 if (!inMST[v] && key[v] > weight) {
 key[v] = weight;
 pq.push(make_pair(key[v], v));
 parent[v] = u;
}
 }
 }
 cout << "\nEdges in Minimum Cost Road Network (MST):\n";
 int totalCost = 0;
 for (int i = 1; i < V; i++) {
 cout << "City " << parent[i] << "- City " << i
 << " (Cost: " << key[i] << ")\n";
 totalCost += key[i];
 }
 cout << "Total Minimum Cost = " << totalCost << endl;
 }
 int main() {
 int V = 5;
 vector<Pair> adj[V];
 addEdge(adj, 0, 1, 2);
 addEdge(adj, 0, 3, 6);
 addEdge(adj, 1, 2, 3);
 addEdge(adj, 1, 3, 8);
 addEdge(adj, 1, 4, 5);
 addEdge(adj, 2, 4, 7);
 addEdge(adj, 3, 4, 9);
 primMST(adj, V);
 return 0;
}
