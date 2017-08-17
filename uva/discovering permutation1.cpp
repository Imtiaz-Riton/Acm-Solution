#include <bits/stdc++.h>
using namespace std;

string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string l , l1;
int cnt;
int n,k;
int chk[234];

void permute(int index, int sz){
    if(index >= sz){
        for(int i = 0; i < n; i++)
            cout << l1[i];
        cout << endl;
        cnt++;
    }
    else{
        for(int i = 0; i < sz; i++){
            if(cnt < k){
                if(!chk[l[i]]){
                    chk[l[i]] = 1;
                    l1[index] = l[i];
                    permute(index + 1, sz);
                    chk[l[i]] = 0;
                }
            }
        }
    }
    return;
}

int main()
{
    int t,nc = 1;
    cin >> t;
    while(t--){
        memset(chk , 0, sizeof chk);
        l = "";
        l1 = "";
        cin >> n >> k;
        for(int i = 0; i < n; i++)
            l += s[i];

        printf("Case %d:\n",nc++);
        permute(0,n);
        cnt = 0;
    }
    return 0;
}
