//Leetcode link -> https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
#include <bits/stdc++.h>
using namespace std;

class TreeAncestor {
public:
    vector<vector<int> > up;
    TreeAncestor(int n, vector<int>& parent) {
        int log = 0;
        while((1<<log)<=n)log++;

        up.resize(n, vector<int>(log,-1));
        for(int i=0;i<n;i++)up[i][0] = parent[i];
        
        for(int j=1;j<log;j++){
            for(int i=0;i<n;i++){
                up[i][j] = up[max(0,up[i][j-1])][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int j=0;
        while(k>0 && node!=-1){
            if(k&1){
                node = up[node][j];
            }
            j++;
            k=k>>1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

int main(){
  // [[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]
  vector<int> par = {-1,0,0,1,1,2,2};
  TreeAncestor* obj = new TreeAncestor(7, par);
  vector<array<int,2>> getKthAncestor = {{3,1},{5,2},{6,3}};
  for(auto [node,k]: getKthAncestor){
    cout << obj->getKthAncestor(node,k) << endl;
  }
}