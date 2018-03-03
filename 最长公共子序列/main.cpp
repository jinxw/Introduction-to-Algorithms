#include "LCS.h"
#include <iostream>

int main(){
    std::vector<int> a{1,2,3,2,4,1,2};
    std::vector<int> b{2,4,3,1,2,1};
    auto res = LCS_length(a,b);
    std::cout<<res.back().back()<<std::endl;
    std::vector<int> lcs;
    for(std::size_t i=a.size()-1,j=b.size()-1; ; ){
        if(i==0 || j==0){
            lcs.insert(lcs.begin(),a[i]);
            break;
        }else if(res[i][j] == res[i-1][j]){
            --i;
        }else if(res[i][j] == res[i][j-1]){
            --j;
        }else{
            lcs.insert(lcs.begin(),a[i]);
            --i;
            --j;
        }
    }
    for(auto &n:lcs){
        std::cout<<n<<" ";
    }
    std::cout<<std::endl;
    return 0;
}