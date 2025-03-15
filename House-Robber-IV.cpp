class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(),nums.end());
        int r = *max_element(nums.begin(),nums.end());
        int ans = r;

        while (l<=r){
            int md = l + (r-l) /2;
            
            int cnt = 0;
            for (int i=0 ; i<nums.size() ; i++){
                if (nums[i]<=md){
                    cnt++;
                    i++;
                }
            }

            if (cnt>=k){
                r = md-1;
                ans = md;
            }else{
                l = md+1;
            }
        }

        return ans;
    }
};