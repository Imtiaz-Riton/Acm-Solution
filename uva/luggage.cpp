#include <bits/stdc++.h>
using namespace std;

int a[33],make,n,memo[30][1234];

bool rec(int i, int mk)
{
    if(i >= n){
        if(mk == 0) return 1;
        else return 0;
    }
    if(memo[i][mk] != -1) return memo[i][mk];
    int ret1 = 0, ret2 = 0;
    if(mk - a[i] >= 0)
        ret1 = rec(i + 1, mk - a[i]);
    ret2 = rec(i + 1, mk);
    return memo[i][mk] = ret1 | ret2;
}

int main()
{
    int t;
    cin >> t;
    getchar();
    while(t--){
        memset(memo, -1, sizeof memo);
        string s;
        getline(cin,s);
        istringstream ss(s);
        int num, idx = 0,sum = 0;
        while(ss >> num){
            a[idx++] = num;
            sum += num;
        }
        n = idx;
        if(sum & 1)
            cout << "NO" << endl;
        else{
            if(rec(0,sum / 2))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
