#include <bits/stdc++.h>
using namespace std;

int row[8];
int fRow[8];
int mn = INT_MAX;

bool valid(int r, int c){
    for(int i = 0; i < c; i++){
        if(row[i] == r || (abs(row[i] - r) == abs(i - c)))
            return false;
    }
    return true;
}

void queen(int c){
    if(c == 8){
        int v = 0;
        for(int i = 0; i < 8; i++){
            if(fRow[i] == row[i])
                v += 0;
            else
                v += 1;
        }
        mn = min(v,mn);
    }
    for(int i = 0; i < 8; i++){
        if(valid(i,c)){
            row[c] = i;
            queen((c + 1));
        }
    }
}

int main()
{
    int nc = 1;
    while(cin >> fRow[0] >> fRow[1] >> fRow[2] >> fRow[3] >> fRow[4] >> fRow[5] >> fRow[6] >> fRow[7]){
        fRow[0]--;
        fRow[1]--;
        fRow[2]--;
        fRow[3]--;
        fRow[4]--;
        fRow[5]--;
        fRow[6]--;
        fRow[7]--;
        queen(0);
        printf("Case %d: %d\n",nc++,mn);
        mn = INT_MAX;
    }
    return 0;
}
