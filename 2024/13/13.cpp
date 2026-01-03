#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// Struktur zur Darstellung der Punkte
struct Point {
    int x;
    int y;
};

// Struktur für einen Eintrag in der Datei
struct Entry {
    Point buttonA;
    Point buttonB;
    Point prize;
};

// Funktion, um die Datei einzulesen
std::vector<Entry> readDataFromFile(const std::string& filename) {
    std::vector<Entry> entries;
    std::ifstream file(filename);
    
    if (!file) {
        std::cerr << "Fehler beim Öffnen der Datei." << std::endl;
        return entries;
    }

    std::string line;
    while (std::getline(file, line)) {
        Entry entry;
        std::istringstream iss(line);

        std::string label;
        char colon, comma;

        // Button A
        iss >> label >> colon >> entry.buttonA.x >> comma >> entry.buttonA.y;
        
        // Button B
        std::getline(file, line);
        iss.clear();
        iss.str(line);
        iss >> label >> colon >> entry.buttonB.x >> comma >> entry.buttonB.y;

        // Prize
        std::getline(file, line);
        iss.clear();
        iss.str(line);
        iss >> label >> colon >> entry.prize.x >> comma >> entry.prize.y;

        entries.push_back(entry);

        // Überspringe die leere Zeile
        std::getline(file, line);
    }

    return entries;
}

// Beispiel einer Funktion, um den Pfad zu berechnen (Platzhalter)
void calculatePathToPrize(const std::vector<Entry>& entries) {
    for (const auto& entry : entries) {
        std::cout << "Button A: (" << entry.buttonA.x << ", " << entry.buttonA.y << ")\n";
        std::cout << "Button B: (" << entry.buttonB.x << ", " << entry.buttonB.y << ")\n";
        std::cout << "Prize: (" << entry.prize.x << ", " << entry.prize.y << ")\n";

        // Pfadberechnung hier hinzufügen
        std::cout << "Pfadberechnung fehlt noch.\n\n";
    }
}

int main() {
    std::string filename = "test.txt"; // Dateiname
    std::vector<Entry> entries = readDataFromFile(filename);

    if (!entries.empty()) {
        calculatePathToPrize(entries);
    } else {
        std::cerr << "Keine Daten gefunden." << std::endl;
    }

    return 0;
}
