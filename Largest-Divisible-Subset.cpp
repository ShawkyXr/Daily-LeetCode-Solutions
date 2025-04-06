class Solution {

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        vector <int> dp(n,1);
        vector <int> parent(n,-1);

        int mxdiv = 0 , idx = 0;
        for (int i=0 ; i<n ; i++){
            for (int j = i-1 ; j>=0 ; j--){
                if (nums[i]%nums[j]==0 && dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                    parent[i] = j;
                }
            }
            if (dp[i] > dp[idx]) idx = i;
        }

        vector <int> ans;
        while(idx != -1){
            ans.push_back(nums[idx]);
            idx = parent[idx];
        }

        return ans;
    }
};