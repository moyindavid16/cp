#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
    int n,c; cin >> n >> c;
    vector<int> v(n);int mx=-INF,mxi=0;
    for(int i=0;i<n;i++){
      cin >> v[i];
      if(i==0)v[i]+=c;
      if(v[i]>mx){
        mx=v[i];mxi=i;
      }
    }

    int acc = 0;
    for(int i=0;i<n;i++){
      acc+=v[i];
      if(i==mxi)cout << 0 << " ";
      else if(i>mxi || acc>=mx){
        cout << i << " ";
      }
      else cout << i+1 << " ";
      
    }
    cout << endl;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}