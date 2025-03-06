class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
       vector <int> freq(n*n+1);
       for (int i=0 ; i<n ; i++){
        for (int j=0 ; j <n ;j++){
            freq[grid[i][j]]++;
        }
       } 

        vector <int> ans(2);
       for (int i=1 ; i<freq.size() ; i++){
        if (!freq[i]) ans[1] = i;
        if (freq[i]==2) ans[0] = i;        
       }

        return ans;
    }
};