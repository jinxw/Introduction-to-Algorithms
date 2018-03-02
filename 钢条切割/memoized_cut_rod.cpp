// 带备忘的自顶向下法
#include <vector>
#include <climits>
#include <algorithm>    //max

int memoized_cut_rod_aux(std::vector<int> &p,std::size_t n,std::vector<int> &r);

int memoized_cut_rod(std::vector<int> &p,std::size_t n){
    std::vector<int> r(p.size(),INT_MIN);
    return memoized_cut_rod_aux(p,n,r);
}

int memoized_cut_rod_aux(std::vector<int> &p,std::size_t n,std::vector<int> &r){
    if(r[n]>=0)
        return r[n];
    int q;
    if(n==0)
        q=0;
    else{
        q=INT_MIN;
        for(std::size_t i=1;i<=n;++i){
            q = std::max(q,p[i]+memoized_cut_rod_aux(p,n-i,r));
        }
    }
    r[n] = q;
    return q;
}