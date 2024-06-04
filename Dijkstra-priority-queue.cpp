#include <iostream>
#define FIN "dijkstra.in"
#define FOUT "dijkstra.out"
#include <vector>
#include <queue>
#include <limits>

#define MAX_NODES 50005
#define INF std::numeric_limits<int>::max()

using namespace std;

vector<int> V[MAX_NODES];
vector<int> C[MAX_NODES];
int distMin[MAX_NODES];

void readGraph(int& nodes, int& edges) {
    freopen(FIN, "r", stdin);
    cin >> nodes >> edges;
    for (int edge = 1; edge <= edges; ++edge) {
        int x, y, cost;
        cin >> x >> y >> cost;
        V[x].push_back(y);
        C[x].push_back(cost);
    }
}

void dijkstra(int startNode, int nodes) {
    for (int i = 2; i <= nodes; ++i)
        distMin[i] = INF;
    distMin[startNode] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, startNode});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        if (currDist > distMin[currNode]) continue;

        for (int i = 0; i < V[currNode].size(); ++i) {
            int nextNode = V[currNode][i];
            int cost = C[currNode][i];
            if (distMin[nextNode] > distMin[currNode] + cost) {
                distMin[nextNode] = distMin[currNode] + cost;
                pq.push({distMin[nextNode], nextNode});
            }
        }
    }
}

void printShortestDistances(int nodes) {
    freopen(FOUT, "w", stdout);
    for (int i = 2; i <= nodes; ++i) {
        cout << (distMin[i] < INF ? distMin[i] : 0) << " ";
    }
    cout << endl;
}

int main() {
    int nodes, edges;
    readGraph(nodes, edges);
    dijkstra(1, nodes);
    printShortestDistances(nodes);
    return 0;
}
