class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        vector<int> freq(100005,0);
        int l=0,r=0;
        long long sum =0 ,ans=0;
        while(r<nums.size()){
            sum+=nums[r];
            freq[nums[r]]++;
            while(freq[nums[r]]>1 || freq[nums[l]]>1 || r-l>=k){
                sum-=nums[l];
                freq[nums[l]]--;
                l++;
            }
            if (r-l+1==k) ans = max(ans,sum);
            r++;
        }
        return ans;
    }
};