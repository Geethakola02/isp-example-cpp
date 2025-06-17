#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge between two cities with cost
struct Edge {
    int u, v, cost;

    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

// Disjoint Set Union-Find to detect cycles
class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    bool unionSets(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if (xRoot == yRoot)
            return false; // Cycle detected

        if (rank[xRoot] < rank[yRoot])
            parent[xRoot] = yRoot;
        else if (rank[xRoot] > rank[yRoot])
            parent[yRoot] = xRoot;
        else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
        return true;
    }
};

void kruskalMST(int n, vector<Edge>& edges) {
    UnionFind uf(n);
    vector<Edge> mst;
    int totalCost = 0;

    sort(edges.begin(), edges.end()); // Sort by cost

    for (const Edge& e : edges) {
        if (uf.unionSets(e.u, e.v)) {
            mst.push_back(e);
            totalCost += e.cost;
        } else {
            cout << "Cycle detected and prevented between City " << e.u
                 << " and City " << e.v << " (Cost: " << e.cost << ")\n";
        }
    }

    cout << "\n=== Minimum Spanning Tree ===\n";
    for (const Edge& e : mst)
        cout << "City " << e.u << " - City " << e.v << " : Cost = " << e.cost << endl;

    cout << "Total Minimum Cost: " << totalCost << endl;
}

int main() {
    int n, m;
    cout << "Enter number of cities (nodes): ";
    cin >> n;
    cout << "Enter number of possible connections (edges): ";
    cin >> m;

    vector<Edge> edges(m);
    cout << "Enter connections (format: city1 city2 cost):\n";
    for (int i = 0; i < m; ++i)
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;

    kruskalMST(n, edges);

    return 0;
}


#include <iostream>
#include <set>

int main() {
    std::set<int> s;
    int n, x;

    std::cout << "Enter number of elements: ";
    std::cin >> n;

    std::cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        s.insert(x);  // duplicates automatically ignored
    }

    std::cout << "Set elements (unique & sorted): ";
    for (auto it = s.begin(); it != s.end(); ++it)
        std::cout << *it << " ";
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> vct1 = {1, 2, 3, 4, 5};
    vector<int> vct2 = {3, 4, 5, 6, 7};
    vector<int> result;
    set_intersection(vct1.begin(), vct1.end(), vct2.begin(), vct2.end(), back_inserter(result));
    cout << "Common elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}


#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int>arr;
    arr.push(25);
    arr.push(341);
    arr.push(252);
    arr.push(348);
    cout<<"elements are:"<<endl;
    arr.pop();
    arr.pop();
    cout<<arr.front()<<endl;
    cout<<arr.back()<<endl;
    while(!arr.empty())
    {
        cout<<arr.front()<<endl;
        arr.pop();
    }
 }


 // #include <iostream>
// #include <queue>

// int main() {
//     std::priority_queue<int> maxHeap;

//     // Inserting elements
//     maxHeap.push(5);
//     maxHeap.push(1);
//     maxHeap.push(10);
//     maxHeap.push(3);

//     std::cout << "Max-Heap (default):\n";
//     while (!maxHeap.empty()) {
//         std::cout << maxHeap.top() << " ";
//         maxHeap.pop();
//     }
//     return 0;
// }
#include <iostream>
#include <queue>
#include <functional> // For std::greater

int main() {
    // Create a Min-Heap using std::greater<int> as the comparator
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    // Inserting elements
    minHeap.push(5);
    minHeap.push(1);
    minHeap.push(10);
    minHeap.push(3);

    std::cout << "Min-Heap (lowest priority first):\n";
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }
    return 0;
}


//multiset
#include <iostream>
#include <set>

int main() {
    std::multiset<int> ms;
    int n, x;

    std::cout << "Enter number of elements: ";
    std::cin >> n;

    std::cout << "Enter " << n << " integers (duplicates allowed):\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        ms.insert(x);
    }

    std::cout << "Multiset elements (sorted with duplicates): ";
    for (auto it = ms.begin(); it != ms.end(); ++it)
        std::cout << *it << " ";
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> nums = {7, 2, 5, 1, 9};
    auto maxIt = max_element(nums.begin(), nums.end());
    if (maxIt != nums.end()) {
        cout << "Miximum element: " << *maxIt << endl;
    }
    return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector <int> v1={1,2,3};
    vector <int> v2={11,12,13};
    vector<int> res(v1.size()+v2.size());
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),res.begin());
    cout<<"after merge of two vectors:"<<endl;
    for(auto it:res)
    {
        cout<<it<<endl;
    }
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector <int> v1={1,2,3};
    vector <int> v2={11,12,13};
    vector<int> res(v1.size()+v2.size());
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),res.begin());
    cout<<"after merge of two vectors:"<<endl;
    for(auto it:res)
    {
        cout<<it<<endl;
    }
}

#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
    forward_list<int>fl;

    fl.push_front(34);
    fl.push_front(25);
    fl.push_front(34);
    cout<<"elements are:"<<endl;
    for(int it:fl)
    {
        cout<<it<<endl;
    }
    cout<<"elements are:"<<endl;
    fl.pop_front();
    fl.pop_front();
    for(int it:fl)
    {
        cout<<it<<endl;
    }
    
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
 int n;
 cin>>n;
 vector<int>arr(n);
 cout<<"enter elements:";
 for(int i=0;i<n;i++)
 {
    cin>>arr[i];
 }
 int key;
 cout<<"enter key element:"<<endl;
 cin>>key;
 bool res=binary_search(arr.begin(),arr.end(),key);
 cout<<res<<endl;//res=1 if element found otherwise res=0
 
}