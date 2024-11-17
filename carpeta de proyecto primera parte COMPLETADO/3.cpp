#include <iostream>
#include <regex>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <fstream>

// Códigos de escape ANSI para colores
#define RESET "\033[0m"
#define BLACK_TEXT_WHITE_BG "\033[30;47m"
#define WHITE_TEXT_BLACK_BG "\033[37;40m"
#define ORANGE "\033[38;5;208m"
#define INDIGO "\033[38;5;54m"
#define VIOLET "\033[35m"
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";
const std::string BRIGHT_RED = "\033[91m";
const std::string BRIGHT_GREEN = "\033[92m";
const std::string BRIGHT_YELLOW = "\033[93m";
const std::string BRIGHT_BLUE = "\033[94m";
const std::string BRIGHT_MAGENTA = "\033[95m";
const std::string BRIGHT_CYAN = "\033[96m";
const std::string BRIGHT_WHITE = "\033[97m";



void validar_cadena(const std::string& cadena) {
    // Definicion de las expresiones regulares
    std::regex DIGITO("[0-9]");
    std::regex LETRA("[a-zA-Z]");
    std::regex PALABRA("[a-zA-Z]+");
    std::regex NUMERO_ENTERO("[0-9]+");
    std::regex NUMERO_REAL("[0-9]+\\.[0-9]+");
    std::regex IDENTIFICADOR("[a-zA-Z][a-zA-Z0-9]*");
    std::regex OPERADOR("(=|\\+|-|\\*|/|%)");

    std::cout << std::endl << std::endl; // Dos lineas de espacio
    std::cout << "Expresion introducida: " << cadena << std::endl;
  


    if (std::regex_match(cadena, DIGITO)) {
        std::cout << GREEN << "Validacion: Es un digito valido." << RESET << std::endl;
    } else if (std::regex_match(cadena, LETRA)) {
        std::cout << GREEN << "Validacion: Es una letra valida." << RESET << std::endl;
    } else if (std::regex_match(cadena, PALABRA)) {
        std::cout << GREEN << "Validacion: Es una palabra valida." << RESET << std::endl;
    } else if (std::regex_match(cadena, NUMERO_ENTERO)) {
        std::cout << GREEN << "Validacion: Es un numero entero valido." << RESET << std::endl;
    } else if (std::regex_match(cadena, NUMERO_REAL)) {
        std::cout << GREEN << "Validacion: Es un numero real valido." << RESET << std::endl;
    } else if (std::regex_match(cadena, IDENTIFICADOR)) {
        std::cout << GREEN << "Validacion: Es un identificador valido." << RESET << std::endl;
    } else if (std::regex_match(cadena, OPERADOR)) {
        std::cout << GREEN << "Validacion: Es un operador valido." << RESET << std::endl;
    } else {
        std::cout << RED << "Validacion: La cadena no corresponde a ninguna de las expresiones regulares definidas." << RESET << std::endl;
    }

    std::cout << std::endl << std::endl; // Dos lineas de espacio
}

void mostrar_menu() {
    std::cout << "USAR EN PANTALLA COMPLETA:\n";
    std::cout << std::endl << std::endl << std::endl << std::endl; // Cuatro lineas de espacio

    std::cout << "Menu:\n";
    std::cout << std::endl << std::endl; 

    std::cout << "1) Ver ejemplos de validaciones\n";
     std::cout << std::endl; 

    std::cout << "2) Introducir expresion a validar\n";
    std::cout << std::endl;

    std::cout << "3) Terminar el programa\n";
    std::cout << std::endl;

    std::cout << "Seleccione una opcion: ";
}

void mostrar_ejemplos() { 
    
    validar_cadena("2");             // Dígito
    validar_cadena("a");             // Letra
    validar_cadena("hola");          // Palabra
    validar_cadena("123");           // Número entero
    validar_cadena("123.456");       // Número real
    validar_cadena("variable1");     // Identificador
    validar_cadena("+");             // Operador
    validar_cadena("invalid_string");// Cadena inválida

}

// Función para copiar e imprimir el contenido de un archivo de texto
void copiar_e_imprimir_txt(const std::string& nombre_archivo) {
    std::ifstream archivo(nombre_archivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombre_archivo << std::endl;
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::cout << linea << std::endl;
    }

    archivo.close();
}

void mostrar_mensaje_final() {
    std::vector<std::string> colores = {RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO, VIOLET};
    std::string mensaje = "Terminado el programa......  Muchas gracias por Usarlo :D";
    
    for (size_t i = 0; i < mensaje.size(); ++i) {
        std::cout << colores[i % colores.size()] << mensaje[i] << RESET;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Pausa para el efecto de degradado
    }
    std::cout << std::endl;
}

int main() {
    int opcion;
    std::string expresion;

    while (true) {
        system("CLS"); // Limpiar la pantalla
        mostrar_menu();
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                system("CLS"); // Limpiar la pantalla
                mostrar_ejemplos();
                std::cout << RESET; // Restablecer el color
                break;
            case 2: {
                bool primera_vez = true;
                bool continuar_validando = true;
                while (continuar_validando) {
                    if (primera_vez) {
                        system("CLS"); // Limpiar la pantalla solo la primera vez
                        primera_vez = false;
                    }
                    std::cout << std::endl << std::endl; // Dos lineas de espacio
                    std::cout << "Introduzca la expresion a validar: ";
                    std::cin >> expresion;
                    validar_cadena(expresion);
                    std::cout << RESET; // Restablecer el color

                    char continuar;
                    std::cout << "Desea validar otra expresion?  ";
                    std::cout << std::endl << std::endl;
                    std::cout << "En caso de que " << GREEN << "SI" << RESET << " presione: " << GREEN << "s" << RESET << ", En caso de que " << RED << "NO" << RESET << " presione: " << RED << "n" << RESET << std::endl;

                    std::cin >> continuar;
                    if (continuar == 'n' || continuar == 'N') {
                        continuar_validando = false;
                    }
                }
                break;
            }
            case 3:
                std::cout << RESET; // Restablecer el color
                mostrar_mensaje_final();
                return 0;
            default:
                std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
                std::cout << RESET; // Restablecer el color
        }

        std::cout << "Presione Enter para continuar...";
        std::cin.ignore();
        std::cin.get();
    }

    return 0;
}