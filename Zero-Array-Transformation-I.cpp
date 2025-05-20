class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector <int> par(nums.size());
        for (auto q : queries){
            par[q[0]]++;
            if (q[1]+1 != nums.size()) par[q[1]+1]--;
        }
        nums[0] -= par[0];
        if (nums[0]>0) return false;
        for (int i=1 ; i<nums.size() ;i++){
            par[i] += par[i-1];
            nums[i]-= par[i];
            if (nums[i]>0) return false;
        }

        return true;
    }
};