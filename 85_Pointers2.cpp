#include <iostream>
using namespace std;

// void solve(int arr[])
// {
//     cout << "Size inside solve function: " << sizeof(arr) << endl;

//     cout << "arr: " << arr << endl;
//     cout << "&arr: " << &arr << endl;

//     arr[0] = 50;
// }


void update(int* p){
    *p = *p + 10;
}

int main()
{

    // * Pointers

    // int arr[] = {1, 2, 3, 4};

    // cout<<&arr<<endl;

    // for (int i = 0; i < 3; i++)
    // {
    //     cout << &arr[i] << endl;
    // }

    // int* p=arr;
    // cout<<p<<endl;
    // cout<<&p<<endl;

    // int arr[10];
    // cout<<sizeof(arr)<<endl;

    // int* p = arr;
    // cout<<sizeof(p)<<endl;
    // cout<<sizeof(*p)<<endl;

    // char name[9] = "SherBano";
    // char *cptr = &name[0];

    // cout << name << endl;
    // cout << &name << endl;
    // cout << *(name + 3) << endl;
    // cout << cptr << endl;
    // cout << &cptr << endl;
    // cout << *(cptr + 3) << endl;
    // cout << cptr + 2 << endl;
    // cout << *cptr << endl;
    // cout << cptr + 8 << endl;

    // * Pointers with function

    // int arr[10] = {1, 2, 3, 4};
    // cout << "Size inside main function: " << sizeof(arr) << endl;

    // cout << "arr: " << arr << endl;
    // cout << "&arr: " << &arr << endl;

    // printing array inside main
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // cout << endl
    //      << endl
    //      << "Now calling solve function" << endl;

    // solve(arr);

    // cout << "Wapas main function mein aagye h" << endl;

    // for (int i = 0; i < 10; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;


    int a = 5;
    int* ptr = &a;
    update(ptr);
    cout<<"Value of a is: "<<a<<endl;


    return 0;
}