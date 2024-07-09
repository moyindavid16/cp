#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n, k; cin >> n >> k;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin >> v[i];
  sort(v.begin(), v.end());

  map<int, vector<int>> mod;mod.clear();
  for(auto u: v){
    int temp = u%k;
    if(mod.find(temp)==mod.end())mod[temp]={};
    mod[temp].pb(u);
  }

  int no_found = 0;
  for(auto [key, val]: mod){
    if(val.size()%2==1)no_found++;
    if(no_found>v.size()%2){
      cout << -1 << endl;
      return;
    }
  }

  int ans=0;
  for(auto [key, val]: mod){
    if(val.size()==1)continue;

    if(val.size()%2==1){
      int tans=INF;
      vector<int> p, s(val.size());p=s;
      p[0]=0;s[val.size()-1]=0;
      for(int i=1;i<val.size();i++){
        p[i]=p[i-1];
        if(i%2==1)p[i]+=(val[i]-val[i-1])/k;
      }
      for(int i=val.size()-2;i>=0;i--){
        s[i]=s[i+1];
        if(i%2==1)s[i]+=(val[i+1]-val[i])/k;
      }

      for(int j=0;j<val.size();j++){
        int temp=0;
        if(j>0)temp+=p[j-1];
        if(j+1<val.size())temp+=s[j+1];
        if(j%2==1 && j+1<val.size())temp+=(val[j+1]-val[j-1])/k;
        tans=min(temp, tans);
      }
      ans+=tans;
    }
    else{
      for(int i=0;i<val.size()-1;i+=2){
        // cout << val[i] << " " << val[i+1] << " s";
        ans+=(val[i+1]-val[i])/k;
        // cout <<"h"<< (val[i+1]-val[i])/k << " " << k;
      }
    }
  }

  cout << ans << endl;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}