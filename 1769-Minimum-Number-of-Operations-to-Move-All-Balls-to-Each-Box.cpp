class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector <int> ans(n);
        for(int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ;j++){
                if (i!=j){
                    if (boxes[j]-'0') ans[i]+= abs(j-i);
                }
            }
        }
        return ans;
    }
};