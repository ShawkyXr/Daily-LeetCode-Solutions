class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set <int> st(nums.begin(),nums.end());
        vector <int> freq(2001,0);
        int cnt = 0;
        int ans = 0;
        int r=0;
        for (int l=0 ; l<nums.size() ;l++){
            if (l>0){
                freq[nums[l-1]]--;
                if (freq[nums[l-1]]==0) cnt--;
            }
            while(r<nums.size() && cnt<st.size()){
                if (freq[nums[r]]==0){
                    cnt++;
                }
                freq[nums[r]]++;
                r++;
            }
            if (cnt>= st.size()) {
                ans+= (nums.size()-r+1);
            }

        }
        return ans;
    }
};