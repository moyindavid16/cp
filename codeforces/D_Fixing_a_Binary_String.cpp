#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
    int n, k; cin >> n >> k;
    string s, end; cin >> s;
    unordered_map<char,int> left, right; left['0'] = left['1'] = right['1'] = right['0'] = 0;
    vector<bool> allow(n,1);

    for(int i=0;i<n;i++){
      if(i<k){
        left[s[i]]++;
      }
      else if(i<2*k)right[s[i]]++;
      else break;
    }

    for(int i=0;i<n-k;i++){
      left[s[i]]--;
      left[s[i+k]]++;

      right[s[i+k]]--;
      if(i+2*k<n){
        right[s[i+2*k]]++;
      }
      else{
        right[s[i]]++;
      }

      if((left['0']==right['1'] && left['0']==0) || (right['0']==left['1'] && right['0']==0)){
        bool flag=0; string a="";
        for(int j=i+2*k;j<n;j++){
          a+=s[j];
        }
        for(int j=i;j>=0;j--)a+=s[j];
        for(int j=0;j+k<a.size();j++){
          if(a[j]==a[j+k]){
            flag=1;break;
          }
        }
        if(!flag){
          //cout << (left['0']==right['1'] && left['0']==0) << (right['0']==left['1'] && right['0']==0) << left['0'];
          cout << i + 1 << endl;
          return;
        }
      }

    }
    if((left['0']==right['1'] && left['0']==0) || (right['0']==left['1'] && right['0']==0)){
      cout << k << endl;
      return;
    }
    cout << -1 << endl;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}