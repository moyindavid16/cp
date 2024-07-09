#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
    int n; cin >> n;
    vector<int> a(n), b=a;
    map<int, int> mp;mp.clear();
    for(int i=0;i<n;i++){cin >> a[i];}
    for(int i=0;i<n;i++){cin >> b[i];mp[b[i]]=0;}
    
    
    for(int i=0;i<n;i++){
      if(a[i]!=b[i])mp[b[i]]++;
    }

    int m; cin >> m;
    bool ex = false;
    for(int i=0;i<m;i++){
      int x;cin >> x;
      if(mp.find(x)!=mp.end()){
        ex=true;
        mp[x]--;
      }
      else ex=false;
    }

    if(!ex){
      cout << "NO" << endl;
      return;
    }
    for(auto u: mp){
      if(u.second>0){
        cout << "NO" << endl;
        return;
      }
    }
    cout << "YES" << endl;

}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}