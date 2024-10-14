
#include<stdio.h>
#include <vector>
#include <iostream>
using namespace std;

void connect(int x, int y, vector<int>&leader, vector<int>&size, vector<vector<int>>&comp){
    int leader_x = leader[x];
    int leader_y = leader[y];

    if(leader_x == leader_y) return;

    if(size[leader_y] < size[leader_x]) swap(leader_x, leader_y);
    
    for(int node : comp[leader_x]){
        leader[node] = leader_y;
        comp[leader_y].push_back(node);
    }
    size[leader_y] += size[leader_x];
}


int main(){
    int n ;
    cin>>n;
    vector<int>leader(n,0);
    vector<int>size(n);
    vector<vector<int>>comp(n);
    for(int i = 0; i < n; i++){
        leader[i] = i;
        comp[i] = {i};
        size[i] = 1; // all the node already own leader 
    }
    return 0;

}