class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0 ,numOfNeg =0,maxNeg =INT_MAX;
        for (auto row : matrix){
            for (int i=0 ; i<row.size() ;i++){
                if (row[i]<0){
                    numOfNeg++;
                }
                maxNeg = min(maxNeg,(long long)abs(row[i]));
                ans+=abs(row[i]);
            }
        }
        cout << ans;
        if (numOfNeg & 1){
            ans-=(maxNeg*2);
        } 
        return ans;
    }
};