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
} *inicio,*cola;

int menuPpal();
void crearConjunto(int, string);
void mostrarConjunto(string);

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
            int tamano;
            cout << "Escribe el nombre del conjunto\n";
            cin >> nombre;
            cout << "Escribe el tamaño del conjunto\n";
            cin >> tamano;
            crearConjunto(tamano, nombre);
            
            break;
       case 2:
            mostrarConjunto("a");
            mostrarConjunto("b");
            mostrarConjunto("c");
            break;
       /* case 3:

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
            cola=inicio;
            inicio->siguiente = nuevo;
            }else{
                aux2->siguiente=nuevo;
                nuevo->siguiente=aux;
            }
        }
    }
    else
    {
       
       
       cola->siguienteConjunto=conjunto;
       cola=conjunto;
        
        for (int i = 0; i < tamano; i++)
        {
            int dato = 0;
            Nodo *nuevo = new Nodo(); // creamos el nuevo Nodo
            Nodo *aux = cola;
            Nodo *aux2 = NULL;

            cout << "Digita el numero a insertar en el conjunto";
            cin >> dato;

            nuevo->dato = dato;

            while ((aux != NULL) and (aux->dato < dato))
            {
                aux2 = aux;
                aux = aux->siguiente;
            }

            if(aux==cola){
            aux2 = conjunto;
            aux2->siguiente = nuevo;
            }else{
                aux2->siguiente=nuevo;
                nuevo->siguiente=aux;
            }
        }
    }
}

/////mostrar conjuntooo
void mostrarConjunto(string conjunto){
    Nodo *aux=inicio;
    Nodo *aux2=NULL;
    while(aux->nombre!=conjunto){
        aux=aux->siguienteConjunto;
    }
   
        aux2=aux->siguiente;
        while(aux2!=NULL){
        cout << "\n---------------------------------------------------------------------------\n";
        cout << "\n" <<aux2->dato << endl;
        cout << "\n---------------------------------------------------------------------------\n";
        aux2=aux2->siguiente;
        }
}