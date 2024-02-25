#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

struct Jugador {
    int numero;
    int puntaje;
};

void PantallaInicio();
void jugarpartida(int numeroJugador);
void Dibujar(int vida);
void limpiarpantalla();

Jugador jugadores[3] = {{1, 0}, {2, 0}, {3, 0}};

int main() {
    srand(time(0));
    PantallaInicio();
    return 0;
}

void PantallaInicio() {
    char opcion;
    int numeroJugador;

    do {
        limpiarpantalla();
         cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << " / \\  |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            cout << "  |||||" << endl;
            cout << "Palabra: F _ S" << endl;
        for (int i = 0; i < 25; i++) {
            cout << " *";
        }
        cout << "" << endl;
        cout << " *  Juego del Ahorcado (Palabras de la facultad) *" << endl;
        cout << " *               Menu de Opciones                *" << endl;
        cout << " *  a. Nuevo Juego                               *" << endl;
        cout << " *  b. Mostrar los puntajes                      *" << endl;
        cout << " *  c. Salir del juego                           *" << endl;
        cout << " *  d. CREDITOS                                  *" << endl;
        for (int i = 0; i < 25; i++) {
            cout << " *";
        }
        cout << endl;

        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 'a': {
                cout << "Ingrese el número del jugador (1, 2 o 3): ";
                cin >> numeroJugador;
                if (numeroJugador >= 1 && numeroJugador <= 3) {
                    jugarpartida(numeroJugador);
                } else {
                    cout << "Número de jugador no válido." << endl;
                }
                break;
            }
            case 'b': {
                cout << "Puntajes:" << endl;
                for (int i = 0; i < 3; i++) {
                    cout << "Jugador " << jugadores[i].numero << ": " << jugadores[i].puntaje << " puntos" << endl;
                }
                cin.ignore();
                break;
            }
            case 'c': {
                cout << "¡Hasta luego!" << endl;
                break;
            }
            case 'd': {
                cout << "========CODIGO GENERADO POR=========" << endl;
                cout << "David Alejandro Cuasquer Rodriguez " << endl;
                cout << "Juan Martin Cusme Carrera " << endl;
                cout << "Presione Enter para volver al menú...";
                cin.ignore();
                break;
            }
            default: {
                cout << "Opcion no valida. Intente de nuevo." << endl;
            }
        }

        if (opcion != 'c') {
            cout << "Presione Enter para continuar...";
            cin.ignore();
        }

    } while (opcion != 'c');
}




void agregarPista(string palabra) {
    if (palabra == "int") {
        cout << "Pista: Función relacionada a main." << endl;
    } else if (palabra == "programacion") {
        cout << "Pista: Base de la resolución de problemas mediante algoritmos." << endl;
    } else if (palabra == "cout") {
        cout << "Pista: Utilizado para mostrar información en la consola." << endl;
    } else if (palabra == "algoritmo") {
        cout << "Pista: Conjunto de pasos para realizar una tarea específica." << endl;
    } else if (palabra == "return") {
        cout << "Pista: Utilizado para devolver un valor de una función." << endl;
    } else if (palabra == "namespace") {
        cout << "Pista: Espacio de nombres utilizado para organizar código." << endl;
    } else if (palabra == "include") {
        cout << "Pista: Utilizado para incluir librerías en C++." << endl;
    } else if (palabra == "while") {
        cout << "Pista: Bucle que se ejecuta mientras una condición sea verdadera." << endl;
    } else if (palabra == "busqueda") {
        cout << "Pista: Proceso de encontrar un elemento en una colección de datos." << endl;
    } else if (palabra == "ordenamiento") {
        cout << "Pista: Organizar elementos en un orden específico." << endl;
    }
}

void jugarpartida(int numeroJugador) {
    string palabras[] = {"int", "programacion", "cout", "algoritmo","return","namespace","include","while","busqueda","ordenamiento"};
    srand((int)time(NULL));
    int nA = rand() % 10;
    string palabraSeleccionada = palabras[nA];
    int longitudPalabra = palabraSeleccionada.length();
    string palabraAdivinada(longitudPalabra, '_');

    int intentosRestantes = 6;

    while (intentosRestantes > 0) {
        limpiarpantalla();
        agregarPista(palabraSeleccionada);
        Dibujar(intentosRestantes);
        cout << "Palabra a adivinar: " << palabraAdivinada << endl;

        char letra;
        bool entradaValida = false;

        while (!entradaValida) {
            cout << "Ingrese una letra: ";
            cin >> letra;

            if ((letra >= 'a' && letra <= 'z') && (cin.get() == '\n')) {
                entradaValida = true;
            } else {
                cout << "Entrada no valida. Ingrese solo una letra minuscula." << endl;
                cin.clear();
                cin.ignore();
                while (cin.get() != '\n');
            }
        }
        bool letraAdivinada = false;
        for (int i = 0; i < longitudPalabra; i++) {
            if (palabraSeleccionada[i] == letra) {
                palabraAdivinada[i] = letra;
                letraAdivinada = true;
            }
        }

        if (!letraAdivinada) {
            intentosRestantes--;
        }

        if (palabraAdivinada == palabraSeleccionada) {
            limpiarpantalla();
            Dibujar(intentosRestantes);
            cout << "¡Felicidades! Has adivinado la palabra: " << palabraSeleccionada << endl;
            jugadores[numeroJugador - 1].puntaje += 1;
            break;
        }
    }

    if (intentosRestantes == 0) {
        limpiarpantalla();
        Dibujar(intentosRestantes);
        cout << "Lo siento, has agotado tus intentos. La palabra era: " << palabraSeleccionada << endl;
    }
}
void Dibujar(int vida) {
    switch (vida) {
        case 6:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            cout << "  |||||" << endl;
            break;
        case 5:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            cout << "  |||||" << endl;
            break;
        case 4:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << "  |   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            cout << "  |||||" << endl;
            break;
        case 3:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            cout << "  |||||" << endl;
            break;
        case 2:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            cout << "  |||||" << endl;
            break;
        case 1:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << " /    |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            cout << "  |||||" << endl;
            break;
        case 0:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << " / \\  |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            cout << "  |||||" << endl;
            break;
    }
}


void limpiarpantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}