class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector <int> powers;
        int x = 1;
        while(x<=10000000){
            powers.push_back(x);
            x*=3;
        }
        
        for (int i = 1 ; i<=1<<15 ; i++){
            int sum = 0;
            for(int b=0 ; b < 15 ; b++){
                if (1 & (i>>b)) sum+=powers[b];
            }
            if (sum == n) return true;
        }
        return false;
    }
};