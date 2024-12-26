class Solution {
    int rec(int i,vector<int> &v,int target,int sum){
        if (i==v.size()){
            return sum==target;
        }
        int ans =0;
        int ch1 = rec(i+1,v,target,sum+v[i]);
        int ch2 = rec(i+1,v,target,sum-v[i]);
        ans = ch1 + ch2;
        return ans;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return rec(0,nums,target,0);
    }
};