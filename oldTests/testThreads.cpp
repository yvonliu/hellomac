//
//  testThreads.cpp
//  HelloworldPP
//
//  Created by Yvon Liu on 2/14/16.
//  Copyright © 2016 Yvon Liu. All rights reserved.
//

#include "testThreads.hpp"
#include <thread>
#include <iostream>

using namespace std;

void proc1()
{
    cout << "here is " << __func__ << this_thread::get_id() << endl;
}


void testThreads()
{
    thread one {proc1};
    thread two {proc1};
    
    
    one.join();
    two.join();
    
}