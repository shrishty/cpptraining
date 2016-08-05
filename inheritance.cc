#include<iostream>
using namespace std;

class Base
{
    public:
    int x;
    protected:
    int y;
    private:
    int z;

};

// class DA: public Base
class DA: protected Base
{
    public:
        using Base::x; // reassign privacy - same synstax for methods
        void fda()
        {
            x=2;
            y=1;
            // z=3;
        }
};

class DB: public Base
{
    public:
        void fdb()
        {
            x=2;
            y=1;
            // z=3;
        }

};

void handleInh()
{
    DA oda;
    oda.x;
    oda.fda();
    DB odb;
    odb.x;
    odb.fdb();
}

int main()
{
    handleInh();
    return 0;
}
