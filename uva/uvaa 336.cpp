#include <bits/stdc++.h>

using namespace std;

map < int , vector < int > > g;
map < int , int > vis;
map < int , int > dis;

void bfs(int u){
    vis.clear();
    dis.clear();
    vis[u] = 1;
    dis[u] = 0;
    queue < int > q;
    q.push(u);
    while(!q.empty()){
        u = q.front();
        q.pop();
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(!vis[v]){
            vis[v] = 1;
            dis[v] = dis[u] + 1;
            q.push(v);
        }
      }
    }
}

int main()
{
    int n,c = 1;
    while(cin >> n){
        g.clear();
        if(!n) break;
        int x,y;
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int q,t;
        while(cin >> q >> t){
            if(!q && !t) break;
            int cnt = 0;
            bfs(q);
            map < int , int > :: iterator itr;
            for(itr = dis.begin(); itr != dis.end(); itr++){
                if(itr->second > t)
                    cnt++;
            }
            cnt += g.size() - vis.size();
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",c++,cnt,q,t);
        }
    }
    return 0;
}
