//
//  testAuto.cpp
//  HelloworldPP
//
//  Created by Yvon Liu on 1/10/16.
//  Copyright © 2016 Yvon Liu. All rights reserved.
//

#include "testAuto.hpp"
#include <vector>
#include <iostream>

void testAuto()
{
    std::vector<int> v = {1,2,3,4,5};
    
    for (auto x: v)
        std::cout << x << ", ";
    
    
    std::cout << std::endl;
}
