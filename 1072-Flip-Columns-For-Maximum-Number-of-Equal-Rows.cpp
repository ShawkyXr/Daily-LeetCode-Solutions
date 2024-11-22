class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int ans =0;
        for (int i=0 ;i<matrix.size()-1 ;i++){
            int val=1;
            for (int k=i+1 ; k<matrix.size() ; k++){
                    int sum =0 ;
                for (int j=0 ; j<matrix[0].size() ; j++){
                    sum+= (matrix[i][j]^matrix[k][j]);
                }
                if (sum==0 || sum==matrix[0].size()) val++;
            }
            ans = max(ans,val);
        }
        return ans;
    }
};