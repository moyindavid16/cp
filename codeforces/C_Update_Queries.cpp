#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n,m; cin >> n >> m;
  string s; cin >> s;
  vector<int> ind(m);
  for(int i=0;i<m;i++)cin >> ind[i];
  string c; cin >> c;
  sort(c.begin(), c.end());
  sort(ind.begin(), ind.end());

  int l=1, r=m-1;
  s[ind[0]-1] = c[0];
  for(int i=1;i<m;i++){
    if(ind[i]==ind[i-1]){
      r--;
    }
    else{
      s[ind[i]-1]=c[l];
      l++;
    }
  }
  cout << s << endl;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}