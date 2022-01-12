#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

// estrucuta del Nodo

struct Nodo
{
    int dato;
    string nombre;

    Nodo *siguiente;
    Nodo *siguienteConjunto;
} *inicio;

int menuPpal();
void crearConjunto(int, string);

int main()
{
    int opcion = 0;
    string nombre;
    do
    {
        opcion = menuPpal();
        switch (opcion)
        {
        case 1:
            int tamano = 0;
            cout << "Escribe el nombre del conjunto\n";
            cin >> nombre;
            cout << "Escribe el tamaño del conjunto\n";
            cin >> tamano;
            crearConjunto(tamano, nombre);
        Nodo *lista=inicio->siguiente;
            while (lista != NULL)
    {
        int dato;
        dato=lista->dato;
        lista = lista->siguiente;
        cout << "\n---------------------------------------------------------------------------\n";
        cout << "\n-->"<< dato << endl;
        cout << "\n---------------------------------------------------------------------------\n";
    }


            break;
      /*  case 2:

            break;
        case 3:

            break;
        case 4:

            break;

        default:
            break;*/
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
    cout << "---1. Crear Conjunto------------------------------------------\n";
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
void crearConjunto(int tamano, string nombre)
{
    Nodo *conjunto = new Nodo();
    conjunto->nombre = nombre;
    if (inicio == NULL)
    {
        for (int i = 0; i < tamano; i++)
        {
            int dato = 0;
            Nodo *nuevo = new Nodo(); // creamos el nuevo Nodo
            Nodo *aux = inicio;
            Nodo *aux2 = NULL;

            cout << "Digita el numero a insertar en el conjunto";
            cin >> dato;

            nuevo->dato = dato;

            while ((aux != NULL) and (aux->dato < dato))
            {
                aux2 = aux;
                aux = aux->siguiente;
            }

            if(inicio==NULL){
            inicio = conjunto;
            inicio->siguiente = nuevo;
            }else{
                aux2->siguiente=nuevo;
                nuevo->siguiente=aux;
            }
        }
    }
    else
    {
        for (int i = 0; i < tamano; i++)
        {
            int dato = 0;
            Nodo *nuevo = new Nodo(); // creamos el nuevo Nodo
            Nodo *aux = inicio;
            Nodo *aux2 = NULL;

            cout << "Digita el numero a insertar en el conjunto";
            cin >> dato;

            nuevo->dato = dato;

            while ((aux != NULL) and (aux->dato < dato))
            {
                aux2 = aux;
                aux = aux->siguiente;
            }

                aux2->siguiente=nuevo;
                nuevo->siguiente=aux;
            }
            Nodo *aux3=inicio;
            while(aux3->siguiente!=NULL){
                aux3->siguiente=aux3;
            }
            aux3->siguienteConjunto=conjunto;
        }
    }
