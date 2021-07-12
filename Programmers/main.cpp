#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) 
{
    vector<int> answer;

    unordered_map<string, int> genreTotalMap;
    unordered_map<string, multimap<int, int, greater<int>>> genrePlayIndexMap; 

    for (size_t index = 0ULL; index < genres.size(); ++index) 
    {
        const string& genre = genres[index]; 
        const int play = plays[index]; 

        auto iter = genreTotalMap.find(genre); 
        
        if (iter == genreTotalMap.end())
        {
            genreTotalMap.emplace(genre, play);

            multimap<int, int, greater<int>> playIndexMap; 
            playIndexMap.emplace(play, index); 

            genrePlayIndexMap.emplace(genre, playIndexMap);
        }
        else
        {
            iter->second += play;
            genrePlayIndexMap[genre].emplace(play, index); 
        }
    }

    multimap<int, string, greater<int>> genreTotalMultimap; 

    for (const auto& entry : genreTotalMap)
        genreTotalMultimap.emplace(entry.second, entry.first); 

    for (const auto& entry : genreTotalMultimap) 
    {
        const string& genre = entry.second; 

        int count = 0; 
        for (const auto& entry2 : genrePlayIndexMap[genre])
        {
            if (count >= 2)
                break;

            answer.emplace_back(entry2.second); 
            ++count;
        }
    }
   
    return answer;
}

int main() 
{
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };

    const vector<int>& answer = solution(genres, plays); 

    for (const int elem : answer)
        cout << elem << ' '; 

    return 0; 
}