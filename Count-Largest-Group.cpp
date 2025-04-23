class Solution {
public:
    int countLargestGroup(int n) {
        vector <int> freq(200,0);
        for (int i=1 ;i<=n ;i++){
            int num = i,sum = 0;
            while(num>0){
                sum += num%10;
                num/=10;
            }
            freq[sum]++;
        }

        return count(freq.begin(),freq.end(),*max_element(freq.begin(),freq.end()));
    }
};