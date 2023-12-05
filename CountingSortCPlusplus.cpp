#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <random>
#include <iostream>
#include "Counting_Sort.h"

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100);

    std::vector<int> inputArray(10);

    for (int i = 0; i < inputArray.size(); i++) {
        inputArray[i] = dis(gen); // Genera un número aleatorio entre 0 y 100
    }

    // Mostrar el array generado aleatoriamente
    std::cout << "Array generado aleatoriamente:\n";
    for (int num : inputArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Ordenar el array utilizando CountingSort
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<int> outputArray = Counting_Sort::Sort(inputArray);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    // Mostrar el array ordenado
    std::cout << "\nArray ordenado:\n";
    for (int num : outputArray) {
        std::cout << num << " ";
    }

    // Mostrar el tiempo transcurrido
    std::cout << "\n\nTiempo transcurrido en ordenar: " << elapsed.count() << " segundos\n";

    // Permitir al usuario ingresar una cadena para ordenarla
    std::cout << "\nIngrese una cadena para ordenarla por caracteres ASCII:\n";
    std::string userString;
    std::cin >> userString;

    std::vector<std::string> userArray = { userString };
    std::vector<std::string> sortedUserArray = Counting_Sort::SortStrings(userArray);

    // Mostrar la cadena ordenada
    std::cout << "\nCadena ordenada:\n";
    std::cout << sortedUserArray[0] << std::endl;

    return 0;
}
