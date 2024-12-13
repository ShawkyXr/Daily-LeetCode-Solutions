class Solution {
    struct node{
        int val,next,prev,idx;

        node (): val(0),next(-1),prev(-1),idx(-1){};

        bool operator < (const node &other)const{
            if (val == other.val){
                return idx > other.idx;
            }
            return val > other.val;
        }
    };
public:
    long long findScore(vector<int>& nums) {
        priority_queue <node> pq;
        vector<int> vis(100005);
        for (int i=0 ; i<nums.size() ;i++){
            node n;
            n.val = nums[i];
            n.idx = i;
            if (i>0) n.prev = i-1;
            if (i<nums.size()-1) n.next = i+1;
            pq.push(n);  
        }
        long long ans=0;
        while(!pq.empty()){
            node t = pq.top();
            pq.pop();
            if (vis[t.idx]){
                // vis[t.val]--;
                continue;
            }
            ans += t.val;
            if (~t.next)vis[t.next]++;
            if (~t.prev) vis[t.prev]++;
        }
        return ans;
    }
};