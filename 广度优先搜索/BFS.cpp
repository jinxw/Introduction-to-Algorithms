#include <vector>
#include <climits>
#include <queue>

//返回BFS到的点的下标
std::vector<std::size_t> BFS(std::vector<std::vector<int>> &G,std::size_t s){
    std::vector<int> color(G.size());
    std::vector<int> d(G.size());
    std::vector<int> pi(G.size());
    for(std::size_t i=0;i<color.size();++i){
        if(i == s){
            color[i] = 1;
            d[i] = 0;
            pi[i] == -1;
        }else{
            color[i] = 0;
            d[i] = INT_MAX;
            pi[i] == -1;
        }
    }
    std::queue<std::size_t> Q;
    Q.push(s);
    while(!Q.empty()){
        auto u = Q.front();
        Q.pop();
        for(std::size_t v=0;v<G.size();++v){
            if(G[u][v] != INT_MAX){
                if(color[v] == 0){
                    color[v] = 1;
                    d[v] = d[u]+1;
                    pi[v] = u;
                    Q.push(v);
                }
            }
        }
        color[u] = 2;
    }
    std::vector<std::size_t> visited;
    for(std::size_t i=0;i<color.size();++i){
        if(color[i] == 2){
            visited.push_back(i);
        }
    }
    return visited;
}