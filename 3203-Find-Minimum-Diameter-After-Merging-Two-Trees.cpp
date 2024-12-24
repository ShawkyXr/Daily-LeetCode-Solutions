class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

        int n = edges1.size()+1;
        int m = edges2.size()+1;

        vector <vector<int>> tree1(n);
        vector <vector<int>> tree2(m);

        for (auto &edge : edges1){
            tree1[edge[0]].push_back(edge[1]);
            tree1[edge[1]].push_back(edge[0]);
        }

        for (auto &edge : edges2){
            tree2[edge[0]].push_back(edge[1]);
            tree2[edge[1]].push_back(edge[0]);
        }

        int dia1=0,dia2=0;
        vector <int> maxfor1(n);
        vector <int> maxfor2(m);

        int farth1 = 0,mx=0;
        for (int i=0 ;i<1 ; i++){
            vector <int> vis(n);
            queue <pair<int,int>> q;
            q.push({0,0});
            vis[0] = 1;
            while (!q.empty()){
                pair <int,int> v = q.front();
                q.pop();
                maxfor1[v.first] = max(maxfor1[v.first],v.second);
                if (maxfor1[v.first] > mx){
                    mx = maxfor1[v.first];
                    farth1 = v.first;
                }
                vis[v.first] = 1;

                for (auto & node : tree1[v.first]){
                    if (!vis[node]) q.push({node,v.second+1});
                }

            }
        }

            maxfor1.clear();
        for (int i=0 ; i<1 ;i++){
            mx=0;
            vector <int> vis(n);
            queue <pair<int,int>> q;
            q.push({farth1,0});
            vis[farth1] = 1;
            while (!q.empty()){
                pair <int,int> v = q.front();
                q.pop();
                maxfor1[v.first] = max(maxfor1[v.first],v.second);
                if (maxfor1[v.first] > mx){
                    mx = maxfor1[v.first];
                }
                vis[v.first] = 1;

                for (auto & node : tree1[v.first]){
                    if (!vis[node]) q.push({node,v.second+1});
                }

            }
            dia1 = mx;
            mx=0;
        }


        int farth2 = 0;
        for (int u=0 ; u<1 ; u++){
                vector <int> vis(m);
                queue <pair<int,int>> q;
                q.push({u,0});
                vis[u] = 1;
                while (!q.empty()){
                    pair <int,int> v = q.front();
                    q.pop();
                    maxfor2[v.first] = max(maxfor2[v.first],v.second);
                    if (maxfor2[v.first] > mx){
                        mx = maxfor2[v.first];
                        farth2 = v.first;
                    }
                    vis[v.first] = 1;

                    for (auto & node : tree2[v.first]){
                       if (!vis[node]) q.push({node,v.second+1});
                    }

                }
            
        }

        maxfor2.clear();
        for (int i=0 ; i<1 ;i++){
            mx=0;
             vector <int> vis(m);
                queue <pair<int,int>> q;
                q.push({farth2,0});
                vis[farth2] = 1;
                while (!q.empty()){
                    pair <int,int> v = q.front();
                    q.pop();
                    maxfor2[v.first] = max(maxfor2[v.first],v.second);
                    if (maxfor2[v.first] > mx){
                        mx = maxfor2[v.first];
                    }
                    vis[v.first] = 1;

                    for (auto & node : tree2[v.first]){
                       if (!vis[node]) q.push({node,v.second+1});
                    }

                }
            dia2 = mx;
        }

        int bestnode1 = ceil(dia1 / 2.0);
        int bestnode2 = ceil(dia2 / 2.0);;

        int ans = max({bestnode1 + bestnode2 +1, dia1, dia2});

        return ans;
    }
};