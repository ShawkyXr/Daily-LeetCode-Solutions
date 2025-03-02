class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map <int,int> arr;
        for (auto &i : nums1){
            arr[i[0]] += i[1];
        }
        for (auto &i : nums2){
            arr[i[0]] += i[1];
        }

        vector <vector <int>> ans;
        for (auto id : arr){
            ans.push_back({id.first,id.second});
        }

        return ans;
    }
};