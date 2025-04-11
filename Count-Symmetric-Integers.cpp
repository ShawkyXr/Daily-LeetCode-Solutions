class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i=low ; i<=high ; i++){
            int dig = log10(i) + 1;
            if (dig & 1) continue;

            string num = to_string(i);
            int sum1 = 0, sum2 = 0;
            for (int k=0 ; k < dig ; k++){
                if (k < dig/2) sum1 += num[k] - '0';
                else sum2 += num[k] - '0';
            }

            if (sum1 == sum2) ans++;
        }

        return ans;
    }
};