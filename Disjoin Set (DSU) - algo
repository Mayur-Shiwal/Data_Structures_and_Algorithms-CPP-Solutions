#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DisjoinSet{
    vector<int> rank, parent, size;
public:
    DisjoinSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v){
        int ultimateParent_u = findUPar(u);
        int ultimateParent_v = findUPar(v);
        if(ultimateParent_u == ultimateParent_v) return;
        if(rank[ultimateParent_u] < rank[ultimateParent_v]){
            parent[ultimateParent_u] = ultimateParent_v;
        }
        else if(rank[ultimateParent_v] < rank[ultimateParent_u]){
            parent[ultimateParent_v] = ultimateParent_u;
        }
        else{
            parent[ultimateParent_v] = ultimateParent_u;
            rank[ultimateParent_u]++;
        }
    }
    void unionBySize(int u, int v){
        int ultimateParent_u = findUPar(u);
        int ultimateParent_v = findUPar(v);
        if(ultimateParent_u == ultimateParent_v) return;
        if(size[ultimateParent_u] < size[ultimateParent_v]){
            parent[ultimateParent_u] = ultimateParent_v;
            size[ultimateParent_v] += size[ultimateParent_u];
        }
        else{
            parent[ultimateParent_v] = ultimateParent_u;
            size[ultimateParent_u] += size[ultimateParent_v];
        }
    }

};

int main()
{
    DisjoinSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // checking if 3 and 7 belongs to same component or not;
    if(ds.findUPar(3) == ds.findUPar(7)) cout<<"same components"<<endl;
    else cout<<"not same component"<<endl;
    ds.unionBySize(3, 7);
    //after combining them
    if(ds.findUPar(3) == ds.findUPar(7)) cout<<"same components"<<endl;
    else cout<<"not same component"<<endl;
    return 0;

    // Time Complexity : O(4alfa) which nearly equal to O(1) == constant time..
}





