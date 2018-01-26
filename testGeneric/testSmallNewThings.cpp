#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <type_traits>

using namespace std;

class newBase
{
public:
    virtual void foo(int) {}
    virtual void bar(int) final {};
};

class newDerived : newBase
{
public:
    virtual void foo(int) override {}
};

void unifiedInit()
{
    int a[] = {1,2,3,4,5};

    for (auto i : a)
        cout << i << endl;

    vector<string> b = {"this", "is", "a", "test"};

    for (auto i : b)
        cout << i << endl;
}

void staticAssert()
{
    static_assert(sizeof(void *) == 8, "it's not 64-bit");
}

// new type def
using myfuncspec = float (*)(int, float);
void testLambda(myfuncspec f)
{
    vector<tuple<int, float>> o = {{1,2.3},{2,4.5},{6,3.0}};
    for(auto t : o)
    {
        cout << f(get<0>(t), get<1>(t)) << endl;
    }
}
void testLambdaGeneral(std::function<float (int, float)> f)
{
    vector<tuple<int, float>> o = {{1,2.3},{2,4.5},{6,3.0}};
    for(auto t : o)
    {
        cout << f(get<0>(t), get<1>(t)) << endl;
    }  
}
void testSmallNewThings()
{
    testLambda([](int a, float b){return a * b;});

    double cap = 0.2;
    testLambdaGeneral([cap](int a, float b){return a * b * cap;});
    // Following fails compiler because lambda capture keeps state 
    //   and breaks the function signature.
    // testLambda([cap](int a, float b){return a * b * cap;});
    //

}