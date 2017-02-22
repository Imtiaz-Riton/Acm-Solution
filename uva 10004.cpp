#include <bits/stdc++.h>
#define rep(l,r) for(int i = (l); i < l; i++)
using namespace std;

int vis[234];
int color[1234];

vector < int > v[211];

int bfs()
{
    queue < int > q;
    memset(vis,0,sizeof(vis));
    memset(color,-1,sizeof(color));
    q.push(0);
    vis[q.front()] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < v[u].size(); i++){
            int n = v[u][i];
            if(!vis[n]){
                vis[n] = 1;
                color[n] = color[u] * -1;
                q.push(n);
            }
            else{
                if(color[u] == color[n]){
                    cout << "NOT BICOLORABLE." << endl;
                    return 0;
                }
            }
        }
    }
    cout << "BICOLORABLE." << endl;
    return 0;
}

int main()
{
    int n,e;
    while(cin >> n){
        if(!n) break;
        cin >> e;
        int x,y;
        for(int i = 0; i < e; i++){
           cin >> x >> y;
           v[x].push_back(y);
           v[y].push_back(x);
        }
        bfs();
        for(int i = 0; i < n; i++) v[i].clear();
    }
    return 0;
}
