#include <vector>
#include <climits>
#include <algorithm>

int bottom_up_cut_rod(std::vector<int> &p,std::size_t n){
    std::vector<int> r(n+1);
    r[0] = 0;
    for(std::size_t j=1;j<=n;++j){
        int q=INT_MIN;
        for(std::size_t i=1;i<=j;++i){
            q = std::max(q,p[i]+r[j-i]);
        }
        r[j] = q;
    }
    return r[n];
}