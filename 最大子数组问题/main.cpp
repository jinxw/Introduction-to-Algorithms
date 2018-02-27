#include "find_maximum_subarray.h"
#include <iostream>

int main(){
    std::vector<int> v{13,-3,-25,20,-3,-15,-23,18,20,-7,12,-5,-22,15,-4,7};
    auto res = find_maximum_subarray(v,0,v.size()-1);
    for(auto i=std::get<0>(res);i<=std::get<1>(res);++i){
        if(i!=std::get<0>(res))
            std::cout<<" ";
        std::cout<<v[i];
    }
    std::cout<<"\nmax:"<<std::get<2>(res)<<std::endl;
    return 0;
}