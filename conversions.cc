#include <iostream>
#include <cstring>

using namespace std;

class X
{
    public:
    X() {}
    // X(int x):data(x){}
    explicit X(int x):data(x){}
    X(const char* x){}

    private:
    int data;


};

struct TCB 
{
    TCB()
    {
        // strcpy(tname, "def");
        tid=0xFF;
        tprio=1000;
        cout<<"tcb "<<endl;
    }
    int tid;
    char* tname[8];
    int tprio;

    operator int()
    {
        return tid;
    }
};

int main()
{

    TCB logTask;
    int a = logTask;
    cout<<a<<endl;

    // use these
    
    X oxa(100);

    // Dont use these
    // X oxa = 100;
    // X oxb = 'A';
    // X oxc = 1000000L;
    // X oxd = false;
    // X oxe = "Hello";
    // X meto = oxe;
}
