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

  sort(a.begin(), a.end());
  bool yes=1;
  for(int i=1;i<n;i++){
    if(a[i]%a[0]!=0){
      for(int j=i+1;j<n;j++){
        if(a[j]%a[i]!=0 && a[j]%a[0]!=0)yes=0;
      }
      break;
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