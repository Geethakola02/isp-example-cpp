// #include <iostream>
// #include <vector>

// using namespace std;

// class Graph {
//     int V; // Number of vertices
//     vector<vector<int>> adj; // Adjacency list

// public:
//     // Constructor
//     Graph(int vertices) {
//         V = vertices;
//         adj.resize(V);
//     }

//     // Add edge between u and v
//     void addEdge(int u, int v, bool directed = false) {
//         adj[u].push_back(v);
//         if (!directed) {
//             adj[v].push_back(u); // For undirected graph
//         }
//     }

//     // Display the graph
//     void printGraph() {
//         cout << "Graph adjacency list:\n";
//         for (int i = 0; i < V; ++i) {
//             cout << i << " -> ";
//             for (int neighbor : adj[i]) {
//                 cout << neighbor << " ";
//             }
//             cout << endl;
//         }
//     }
// };

// int main() {
//     int V = 5;
//     Graph g(V);

//     // Sample edges
//     g.addEdge(0, 1);
//     g.addEdge(0, 4);
//     g.addEdge(1, 2);
//     g.addEdge(1, 3);
//     g.addEdge(1, 4);
//     g.addEdge(2, 3);
//     g.addEdge(3, 4);

//     g.printGraph();

//     return 0;
// }
#include<iostream>
#include<vector>
using namespace std;
class graph{
    int v;
    vector<vector<int>>adj;
    public:
    graph(int vetx)
    {
        v=vetx;
        adj.resize(v);
    }
    void addedge(int u, int v,bool direct=false)
    {
        adj[u].push_back(v);
        if(!direct)
        {
            adj[v].push_back(u);
        }
    }
    void printgraph(){
        cout<<"graph valus:"<<endl;
        for(int i=0;i<v;i++)
        {
            cout<<i<<"->";
        
        for(int neg: adj[i])
        {
            cout<<neg<<" ";
        }
    }
        cout<<endl;
    }

};
int main()
{
 int v;
 cout<<"enter no.of vertex:"<<endl;
 cin>>v;
 graph g(v);
 g.addedge(0,1);
  g.addedge(0,2);
 g.addedge(0,5);
 g.addedge(1,0);
  g.addedge(1,2);
   g.addedge(1,5);
    g.addedge(2,3);
     g.addedge(4,6);
g.printgraph();
}

#include <iostream>
#include <vector>
#include <queue>
#include <cstring> // for memset
using namespace std;

const int MAX = 1000;
vector<int> adj[MAX];     // Adjacency list
bool visited[MAX];        // Visited array

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}
void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    // Reading edges
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    // DFS
    memset(visited, false, sizeof(visited));
    cout << "Enter starting node for DFS: ";
    int startDFS;
    cin >> startDFS;
    cout << "DFS Traversal: ";
    dfs(startDFS);
    cout << endl;

    // BFS
    memset(visited, false, sizeof(visited));
    cout << "Enter starting node for BFS: ";
    int startBFS;
    cin >> startBFS;
    cout << "BFS Traversal: ";
    bfs(startBFS);
    cout << endl;

    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

class DisjointSet {
public:
    vector<int> parent, rank;
    
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int find(int v) {
        if (parent[v] != v)
            parent[v] = find(parent[v]); // Path compression
        return parent[v];
    }
    
    void unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

void kruskal(vector<Edge> &edges, int V) {
    vector<Edge> mst;
    DisjointSet ds(V);
    
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });
    
    for (Edge &edge : edges) {
        if (ds.find(edge.src) != ds.find(edge.dest)) {
            mst.push_back(edge);
            ds.unionSet(edge.src, edge.dest);
        }
    }
    
    cout << "Minimum Spanning Tree:\n";
    for (Edge &edge : mst)
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };
    
    kruskal(edges, V);
    
    return 0;
}


//trees
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Inorder Traversal of Full Binary Tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}


#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
const int INF = 1e9;
 
void dijkstra(int src, vector<vector<pair<int, int>>>& adj, vector<int>& dist) {
    int n = adj.size();
    dist.assign(n, INF);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, src));
    while (!pq.empty()) {
        pair<int, int> current = pq.top();
        pq.pop();
        int d = current.first;
        int u = current.second;
 
        if (d > dist[u]) continue;
 
        for (size_t i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;
 
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}
 
int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);
 
    // (u, v, weight)
    adj[0].push_back(make_pair(1, 2));
    adj[0].push_back(make_pair(2, 4));
    adj[2].push_back(make_pair(1, 1));
    adj[1].push_back(make_pair(3, 7));
    adj[2].push_back(make_pair(4, 3));
    adj[3].push_back(make_pair(4, 1));
 
    vector<int> dist;
    dijkstra(0, adj, dist);
 
    cout << "Shortest distances from node 0:\n";
    for (int i = 0; i < V; ++i) {
        cout << "0 -> " << i << " = " << dist[i] << endl;
    }
 
    return 0;
}
 

#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    // Inserting elements
    dq.push_back(10);      // Add to back
    dq.push_front(5);      // Add to front
    dq.push_back(15);
    dq.push_front(2);

    cout << "Deque after insertion: ";
    for (int val : dq) {
        cout << val << " ";
    }
    cout << endl;

    // Accessing elements
    cout << "Front element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl;

    // Removing elements
    dq.pop_front();        // Remove from front
    dq.pop_back();         // Remove from back

    cout << "Deque after deletion: ";
    for (int val : dq) {
        cout << val << " ";
    }
    cout << endl;

    // Check size and emptiness
    cout << "Size: " << dq.size() << endl;
    cout << "Is empty? " << (dq.empty() ? "Yes" : "No") << endl;

    return 0;
}


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> bellman(int v, vector<vector<int>> &edges, int source) {
    vector<int> dist(v, INT_MAX);
    dist[source] = 0;

    // Relax edges v-1 times
    for (int i = 0; i < v - 1; i++) {
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative weight cycle
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
            return {-1}; // Negative cycle found
        }
    }

    return dist;
}

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> edges;

    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    vector<int> distances = bellman(v, edges, source);

    if (distances.size() == 1 && distances[0] == -1) {
        cout << "Negative weight cycle detected." << endl;
    } else {
        cout << "\nShortest distances from source vertex " << source << ":\n";
        for (int i = 0; i < distances.size(); i++) {
            cout << "Vertex " << i << ": ";
            if (distances[i] == INT_MAX)
                cout << "INF";
            else
                cout << distances[i];
            cout << endl;
        }
    }

    return 0;
}
