 #include<iostream>

 using namespace std;

 bool isOdd (int n)
 {
     return (n&1);
 }

 bool checkith(int n,int i)
 {
     int mask = 1<<i;
     return (n&mask);

 }

 void SetIth(int& n,int i)
 {
     int mask = 1<<i;
     n = (n|mask);
 }
 int main()
 {
     cout<<"enter a number:";
     int n;
     cin>>n;

     if(isOdd(n))
     {
         cout << "the number " << n <<" is odd"<<endl;
     }
     else{
        cout << "the number " << n << "is even" << endl;
     }
     cout<<"enter the position:";
     int pos;
     cin>>pos;
     if(checkith(n,pos))
     {
         cout << "the index"<<pos<<"is 1"<<endl;
     }
     else
     {
         cout << "the index"<<pos<<"is 0"<<endl;
     }

     int x;
     cout << "Enter a Number:" ;
     cin>>x;

     SetIth(x,3);

     cout<<x<<endl;
 }
