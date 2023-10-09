#include<iostream>
#include<string.h>
using namespace std; 

int main(){

    // & Character Array is data structure of character type value 

    // * how to declare and take input

    // char name[100];
    
    // cout<<"Enter your name: "<<endl;

    // cin>>name; or cin>>ch[2];

    // cout<<"Apka naam: "<<name<<" hai"<<endl;

    // cin>>name;

    // for(int i=0;i<20;i++){
    //     cout<<"index: "<<i<<" value: "<<name[i]<<endl;
    // }

    // cin.getline(name,50);
    // cout<<name;

    // * 1. Length of string

    // char name[100];
    // cin.getline(name,100);

    // int length = 0,i = 0;

    // while(name[i] != '\0'){
    //     length++;
    //     i++;
    // }

    // cout<<"length is: "<<length <<endl;

    // cout<<"length is: "<<strlen(name) <<endl;

    // * 2. Reverse a String

    // char name[100];
    // cin>>name;
    // int s=0;
    // int n=strlen(name);
    // int e=n-1;

    // while(s<=e){
    //     swap(name[s],name[e]);
    //     s++;
    //     e--;
    // }

    // cout<<name;
    
    // * 3. Replace all spaces

    // ! space ---> @ lagana h

    // char sentence[100];
    // cin.getline(sentence,100);
    // int s=0;
    // int n=strlen(sentence);
    
    // for(int i=0;i<n;i++){
    //     if(sentence[i] == ' '){
    //         sentence[i] = '@';
    //     }
    // }

    // cout<<sentence;

    // * 4. Palindrome

    // char name[100];
    // cin.getline(name,100);
    // int s=0;
    // int n=strlen(name);
    // int e=n-1;
    // bool flag=1;

    // while(s<=e){
    //     if(name[s] == name[e]){
    //         s++;
    //         e--;
    //     }
    //     else{
    //         flag=0;
    //         break;
    //     }
    // }
    // if(flag){
    //     cout<<"It is Palindrome"<<endl;
    // }
    // else{
    //     cout<<"Not a Palindrome"<<endl;
    // }

    // ~ ASCII VALUE a->97 and A->65

    // * 5. Convert into Uppercase

    // char name[100];
    // cin.getline(name,100);
    // int s=0;
    // int n=strlen(name);
    
    // for(int i=0;i<n;i++){
    //     name[i]=name[i] - 'a' + 'A';
    // }
    
    // cout<<name;

    // * 6. Convert into Lowercase

    // char name[100];
    // cin.getline(name,100);
    // int s=0; 
    // int n=strlen(name);
    
    // for(int i=0;i<n;i++){
    //     name[i]=name[i] - 'A' + 'a';
    // }
    
    // cout<<name;


    // & String is data type

    // * How to declare

    // string str = "babbar";

    // string str;
    // cin>>str;
    // getline(cin,str);
    // cout<<str;

    // cout<<"length: "<<str.length()<<endl;

    // cout<<"isEmpty: "<<str.empty()<<endl;
    // ! 1 --> True and 0 --> False

    // str.push_back('A');
    // str.pop_back();
    // cout<<str.substr(0,6)<<endl;

    // string s1 = "greenapple";
    // string s2 = "greenapple";
    // s1.compare(s2)  // ! --> 0 means equal


    // string sentence = "hello kaise ho";
    // string target = "hello";

    // cout<< sentence.find(target);


    // string sentence1 = "This is my message";
    // string word = "text";

    // sentence1.replace(11,17,word);
    // cout<<sentence1<<endl;

    string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    str.erase(0,4);
    cout<<str; // ! EFGHIJKLMNOPQRSTUVWXYZ

    return 0;
}