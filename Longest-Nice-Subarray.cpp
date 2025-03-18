class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l=0,r=0,ans = 1;
        vector <int> freq(64,0);

        while(l<=r && l < nums.size() && r < nums.size()){

            while(r<nums.size()){
                if (*max_element(freq.begin(),freq.end()) > 1) break;
                for (long long i=63 ; i>=0 ; i--){
                    if ((1LL<<i) & nums[r]) freq[i]++;
                }
                if (*max_element(freq.begin(),freq.end()) > 1) {
                    for (long long i=63 ; i>=0 ; i--){
                        if ((1LL<<i) & nums[r]) freq[i]--;
                        // ans = max(ans,r-l);
                    }
                        break;
                }
                r++;
                ans = max(ans,r-l);
            }

            for (long long i=63 ; i>=0 ; i--){
                if ((1LL<<i) & nums[l]) freq[i]--;
            }
            l++;
        }
        return ans;
    }
};