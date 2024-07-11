#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n; cin >> n;
  if(n==1){
    cout << 9999 << endl;
    for(int i=2;i<=10000;i++)cout << i << " " << i-1 << endl;
    return;
  }
  vector<pair<int,int>> ans;

  int res=n, ocnt=to_string(n).size();
  int a=0;
  string sn = to_string(n);
  string curr="";
  for(int i=0;i<1000;i++){
    curr+=sn[i%ocnt];
    if(curr.size()>7)break;
    int top = stoi(curr)-curr.size();
    int bot = n-ocnt;
    if(bot<=0)break;
    if(top%bot!=0)continue;
    int a=top/bot;
    int b=a*ocnt - curr.size();
    if(a>0 && b>0 && a<=10000)ans.pb({a,b});
  }

  cout << ans.size() << endl;
  for(auto [a,b]: ans)cout << a << " " << b << endl;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}