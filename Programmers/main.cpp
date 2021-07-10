#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    string answer = "";

    unordered_map<string, int> completionMap; 
    for (size_t i = 0; i < completion.size(); ++i) 
    {
        const string& name = completion[i]; 
        const auto iter = completionMap.find(name); 
        
        if (iter == completionMap.end())
            completionMap.emplace(name, 1);
        else
            ++(iter->second); 
    }

    for (size_t i = 0; i < participant.size(); ++i) 
    {
        const string& name = participant[i]; 
        const auto iter = completionMap.find(name); 
        
        answer = name;

        if (iter == completionMap.end())
            break;
        else 
        {
            int& count = iter->second; 

            if (count)
                --count;
            else
                break;
        }
    }

    return answer; 
}

int main() 
{
    vector<string> participant = { "mislav", "stanko", "mislav", "ana" };
    vector<string> completion = { "stanko", "ana", "mislav" };

    cout << solution(participant, completion) << endl; 

    return 0; 
}