#include <bits/stdc++.h>
#define ll long long
// #define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n,m,p; cin >> n >> m >> p;
  if(n>m)swap(n,m);

  
  for(int i=1;i<=sqrt(p);i++){
    if(!(p%i)){
      int a=i, b=p/i;
      if(n>=a && m>=b){
        cout << "Yes" << endl;
        return;
      }
    }
  }

  cout << "No" << endl;

}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}