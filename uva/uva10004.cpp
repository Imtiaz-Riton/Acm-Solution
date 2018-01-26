#include <bits/stdc++.h>
using namespace std;

const int M = 1e3 + 7;
vector < int > g[M];
int vis[M],col[M];
bool ok;

void dfs(int s, int color){
    vis[s] = 1;
    col[s] = color;
    for(int i = 0; i < g[s].size(); i++){
        int v = g[s][i];
        if(!vis[v]){
            dfs(v,1 ^ color);
        }
        else{
            if(col[s] == col[v])
                ok = true;
        }
    }
}

int main()
{
    int n;

    while(scanf("%d", &n) == 1){
        if(!n) break;
        memset(g,0,sizeof g);
        memset(vis,0,sizeof vis);
        memset(col,0,sizeof col);
        ok = false;
        int e;
        scanf("%d", &e);
        int x,y;
        for(int i = 0; i < e; i++){
            scanf("%d %d",&x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }

        dfs(0,0);
        if(!ok) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }

    return 0;
}
