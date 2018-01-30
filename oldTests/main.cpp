//
//  main.cpp
//  HelloworldPP
//
//  Created by Yvon Liu on 3/16/14.
//  Copyright (c) 2014 Yvon Liu. Aqll rights reserved.
//

#include "testAuto.hpp"
#include "testLambda.hpp"
#include "testCallback.hpp"
#include "testRegex.hpp"
#include "testThreads.hpp"

#include <string>
#include <iostream>
#include <queue>

using namespace std;



int main(int argc, const char * argv[])
{
    // ::testAuto();
    // ::testCallback();
    // ::testLambda();
    // ::testTemplate();
    // ::testRegex();

    // ::testThreads();
    
    priority_queue<int, vector<int>, greater<int>> minQ;
    
    minQ.push(1);
    cout.precision(1);
    cout << fixed  << (double) minQ.top() << endl;
    minQ.push(3);
    cout << minQ.top() << endl;
    minQ.push(2);
    cout << minQ.top() << endl;
    
    return 0;
}

