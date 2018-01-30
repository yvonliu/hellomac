//
//  testRegex.cpp
//  HelloworldPP
//
//  Created by Yvon Liu on 2/11/16.
//  Copyright © 2016 Yvon Liu. All rights reserved.
//

#include "testRegex.hpp"
#include <iostream>
#include <regex>
#include <string>

using namespace std;


void testRegex()
{
    string s = "<test>hello</test> <test>world</test>";
    regex pattern {R"(<(.*?)>(.*?)</\1>)"};
    
    smatch matches;

    
    if (regex_search(s, matches, pattern))
    {
        cout << "group 0:" << matches[0] << endl;
        cout << "group 1:" << matches[1] << endl;
        cout << "group 2:" << matches[2] << endl;
    }
    else
    {
        cout << "not matched" << endl;
    }
    
    
    for (sregex_iterator it(s.begin(), s.end(), pattern); it != sregex_iterator{}; ++it)
    {
        cout << "it:" << (*it)[0] << endl;
    }
    
}