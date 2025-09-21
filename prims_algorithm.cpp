#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
#include <cstdlib>  // for rand() and srand()
#include <iomanip>  // for setw, setprecision
using namespace std;

// Function to compute MST using Prim's Algorithm
int spanningTree(int V, vector<vector<int> > adj[])
{
    vector<int> visited(V, 0);

    // Min-heap: {weight, node}
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, 0));

    int sum = 0;

    while (!pq.empty())
    {
        pair<int, int> it = pq.top();
        pq.pop();

        int wt = it.first;
        int node = it.second;

        if (visited[node])
            continue;

        visited[node] = 1;
        sum += wt;

        // Iterate over adjacency list of this node
        for (size_t j = 0; j < adj[node].size(); j++)
        {
            int adjNode = adj[node][j][0];
            int edW = adj[node][j][1];

            if (!visited[adjNode])
                pq.push(make_pair(edW, adjNode));
        }
    }

    return sum;
}

int main()
{
    srand(time(0));

    int sizes[] = {1000, 10000, 20000, 30000, 40000, 50000, 100000};
    int nSizes = sizeof(sizes) / sizeof(sizes[0]);

    // Print table header
    cout << left << setw(12) << "Vertices"
         << setw(15) << "MST Weight"
         << setw(15) << "Time (sec)" << endl;
    cout << string(42, '-') << endl;

    for (int idx = 0; idx < nSizes; idx++)
    {
        int V = sizes[idx];
        vector<vector<int> > *adj = new vector<vector<int> >[V];

        // Ensure connectivity (chain edges)
        for (int i = 0; i < V - 1; i++)
        {
            int w = rand() % 100 + 1;
            adj[i].push_back(vector<int>(2));
            adj[i][adj[i].size() - 1][0] = i + 1;
            adj[i][adj[i].size() - 1][1] = w;

            adj[i + 1].push_back(vector<int>(2));
            adj[i + 1][adj[i + 1].size() - 1][0] = i;
            adj[i + 1][adj[i + 1].size() - 1][1] = w;
        }

        // Add random extra edges (make graph denser)
        for (int i = 0; i < 5 * V; i++)
        {
            int u = rand() % V;
            int v = rand() % V;
            if (u != v)
            {
                int w = rand() % 100 + 1;

                adj[u].push_back(vector<int>(2));
                adj[u][adj[u].size() - 1][0] = v;
                adj[u][adj[u].size() - 1][1] = w;

                adj[v].push_back(vector<int>(2));
                adj[v][adj[v].size() - 1][0] = u;
                adj[v][adj[v].size() - 1][1] = w;
            }
        }

        // Measure time using clock()
        clock_t start = clock();
        int mstWeight = spanningTree(V, adj);
        clock_t end = clock();

        double time_taken = double(end - start) / CLOCKS_PER_SEC;

        cout << left << setw(12) << V
             << setw(15) << mstWeight
             << fixed << setprecision(6)
             << setw(15) << time_taken << endl;

        delete[] adj;
    }

    return 0;
}
