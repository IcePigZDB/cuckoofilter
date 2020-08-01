//
// Created by IcePig on 2020-08-01.
//
#include "bitsutil.h"
#include <cstdint>
#include <iostream>
int main(){
    size_t total_items = 1000000;
    std::cout<<cuckoofilter::upperpower2(1)<<std::endl;
    std::cout<<cuckoofilter::upperpower2(total_items/4)<<std::endl;
}
