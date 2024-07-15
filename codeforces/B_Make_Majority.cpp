#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n; cin >> n;
  string s; cin >> s;
  int z,o;z=o=0;
  for(int i=0;i<n;i++){
    if(s[i]=='1')o++;
    else{
      i+=1;
      while(i<n && s[i]=='0'){
        i+=1;
      }
      i-=1;
      z++;
    }
  }
  if(o>z)cout << "Yes";
  else cout << "No";
  cout << endl;
}
 
int32_t main(){
  int t=1;cin>>t;
  while(t--)solve();
  return 0;
}