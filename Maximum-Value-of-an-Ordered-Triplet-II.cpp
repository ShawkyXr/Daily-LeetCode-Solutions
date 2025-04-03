class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long val = 0;
        int n = nums.size();
        vector <int> rmx(n),lmx(n);  
        for (int i=1 ; i<n ; i++){
            lmx[i] = max(lmx[i-1],nums[i-1]);
            rmx[n-i-1] = max(rmx[n-i] , nums[n-i]);
        }

        for (int i=1 ; i<n-1 ; i++){
            val = max(val, (lmx[i] - nums[i] * 1LL) * rmx[i] *1LL) ;
        }

        return val;
    }
};