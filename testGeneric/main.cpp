#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <memory>


using namespace std;

class inner 
{
public:
    inner() 
    {
        cout << "inner defaut ctor" << endl;
    }
    ~inner()
    {
        cout << "inner dtor" << endl;
    }
};
class outer 
{
private:
    unique_ptr<inner> m_inner;
public:
    outer() : m_inner(nullptr)
    {
        m_inner = make_unique<inner>();
        cout << "end of outer ctro" << endl;
    }
};

int main()
{
    cout << "main" << endl;
    outer o;

    cout << " after making o, quit" << endl;
    return 0;
}