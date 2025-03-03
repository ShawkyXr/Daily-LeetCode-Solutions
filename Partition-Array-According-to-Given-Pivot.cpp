class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector <int> ans,less,great;
        int cnt = 0;
        for (int i=0 ; i<nums.size() ; i++){
            if (nums[i] < pivot) less.push_back(nums[i]);
            else if (nums[i] > pivot) great.push_back(nums[i]);
            else cnt++;
        }
        for (int i=0 ; i<less.size() ; i++) ans.push_back(less[i]);
        for (int i=0 ; i<cnt ; i++) ans.push_back(pivot);
        for (int i=0 ; i<great.size() ; i++) ans.push_back(great[i]);

        return ans;
    }
};