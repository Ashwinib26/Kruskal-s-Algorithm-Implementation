
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge 
{
    int u, v, weight;
};

int Find(int parent[], int i) 
{
    if (parent[i] == -1)
        return i;
    return parent[i] = Find(parent, parent[i]); 
}

void Union(int parent[], int rank[], int x, int y) 
{
    int xroot = Find(parent, x);
    int yroot = Find(parent, y);
    
    if (xroot != yroot) 
    {
        if (rank[xroot] < rank[yroot])
        {
            parent[xroot] = yroot;
        }
        else if (rank[xroot] > rank[yroot])
        {
            parent[yroot] = xroot;
        }
        else 
        {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }
}

void Heapify(vector<Edge>& edges, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && edges[left].weight < edges[smallest].weight)
    {
        smallest = left;
    }
    if (right < n && edges[right].weight < edges[smallest].weight)
    {
        smallest = right;
    }
    if (smallest != i) 
    {
        swap(edges[i], edges[smallest]);
        Heapify(edges, n, smallest);
    }
}

void BuildMinHeap(vector<Edge>& edges) 
{
    int n = edges.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(edges, n, i);
    }
}

Edge ExtractMin(vector<Edge>& edges) 
{
    Edge minEdge = edges[0];
    edges[0] = edges.back();
    edges.pop_back();
    Heapify(edges, edges.size(), 0);
    return minEdge;
}

int Kruskal(vector<Edge>& edges, int cost[][100], int n, int tree[][2]) 
{
    BuildMinHeap(edges);
    int parent[n], rank[n];
    fill(parent, parent + n, -1);
    fill(rank, rank + n, 0);

    int i = 0, mincost = 0;
    
    while (i < n - 1 && !edges.empty()) 
    {
        Edge minEdge = ExtractMin(edges);
        int u = minEdge.u, v = minEdge.v;
        int p = Find(parent, u);
        int q = Find(parent, v);

        if (p != q) 
        {
            i++;
            tree[i - 1][0] = u;
            tree[i - 1][1] = v;
            mincost += cost[u][v];
            Union(parent, rank, p, q);
        }
    }

    if (i != n - 1) 
    {
        cout << "No Spanning Tree" << endl;
        return -1;
    }

    return mincost;
}

int main() 
{
    int n = 5;  
    int E = 7;  

    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    int cost[100][100] = {0};
    int tree[100][2];

    for (const auto& edge : edges) 
    {
        cost[edge.u][edge.v] = cost[edge.v][edge.u] = edge.weight;
    }

    int mincost = Kruskal(edges, cost, n, tree);

    if (mincost != -1) 
    {
        cout << "Minimum Cost of Spanning Tree: " << mincost << endl;
        cout << "Edges in MST:" << endl;
        for (int i = 0; i < n - 1; i++)
            cout << tree[i][0] << " - " << tree[i][1] << endl;
    }

    return 0;
}
