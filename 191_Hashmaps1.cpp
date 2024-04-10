#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    // * Hashmap - I
    // ! It is an associative container that stores elements in a key-value format.
    // ~ Ordered map -> O(log n) based on BST
    // ~ Unordered map -> O(1)

    // * Creation
    // unordered_map<string, int> m;

    // * Insertion
    // pair<string, int> p = make_pair("scorpio", 9);
    // m.insert(p);

    // pair<string, int> p2("alto", 2);
    // m.insert(p2);

    // m["fortuner"] = 10;

    // * Access
    // cout << m.at("alto") << endl;
    // cout << m.at("scorpio") << endl;

    // cout<<m["fortuner"]<<endl;

    // * Search
    // cout<<m.count("scorpio")<<endl; // 1
    // if(m.find("fortuner") != m.end()){
    //     cout<<"Fortuner found"<<endl;
    // }
    // else{
    //     cout<<"Fortuner not found"<<endl;
    // }

    // cout<<m.size()<<endl;
    // cout<<m["hummer"]<<endl;
    // cout<<m.size()<<endl; // 4

    // cout<<"Printing all entries: "<<endl;

    // for(auto i:m){
    //     cout<<i.first<<"-> "<<i.second<<endl;
    // }


    // * Hash function

    // ~ Hash code + Compression function
    // ! Conversion of: key->hash code-> numerical value

    // * Problem:- I/P -> string -> "Thiruvananthapuram"
    // ! O/P -> each character ki occurences

    string str = "Thiruvananthapuram";
    unordered_map<char, int> freq;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        freq[ch]++;
    }

    for(auto i:freq){
        cout<<i.first<<"-> "<<i.second<<endl;
    }
    

    return 0;
}
