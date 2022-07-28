 #include<iostream>
#include<string.h>

using namespace std;

class Car
{
    private:
    float price; // Cannot be changed from main fnc

    public:

    //copy constructor

    Car(Car& x) // fnc call by passing refernce
    {
        cout << "Calling Copy Constructor!" << endl;
        price = x.price;
        model_no =  x.model_no;
        strcpy(name,x.name);
    }
    
    Car(Car* x)   // fnc call by passing pointer
    { 
        cout<< "calling copy constructor by pntr"<<endl;
        price = x->price;
        model_no =  x->model_no;
        strcpy(name,x->name);

    }

    //////////////////////////////////////////////////////////////////
    Car() // To overide constructor
    {
        cout << " a car object is being created"<<endl;
    }
    Car(float p,int m,char* s) //here 2 constructors using same function Car with different parameter
    {                                  // This is called Constructor Overloading!!
        price = p;
        model_no = m;
    strcpy(name,s);
        }

    int model_no;
    char name[20];
    void print()
    {
        cout<< "Name:" << name<<endl;
        cout<< "Model No:" << model_no << endl;
        cout << "price:" << price << endl;
    }
     
    void set_discount(float x)
    {
        price = price - (price*x)/100;
    }
    float final_price()
    {
        return price;
    }

    void set_price(float s) // Setter
    {
        price = s;
    }
    float return_price()  // Getter
    {
        return price;
    }
};

int main()
{
    Car c;
   // c.price = 100;
   c.set_price(100);

    Car d(300,234242,"audi");

    c.model_no= 1234;
    c.name[0] = 'B';
    c.name[1] = 'M';
    c.name[2] = 'W';
    c.name[3] = '\0';

    Car e(d);
    Car f(&e);
    
    c.print();
    cout<< "car d:"<<endl;

    d.print();

    cout<< "car e" << endl;
    e.print();  
    
    cout<< "car f:"<<endl;
    f.print();


}