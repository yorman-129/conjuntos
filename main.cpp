#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

// estrucuta del Nodo

struct Nodo
{
    int dato;

    Nodo *siguiente;
    Nodo *siguienteConjunto;
} * inicio;

int menuPpal();
void crearConjunto(int);

int main()
{
    int opcion = 0;
    do
    {
        opcion = menuPpal();
        switch (opcion)
        {
        case 1:
            int tamano = 0;
            cout << "Escribe el tamaño del conjunto\n";
            cin >> tamano;
            crearConjunto(tamano);

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;

        default:
            break;
        }
    } while (opcion != 4);
}

// menu principal el cual es el centro del sistema
int menuPpal()
{
    int op;
    cout << "------------------------Menu Principal------------------------\n";
    cout << "--------------------------------------------------------------\n";
    cout << "--------------------------------------------------------------\n";
    cout << "---1. Agregar ------------------------------------------------\n";
    cout << "---2. Mostrar Por Nombre--------------------------------------\n";
    cout << "---3. Buscar--------------------------------------------------\n";
    cout << "---4. Modificar-----------------------------------------------\n";
    cout << "---5. Eliminar------------------------------------------------\n";
    cout << "---6. informes------------------------------------------------\n";
    cout << "---7. Salir del Programa--------------------------------------\n";
    cout << "--------------------------------------------------------------\n";
    cout << "---<1-2-3-4-5-6>----------------------------------------------\n";
    cin >> op;
    return op;
    return 0;
}

// funcion para la creacion de los conjuntos
void crearConjunto(int tamano)
{
    Nodo *conjunto = new Nodo();
    if (inicio == NULL)
    {
        
        for (int i = 0; i < tamano; i++)
        {
            int dato = 0;
            Nodo *nuevo = new Nodo();//creamos el nuevo Nodo
            Nodo *aux = inicio;
            Nodo *aux2 = NULL;

            conjunto->siguiente=aux;// voy aqui estoy pensando en crear una estructura de Nodo nueva para manejar los conjuntos!!!!!!!!!!!!!!


            cout << "Digita el numero a insertar en el conjunto";
            cin >> dato;

            nuevo->dato = dato;

            while ((aux != NULL) and (aux->dato < dato))
            {
                aux2 = aux;
                aux = aux->siguiente;
            }
        }
    }
}
