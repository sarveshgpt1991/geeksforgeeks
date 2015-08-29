// http://www.geeksforgeeks.org/shortest-path-exactly-k-edges-directed-weighted-graph

#include <bits/stdc++.h>
using namespace std;

#define PB push_back
typedef stack<int> SI;
typedef queue<int> QI;
typedef list<int> LI;

#define V 4

int shortestPath(int graph[V][V], int src, int dest, int k){
	int cache[k+1][V];
	fill(cache, cache + (k+1)*V, INT_MAX);
	cache[0][dest] = 0;
	
}

int main(){
	int graph[V][V] = { {0, 10, 3, 2},
                        {INF, 0, INF, 7},
                        {INF, INF, 0, 6},
                        {INF, INF, INF, 0}
                      };
    int u = 0, v = 3, k = 2;
    cout << shortestPath(graph, u, v, k);
	return 0;
}

