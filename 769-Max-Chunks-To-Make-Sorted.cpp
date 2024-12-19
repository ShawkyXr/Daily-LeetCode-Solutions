class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0;
        int unsorted=0;
        int mx=0;
        for (int i=0 ; i<arr.size() ;i++){
            if (arr[i]!=i ){
                unsorted=1;
                mx = max(mx,arr[i]);
                if (mx == i) {
                    unsorted=0;
                    ans++;
                }
            }else{
                if (arr[i]<mx) continue;
                if (unsorted) ans++;
                unsorted=0;
                ans++;
            }
        }
        if (unsorted) ans++;
        return ans;
    }
};