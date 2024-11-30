class Solution {
    map <int,vector<int>> adj;
    vector <vector<int>> ans;

    void dfs(int u){
        while(!adj[u].empty()){
            int v = adj[u].back();
            adj[u].pop_back();
            dfs(v);
            ans.push_back({u,v});
        }
    }

public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        bool startfound=0;
        int start=-1;
        map <int,int> right,left;
        
        for (auto &vec : pairs){
            adj[vec[0]].push_back(vec[1]);
            left[vec[0]]++;
            right[vec[1]]++;
        }

        for (auto & i : pairs){
            int u = i[0];
            if (left[u]>right[u]){
                start =u;
                startfound=1;
                break;
            }
        }


        if (!startfound) start = pairs[0][0];
        
        dfs(start);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};