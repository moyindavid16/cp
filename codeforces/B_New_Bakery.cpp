#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n,a,b; cin >> n >> a >> b;
  int num = b-a+1;
  if(num<=0){
    cout << a * n << endl;
    return;
  }  
  if(num>=n){
    cout << n * (b+b-n+1)/2 << endl;
    return;
  }

  int ans = (num * (a+b))/2;
  ans+= (n-num) * a;
  cout << ans << endl;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}