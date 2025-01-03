class Solution {
    #define ll long long
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector <ll> pre(n);
        vector <ll> suf(n);

        pre[0]=nums[0];
        for (int i=1 ; i< n ; i++){
            pre[i] = pre[i-1] + nums[i];
        }

        suf[n-1] = nums[n-1];
        for (int i=n-2 ; i>=0 ;i--){
            suf[i] = suf[i+1] + nums[i];
        }

        int ans = 0;
        for (int i=0 ; i<n-1 ;i++){
            if (pre[i]>=suf[i+1]) ans++;
        }

        return ans;
    }
};