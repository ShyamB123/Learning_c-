#include<iostream>
using namespace std;

class Car
{
    private:
    float price; // Cannot be changed from main fnc

    public:
    
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

    c.model_no= 1234;
    c.name[0] = 'B';
    c.name[1] = 'M';
    c.name[2] = 'W';
    c.name[3] = '\0';
    c.print();
    c.set_discount(20);
    cout<< "final price is:" << c.final_price() <<endl;


}