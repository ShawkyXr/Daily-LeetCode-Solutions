class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        map <pair<int,int>,int> mp;
        for (int i=0 ;i<dominoes.size() ; i++){
            int p1 = min(dominoes[i][0],dominoes[i][1]);
            int p2 = max(dominoes[i][0],dominoes[i][1]);
            mp[{p1,p2}]++;
        }

        for (auto d : mp){
            ans += (d.second * (d.second-1))/2;
        }

        return ans;
    }
};