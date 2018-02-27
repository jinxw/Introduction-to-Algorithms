#include <vector>
#include <unordered_map>
#include <utility>
#include <queue>
#include <algorithm>
#include <set>
#include <cfloat>

std::vector<double> d;
std::vector<int> pi;

void initialize_single_source(std::vector<std::vector<double>> &G,std::size_t s);
void relax(int u,int v,std::vector<std::vector<double>> &G);

std::pair<std::vector<double>,std::vector<int>> Dijkstra(std::vector<std::vector<double>> &G,std::size_t s){
    initialize_single_source(G,s);
    std::set<std::size_t> S;
    std::set<std::size_t> Q;
    for(std::size_t i=0;i<G.size();++i){
        Q.insert(i);
    }
    while(!Q.empty()){
        std::size_t u = *Q.begin();
        for(auto v:Q){
            if(d[v] < d[u]){
                u = v;
            }
        }
        Q.erase(u);
        S.insert(u);
        for(int i=0;i<G.size();++i){
            if(i!=u && G[u][i]!=DBL_MAX){
                relax(u,i,G);
            }
        }
    }
    return std::make_pair(d,pi);
}

void initialize_single_source(std::vector<std::vector<double>> &G,std::size_t s){
    d.resize(G.size());
    std::fill(d.begin(),d.end(),DBL_MAX);
    pi.resize(G.size());
    std::fill(pi.begin(),pi.end(),-1);
    d[s] = 0;
}

void relax(int u,int v,std::vector<std::vector<double>> &G){
    if(d[v] > d[u]+G[u][v]){
        d[v] = d[u]+G[u][v];
        pi[v] = u;
    }
}