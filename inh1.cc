#include <iostream>

using namespace std;

class Basic
{
    public:

        virtual void serviceA()
        {
            cout<<"In basic service"<<endl;
        }
        Basic()
        {
            cout<<"Basic cTor"<<endl;
        }

        virtual ~Basic()
        {
            cout<<"Basic DTor"<<endl;
        }
};

class Better: public Basic
{
    public:
        void serviceA()
        {
            cout<<"In better service"<<endl;
        }
        Better()
        {
            cout<<"Better cTor"<<endl;
        }

        ~Better()
        {
            cout<<"Better DTor"<<endl;
        }

};

class Best: public Better
{
    public:
        void serviceA()
        {
            cout<<"In best service"<<endl;
        }

        Best()
        {
            cout<<"Best cTor"<<endl;
        }

        ~Best()
        {
            cout<<"Best DTor"<<endl;
        }


};

void ServiceInterface(Basic *basic)
{
        basic->serviceA();

    // this method must not be used will need dynamic 
    // cast
    // if(typeid(*Basic) == typeid(Basic))
    //     basic->serviceA();
    // if(typeid(*Basic) == typeid(Basic))
    //     basic->serviceA();
    // if(typeid(*Basic) == typeid(Basic))
    //     basic->serviceA();
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
    delete bp;
    }
}

int main()
{
    handlePoly();
    return 0;
}
