#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;

void testLowerbound()
{
    int array[] ={ 0,1,4,4,4,5,7,10 };
    size_t n = sizeof(array)/sizeof(array[0]);
    int * p = lower_bound(&array[0], &array[n], 3);

    for_each(&array[0], &array[n], [](const int& n) { std::cout << " " << n; });
    cout << endl;
    cout << "the lower bound point to value: " << *p << endl;
    cout << "number count: " << distance(&array[0], p) << endl;
 
}
int main()
{

    //testLowerbound();

    int a[] = {1,9,4,6,3,5};
    priority_queue<int, vector<int>, greater<int>> q;
    for(auto i : a)
    {
        q.push(i);
    }

    while (!(q.empty()))
    {
        cout << q.top() << ",";
        q.pop();
    }
    cout << endl;
    return 0;
}