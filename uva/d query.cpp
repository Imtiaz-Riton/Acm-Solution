#include <bits/stdc++.h>
using namespace std;

const int M = 1e6 + 7;
int tree1[M],a[M],n,ans[M];
pair < int , pair < int , int > > p[M];
int ok[M];

void update(int idx, int val)
{
    while(idx <= n){
        tree1[idx] += val;
        idx += idx & (-idx);
    }
}

int query(int idx)
{
    int s = 0;
    while(idx > 0){
        s += tree1[idx];
        idx -= idx & (-idx);
    }
    return s;
}

int main()
{
    //int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d", a + i);
    }
    int q,x,y;
    scanf("%d",&q);
    for(int i = 0; i < q; i++){
        scanf("%d%d",&x,&y);
        p[i].first = y;
        p[i].second.first = x;
        p[i].second.second = i;
    }
    sort(p, p + q);



    int tx = 0;
    for(int i = 1; i <= n; i++){

        if(ok[a[i]])
            update(ok[a[i]],-1);

        ok[a[i]] = i;
        update(i,1);

        while(tx < q && p[tx].first == i){
            ans[p[tx].second.second] = query(p[tx].first) - query(p[tx].second.first - 1);
            tx++;
        }
    }
    for(int i = 0; i < q; i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
