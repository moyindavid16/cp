#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
    int n, m; cin >> n >> m;
    map<char, int> mp;
    for(char c = 'A';c<='G';c++)mp[c]=0;

    string s; cin >> s;
    for(auto u:s)mp[u]++;

    int res=0;
    for(auto u: mp){
      res+=max(0,m-u.second);
    }
    cout << res << endl;
    

}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}