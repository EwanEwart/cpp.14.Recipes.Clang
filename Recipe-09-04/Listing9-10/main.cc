#include <iostream>
#include <cassert>
#include <string>

using namespace std;

template <typename T>
class Singleton
{
private:
    static T* m_Instance;

public:
    Singleton()
    {
        // assert((m_Instance == nullptr) && "Singleton: only one instance is allowed.");
        if (m_Instance != nullptr)
        {
            auto msg = std::string("Exception:\nFile ... \"");
            msg += __FILE__;
            msg += "\nLine .... \"";
            msg += std::to_string(__LINE__);
            msg += "\"\nOnly one instance of Singleton is allowed !\n";
            throw std::exception(msg.c_str());
        }

        m_Instance = static_cast<T*>(this);
    }

    virtual ~Singleton()
    {
        if (m_Instance != nullptr)
        {
            m_Instance = nullptr;
        }
    }

    static T& GetSingleton()
    {
        return *m_Instance;
    }

    static T* GetSingletonPtr()
    {
        return m_Instance;
    }
};

template <typename T>
T* Singleton<T>::m_Instance = nullptr;

class Manager
    : public Singleton < Manager >
{
public:
    void Print() const
    {
        cout << "Singleton Manager Successfully Printing!" << std::endl;
    }
    virtual ~Manager() {
        int i{ 0 };
        ++i;
        i;
    }
};

// #define DEBUG
// #define _DEBUG
#include<vector>
#include<algorithm>

int main(int argc, char* argv[])
{
    try
    {
        new Manager();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    Manager& manager{ Manager::GetSingleton() };
    manager.Print();

    // attempt to have more than one instance
    try
    {
        new Manager();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    delete Manager::GetSingletonPtr();

    // aside : using std::default_delete<T>()
    std::vector<int*> v;
    for (int n = 0; n < 100; ++n)
    {
        v.push_back(new int(n));
    }
    auto f = std::default_delete<int>();
    f(v[0]);
    std::for_each(v.begin()+1, v.end(), std::default_delete<int>());
    return 0;
}
