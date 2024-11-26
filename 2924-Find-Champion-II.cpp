class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector <int> loser(n,0);
        for (auto edge : edges){
            loser[edge[1]]++;
        }
        int cnt = 0,ans=0;
        for (int i=0 ;i<n ;i++){
            if (!loser[i]){
                cnt++;
                ans=i;
            }
        }
        if (cnt!=1) return -1;
        return ans;
    }
};