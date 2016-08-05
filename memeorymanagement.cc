#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class XHandler 
{
    public:
    char *data;

    XHandler()
    {
        cout<<"In cons"<<endl;
        data = (char*) malloc(10);
        strcpy(data,"shrishty");
    }

    XHandler(const char* a)
    {
        data = (char*)malloc(strlen(a)+1);
        strcpy(data, a);
    }

    ~XHandler()
    {
        cout<<"Destructor"<<endl;
        free(data);
    }

    void showData()
    {
        cout<<data<<endl;
    }

    XHandler(const XHandler &rhs)
    {
        data = (char*)malloc(strlen(rhs.data)+1);
        strcpy(data, rhs.data);
    }
    
    XHandler operator=(const XHandler &rhs)
    {
        if(data != NULL)
            free(this->data);
        data = (char*)malloc(strlen(rhs.data)+1);
        strcpy(data, rhs.data);
    }

};

void handleDMA()
{
    {
    XHandler xa, xb("Helloo"), xc("Here");
    XHandler temp(xc);
    xa = xb;
    }
}

int main()
{
    handleDMA();
    return 0;
}

#if 0
int main()
{
    XHandler *ha;

    // ha = (XHandler*)malloc(sizeof(XHandler));
    ha = new XHandler();
    ha->showData();
    // free(ha);
    delete ha;

    ha = new XHandler[5];

    for(int i=0;i<5;++i)
    {
        ha[i].showData();
    }

    delete [] ha;
    return 0;

}
#endif 
