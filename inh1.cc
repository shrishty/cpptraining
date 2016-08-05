#include <iostream>

using namespace std;

class Basic
{
    public:

        void serviceA()
        {
            cout<<"In basic service"<<endl;
        }
};

class Better: public Basic
{
    public:
        void serviceA()
        {
            cout<<"In better service"<<endl;
        }
};

class Best: public Basic
{
    public:
        void serviceA()
        {
            cout<<"In best service"<<endl;
        }
};

void ServiceInterface(Basic *basic)
{
    basic->serviceA();
}

void handlePoly()
{
    Basic *bp;
    int choice=1;
    while(1)
    {
    cin>>choice;
    switch(choice)
    {
        case 1:
            bp = new Basic();
            break;
        case 2:
            bp = new Better();
            break;
        case 3:
            bp = new Best();
            break;
    }
    ServiceInterface(bp);
    }
}

int main()
{
    handlePoly();
    return 0;
}
