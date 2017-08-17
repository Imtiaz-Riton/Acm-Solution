#include <bits/stdc++.h>
using namespace std;

int a[12345];
int n,k;

int rec(int index, int sum, int k){
    if(k == 0)
        return sum;
    if(index >= n)
        return 0;

    int x = rec(index + 1, sum ^ a[index], k - 1);
    int y = rec(index + 1, sum, k);

    return max(x,y);
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        cout << rec(0,0,k) << endl;
    }
    return 0;
}
