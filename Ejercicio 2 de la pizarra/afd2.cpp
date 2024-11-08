#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int charToIndex(char c)
{
    switch (c)
    {
    case 'a':
        return 0;
    case 'b':
        return 1;
    case 'i':
        return 2;
    case 'o':
        return 3;
    case 't':
        return 4;
    case 'v':
        return 5;
    default:
        return -1; // Carácter no válido
    }
}

bool isValidExpression(const string &line)
{
    // Tabla de aceptación del autómata
    int matrix[6][6] = {
        {-1, 2, -1, -1, -1, 1},  // Estado 0
        {2, 4, -1, -1, -1, -1},  // Estado 1
        {-1, -1, -1, 1, -1, 3},  // Estado 2
        {-1, -1, 3, -1, 5, -1},  // Estado 3
        {-1, -1, 3, -1, -1, -1}, // Estado 4
        {-1, -1, 5, -1, -1, -1}  // Estado 5
    };

    int state = 0;
    for (char c : line)
    {
        int index = charToIndex(c);
        if (index == -1 || matrix[state][index] == -1)
        {
            return false; // Carácter no válido o transición no válida
        }
        state = matrix[state][index];
    }

    return state == 4 || state == 5 || state == 3; // Verificar si el estado final es el estado de aceptación
}

int main()
{
    ifstream inputFile("text.txt");
    if (!inputFile.is_open())
    {
        cout << "No se encontró el archivo." << endl;
        return 1;
    }

    string line;
    vector<string> validLines;
    vector<string> invalidLines;

    while (getline(inputFile, line))
    {
        if (isValidExpression(line))
        {
            validLines.push_back(line);
        }
        else
        {
            invalidLines.push_back(line);
        }
    }

    // Printing valid and invalid lines
    cout << "Válidas: ";
    for (const string &vline : validLines)
    {
        cout << vline << " ";
    }
    cout << endl;

    cout << "No válidas: ";
    for (const string &ivline : invalidLines)
    {
        cout << ivline << " ";
    }
    cout << endl;

    return 0;
}