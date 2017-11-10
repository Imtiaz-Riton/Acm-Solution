#include <bits/stdc++.h>
#define lli long long int
using namespace std;

lli pw(lli b, lli p)
{
    lli ans = 1;
    for(int i = 0; i < p; i++)
        ans *= b;
    return ans;
}

lli rec(lli n)
{
    if(n == 0)
        return 0;
    else
        return 2 * rec(n - 1) + pw(2,n - 1);
}

lli cnt_digit(lli n)
{
    lli cnt = 0;
    while(n != 0){
        cnt++;
        n = n / 2;
    }
    return cnt;
}

lli dig_ret(lli d)
{
    lli dig = 1;
    for(int i = 0; i < d; i++)
        dig = dig << 1;
    return dig;
}

lli process(lli n)
{
    lli tt = n;
    lli temp = cnt_digit(n);
    lli dig;
    dig = dig_ret(temp - 1);
    lli sum = 0;
    sum += rec(temp - 1);
    while((n - dig) >= 1){
        sum += n - dig;
        n = n - dig;
        temp = cnt_digit(n);
        dig = dig_ret(temp - 1);
        sum += rec(temp - 1);
    }
    while(tt != 0){
        sum += tt % 2;
        tt = tt / 2;
    }
    return sum;
}

int main()
{
    lli n,m,nc = 1;
    while(cin >> n >> m){
        if(!n && !m) break;
        lli sum = 0,x,y;
        if(n == m){
            while(n != 0){
                (n % 2) ? sum++ : sum;
                n = n / 2;
            }
            printf("Case %lld: %lld\n",nc++,sum);
        }
        else{
            if(n == 0 || n == 1)
                sum = process(m);
            else{
                x = process(n - 1);
                y = process(m);
                sum = y - x;
            }
            printf("Case %lld: %lld\n",nc++,sum);
        }
    }

    return 0;
}
