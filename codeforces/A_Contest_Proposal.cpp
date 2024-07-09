#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
	int n; cin >> n;
  vector<int> a,b;
  for(int i=0;i<n;i++){
    int temp;
    cin >> temp;
    a.pb(temp);
  }
  for(int i=0;i<n;i++){
    int temp;
    cin >> temp;
    b.pb(temp);
  }

  int res = 0;
  int i=0;
  for(int j=0;j<n;j++){
    if(a[i]>b[j]){
      res++;
    }
    else{
      i++;
    }
  }
  cout << res << endl;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}