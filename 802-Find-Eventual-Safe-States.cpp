class Solution {
        map <int,int> safe;

        int dfs(int u,vector<vector<int>>& graph,vector <int> &vis){
            if (safe.count(u) ) {
                safe[u] = 1;
                return 1;
            }
            if (vis[u]) return 0;
            vis[u] = 1;
            for (auto v: graph[u]){
                if (dfs(v,graph,vis)){
                    safe[v] = 1;
                }else{
                    return 0;
                }
            } 
            return 1;
        }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        for (int i=0 ; i<n ; i++){
            if (graph[i].size()==0) safe[i] = 1;
        }
        
        vector <int> ans;
        vector <int> vis(n,0);
        for (int i=0 ; i<n ;i++){
            if (dfs(i,graph,vis)) {
                ans.push_back(i);
                safe[i] = 1;    
            }
        }

        return ans;
    }
};