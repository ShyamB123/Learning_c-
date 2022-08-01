#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[] = {1,3,4,56,75,333};
    int n = sizeof(arr)/ sizeof (int);

    int srch = 2;
    bool ans = binary_search(arr,arr+n,srch);

    if(ans == true)
    {
        cout<< " the element is found!!"<<endl;
    }
    else{
        cout<<"the element is not present!"<< endl;
    }
}