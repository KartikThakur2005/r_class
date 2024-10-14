#include<iostream>
#include<vector>
using namespace std;

struct DSU
{
    int n;
    vector<int>leader,size;

    DSU(int n){
        n = this->n;
       leader.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i <= n; i++){
           leader[i] = i;
            size[i] = 1;
        }
    }

    int getLeader(int u){
        // if u is the leader own ourself return u
        // else return u = getLeader(leader(u));
        if(leader[u] == u) return u;
        return leader[u] = getLeader(leader[u]); // update the leader of u 
    }

    void  connect(int x, int y){
        int leader_x = getLeader(x);
        int leader_y = getLeader(y);

        if(leader_x == leader_y) return ;

        if(size[leader_x] > size[leader_y]) swap(leader_x, leader_y);

        leader[leader_y] = leader_x;
        size[leader_x] += leader[leader_y];
    }
};

int main(){

}
