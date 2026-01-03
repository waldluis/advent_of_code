#include <iostream>
#include <vector>
#include <string>
#include <fstream>


#define SIZE 71
#define LINES 1024

struct Point {
    int x;
    int y;
};


int main() {

    std::vector<std::vector<char>> map(SIZE, std::vector<char>(SIZE, '.'));

    std::string fileName = "input.txt";
    std::ifstream file(fileName);
    std::string line;
    int lineCount = 0;

    while(std::getline(file, line) && lineCount < LINES) {
        int x, y;
        // Parsen der Zeile im Format "x,y"
        if (sscanf(line.c_str(), "%d,%d", &x, &y) == 2) {
            if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
                map[y][x] = '#'; // Setze '#' an die entsprechende Position
            } else {
                std::cerr << "Ungültige Koordinaten: " << x << "," << y << std::endl;
            }
        } else {
            std::cerr << "Fehler beim Lesen der Zeile: " << line << std::endl;
        }
        ++lineCount;

    }

    // Ausgabe der Karte
    // for (int y = 0; y < SIZE; ++y) {
    //     for (int x = 0; x < SIZE; ++x) {
    //         std::cout << map[y][x];
    //     }
    //     std::cout << std::endl;
    // }

    struct Point current = {0, 0};
    struct Point finish = {SIZE - 1, SIZE - 1};

    // find shortest path
    // # are obstacles
    // . are free spaces
    // print number of steps
    // use breadth-first search

    std::vector<std::vector<int>> distances(SIZE, std::vector<int>(SIZE, -1));
    distances[current.y][current.x] = 0;

    std::vector<struct Point> queue;
    queue.push_back(current);

    while (!queue.empty()) {
        struct Point current = queue.front();
        queue.erase(queue.begin());

        if (current.x == finish.x && current.y == finish.y) {
            break;
        }

        // check right
        if (current.x + 1 < SIZE && map[current.y][current.x + 1] != '#' && distances[current.y][current.x + 1] == -1) {
            distances[current.y][current.x + 1] = distances[current.y][current.x] + 1;
            queue.push_back({current.x + 1, current.y});
        }

        // check left
        if (current.x - 1 >= 0 && map[current.y][current.x - 1] != '#' && distances[current.y][current.x - 1] == -1) {
            distances[current.y][current.x - 1] = distances[current.y][current.x] + 1;
            queue.push_back({current.x - 1, current.y});
        }

        // check down
        if (current.y + 1 < SIZE && map[current.y + 1][current.x] != '#' && distances[current.y + 1][current.x] == -1) {
            distances[current.y + 1][current.x] = distances[current.y][current.x] + 1;
            queue.push_back({current.x, current.y + 1});
        }

        // check up
        if (current.y - 1 >= 0 && map[current.y - 1][current.x] != '#' && distances[current.y - 1][current.x] == -1) {
            distances[current.y - 1][current.x] = distances[current.y][current.x] + 1;
            queue.push_back({current.x, current.y - 1});
        }
    }

    std::cout << "Number of steps: " << distances[finish.y][finish.x] << std::endl;


    return 0;
}