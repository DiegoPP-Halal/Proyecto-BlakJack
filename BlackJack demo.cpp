#include <iostream>
#include <algorithm> // Para usar random_shuffle
#include <stdlib.h>  // Para usar system()
#include <limits>    // Para la validación de la variable op
#include <vector>    // Para usar vector en lugar de arrays

#ifdef _WIN32
    #include <windows.h> // Para Windows
#endif

using namespace std;

class Pila {
    public:
        string ARREGLO[52];  // La pila tendrá 52 cartas (mazo completo)
        int top = -1;
        
        // Método para agregar un elemento
        void push(string n) {
            if (top != 51) {
                ARREGLO[++top] = n;
            } else {
                cout << "Tope alcanzado." << endl << endl;
            }
        }
        
        // Método para eliminar un elemento
        string pop() {
            string d;
            if (top != -1) {
                d = ARREGLO[top--];
            } else {
                d = "-1";  // Regresamos una cadena vacía si la pila está vacía
            }
            return d;
        }
        
        // Método para contar el número de elementos
        int count() {
            return top + 1;
        }

        // Método para ver el último elemento sin eliminarlo
        string peek() {
            string d;
            if (top != -1) {
                d = ARREGLO[top];
            } else {
                d = "-1";
            }
            return d;
        }

        // Método para verificar si la pila está vacía
        bool isEmpty() {
            return (top == -1);
        }

        // Método para verificar si la pila está llena
        bool isFull() {
            return (top == 51);
        }

        // Método para mostrar todas las cartas en la pila
        void MostrarTodo() {
            if (isEmpty()) {
                cout << "La pila está vacía." << endl;
                return;
            }
            for (int i = 0; i <= top; i++) {
                cout << ARREGLO[i] << endl;
            }
        }

        // Método para limpiar la pantalla según el sistema operativo
        void clearScreen() {
            #ifdef _WIN32
                system("cls"); // Comando para limpiar pantalla en Windows
            #else
                system("clear"); // Comando para limpiar pantalla en Unix (Linux/MacOS)
            #endif
        }
};

// Función para revolver el mazo
void revolver(Pila &mazo, string &mazoinicial, vector<string> &simbolos) {
    random_shuffle(mazoinicial.begin(), mazoinicial.end());  // Mezcla los números/letras
    random_shuffle(simbolos.begin(), simbolos.end());  // Mezcla los símbolos

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            string carta = simbolos[i] + " " + mazoinicial[j];  // Concatenar símbolo y número/letra
            mazo.push(carta);  // Añadir carta al mazo
        }
    }

    // Mezclar todo el mazo
    random_shuffle(mazo.ARREGLO, mazo.ARREGLO + 52);

    /** Mostrar las cartas mezcladas
    mazo.MostrarTodo();
    cout<<mazo.count();**/
}

void repartir (Pila &mazo, Pila &crupier, Pila &Jugador){
    Jugador.push(mazo.pop());
    crupier.push(mazo.pop());
    Jugador.push(mazo.pop());
    crupier.push(mazo.pop());
}

int main() {
    Pila crupier;
    Pila Jugador;
    Pila mazo;  // Instancia de la pila para el mazo
    string mazoinicial = "123456789JQKA";  // Las cartas numeradas y letras
    vector<string> simbolos = {"Diamantes", "Tréboles", "Corazones", "Picas"};  // Los 4 palos
    bool jugar = true;
    int opcion, levantarse = 2;
    
    while (jugar == true){
        cout<< "       BLACKJACK"<<endl<<endl;
        cout<<"1. Jugar."<<endl;
        cout<<"2. Salir del juego."<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:
                mazo.clearScreen();
                revolver(mazo,mazoinicial,simbolos);
                
            break;
            case 2:
            jugar = false;
            break;
        }
    }

    
    

    // Siguiente: puedes implementar el resto de las funciones como repartir cartas, reglas del blackjack, etc.

    return 0;
}

