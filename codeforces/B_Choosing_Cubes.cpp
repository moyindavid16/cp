#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
    int n,f, k; cin >> n >> f >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin >> v[i];
    int num = v[f-1];
    sort(v.rbegin(), v.rend());
    if(k>=n || v[k]<num)cout << "YES";
    else if(v[k-1]==num && v[k]==num)cout << "MAYBE";
    else cout << "NO";
    cout << endl;

}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}