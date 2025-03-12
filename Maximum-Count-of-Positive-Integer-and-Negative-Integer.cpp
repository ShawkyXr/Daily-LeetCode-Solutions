class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg= lower_bound(nums.begin(),nums.end(),0) - nums.begin();
        int pos= lower_bound(nums.begin(),nums.end(),1) - nums.begin();
        int Nneg = max(0,neg);
        int Npos = max(0,int(nums.size())-pos);
        return max(Npos,Nneg); 
    }
};