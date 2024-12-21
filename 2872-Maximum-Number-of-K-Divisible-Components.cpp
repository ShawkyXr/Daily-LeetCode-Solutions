class Solution {
    vector<bool> vis;
    unordered_map <int,unordered_set<int>> adj;
    int ans=0;

    long long dfs(int node,vector<int>& values,int x){
        vis[node]=1;
        long long sum = values[node];
        for (auto &v : adj[node]){
            if (!vis[v]){
                sum += dfs(v,values,x);
                sum%=x;
            }
        }

        if (sum%x==0) {
            ans++;
            return 0;
        }
        
        return sum;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        for (auto &edge : edges){
            adj[edge[0]].emplace(edge[1]);
            adj[edge[1]].emplace(edge[0]);
        }
        vis.assign(n,0);
        long long d = dfs(0,values,k);
        return ans;
    }
};