#include <bits/stdc++.h>
using namespace std;

const int INF= (1<<29);
int a[123456];
int mn = INF;
int state[123456];

int cc(int index, int pos,const int des, int cnt){
    if(state[index] > 1 || cnt >= mn) return INF;
    if(pos == des){
        mn = min(mn, cnt);
        return mn;
    }

    int x = INF, y = INF;
    if(pos + 1 <= des){
        state[pos]++;
        x = cc(index + 1, pos + 1,des, cnt + 1);
        state[pos]--;
    }
    if(pos + a[pos] >= 0 && pos + a[pos] <= des){
        state[pos + a[pos]]++;
        y = cc(index + a[index], pos + a[pos],des, cnt + 1);
        state[pos + a[pos]]--;
    }
    return min(x,y);
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int make;
        cin >> make;
        for(int i = 0; i < make; i++)
            cin >> a[i];
        cout << cc(0,0,make,0) << endl;
        mn = INF;
    }
    return 0;
}
