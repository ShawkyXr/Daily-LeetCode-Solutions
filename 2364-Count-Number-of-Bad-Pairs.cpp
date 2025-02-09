class Solution {
    #define ll long long
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int,ll> count;

        for (int i=0 ; i <nums.size() ; i++){
            count [nums[i]-i]++;
        }

        ll cnt = 0;
        ll ans = ((ll)n * (ll)(n-1))/2;
        for (auto &c : count){
            cnt += (c.second * (c.second-1))/2;
        }

        return ans - cnt;
    }
};