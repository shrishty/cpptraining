#include <iostream>
#include <typeinfo>

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
        void cunning()
        {
            cout<<"Way ahead of all the creature"<<endl;
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

class Robot
{
    // public:
    //     void legs()
    //     {
    //         cout<<"Two legs"<<endl;
    //     }
    //     void avg_age()
    //     {
    //         cout<<"Battery life 5 days"<<endl;
    //     }
};


class Cyborg: public LandAnimal, public Robot
{
    public:
        void legs()
        {
            cout<<"Two legs - Cyborg"<<endl;
        }
        void avg_age()
        {
            cout<<"Batter life 3 days"<<endl;
        }
        void blood_color()
        {
            cout<<"uses coolent (liqiuid chemical)"<<endl;
        }

};

void encyclo(LandAnimal *la)
{
    la -> legs();
    la -> avg_age();
    la -> blood_color();

    // cant be used directly
    // la->cunning();
    if(typeid(*la) == typeid(Human))
    {
        Human *me = dynamic_cast<Human*>(la);
        if(me != NULL)
            me->cunning();
    }
}

void handleEncyclo()
{
    LandAnimal *la = new Human();
    encyclo(la);
    delete la;

    la = new Elephant();
    encyclo(la);
    delete la;

    la = new Cyborg();
    encyclo(la);
    delete la;
}

int main()
{
    handleEncyclo();

    return 0;
}
