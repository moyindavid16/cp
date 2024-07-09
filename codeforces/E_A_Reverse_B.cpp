#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int a; cin >> a;
  string b; cin >> b;
  reverse(b.begin(), b.end());
  int newb = stoi(b);
  cout << a + newb << endl;

}
 
int32_t main(){
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}