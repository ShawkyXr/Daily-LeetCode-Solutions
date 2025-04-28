class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        vector <long long> pref;
        pref.push_back(0);
        pref.push_back(nums[0]);
        for (int i=1 ; i<nums.size() ; i++){
            pref.push_back(pref.back()+nums[i]);
        }
        long long ret=0;
        for (int i=1 ; i<=nums.size() ; i++){
            int l=i , r=nums.size(),ans = i-1;
            while(l<=r){
                int md = (l+r)/2;
                if ((pref[md]- pref[i-1]) * (md-i+1) < k) l = md+1,ans = md;
                else r = md-1;
            }
            if (ans >=i) {
                // cout << i << " " << ans << "\n";
                ret += ans-i+1;
            }
        }

        return ret;
    }
};