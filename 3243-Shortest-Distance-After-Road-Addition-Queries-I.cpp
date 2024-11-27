class Solution {
    vector <vector<int>> next;
    int goal;
public:
    vector<int>dp;
    int tryroads(int i){
        if (i==goal) return 0;
        int &ret = dp[i];
        if (~ret) return ret;
        int mn = goal+1;
        for (auto v:next[i]){
            mn = min(mn,tryroads(v)+1);
        }
        return ret=mn;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        goal=n-1;
        next.assign(n,vector<int>(0));
        dp.assign(n, -1);
        vector <int> ans;
        for (int i=0 ;i<n-1 ;i++){
            next[i].push_back(i+1);
        }
        for (auto &q :queries){
            next[q[0]].push_back(q[1]);
            ans.push_back(tryroads(0));
            dp.clear();
            dp.resize(n, -1);
        }
        return ans;
    }
};