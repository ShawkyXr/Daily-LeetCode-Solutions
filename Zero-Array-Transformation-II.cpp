class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();

        int l=0 ,r = q, ans = -1;
        while(l<=r){
            int md = (l+r)/2;
            vector <int> par(n+1);
            for (int i=0 ; i<md ; i++){
                par[queries[i][0]] += queries[i][2];
                par[queries[i][1]+1] -= queries[i][2];
            }

            int cnt=0;
            for (int i=0 ; i<n ; i++){
                if (i>0){
                    par[i]+=par[i-1];
                }
                if (par[i]>=nums[i]) cnt++;
            }

            if (cnt==n){
                r=md-1;
                ans = md;
            }else{
                l=md+1;
            }
        }

        return ans;
    }
};