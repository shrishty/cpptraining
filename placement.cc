#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<new>
#include<cstring>

using namespace std;

class X
{
    private:
    static char RAM[8*1024*1024]; //8M to play
    char data[10];

    public:
    X() { strcpy(data,"abc");}
    ~X()
    {
        cout<<data<<"in detor"<<endl;
    }

    void showData()
    {
        cout<<data<<endl;
    }

    void* operator new(size_t size)
    {
        char *handle;
        #ifdef CSTYLE_MIGRATE
            cout<<"c style";
            return malloc(size);
        #else
            cout<<"Cpp style";
            // handle = (char *)::operator new(size);
            handle = RAM;

            return handle;
            // return ::operator new(size);
        #endif
    }



};

char X::RAM[8388608] = {0};

int main()
{
    X *xp = new X;
    xp->showData();
}
