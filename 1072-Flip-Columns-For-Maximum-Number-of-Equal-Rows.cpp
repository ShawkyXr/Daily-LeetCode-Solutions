class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int ans =0;
        map<string,int> mp;
        for (int i=0 ;i<matrix.size() ;i++){
            string s="";
            for (int j=0 ;j<matrix[0].size() ;j++){
                s+= (matrix[i][j]^matrix[i][0])+'0';
            }
            mp[s]++;
        }
        for (auto f : mp){
            ans = max(f.second,ans);
        }
        return ans;
    }
};