#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Funktion, um die Karte aus einer Datei zu lesen
vector<vector<int>> readMapFromFile(const string& filename) {
    vector<vector<int>> map;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Fehler beim Öffnen der Datei!" << endl;
        return map;
    }

    string line;
    while (getline(file, line)) {
        vector<int> row;
        for (char ch : line) {
            if (isdigit(ch)) {
                row.push_back(ch - '0'); // Zeichen in Zahl umwandeln
            }
        }
        if (!row.empty()) {
            map.push_back(row);
        }
    }

    file.close();
    return map;
}

// Funktion, um die Karte auszugeben
void printMap(const vector<vector<int>>& map) {
    for (const auto& row : map) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

// Tiefensuche (DFS) mit Höhensteigerung und Pfad-Speicherung
void dfs(vector<vector<int>>& map, vector<vector<bool>>& visited, int x, int y, vector<pair<int, int>>& path, vector<vector<pair<int, int>>>& allPaths) {
    int rows = map.size();
    int cols = map[0].size();

    // Ziel erreicht (9 gefunden)
    if (map[x][y] == 9) {
        path.push_back({x, y}); // Ziel zur Pfadliste hinzufügen
        allPaths.push_back(path); // Pfad speichern
        path.pop_back(); // Ziel entfernen, um weitere Pfade zu finden
        return;
    }

    // Grenzen und Bedingungen prüfen
    if (x < 0 || x >= rows || y < 0 || y >= cols || visited[x][y]) {
        return;
    }

    // Knoten als besucht markieren
    visited[x][y] = true;
    path.push_back({x, y}); // Aktuelle Position zum Pfad hinzufügen

    // In alle vier Richtungen bewegen
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    for (int dir = 0; dir < 4; ++dir) {
        int newX = x + dx[dir];
        int newY = y + dy[dir];

        // Prüfen, ob der nächste Höhenwert genau um 1 steigt
        if (newX >= 0 && newX < rows && newY >= 0 && newY < cols &&
            map[newX][newY] == map[x][y] + 1) {
            dfs(map, visited, newX, newY, path, allPaths);
        }
    }

    // Knoten als nicht besucht markieren und aus Pfad entfernen
    visited[x][y] = false;
    path.pop_back();
}

int main() {
    string filename = "test.txt";
    vector<vector<int>> map = readMapFromFile(filename);

    if (map.empty()) {
        return 1;
    }

    cout << "Eingelesene Karte:" << endl;
    printMap(map);

    int rows = map.size();
    int cols = map[0].size();

    int count = 0;

    // Alle Positionen mit einer 0 durchsuchen
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (map[i][j] == 0) {
                vector<vector<bool>> visited(rows, vector<bool>(cols, false));
                vector<pair<int, int>> path; // Aktueller Pfad
                vector<vector<pair<int, int>>> allPaths; // Alle gefundenen Pfade

                dfs(map, visited, i, j, path, allPaths);

                // Alle gefundenen Pfade ausgeben
                if (!allPaths.empty()) {
                    // cout << "Wege von der 0 an Position (" << i << ", " << j << "):" << endl;
                    count += allPaths.size();
                    // for (const auto& singlePath : allPaths) {
                    //     for (const auto& [x, y] : singlePath) {
                    //         cout << "(" << x << ", " << y << ") ";
                    //     }
                    //     cout << endl;
                    // }
                } else {
                    // cout << "Kein Weg von der 0 an Position (" << i << ", " << j << ") zur 9 gefunden." << endl;
                }
            }
        }
    }
    cout << "Anzahl der gefundenen Wege: " << count << endl;

    return 0;
}
