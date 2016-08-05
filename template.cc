#include <iostream>

using namespace std;

template <typename T> void swapX(T &lhs, T &rhs)
{
    T t;
    t = lhs;
    lhs = rhs;
    rhs = t;
    cout<<"Generic template"<<endl;
}

template <> void swapX(int &lhs, int &rhs)
{

    if(lhs < 0 && rhs < 0)
        return;
    int t;
    t = lhs;
    lhs = rhs;
    rhs = t;
    cout<<"template specialization"<<endl;
}

// Overloaed takes priority over specialization
void swapX(int &lhs, int &rhs)
{

    if(lhs < 0 && rhs < 0)
        return;
    int t;
    t = lhs;
    lhs = rhs;
    rhs = t;
    cout<<"overloaded function"<<endl;
}

// c program is being exported
extern "C" 
{
    // many can be included here in the same manner
    void swapX(int *a, int *b);
}

class Point
{
    public:
        Point(int a=0, int b=0):x(a),y(b){}
        void showData()
        {
            cout<<x<<" "<<y<<endl;
        }
    private:
        int x, y;
};

int main()
{
    int ia = 1, ib = 5;
    Point pa, pb(1,2);

    swapX(ia,ib);
    swapX(pa,pb);
    swapX<int>(ia, ib); // explicit instansiation for specialized calls

    return 0;
}
