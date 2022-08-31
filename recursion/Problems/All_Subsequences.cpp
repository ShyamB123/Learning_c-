#include<iostream>
#include<cstring>

 using namespace std;



 char s[100][21];
 int k= 0 ;

 void subseq(char * a , char * out , int i ,int j)
 {
     if(a[i] ==  '\0')
     {
         out[j] = '\0';
        
        int l ;

        for(l =0; out[l]!='\0';l++)
        {
            s[k][l] = out[l];
        }
        s[k][l] = '\0';
        
        k++;
         
         return;
     }

        subseq(a,out,i+1,j);
        out[j] = a[i];
        subseq(a,out,i+1,j+1);

 }

 int main()
 {
     int t;
     cin>>t;
	 if(t<=0)
	 {
		 return 0;
	 }
	 else
{     while(t--)
     {
         k=0;
     char a[21];
     cin >> a;

     char out [100];
     

     subseq(a,out,0,0);
     int n=1;
     int len = strlen(a);
     for(int i =1 ; i<=len;i++)
     {
         n *= 2;
     }
    

    char temp[21];
   
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n-i;j++)
                    {
                if(strcmp(s[j],s[j+1]) > 0)
                 {
                   strcpy(temp, s[j]);
                      strcpy(s[j], s[j+1]);
                     strcpy(s[j+1], temp);
                 }
                  }
            }

     for(int i = 0;i<n;i++)
     {
         cout << s[i] << endl;
     }
     }

 }
 }