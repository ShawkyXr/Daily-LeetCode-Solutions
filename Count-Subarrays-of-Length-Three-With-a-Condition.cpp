class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int p1=0,p2=1,p3=2;
        int ans = 0;
        while(p3<nums.size()){
            if ((nums[p1++]+nums[p3++])*2 == nums[p2++]) ans++;
        }

        return ans;
    }
};