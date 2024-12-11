class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int freq[100001]{};

        for (auto &i : nums){
            freq[i]++;
        }

        int pref[100003]{};

        int mx = *max_element(nums.begin(),nums.end());

        for (int i=0 ; i <= mx ;i++){
            if (i>0) pref[i] = pref[i-1] + freq[i];
            else pref[i] = freq[i];
        }

        int ans = 0;

        for (int i=0 ; i<=mx ;i++){
            int n=0;
            int l = i-k-1,r = min(mx,i+k);
            if (l<0){
                n = pref[r];
            }else{
                n = pref[r]-pref[l];
            }
            ans = max(ans,n);
        }

        return ans;
    }
};