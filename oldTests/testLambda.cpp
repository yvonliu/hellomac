//
//  testLambda.cpp
//  HelloworldPP
//
//  Created by Yvon Liu on 2/11/16.
//  Copyright © 2016 Yvon Liu. All rights reserved.
//
#include <iostream>
#include "testLambda.hpp"

template <typename Fx>
int dummy(int i, Fx f)
{
    return f(i);
}
void testLambda()
{
    using namespace std;
    
    cout << "this is testLambda." << endl;
    int multi = 3;
    
    for (int i = 0; i < 10; ++i)
    {
        cout << dummy(i, [multi](int x){return multi * x * 2;}) << endl;
    }
}