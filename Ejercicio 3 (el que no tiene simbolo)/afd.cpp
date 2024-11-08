#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const int NUMSTATES = 7; // Estados del 0 al 6
const int NUMCAR = 4;    // Caracteres: 'a', 'b', 'c', 'd'
int matrix[NUMSTATES][NUMCAR] = {
    {0, 1, 2, -1},   // Estado 0: 
    {-1, 1, 2, -1},  // Estado 1: 
    {3, -1, -1, -1}, // Estado 2: 
    {-1, 4, -1, -1}, // Estado 3: 
    {-1, -1, 5, -1}, // Estado 4: 
    {-1, -1, -1, 6}, // Estado 5: 
    {-1, -1, -1, -1} // Estado 6:
};

int charToIndex(char c)
{
    switch (c)
    {
    case 'a':
        return 0;
    case 'b':
        return 1;
    case 'c':
        return 2;
    case 'd':
        return 3;
    default:
        return -1; // Carácter no válido
    }
}

bool isValidExpression(const string &line)
{
    int state = 0;
    for (char c : line)
    {
        int index = charToIndex(c);
        if (index == -1)
        {
            return false; // Carácter no válido
        }
        state = matrix[state][index];
        if (state == -1)
        {
            return false; // Transición no válida
        }
    }
    return state == 6; // Verificar si el estado final es el estado de aceptación
}

void processFile(const string &filename)
{
    ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        cout << "No se encontró el archivo." << endl;
        return;
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
}

int main()
{
    processFile("text.txt");
    return 0;
}
