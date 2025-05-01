class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(workers.begin(),workers.end());
        sort(tasks.begin(),tasks.end());
        int l =1 , r = min(tasks.size(),workers.size()),ans=0;
        while(l<=r){
            int md = (l+r)/2 ;
            int k = workers.size()-1,p=pills,done = md;
            
            deque <int> qu;

            for (int i=md-1 ; i>=0 ; i--){
                while(k >= workers.size()-md && k>=0 && workers[k]+strength >= tasks[i]){

                    qu.push_front(workers[k]);
                    k--;
                }
                if (qu.empty()) break;
                else if (qu.back() >= tasks[i]){
                    qu.pop_back();
                    done--;
                }else{
                    if (p){
                        qu.pop_front();
                        p--;
                        done--;
                    }else{
                        break;
                    }
                }
            }
            if (done==0){
                ans = md;
                l = md+1;
            }else{
                r = md -1;
            }

        }

        return ans;
    }
};