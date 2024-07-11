#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int a,b,c;cin >> a >> b >> c;
  int ans = INT_MIN;
  for(int i=0;i<=5;i++){
    for(int j=0;j<=5;j++){
      for(int k=0;k<=5;k++){
        if(i+k+j==5)ans=max(ans, (a+i)*(b+j)*(c+k));
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