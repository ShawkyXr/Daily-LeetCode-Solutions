class Solution {
public:
    long long coloredCells(int n) {
        long long x = 1;
        long long add = 4;
        for (int i=1 ; i<n ; i++){
            x+=add;
            add+=4;
        }

        return x;
    }
};