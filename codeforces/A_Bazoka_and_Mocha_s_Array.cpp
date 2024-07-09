#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++)cin >> a[i];
  int i=1;
  while(i<n && a[i]>=a[i-1]){
    i++;
  }
  bool yes=1;
  if(i<n){
    if(a[i]>a[0]){yes=0;}
    i++;
    while(i<n){
      if(a[i]<a[i-1] || a[i]>a[0]){
        yes=0;break;
      }
      i++;
    }
  }
  if(yes)cout << "Yes";
  else cout << "No";
  cout << endl;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}