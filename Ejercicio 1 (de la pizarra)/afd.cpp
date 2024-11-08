#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int charToIndex(char c)
{
    switch (c)
    {
    case 'P':
        return 0;
    case 'L':
        return 1;
    case 'A':
        return 2;
    case 'Z':
        return 3;
    case 'O':
        return 4;
    default:
        return -1; // Carácter no válido
    }
}

bool isValidExpression(const string &line)
{
    // Tabla de aceptación del autómata
    int matrix[4][5] = {
        {1, 1, -1, -1, -1},  // Estado 0
        {-1, -1, 1, 2, 0},   // Estado 1
        {-1, -1, 0, 3, 2},   // Estado 2
        {-1, -1, -1, -1, -1} // Estado 3
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

    return state == 3; // Verificar si el estado final es el estado de aceptación
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
