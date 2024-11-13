class Solution {

vector<int> fill_sieve (){
    vector <int> is_prime(1e3+1,1);
    is_prime[0]=is_prime[1]=0;
    for (int i=2 ; i*i<=1e3 ; i++){
        if (is_prime[i]){
            for (int j=i*i ; j<=1e3 ; j+=i){
                is_prime[j]=0;
            }
        }
    }
    return is_prime;
}
vector <int> sieve = fill_sieve();

public:

    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes(1,-1);
        for (int i=1 ; i<=1e3 ; i++){
            if (sieve[i]) primes.push_back(i);
        }
        int lst=0;
        for (int i=0 ; i<nums.size();i++){
            int l=0,r=primes.size()-1,ans=-1;
            while(l<=r){
                int md = (l+r)/2;
                if (primes[md]<(nums[i]-lst)){
                    l=md+1;
                    ans=primes[md];
                }else{
                    r=md-1;
                }
            }
            if (ans==-1){
                lst = nums[i];
                continue;
            }
            nums[i]-=ans;
            lst=nums[i];
        }
        for (auto i : nums){
            cout << i << " ";
        }

        for (int i=1 ; i<nums.size() ; i++){
            if (nums[i]<= nums[i-1]) return false;
        }
        return true;
    }
};