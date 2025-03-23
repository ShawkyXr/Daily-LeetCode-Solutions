class Solution {
public:
    typedef long long ll;
    #define Mod  int(1e9 + 7)
    #define sz(x) int(x.size())


   template <typename T=int> struct Dijkstra{

    struct edge{
        T u, v, w;
        edge(T u, T v, T w): u(u), v(v), w(w) {}
        bool operator < (const edge& e) const{
            return w > e.w;
        }
    };

    vector<vector<edge>> adj;
    vector<T> dist;
    vector<T> parent;

    Dijkstra(int n): adj(n), dist(n, LLONG_MAX), parent(n, -1) {}

    void AddE(T u, T v, T w, bool directed = false){
        adj[u].emplace_back(edge(u, v, w));
        if (!directed) adj[v].emplace_back(edge(v, u, w));
    }

    ll FindDist(T src,T target = -1){
        dist.assign(sz(adj), LLONG_MAX);
        parent.assign(sz(adj), -1);
        // create pq with edges sorted by lowest weight
        priority_queue<edge> pq;
        pq.emplace(edge(-1, src, 0));
        vector < ll > cnt(sz(adj),0);
        // initialize the distance of the source node to 0
        dist[src] = 0;
        parent[src] = -1;
        cnt[src]=1;
        while (!pq.empty()){
            edge e = pq.top();
            pq.pop();
            if (dist[e.v] < e.w) continue;
            // relax all the edges that are going out of the current node
            for (auto& road : adj[e.v]){
                if (dist[road.v] > e.w + road.w){
                    dist[road.v] = e.w + road.w;  // relaxtion
                    cnt[road.v] = cnt[e.v];
                    parent[road.v] = e.v;
                    pq.emplace(edge(road.u, road.v, dist[road.v]));
                }else if (dist[road.v] == e.w + road.w){
                    cnt[road.v] = ((cnt[e.v]%Mod)+(cnt[road.v]%Mod))%Mod;
                }
            }
        }
        return cnt[target];
    }
};

    int countPaths(int n, vector<vector<int>>& roads) {
        Dijkstra <ll> dij(n+5);
        for (int i=0 ; i<sz(roads) ; i++){
            dij.AddE(roads[i][0],roads[i][1],roads[i][2]);
        }
        return dij.FindDist(0,n-1);
    }
};