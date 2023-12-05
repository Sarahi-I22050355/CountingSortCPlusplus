#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <random>
#pragma once
class Counting_Sort
{
public:
    static std::vector<int> Sort(std::vector<int>& inputArray) {
        // Encontrar el elemento máximo de inputArray.
        int M = 0;
        for (int num : inputArray) {
            if (num > M) {
                M = num;
            }
        }

        // Inicializar countArray con 0
        std::vector<int> countArray(M + 1, 0);

        // Asignar cada elemento de inputArray como un índice de countArray
        for (int num : inputArray) {
            countArray[num]++;
        }

        // Calcular la suma prefija en cada índice de countArray
        for (int i = 1; i < M + 1; i++) {
            countArray[i] += countArray[i - 1];
        }

        // Crear outputArray a partir de countArray
        std::vector<int> outputArray(inputArray.size());

        for (int i = inputArray.size() - 1; i >= 0; i--) {
            outputArray[countArray[inputArray[i]] - 1] = inputArray[i];
            countArray[inputArray[i]]--;
        }

        return outputArray;
    }

    static std::vector<std::string> SortStrings(std::vector<std::string>& inputArray) {
        // Encontrar la cadena más larga en inputArray.
        int maxLength = 0;
        for (const std::string& str : inputArray) {
            if (str.length() > maxLength) {
                maxLength = str.length();
            }
        }

        // Inicializar countArray con 0
        int range = 256; // Considerando el rango ASCII extendido
        std::vector<std::vector<int>> countArray(inputArray.size(), std::vector<int>(range, 0));

        // Contar la frecuencia de cada carácter en cada string
        for (size_t i = 0; i < inputArray.size(); i++) {
            for (char c : inputArray[i]) {
                countArray[i][c]++;
            }
        }

        // Calcular la suma prefija en cada índice de countArray
        for (size_t i = 0; i < inputArray.size(); i++) {
            for (int j = 1; j < range; j++) {
                countArray[i][j] += countArray[i][j - 1];
            }
        }

        // Crear outputArray a partir de countArray
        std::vector<std::string> outputArray(inputArray.size());
        for (size_t i = 0; i < inputArray.size(); i++) {
            std::vector<char> sortedString(maxLength);

            for (int j = inputArray[i].length() - 1; j >= 0; j--) {
                int index = --countArray[i][inputArray[i][j]];
                sortedString[index] = inputArray[i][j];
            }

            outputArray[i] = std::string(sortedString.begin(), sortedString.end());
        }

        return outputArray;
    }
};

