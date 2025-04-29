class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        vector <int> idx;
        int mx = *max_element(nums.begin(),nums.end());
        for (int i=0 ; i<nums.size() ; i++){
            if (nums[i]==mx) idx.push_back(i);
        }  
        long long ans = 0;
        for (int l=0 ; l<nums.size() ; l++){
            int st = lower_bound(idx.begin(),idx.end(),l) - idx.begin();
            int end = st+k-1;
            if (st==nums.size() || end>=idx.size()) continue;
            ans += nums.size()-idx[end];
        }

        return ans;
    }
};