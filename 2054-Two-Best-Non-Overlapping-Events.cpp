class Solution {

    struct event{
        int start;
        int end;
        int val;

        event(int s,int e,int v): start(s),end(e),val(v){}

        bool operator < (const event &other) const{
            if (start==other.start) return val < other.val;
            return start < other.start;
        }
    };

public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector <event> vec;
        for (auto &ev : events){
            vec.push_back(event(ev[0],ev[1],ev[2]));
        }

        sort(vec.begin(),vec.end());

        map <int,int> best; // best val from each start
        int best_val = 0;
        for (int i= vec.size()-1 ; i>=0 ;i--){
            best_val = max(best_val,vec[i].val);
            best[vec[i].start]=best_val;
        }

        int ans = 0;
        for (int i=0 ;i<vec.size() ; i++){
            if (vec[i].end+1 > vec[vec.size()-1].start){
                ans = max (ans,vec[i].val);
                continue;
            }
            int best_next = best.lower_bound(vec[i].end+1)->second;
            ans = max(ans, vec[i].val + best_next );
        }

        return ans;
    }
};