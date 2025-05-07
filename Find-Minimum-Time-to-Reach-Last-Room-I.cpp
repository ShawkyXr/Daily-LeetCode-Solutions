class Solution {
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    struct room{
        long long x,y,t;

        room(long long x,long long y, long long t): x(x), y(y), t(t){}

        bool operator < (const room& e) const{
            return t > e.t;
        }
    };

public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(),m = moveTime[0].size();
        priority_queue <room> pq;
        vector <vector <long long>> dis(n,vector <long long>(m,100000000005));
        vector <vector <int>> vis(n,vector <int>(m,0));

        pq.push(room(0,0,0));
        dis[0][0] = 0;

        while(!pq.empty()){
            room r = pq.top();
            pq.pop();

            if (vis[r.x][r.y]) continue;
            vis[r.x][r.y] = 1;
            
            for (int i=0 ; i<4 ; i++){
                int x = r.x+dx[i], y = r.y+dy[i];
                if (x>=0 && x<n && y>=0 && y<m){
                    long long t = max(dis[r.x][r.y],(long long)moveTime[x][y])+1;
                    if (t < dis[x][y]){
                        dis[x][y] =  t;
                        pq.push(room(x,y,t));
                    }
                }
            }          
        }

        return dis[n-1][m-1];
    }
};