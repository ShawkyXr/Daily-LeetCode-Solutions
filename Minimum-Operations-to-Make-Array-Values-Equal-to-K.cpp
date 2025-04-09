class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mn = *min_element(nums.begin(),nums.end());

        if (k > mn) return -1;

        set <int> st (nums.begin(),nums.end());
        return k == mn ? st.size()-1 : st.size();
    }
};