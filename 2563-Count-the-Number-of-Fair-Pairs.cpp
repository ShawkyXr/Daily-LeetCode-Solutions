class Solution {
    int get_lower(vector<int>& vec,long long val,int i){
        int l=i,r=vec.size()-1;
        while(l<=r){
            int md = (l+r)/2;
            if (vec[md]>=val){
                r = md-1;
            }else{
                l = md+1;
            }
        }
        return l;
    }

      int get_upper(vector<int>& vec,long long val,int i){
        int l=i,r=vec.size()-1;
        while(l<=r){
            int md = (l+r)/2;
            if (vec[md]<val){
                l = md+1;
            }else{
                r = md-1;
            }
        }
        return l;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long ans = 0;
        for (int i=0 ; i<n ; i++){
            int left = 0,right=0;
            // get lower bound for lower-nums[i]
            long long val = lower-nums[i];
            left = get_lower(nums,val,i+1);

            // get upper bound for upper-nums[i]
            val = upper-nums[i]+1;
            right = get_upper(nums,val,i+1);

            ans+=(right-left);
        }
        return ans;
    }
};