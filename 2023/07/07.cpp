#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Function to calculate the rank of a hand
int calculateRank(const std::string &hand)
{
    std::vector<int> count(26, 0);
    for (char c : hand)
    {
        count[c - 'A']++;
    }
    std::sort(count.rbegin(), count.rend());
    int rank = 0;
    for (int i = 0; i < 5; i++)
    {
        rank = rank * 26 + count[i];
    }
    return rank;
}

int main()
{
    std::vector<std::pair<std::string, int>> hands = {
        {"32T3K", 765},
        {"T55J5", 684},
        {"KK677", 28},
        {"KTJJT", 220},
        {"QQQJA", 483}};

    // Sort the hands based on their rank
    std::sort(hands.begin(), hands.end(), [](const auto &a, const auto &b)
              { return calculateRank(a.first) < calculateRank(b.first); });

    for(int i = 0; i < hands.size(); i++)
    {
        std::cout << hands[i].first << std::endl;
    }

    // Calculate the total winnings
    int totalWinnings = 0;
    for (int i = 0; i < hands.size(); i++)
    {
        totalWinnings += hands[i].second * (i + 1);
    }

    std::cout << "Total winnings: " << totalWinnings << std::endl;

    return 0;
}
