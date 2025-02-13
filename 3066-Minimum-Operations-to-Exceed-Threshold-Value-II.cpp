class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue  <long long,vector<long long> ,greater<long long>> pq;
        for (auto num : nums){
            pq.push((long long)num);
        }

        int cnt = 0;
        while(pq.top()<k && pq.size() >= 2){
            long long t1 = pq.top();
            pq.pop();
            long long t2 = pq.top();
            pq.pop();
            long long n = min(t1,t2)*2 + max(t1,t2);
            pq.push(n);
            cnt++;
        }

        return cnt;
    }
};