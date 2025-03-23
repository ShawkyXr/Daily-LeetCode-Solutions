class Solution {
    vector <bool> vis;
    vector <int> dfs(int u,int mx,int mn,int cnt,vector<vector<int>> &adj){
        if (vis[u]) return {mx,mn,cnt};

        vis[u] = 1;
        cnt++;
        vector <int> ans = {mx,mn ,cnt};
        for (auto &v : adj[u]){
            mx = max(mx,int(adj[v].size()));
            mn = min(mn,int(adj[v].size()));
            vector <int> tmp = dfs(v,mx,mn,cnt,adj);
            ans[0] = max(ans[0],tmp[0]);
            ans[1] = min(ans[1],tmp[1]);
            ans[2] = max(ans[2],tmp[2]);
        } 

        return ans;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector <vector<int>> adj(n);

        for (auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vis = vector <bool> (n);
        int ans = 0;

        for (int i=0 ; i<n ; i++){
            if (!vis[i]){
                vector <int> info = dfs(i,adj[i].size(),adj[i].size(),0,adj);
                int mx = info[0], mn = info[1], cnt = info[2];
                // cout << mx << " " << mn << " " << cnt << "\n";
                if (mx == cnt-1 && mn == cnt-1) ans++;
            }
        }

        return ans;
    }
};