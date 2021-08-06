#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) 
{
    vector<int> answer; 
    const int size = (int(prices.size()) - 1); 

    for (int i = 0; i < size; ++i) 
    {
        int price = prices[i]; 
        int count = 1; 

        for (int j = (i + 1); j < size; ++j)
        {
            if (price <= prices[j])
                ++count;
            else
                break;
        }

        answer.emplace_back(count); 
    }

    answer.emplace_back(0); 

    return answer;
}

int main() 
{
    vector<int> prices = { 1, 2, 3, 2, 3 };
    
    for (int price : solution(prices)) 
        cout << price << endl;

    return 0; 
}