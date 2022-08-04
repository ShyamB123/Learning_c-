 #include<iostream>
 #include<algorithm>
  using namespace std;

 /* int main()
  {
        int n,m,x,y;
      cin>>n>>m>>x>>y;

        long long int stud;
       long long int max = 0;
      for(long long int i=0;i<n;i++)
      {
          stud = (m + i*y)/x -i;
          if(stud>=max)
          {
              max= stud;
          }
      }
      cout << max<<endl;
  }*/


  int main()
  {
     float n,m,x,y;
      cin>>n>>m>>x>>y;

    if((m/x)>=n){
        cout<<n<<endl;

    }
    else{
            int first = 0;
            int last = n;

            int middle = (first + last)/2;

            while((middle!=last)&&(middle!=first))
            {
                if(middle <= (m+(n*y))/(x+y)){
                    first = middle;
                    middle = (first +last)/2;
                }
                else{
                    last = middle;
                    middle = (first + last)/2;
                }
            }
                cout<<middle<<endl;

    }
    


  }