class Solution {
public:

     void dfs(int u, int parent, int time, int income, vector<vector<int>>& adj, vector<int>& amount, vector<int>& bobTime, int& ans) {
        if (time < bobTime[u]) {
            income += amount[u]; 
        } else if (time == bobTime[u]) {
            income += amount[u] / 2; 
        }

        if (adj[u].size() == 1 && u != 0) {
            ans = max(ans, income);
            return;
        }

        for (int v : adj[u]) {
            if (v != parent) {
                dfs(v, u, time + 1, income, adj, amount, bobTime, ans);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        vector <vector<int>> adj(edges.size()+1);
        int p = 0;

       for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue <int> q;
        q.push(0);
        vector <int> path;
        vector <int> parent(edges.size()+1,-1);
        parent[0] = -2;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            if (u==bob) break;
            for (auto v : adj[u]){
                if (parent[v]== -1){
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        p = bob;
        while(p != -2){
            path.push_back(p);
            p = parent[p];
        }
        // reverse(path.begin(),path.end());

        vector<int> bobTime(adj.size(), INT_MAX);
        for (int t = 0; t < path.size(); t++) {
            bobTime[path[t]] = t;
        }
        
        int ans = INT_MIN;
        dfs(0, -1, 0, 0, adj, amount, bobTime, ans);
        return ans;
    }
};