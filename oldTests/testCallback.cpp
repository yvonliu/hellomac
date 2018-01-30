//
//  testCallbak.cpp
//  HelloworldPP
//
//  Created by Yvon Liu on 2/11/16.
//  Copyright © 2016 Yvon Liu. All rights reserved.
//

#include <iostream>
#include "testCallback.hpp"


// typedef int (*TestCallback)(int, int);
using TestCallback = int (*)(int, int);

int callmeback(int a, int b)
{
    using namespace std;
    cout << "callback" << endl;
    return (a+b);
}

TestCallback fp = nullptr;

void testCallback()
{
    fp = callmeback;
    
    if (fp)
        std::cout << "callback: " << fp(100,200) << std::endl;
}