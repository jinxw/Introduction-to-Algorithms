#include "find_maximum_subarray.h"
#include <cmath>
#include <climits>

std::tuple<std::size_t, std::size_t, int> find_max_crossing_subarray(std::vector<int> &v,std::size_t low,std::size_t mid,std::size_t high);

std::tuple<std::size_t, std::size_t, int> find_maximum_subarray(std::vector<int> &v,std::size_t low,std::size_t high){
    if(high == low)
        return std::make_tuple(low,high,v[low]);
    else{
        std::size_t mid = floor((low+high)*0.5);
        auto left = find_maximum_subarray(v,low,mid);
        auto right = find_maximum_subarray(v,mid+1,high);
        auto cross = find_max_crossing_subarray(v,low,mid,high);
        if(std::get<2>(left)>=std::get<2>(right) && std::get<2>(left)>= std::get<2>(cross))
            return left;
        else if(std::get<2>(right)>=std::get<2>(left) && std::get<2>(right)>=std::get<2>(cross))
            return right;
        else
            return cross;
    }
}

std::tuple<std::size_t, std::size_t, int> find_max_crossing_subarray(std::vector<int> &v,std::size_t low,std::size_t mid,std::size_t high){
    int left_sum = INT_MIN;
    int max_left;
    int sum = 0;
    for(int i=mid;i>=(int)low;--i){ //注意有符号数与无符号数的比较
        sum += v[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }
    int right_sum = INT_MIN;
    int max_right;
    sum = 0;
    for(int j=mid+1;j<=(int)high;++j){
        sum += v[j];
        if(sum > right_sum){
            right_sum = sum;
            max_right = j;
        }
    }
    return std::make_tuple(max_left,max_right,left_sum+right_sum);
}