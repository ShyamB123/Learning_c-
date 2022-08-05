 #include<iostream>

 using namespace std;

 bool isOdd (int n)
 {
     return (n&1); // if last bit is 1 it return 1 which is taken as boolean true
                    // if last bit is 0 it returns 0 which is taken as boolean false
 }

 bool checkith(int n,int i)
 {
     int mask = 1<<i;           //moves 1 to ith position
     return (n&mask);           // returns value of the ith bit

 }

 void SetIth(int& n,int i)
 {
     int mask = 1<<i;           //moves 1 to the ith bit
     n = (n|mask);              // sets ith bit to 1 regardless of the value at ith bit using OR
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
