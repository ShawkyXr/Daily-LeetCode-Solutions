class Solution {

    bool is_valid(vector<int> &vec, int l , int r){
        for (int i=l+1 ; i<r ;i++){
            if (vec[i]<=vec[i-1] || vec[i]-vec[i-1]!=1) return false;
        }
        return true;
    }

public:

    vector<int> resultsArray(vector<int>& nums, int k) {
        vector <int> ans;
        int i=0;
        while(i+k <= nums.size()){
            int l=i,r=i+k;
            if (is_valid(nums,l,r)){
                ans.push_back(nums[r-1]);
            }else{
                ans.push_back(-1);
            }
            i++;
        }
        return ans;
    }
};