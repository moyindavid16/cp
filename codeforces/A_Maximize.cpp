#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
	int x; cin >> x;
  int y = x-1;
  int ans=0, res=0;
  while(y>=1){
    int temp=0;
    if(x%y==0)temp+=y;
    else temp+=1;
    temp+=y;
    if(temp>ans)ans = temp, res = y;
    y--;
  }
  cout << res << endl;
  return;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}