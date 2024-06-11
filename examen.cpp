#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

bool isLineStartingWithNumber(const std::string& line) {
    if (line.empty()) {
        return false;
    }
    if (std::isdigit(line[0])) {
        return true;
    }
    return false;
}

bool isLineStartingWithVowel(const std::string& line) {
    if (line.empty()) {
        return false;
    }
    char firstChar = line[0];
    if (std::tolower(firstChar) == 'a' || std::tolower(firstChar) == 'e' || std::tolower(firstChar) == 'i' || std::tolower(firstChar) == 'o' || std::tolower(firstChar) == 'u') {
        return true;
    }
    return false;
}

bool isLineStartingWithConsonant(const std::string& line) {
    if (line.empty()) {
        return false;
    }
    char firstChar = line[0];
    if (std::isalpha(firstChar) && !isLineStartingWithVowel(line)) {
        return true;
    }
    return false;
}

void readCSV(const std::string& entrada, const std::string& salidaNormal, const std::string& salidaVocales, const std::string& salidaConsonantes) {
    std::ifstream inputFile(entrada);
    if (!inputFile.is_open()) {
        std::cout << "Error al abrir el archivo de entrada." << std::endl;
        return;
    }

    std::ofstream outputFile(salidaNormal);
    if (!outputFile.is_open()) {
        std::cout << "Error al abrir el archivo de salida normal." << std::endl;
        return;
    }

    std::ofstream outputFileVocales(salidaVocales);
    if (!outputFileVocales.is_open()) {
        std::cout << "Error al abrir el archivo de salida de vocales." << std::endl;
        return;
    }

    std::ofstream outputFileConsonantes(salidaConsonantes);
    if (!outputFileConsonantes.is_open()) {
        std::cout << "Error al abrir el archivo de salida de consonantes." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        if (!isLineStartingWithNumber(line)) {
            outputFile << line << "\n";
            if (isLineStartingWithVowel(line)) {
                outputFileVocales << line << "\n";
            }
            if (isLineStartingWithConsonant(line)) {
                outputFileConsonantes << line << "\n";
            }
        }
    }

    inputFile.close();
    outputFile.close();
    outputFileVocales.close();
    outputFileConsonantes.close();
}

int main() {
    std::string entrada = "dataExamen2.csv";
    std::string salidaNormal = "starting_without_number.csv";
    std::string salidaVocales = "starting_with_vowel.csv";
    std::string salidaConsonantes = "starting_with_consonant.csv";

    readCSV(entrada, salidaNormal, salidaVocales, salidaConsonantes);

    return 0;
}