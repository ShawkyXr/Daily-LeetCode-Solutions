class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        
        for (int i=1 ; i<n ; i++){
            arr[i] += arr[i-1];
        }

        int even = 0,odd = 0;
        int ans = 0;
        for (int i=0 ; i<n ;i++){
            if (arr[i]&1){
                ans =  (ans%1000000007 +(even + 1) %1000000007) %1000000007;
                odd++;
            }else{
                ans = (ans%1000000007 + odd % 1000000007)%1000000007; 
                even ++;
            }
        }

        return ans;
    }
};