//
//  testTemplate.hpp
//  HelloworldPP
//
//  Created by Yvon Liu on 2/11/16.
//  Copyright © 2016 Yvon Liu. All rights reserved.
//

#ifndef testTemplate_hpp
#define testTemplate_hpp

#include <stdio.h>

#include <iostream>
#include <vector>

using namespace std;
template <typename H>
void px(H head)
{
    cout << "(" << typeid(head).name() << "):" << endl << head << endl;
}

void fx() {};

template <typename H, typename... Tail>
void fx(H head, Tail... t)
{
    px(head);
    fx(t...);
}

template <typename VX>
void f(VX v)
{
    vector<typename VX::value_type> z;
    z.push_back(v[0]);
    cout << z.size() << endl;
}

void testTemplate();

#endif /* testTemplate_hpp */
