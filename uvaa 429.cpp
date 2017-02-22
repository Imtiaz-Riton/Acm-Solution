#include <bits/stdc++.h>

using namespace std;

map < string , int > vis;
map < string , int > dis;
vector < string > v;
void bfs(string s1){
    vis.clear();
    dis.clear();
     queue < string > q;
     vis[s1] = 1;
     dis[s1] = 0;
     q.push(s1);
     vector < string > :: iterator itr;
     while(!q.empty()){
        s1 = q.front();
        q.pop();
        for(itr = v.begin(); itr != v.end(); itr++){
            if((*itr).size() != s1.size()) continue;
            string s2 = *itr;
            int dif = 0;
            for(int i = 0; i < s1.size(); i++){
                if(s1[i] != s2[i])
                    dif++;
            }
            if(dif == 0 || dif == 1){
                if(!vis[s2]){
                    vis[s2] = 1;
                    dis[s2] = dis[s1] + 1;
                    q.push(s2);
                }
            }
        }
     }
}

int main()
{
    //freopen("input.txt", "r",  stdin);
    //freopen("output.txt", "w",  stdout);
    int t;
    cin >> t;
    getchar();
    while(t--){
        v.clear();
        string s;
        while(cin >> s){
            if(s == "*") break;
            v.push_back(s);
        }
        getchar();
        string q1,q2;
        getline(cin,s);
        while(s != ""){
            int pos = s.find(" ");
            q1 = s.substr(0,pos);
            q2 = s.substr(pos+1,s.size());
            bfs(q1);
            cout << q1 << " " << q2 << " " << dis[q2] << endl;
            if(!getline(cin,s)) break;
        }
        if(t)
            cout << endl;
    }
    return 0;
}
