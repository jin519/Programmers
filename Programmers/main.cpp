#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int time = 0;

    queue<int> bridge;
    for (size_t i = 0; i < bridge_length; ++i)
        bridge.emplace(0); 

    int sum = 0;
    int i = 0; 

    do
    {
        ++time;

        // 트럭 한칸 이동
        sum -= bridge.front();
        bridge.pop();

        const int truck = truck_weights[i];
        sum += truck;

        if (sum <= weight)
        {
            // 유효 트럭 배치
            bridge.emplace(truck);
            ++i; 
        }
        else 
        {
            // 빈 트럭 배치
            bridge.emplace(0); 
            sum -= truck;
        }
    } while (i < truck_weights.size()); 

    // 유효 트럭 전부 이동
    time += bridge_length;

    return time;
}

int main() 
{
    int bridge_length = 2;
    int weight = 10; 
    vector<int> truck_weights = { 7,4,5,6 };

    cout << solution(bridge_length, weight, truck_weights);

    return 0; 
}