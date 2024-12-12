class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue <int> pq;

        for (int i=0 ; i<gifts.size() ; i++){
            pq.push(gifts[i]);
        }

        long long ans=0;
        for (int i=0 ; i<k ; i++){
            pq.push(sqrt(pq.top()));
            pq.pop();
        }
        while(!pq.empty()){
            ans+= pq.top();
            pq.pop();
        }
        return ans;
    }
};