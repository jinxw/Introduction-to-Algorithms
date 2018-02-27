#include <iostream>
#include <vector>
#include <cfloat>
#include "Dijkstra.h"

int main(){
    std::vector<std::vector<double>> G(5,std::vector<double>(5,DBL_MAX));
    G[0][1] = 10;
    G[0][3] = 5;
    G[1][2] = 1;
    G[1][3] = 2;
    G[2][4] = 4;
    G[3][1] = 3;
    G[3][2] = 9;
    G[3][4] = 2;
    G[4][0] = 7;
    G[4][2] = 6;
    auto res = Dijkstra(G,0);
    auto &d = res.first;
    auto &pi = res.second;
    for(std::size_t i=0;i<d.size();++i){
        std::cout<<i<<" "<<d[i]<<std::endl;
    }
    return 0;
}