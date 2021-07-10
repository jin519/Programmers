#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

bool solution(vector<string> phone_book)
{
    set<string> phoneSet{ phone_book.begin(), phone_book.end() };

    auto iter1 = phoneSet.begin(); 
    auto iter2 = iter1;
    ++iter2; 

    while (iter2 != phoneSet.end()) 
    {
        const string& current = *iter1;
        const string& next = *iter2; 

        if ((current[0] == next[0]) && (next.find(current) != string::npos))
            return false; 

        ++iter1; 
        ++iter2; 
    }
    
    return true; 
}

int main() 
{
    // vector<string> phone_book = { "119", "97674223", "1195524421" };
    vector<string> phone_book = { "123", "456", "789" };
    // vector<string> phone_book = { "12", "123", "1235", "567", "88" };

    if (solution(phone_book))
        cout << "true";
    else
        cout << "false"; 

    return 0; 
}