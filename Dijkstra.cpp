/// ---Dijkstra Algorithm---
/// -Finding shortest distances on a graph
/// !Does not work on graphs with negative edges
/// -Complexity: O(E+VlogV)
/// ------------------------

#define INF 1e9
using pii=pair<int, int>;

int n; /// Number of vertexes
int s; /// Start point
// int ep; /// End point (Not necessary)
vector<pii> e[maxn]; /// Edges (e[u] -> {v, w})
bool vis[maxn]; /// Visited
int d[maxn]; /// Shortest distance

void init() { /// Needs to be called before inputing edges!
    for (int i=0; i<n; i++) {
        d[i]=INF; /// Set all distances to INF
        e[i].clear();
        vis[i]=false;
    }
    d[s]=0;
}

void Dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii>> pq; /// smallest {d, v}
    pq.emplace(0, s);
    while (!pq.empty()) {
        pii u=pq.top();
        pq.pop();
        //if (u.second==ep) break;
        if (vis[u.second]) continue; /// u.second = id of u
        vis[u.second]=true;
        for (pii p:e[u.second]) { /// For each v
            int v=p.first, w=p.second;
            if (d[v]>d[u.second]+w) { /// Relax
                d[v]=d[u.second]+w; /// Update
                pq.emplace(d[v], v);
            }
        }
    }
}

/// After running Dijkstra, the shortest distance from s to e is d[e]
