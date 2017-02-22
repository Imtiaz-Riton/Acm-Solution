#include <bits/stdc++.h>

using namespace std;

map < string, int > level;
map < string , int > m;
map < string , int > :: iterator itr;
void bfs(string l1, string l2)
{
    queue < string > q;
    q.push(l1);
    level[l1] = 0;

    while(!q.empty()){
        string s = q.front();
        q.pop();
        for(int i = 0; i < l1.size(); i++){
            for(itr = m.begin(); itr != m.end(); itr++){
               if(itr->first.size() != l1.size()) continue;
                int dif = 0;
                string temp1,temp2;
                temp1 = itr->first;
                temp2 = s;
                //cout << temp1 << endl;
                //sort(temp1.begin(),temp1.end());
                //sort(temp2.begin(),temp2.end());

                    for(int k = 0; k < temp2.size(); k++){
                    if(temp1[k] == temp2[k])
                        dif++;
                    }
                    //cout << dif << endl;

                if((dif == (temp2.size() - 1) || dif == temp2.size()) && (m[temp1] == 0)){
                    q.push(temp1);
                    level[temp1] = level[s] + 1;
                    m[temp1] = 1;
                    //cout << temp1 << endl;
                }
            }
        }
    }
    //for(itr = level.begin(); itr != level.end(); itr++)
        //cout << itr->second << endl;
    cout << l1 << " "<< l2 << " ";
    cout << level[l2] << endl;
}

int main()
{
    int t;
    cin >> t;
    getchar();
    string l;
    while(t--)
    {
        m.clear();
        while(cin >> l){
        //cout << l << endl;
        if(l == "*") break;
        m.insert(make_pair(l,0));
        }
        //cout << "working2"<< endl;
        string start,to,line;
    size_t pos;
    getline(cin,line);
    getline(cin,line);
    while(line != ""){
      pos = line.find(" ");
      start = line.substr(0,pos);
      to = line.substr(pos+1,line.size());
      level.clear();
      bfs(start,to);
      if(!getline(cin,line))
        break;
    }
    if(t != 0)
      cout<<endl;
    }
    return 0;
}
