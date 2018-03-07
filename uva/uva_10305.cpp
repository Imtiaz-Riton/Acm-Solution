#include <bits/stdc++.h>
using namespace std;

const int M = 1e2 + 7;
vector < int > g[M];
int vis[M],indegree[M];

int main()
{
    int n,m;
    while(cin >> n >> m){
        if(!m && !n) break;
        memset(g,0,sizeof g);
        memset(indegree,0,sizeof indegree);
        for(int i = 0; i < m; i++){
            int x,y;
            cin >> x >> y;
            g[x].push_back(y);
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < g[i].size(); i++){
                int v = g[i][j];
                indegree[v]++;
            }
        }
        queue < int > q;
        vector < int > order;
        order.clear();
        for(int i = 1; i <= n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            order.push_back(u);
            for(int i = 0; i < g[u].size(); i++){
                int v = g[u][i];
                indegree[v]--;
                if(indegree[v] == 0)
                    q.push(v);
            }
            cnt++;
        }
        for(int i = 0; i < order.size(); i++)
            cout << order[i] << " ";
        cout << endl;
    }
    return 0;
}
