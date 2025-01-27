class Solution {
    vector <vector <int>> dp;

    bool dfs(int u, int course,vector<vector<int>>& adj){
        if (u == course) return true;
        int &ret = dp[u][course];
        if (~ret) return ret;
        bool ans = false;
        for (auto v : adj[u]){
            ans |= dfs(v,course,adj);
        } 
        return ret = ans;
    }
    
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector <vector <int>> adj(numCourses);
        dp.assign(numCourses,vector <int> (numCourses,-1));
        for (auto c : prerequisites){
            adj[c[0]].push_back(c[1]);
        }

        vector <bool> ans;

        for (auto c : queries){
            ans.push_back(dfs(c[0],c[1],adj));
        }

        return ans;
    }
};