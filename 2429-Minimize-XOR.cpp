class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ones = __builtin_popcount(num2);
        int x = 0;

        for (int i = 31 ; i>=0 ; i--){
            if (((1<<i)&num1) && ones){
                ones--;
                x |= (1<<i);
            }
        }

        for (int i=0 ; i<32 ;i++){
            if (!((1<<i)&x) && ones){
                ones--;
                x |= (1<<i);
            }
        }

        return x;
    }
};