#include "BFS.h"
#include <iostream>
#include <climits>

int main(){
    std::vector<std::vector<int>> G(8,std::vector<int>(8,INT_MAX));
    G[0][1] = 1;
    G[1][0] = 1;
    G[0][4] = 1;
    G[4][0] = 1;
    // G[1][5] = 1;
    // G[5][1] = 1;
    G[2][3] = 1;
    G[3][2] = 1;
    G[2][5] = 1;
    G[5][2] = 1;
    G[2][6] = 1;
    G[6][2] = 1;
    G[3][6] = 1;
    G[6][3] = 1;
    G[3][7] = 1;
    G[7][3] = 1;
    G[5][6] = 1;
    G[6][5] = 1;
    G[6][7] = 1;
    G[7][6] = 1;
    auto res = BFS(G,1);
    for(auto n:res){
        std::cout<<n<<std::endl;
    }
    return 0;
}