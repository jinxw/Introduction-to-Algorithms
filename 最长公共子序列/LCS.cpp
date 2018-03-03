#include <vector>

//todo:template改写
std::vector<std::vector<int>> LCS_length(std::vector<int> &X, std::vector<int> &Y){
    auto m = X.size();
    auto n = Y.size();
    std::vector<std::vector<int>> c(m,std::vector<int>(n,0));
    for(std::size_t i=0;i<m;++i){
        for(std::size_t j=0;j<n;++j){
            if(X[i] == Y[j]){
                c[i][j] = i==0||j==0 ? 1 : c[i-1][j-1]+1;
            }else if(i==0 || j==0 || c[i-1][j] >= c[i][j-1]){
                c[i][j] = i==0 ? 0 : c[i-1][j];
            }else{
                c[i][j] = j==0 ? 0 : c[i][j-1];
            }
        }
    }
    return c;   //通过与周围三项比较得知行进路线
}