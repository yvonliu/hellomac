#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <memory>


using namespace std;

class dummy
{
    string m_name;
public:
    dummy() : m_name("default")
    {
        cout << this << " dummy(" << m_name << ") cons-tor" << endl;
    }
    dummy(string name) : m_name(name)
    {
        cout << this << " dummy(" << m_name << ") cons-tor" << endl;
    }
    ~dummy()
    {
        cout << this << " dummy(" << m_name << ") des-tor" << endl;
    }
    dummy(const dummy & d) noexcept
    {
        m_name = d.m_name;
        cout << this << " dummy(" << m_name << ") copy cons-tor" << endl;
    }
    dummy(dummy && d) noexcept
    {
        m_name = std::move(d.m_name);
        cout << this << " dummy(" << m_name << ") move cons-tor" << endl;
    }
    dummy & operator=(dummy another) noexcept
    {
        std::swap(m_name, another.m_name);
        cout << this << " dummy(" << m_name << ") copy elision op=" << endl;
        return *this;
    }
};

void moveSwap(dummy & first, dummy & second)
{
    cout << ">> moveSwap" << endl;
    dummy tmp(std::move(first));
    cout << "---after dummy tmp(std::move(first));" << endl;
    first = std::move(second);
    cout << "---after first = std::move(second);" << endl;
    second = std::move(tmp);
    cout << "<< moveSwap" << endl;
}

void copySwap(dummy & first, dummy & second)
{
    cout << ">> copySwap" << endl;
    dummy tmp(first);
    cout << "---after dummy tmp(first);" << endl;
    first = second;
    cout << "---after first = second;" << endl;
    second = tmp;
    cout << "<< copySwap" << endl;
}
void testMoveCopySwap()
{
    dummy A("A"), B("B");

    cout << "main ent--" << endl;

    moveSwap(A, B);
    cout << "^^^^move--copy___" << endl;
    copySwap(A, B);

    cout << "main ent--" << endl;
}
