#include <vector>
#include <climits>
#include <algorithm>
#include <tuple>
#include <iostream>

std::tuple<std::vector<int>,std::vector<int>> extended_bottom_up_cut_rod(std::vector<int> &p,std::size_t n){
    std::vector<int> r(n+1);
    std::vector<int> s(n+1);
    r[0] = 0;
    for(std::size_t j=1;j<=n;++j){
        int q=INT_MIN;
        for(std::size_t i=1;i<=j;++i){
            if(q < p[i]+r[j-i]){
                q = p[i]+r[j-i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
    return std::make_tuple(r,s);
}

void print_cut_rod_solution(std::vector<int> &p,std::size_t n){
    auto res = extended_bottom_up_cut_rod(p,n);
    auto &r = std::get<0>(res);
    auto &s = std::get<1>(res);
    while(n>0){
        std::cout<<s[n]<<std::endl;
        n -= s[n];
    }
}