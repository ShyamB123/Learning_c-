#include <iostream>
 using namespace std;

int Multiply(int num1, int num2) // parameters  passed are integers
{
    return num1*num2;

}
int Multiply(double num1,double num2) // parameters passed are integers
{
    return (int(num1*num2+0.5f));
}
int main()
{
    int a=Multiply(5,10); 
    int b =  Multiply(5.25,10.5);
   cout << a<< endl;
  cout << b << endl;
   }