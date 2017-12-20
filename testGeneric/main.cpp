#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;


class ResourceHolder
{
private:
    string m_resource;
public:
    ResourceHolder()
    : m_resource("--")
    {
        cout << "/ default cons /";
    }
    ResourceHolder(const string & assign)
    : m_resource(assign)
    {
        cout << m_resource << "/ string cons /";
    }
    ResourceHolder(const ResourceHolder & rhs)
    : m_resource(rhs.m_resource)
    {
        cout << m_resource << "/ copy cons /";
    }
    ResourceHolder & operator=(ResourceHolder copied)
    {
        cout << m_resource << "/ op= /";
        this->swap(copied);
        return *this;
    }
    void swap(ResourceHolder & second)
    {
        std::swap(m_resource, second.m_resource);
        cout << m_resource << "/ my swap /";
    }
    ~ResourceHolder()
    {
        cout << m_resource << "/ destruct /";
    }
};

void testCopyCon()
{

    ResourceHolder rh1; 
    cout << endl;
    ResourceHolder rh2("dog"), rh3("cat");
    cout << endl;
    rh1 = rh2;
    cout << endl;
    std::swap(rh2, rh3);
    cout << endl;
}
int main()
{
    testCopyCon();
    return 0;
}