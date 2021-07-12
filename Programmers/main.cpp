#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) 
{
    int answer = 1;
    unordered_map<string, int> clothMap; 

    for (const auto& entry : clothes) 
    {
        const string& cloth = entry.front(); 
        const string& type = entry.back(); 

        auto iter = clothMap.find(type); 
        
        if (iter == clothMap.end())
            clothMap.emplace(type, 1);
        else
            ++(iter->second); 
    }

    for (const auto& entry : clothMap)
        answer *= (entry.second + 1); 

    --answer; 

    return answer;
}

int main() 
{
    // vector<vector<string>> clothes = { { "yellowhat", "headgear" }, { "bluesunglasses", "eyewear" }, { "green_turban", "headgear" } };
    vector<vector<string>> clothes = { { "crowmask", "face" }, { "bluesunglasses", "face" }, { "smoky_makeup", "face" } };
    cout << solution(clothes); 

    return 0; 
}