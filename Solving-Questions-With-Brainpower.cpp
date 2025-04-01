class Solution {
    vector <long long> dp;
    long long MaxSC(int i, vector <vector <int>> &arr){
        if (i>=arr.size()) return 0;
        long long &ret = dp[i];
        if (~ret) return ret;
        return ret = max(arr[i][0] + MaxSC(i+arr[i][1]+1,arr) , MaxSC(i+1,arr));
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        dp.assign(questions.size()+1,-1);
        return MaxSC(0,questions);
    }
};