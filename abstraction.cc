#include <iostream>
using namespace std;

class LandAnimal
{
    public:
        virtual void legs()=0;
        virtual void avg_age()=0;
        void blood_color()
        {
            cout<<"RBC+WBC"<<endl;
        }
};

class Human: public LandAnimal
{
    public:
        void legs()
        {
            cout<<"Two legs"<<endl;
        }
        void avg_age()
        {
            cout<<"Avg age = 60"<<endl;
        }
};

class Elephant: public LandAnimal
{
    public:
        void legs()
        {
            cout<<"Four legs"<<endl;
        }
        void avg_age()
        {
            cout<<"Avg age = 60"<<endl;
        }
};


void encyclo(LandAnimal *la)
{
    la -> legs();
    la -> avg_age();
    la -> blood_color();
}

void handleEncyclo()
{
    LandAnimal *la = new Human();
    encyclo(la);
    delete la;

    la = new Elephant();
    encyclo(la);
    delete la;
}

int main()
{
    handleEncyclo();

    return 0;
}
