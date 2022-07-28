#include <iostream>
#include <string.h>

using namespace std;




class car
{
    private:
    float price;

    public:
    int model_no;
    char* name;

    car(float p,int m,char* n)   // constructor
    {
        price =p;
        model_no =  m;
        name= new char[strlen(n)+1];
        strcpy(name,n);

    }
    car ()
    {

    }

    ////////////////////////

    // Copy contructor overloading

    car(car * x) // Copy Constructor by passing a pntr
    {
        price = x->price;
        model_no= x->model_no;
        name = new char[strlen(x->name)+1];
        strcpy(name,x->name);

    }

    car(car& x) // Copy Constructor by passing a refcerence
    {
        price = x.price;
        model_no = x.model_no;
        name= new char[strlen(x.name)+1];
        strcpy(name,x.name);
    }
    ////////////////////////////////////////////

        // COPY ASSIGNMENT OPERATOR

    void operator = (car& x)
    {
        price = x.price;
        model_no = x.model_no;
        name= new char[strlen(x.name)+1];
        strcpy(name,x.name);

    }

    //////////////////////////////////////////////


   void print()
    {
        cout<< "Name:" << name<<endl;
        cout<< "Model No:" << model_no << endl;
        cout << "price:" << price << endl;
    }


};
int main()
{
    car d(1000,234,"BMW"); // calling constructor
    car e(&d); // copy constructor passing pointer
    car f(d) ;// copy constructor passing reference
    car s;
    s=f;
    e.name[0] = 'A';
    e.model_no = 9876;
    f.name[1] = 'F';
    f.model_no = 34213;
    d.print();
    e.print();
    f.print();
    s.print();


}