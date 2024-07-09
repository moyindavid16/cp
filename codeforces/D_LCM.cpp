#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int a,b; cin >> a >> b;
  if(a>b)swap(a,b);

  int res=b;
  while(res%a!=0)res+=b;
  cout << res << endl;

}
 
int32_t main(){
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}