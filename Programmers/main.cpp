#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <utility>

using namespace std;

int solution(vector<int> priorities, int location) 
{
    queue<pair<int, int>> queue; 
    priority_queue<int> pQueue; 
    
    for (size_t i = 0; i < priorities.size(); ++i) 
    {
        const int priority = priorities[i]; 
        
        queue.emplace(priority, i); 
        pQueue.emplace(priority); 
    }

    int answer = 1;

    while (true) 
    {
        const pair<int, int> front = queue.front(); 
        queue.pop(); 

        if (front.first < pQueue.top()) 
            queue.emplace(front.first, front.second); 
        else 
        {
            if (location == front.second) 
                break;

            pQueue.pop();
            ++answer;
        }
    }
    
    return answer;
}

int main() 
{
    vector<int> priorities = { 1, 1, 9, 1, 1, 1 };
    int location = 0;

    cout << solution(priorities, location); 

    return 0; 
}