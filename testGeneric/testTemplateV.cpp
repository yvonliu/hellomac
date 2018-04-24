#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class useless {};
class bad_ssl_resource : public std::runtime_error
{
public:
    bad_ssl_resource() = delete;
    bad_ssl_resource(const string & error) : std::runtime_error( error + " - bad_ssl_resource ") {}    
};
useless* r1_acquire(int a1) 
{
    cout << "r1_a(" << a1 << endl; 
    if (a1 == 0) 
        return nullptr; 
    else
        return new useless; 
}
void r1_delete(useless* r1) { cout << "r1_d(" << r1 << endl; delete r1; }

template<typename ResourceType, typename Uninit, typename Init, typename...InitArgs>
std::unique_ptr<ResourceType, Uninit> create_unique_resource(Init init, Uninit uninit, InitArgs&&...args)
{
    ResourceType * o = init(std::forward<InitArgs>(args)...);
    cout << ":" << typeid(ResourceType).name() << endl;
    cout << ":" << __PRETTY_FUNCTION__ << endl;
    cout << ":" << typeid(init).name() << endl;
    if (NULL == o) throw bad_ssl_resource(typeid(init).name());
    return {o, uninit};
}
int testTemplateV()
{
    cout << "scope {" << endl;
    try
    {
        auto w = create_unique_resource<useless>(r1_acquire, r1_delete, 10);
        auto x = create_unique_resource<useless>(r1_acquire, r1_delete, 10);
        auto y = create_unique_resource<useless>(r1_acquire, r1_delete, 0);
        auto z = create_unique_resource<useless>(r1_acquire, r1_delete, 100);
    }
    catch(const std::runtime_error & e)
    {
        cout << "runtime error:" << e.what() << endl;;
    }

    cout << "}" << endl;
    return 0;
}