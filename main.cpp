#include <iostream>
#include<string.h>
#include <iomanip>
#include <stdlib.h>
#define TAMANO 15

using namespace std;

// estrucuta del Nodo

struct Nodo
{
    int dato;
    string nombre;

    Nodo *siguiente;
    Nodo *siguienteConjunto;
} * inicio, *cola;

int menuPpal();
int menuMantenimiento();
void crearConjunto(int, string);
void mostrarConjunto(string);
bool validarParentesis(char[]);
void expresionPosfija(string );
bool existeConjunto(string);
bool existenTodosConjuntos(string);


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

            int op;

            op = menuMantenimiento();

            switch (op)
            {
            case 1:

                cout << "\nDigita el nombre del conjunto\n";
                cin >> nombre;
                mostrarConjunto(nombre);
                break;

            default:
                break;
            }
            break;

        case 3:
            expresionPosfija(" ");
            break;
            /*
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
    cout << "----------------------Menu Principal--------------------------\n";
    cout << "--------------------------------------------------------------\n";
    cout << "--------------------------------------------------------------\n";
    cout << "---1. Crear Conjunto------------------------------------------\n";
    cout << "---2. Mantenimiento-------------------------------------------\n";
    cout << "---3. Digita el Problema--------------------------------------\n";
    cout << "---4. Salir del Programa--------------------------------------\n";
    cout << "--------------------------------------------------------------\n";
    cout << "--------<1-2-3-4>---------------------------------------------\n";
    cin >> op;
    return op;
    return 0;
}
int menuMantenimiento()
{
    int op;
    cout << "---------------------Menu Mantenimiento-----------------------\n";
    cout << "--------------------------------------------------------------\n";
    cout << "--------------------------------------------------------------\n";
    cout << "---1. Mostrar conjunto-----------------------------------------\n";
    cout << "---2. Modificar conjunto--------------------------------------\n";
    cout << "---3. Eliminar elemento---------------------------------------\n";
    cout << "---4. Eliminar conjunto---------------------------------------\n";
    cout << "---5. Salir del Programa--------------------------------------\n";
    cout << "--------------------------------------------------------------\n";
    cout << "---------<1-2-3-4-5>------------------------------------------\n";
    cin >> op;
    return op;
    return 0;
}

//funcion para saber si existe o no un conjunto
bool existeConjunto(string Nombre){
    Nodo *aux=inicio;
    while (aux->siguienteConjunto!=NULL)    
    {
        if(aux->nombre==Nombre){
            return true;
        }else{
            aux=aux->siguienteConjunto;
        }
    }
    return false;
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

            if (inicio == NULL)
            {
                inicio = conjunto;
                cola = inicio;
                inicio->siguiente = nuevo;
            }
            else
            {
                aux2->siguiente = nuevo;
                nuevo->siguiente = aux;
            }
        }
    }
    else
    {

        cola->siguienteConjunto = conjunto;
        cola = conjunto;

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

            if (aux == cola)
            {
                aux2 = conjunto;
                aux2->siguiente = nuevo;
            }
            else
            {
                aux2->siguiente = nuevo;
                nuevo->siguiente = aux;
            }
        }
    }
}

/////funcion para mostrar los conjuntos conjuntos
void mostrarConjunto(string conjunto)
{
    Nodo *aux = inicio;
    Nodo *aux2 = NULL;
    while (aux->nombre != conjunto)
    {
        aux = aux->siguienteConjunto;
    }

    aux2 = aux->siguiente;
    cout << endl
         << conjunto << " (" << aux2->dato;
    aux2 = aux2->siguiente;
    while (aux2 != NULL)
    {
        cout << " - " << aux2->dato;
        aux2 = aux2->siguiente;
    }
    cout << ")\n";
}

// funcion para validar los parentesis RETURN TRUE BUENO/FALSE MALO
bool validarParentesis(char expresion[])
{
    char pila[TAMANO];
    int tope = -1;
    for (int i = 0; i < TAMANO; i++)
    {
        if (expresion[i] == '(')
        {
            tope++;
            pila[tope] = expresion[i];
        }
        else if (pila[tope] == '(' && expresion[i] == ')')
        {
            pila[tope] = ' ';
            tope--;
        }
    }
    if (tope = -1)
    {
        cout << "la expresion esta correcta\n";
        return true;
    }
    else
    {
        cout << "la expresion esta incorrecta\n";
        return false;
    }
}

//funcion para validar los conjuntos en la expresion
bool existenTodosConjuntos(string expresion){
    Nodo *aux=inicio;
    for (int i = 0; i < expresion.length(); i++)
    {
        if ((expresion[i]>='a') && (expresion[i]<='z'))
        {
            string str="";
            str=expresion[i];
            if(!existeConjunto(str)){
                cout<<"conjunto "<<str<<" no existe\n";
                return false;
        }
    }
    return true;
}

void expresionPosfija(string expresion)
{
    system("cls");
					cout<<"Ingresa la expresion en notacion infija (sin espacios)";
					cin>>expInf;
				
					if(validar(expInf)){
						tope=-1;
						pos=-1;
						tamExp=strlen(expInf);
					
					for(int i=0;i<tamExp;i++){
						simbolo=expInf[i];
						if(simbolo=='('){
							tope++;
							pila[tope]=simbolo;
						}else if(simbolo==')'){
							while(pila[tope]!='('){
								pos++;
								expPos[pos]=pila[tope];
								tope--;
							}
							tope--;
						}
						else if((simbolo>='1')&&(simbolo<='9')){
							pos++;
							expPos[pos]=simbolo;
						}
						else{
							while(tope>-1 && (prioridad(simbolo)<=prioridad(pila[tope]))){
								pos++;
								expPos[pos]=pila[tope];
								tope--;
							}
							tope++;
							pila[tope]=simbolo;
						}
					}
					
					while(tope>-1){
						pos++;
						expPos[pos]=pila[tope];
						tope--;
					}	
					cout<<("la expresion en postfija es: \n");
					for(int i=0; i<=pos;i++){
						cout<<(expPos[i]);
					}	
					cout<<"\n";
					resultadoPos(resultado,expPos,simbolo,pos);
				cout<<"\n";
					}else{
						cout<<"expresion invalida";
					}

    
}