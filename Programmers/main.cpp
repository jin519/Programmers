#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    int day = 0;
    int count = 0; 

    for (size_t i = 0; i < progresses.size(); ++i) 
    {
        int progress = progresses[i];
        const int speed = speeds[i]; 

        progress += (day * speed); 

        if (progress >= 100)
            ++count;
        else 
        {
            if (count) 
            {
                answer.emplace_back(count);
                count = 0;
            }

            while (progress < 100)
            {
                ++day;
                progress += speed;
            }

            ++count;
        }
    }

    if (count)
        answer.emplace_back(count); 

    return answer;
}

int main() 
{
    //vector<int> progresses = { 93, 30, 55 };
    vector<int> progresses = { 95, 90, 99, 99, 80, 99 };
    //vector<int> speeds = { 1, 30, 5 };
    vector<int> speeds = { 1, 1, 1, 1, 1, 1 };

    const vector<int>& answer = solution(progresses, speeds); 

    for (const int elem : answer)
        cout << elem << ' '; 

    return 0; 
}