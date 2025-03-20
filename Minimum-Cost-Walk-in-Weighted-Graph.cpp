class Solution {

#define ll long long;

    template <typename T> struct DSU{

    public:

        int n;
        vector <T> parent;
        vector <T> size;
        vector <T> OR;


        DSU(int n) : n(n) , parent(n+2), size(n+2),OR(n+2) {

            for (int i=0 ; i<n ; i++){
                parent[i] = i;
                size[i] = 1;
                OR[i] = -1;
            }

        }
        

        T get_parent(T u){
            return parent[u] = (parent[u] == u ? u : get_parent(parent[u])); // path compression
        }


        bool connected(T u, T v){
            return get_parent(u) == get_parent(v);
        }


        void unoin(T u ,T v){
            
            // if (connected(u,v)) return;

            int Pu = get_parent(u), Pv = get_parent(v);
            
            if (OR[Pu] > OR[Pv] ) swap (Pu,Pv);
            OR[Pv] &= (OR[v] & OR[u]);
            OR[Pu] &= OR[Pv];
            parent[Pv] = Pu;
            // size[Pu]+=size[Pv];
           
        }

};

public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        
        DSU <int> dsu(100005);

        for (auto &e : edges){
            int u = e[0], v = e[1], w = e[2];

            dsu.OR[u] &= w;
            dsu.OR[v] &= w;
            dsu.unoin(u,v);
        }

        vector <int> ans;

        for (auto &q : query){
            int u = q[0], v= q[1];
            if (!dsu.connected(u,v)){
                ans.push_back(-1);
                continue;
            }
            ans.push_back(dsu.OR[dsu.get_parent(u)]);
        }

        return ans;
    }
};