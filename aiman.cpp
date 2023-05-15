#include<iostream>
using namespace std;

class Base
{
    private:
        int x;
    public:
       void set_value()
       {
        cout<<"Enter value of x: "<<endl;
        cin>> x;
       }
       int get_value()
       {
         return x;
       }
       void show()
       {
        get_value();
        cout<<" x is :"<<x<<endl;
       }
};
int main()
{
    Base b;
    b.set_value();
    b.show();

    return 0;
}
