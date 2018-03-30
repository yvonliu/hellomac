#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class useless {};

useless* r1_acquire(int a1) { cout << "r1_a(" << a1 << endl; return new useless; }
void r1_delete(useless* r1) { cout << "r1_d(" << r1 << endl; delete r1; }

template<typename T, typename Deletion, typename Acquisition, typename...Args>
std::unique_ptr<T, Deletion> create_unique_resource(Acquisition acquisition, Deletion deletion, Args&&...args)
{
    return {acquisition(std::forward<Args>(args)...), deletion};
}

int main()
{
    cout << "scope {" << endl;
    {
        auto r = create_unique_resource<useless>(r1_acquire, r1_delete, 100);
    }

    cout << "}" << endl;
    return 0;
}