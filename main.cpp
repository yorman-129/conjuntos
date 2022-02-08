#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cmath>
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
void crearConjuntoUniversal(int, string);
void mostrarConjunto(string);
bool validarParentesis(string);
bool numerosRepetidos(int, string);
bool numerosRepetidosUniversal(int, string);
string postfijo(string);
string resultado(string);
string Union(string, string); // retorna nombre del nuevo conjunto unido
string interseccion(string, string);
string diferencia(string , string );
string diferenciaSimetrica(string , string );

int main()
{
    string expresion, nombre, expPos, fin;
    int tamano;
    cout << "----------------------Menu Principal--------------------------\n";
    cout << "--------------------------------------------------------------\n";
    do
    {
        cout << "Digita tu expresion ==>\n";
        cin >> expresion;
    } while (validarParentesis(expresion));

    cout << "--------------------------------------------------------------\n";
    cout << "--------------------------------------------------------------\n";

    system("pause");
    system("cls");

    for (int i = 0; i < expresion.length(); i++)
    {
        if (expresion[i] >= 'a' and expresion[i] <= 'z')
        {

            nombre = expresion[i];
            cout << "Digita la cantidad de elementos en: " << nombre << endl;
            cin >> tamano;
            nombre = expresion[i];
            crearConjunto(tamano, nombre);
        }
    }

    /// conjunto universal falta y validacion de elementos
    cout << "Digita la cantidad de elementos en: U"  << endl;
            cin >> tamano;
    crearConjuntoUniversal(tamano,"u");
    mostrarConjunto("u");

    // que cree todas las operaciones en todos los conjuntos y pa la mierda
    system("pause");

    expPos = postfijo(expresion);
    resultado(expPos);
    cout << "Salio de resultado\n";
    return system("pause");
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
    cout << "---5. Salir del Mantenimiento---------------------------------\n";
    cout << "--------------------------------------------------------------\n";
    cout << "---------<1-2-3-4-5>------------------------------------------\n";
    cin >> op;
    return op;
    return 0;
}

bool numerosRepetidos(int num, string nombre)
{
    Nodo *aux = inicio;

    while (aux != NULL)
    {

        if (aux->nombre == nombre)
        {
            Nodo *aux2 = aux;
            while (aux2 != NULL)
            {
                if (num == aux2->dato)
                {
                    return true;
                }
                aux2 = aux2->siguiente;
            }
        }
        aux = aux->siguienteConjunto;
    }
    return false;
}

bool numerosRepetidosUniversal(int num, string nombre)
{

    Nodo *aux = inicio;

    while (aux != NULL)
    {
            Nodo *aux2 = aux;
            while (aux2 != NULL)
            {
                if (num == aux2->dato)
                {
                    return true;
                }
                aux2 = aux2->siguiente;
            }
        aux = aux->siguienteConjunto;
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

            do
            {
                cout << "Digita el numero a insertar en el conjunto: ";
                cin >> dato;
            } while (numerosRepetidos(dato, nombre));

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

            do
            {
                cout << "Digita el numero a insertar en el conjunto: ";
                cin >> dato;
            } while (numerosRepetidos(dato, nombre));

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

void crearConjuntoUniversal(int tamano, string nombre){
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

            do
            {
                cout << "Digita el numero a insertar en el conjunto: ";
                cin >> dato;
            } while (numerosRepetidosUniversal(dato, nombre));

            nuevo->dato = dato;
            cout<<".";

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

            do
            {
                cout << "Digita el numero a insertar en el conjunto: ";
                cin >> dato;
            } while (numerosRepetidosUniversal(dato, nombre));

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

// funcion para validar los parentesis
bool validarParentesis(string expresion)
{
    string pila[TAMANO];
    int tope = -1;
    cout << expresion.length();
    for (int i = 0; i < expresion.length(); i++)
    {
        if (expresion[i] == '(')
        {
            tope++;
            pila[tope] = expresion[i];
            cout << expresion[i];
        }
        else if (expresion[i] == ')' and pila[tope] == "(")
        {
            pila[tope] = ' ';
            tope--;
            cout << expresion[i];
        }
        else if (expresion[i] == ')')
        {
            if (pila[tope] != "(")
                cout << "la expresion esta incorrecta\n";
            return true;
        }
    }
    if (tope == -1)
    {

        cout << "la expresion esta correcta\n";
        return false;
    }
    else
    {
        cout << "la expresion esta incorrecta\n";
        return true;
    }
}

string postfijo(string expre)
{
    string pila[TAMANO];
    int tope;
    string resultado;

    tope = -1;

    for (int i = 0; i < expre.length(); i++)
    {
        if (expre[i] == '(')
        {
            tope++;
            pila[tope] = expre[i];
        }
        else if (expre[i] == '+' or expre[i] == '*' or expre[i] == '-' or expre[i] == '/' or expre[i] == '^')
        {
            tope++;
            pila[tope] = expre[i];
        }
        else if (expre[i] == ')')
        {
            while (pila[tope] != "(")
            {
                resultado += pila[tope];
                pila[tope] = " ";
                tope--;
            }
        }
        else
        {
            resultado += expre[i];
        }
    }
    while (tope != -1)
    {

        if (pila[tope] == "(")
        {
            pila[tope] = " ";
            tope--;
        }
        else
        {
            resultado += pila[tope];
            pila[tope] = " ";
            tope--;
        }
    }
    cout << endl
         << resultado << endl;
    return resultado;
}

string resultado(string expresion)
{
    cout << "Entro a resultado\n";

    int top = -1;
    string op1;
    string op2;
    string solucion[TAMANO];
    for (int i = 0; i < expresion.length(); i++)
    {
        if (expresion[i] >= 'a' && expresion.length() <= 'z')
        {
            top++;
            solucion[top] = expresion[i];
        }
        else if (expresion[i] == '^' || expresion[i] == '*' || expresion[i] == '/' || expresion[i] == '+' || expresion[i] == '-')
        {

            op2 = solucion[top];
            solucion[top] = ' ';
            top--;

            if (top > -1)
            {

                op1 = solucion[top];
                solucion[top] = ' ';
                top--;
            }
string Op1="";
string Op2="";
            switch (expresion[i])
            {
            case '^':
                top++;
             Op1 = diferencia(op1,op2);
             Op2 = diferencia(op2,op1);
             solucion[top] = Union(Op1, Op2);
                break;
            case '*':
                top++;
                solucion[top] = interseccion(op1, op2);
                break;
            case '/':
                top++;
                break;
            case '+':
                top++;
                solucion[top] = Union(op1, op2);

                break;
            case '-':
                top++;
                solucion[top] = diferencia(op1, op2);
                break;
            default:
                break;
            }
        }
    }
    mostrarConjunto(solucion[top]);
    return solucion[top];
}

string Union(string op1, string op2)
{
    Nodo *aux = inicio;
    Nodo *aux2 = NULL;
    Nodo *aux3 = NULL;
    string nom = "";
    nom.append(op1);
    nom.append("+");
    nom.append(op2);
    Nodo *nuevo = new Nodo();
    nuevo->nombre = nom;
    cout << endl
         << nuevo->nombre << endl;
    system("pause");
    while (aux != NULL)
    {
        if (aux->nombre == op1)
        {
            aux2 = aux;
            if (nuevo == NULL)
            {
                aux2 = aux2->siguiente;
                Nodo *auxx = nuevo;
                while (aux2 != NULL)
                {
                    Nodo *n = new Nodo();
                    n->dato = aux2->dato;
                    auxx->siguiente = n;
                    auxx = auxx->siguiente;
                    aux2 = aux2->siguiente;
                }
            }
            else
            {
                aux3 = nuevo;
                while (aux3->siguiente != NULL)
                {
                    aux3 = aux3->siguiente;
                }
                aux2 = aux2->siguiente;
                while (aux2 != NULL)
                {
                    Nodo *n = new Nodo();
                    n->dato = aux2->dato;
                    aux3->siguiente = n;
                    aux3 = aux3->siguiente;
                    aux2 = aux2->siguiente;
                }
            }
        }
        else if (aux->nombre == op2)
        {
            aux2 = aux;
            if (nuevo == NULL)
            {
                aux2 = aux2->siguiente;
                Nodo *auxx = nuevo;
                while (aux2 != NULL)
                {
                    Nodo *n = new Nodo();
                    n->dato = aux2->dato;
                    auxx->siguiente = n;
                    auxx = auxx->siguiente;
                    aux2 = aux2->siguiente;
                }
            }
            else
            {
                aux3 = nuevo;
                while (aux3->siguiente != NULL)
                {
                    aux3 = aux3->siguiente;
                }
                aux2 = aux2->siguiente;
                while (aux2 != NULL)
                {
                    Nodo *n = new Nodo();
                    n->dato = aux2->dato;
                    aux3->siguiente = n;
                    aux3 = aux3->siguiente;
                    aux2 = aux2->siguiente;
                }
            }
        }
        aux = aux->siguienteConjunto;
    }
    cola->siguienteConjunto = nuevo;
    cola = nuevo;
    return nuevo->nombre;
}

string interseccion(string op1, string op2)
{
    cout << "entro interseccion\n";
    Nodo *aux = inicio;
    Nodo *aux2 = NULL;
    Nodo *aux3 = NULL;
    string nom = "";

    nom.append(op1);
    nom.append("*");
    nom.append(op2);

    Nodo *nuevo = new Nodo();
    nuevo->nombre = nom;
    cola->siguienteConjunto = nuevo;
    cola = nuevo;
    cout << endl
         << nuevo->nombre << endl;
    system("pause");
    while (aux != NULL)
    {
        if (aux->nombre == op1)
        {
            aux2 = aux;

            if (nuevo->siguiente == NULL)
            {
                aux2 = aux2->siguiente;
                Nodo *auxx = nuevo;
                while (aux2 != NULL)
                {

                    if (numerosRepetidos(aux2->dato, op2))
                    {
                        Nodo *n = new Nodo();
                        n->dato = aux2->dato;
                        auxx->siguiente = n;
                        auxx = auxx->siguiente;
                        aux2 = aux2->siguiente;
                    }
                    else
                    {
                        aux2 = aux2->siguiente;
                    }
                }
            }
            else
            {
                aux3 = nuevo;
                while (aux3->siguiente != NULL)
                {
                    aux3 = aux3->siguiente;
                }
                aux2 = aux2->siguiente;
                while (aux2 != NULL)
                {
                    Nodo *n = new Nodo();
                    if (numerosRepetidos(aux2->dato, nom))
                    {
                        n->dato = aux2->dato;
                        aux3->siguiente = n;
                        aux3 = aux3->siguiente;
                        aux2 = aux2->siguiente;
                    }
                    else
                    {
                        aux2 = aux2->siguiente;
                    }
                }
            }
        }

        aux = aux->siguienteConjunto;
    }

    return nuevo->nombre;
}

string diferencia(string op1, string op2)
{
    cout << "entro interseccion\n";
    Nodo *aux = inicio;
    Nodo *aux2 = NULL;
    Nodo *aux3 = NULL;
    string nom = "";

    nom.append(op1);
    nom.append("-");
    nom.append(op2);

    Nodo *nuevo = new Nodo();
    nuevo->nombre = nom;
    cola->siguienteConjunto = nuevo;
    cola = nuevo;
    cout << endl
         << nuevo->nombre << endl;
    system("pause");
    while (aux != NULL)
    {
        if (aux->nombre == op1)
        {
            aux2 = aux;

            if (nuevo->siguiente == NULL)
            {
                aux2 = aux2->siguiente;
                Nodo *auxx = nuevo;
                while (aux2 != NULL)
                {

                    if (numerosRepetidos(aux2->dato, op2))
                    {
                        aux2 = aux2->siguiente;
                    }
                    else
                    {
                        Nodo *n = new Nodo();
                        n->dato = aux2->dato;
                        auxx->siguiente = n;
                        auxx = auxx->siguiente;
                        aux2 = aux2->siguiente;
                    }
                }
            }
            else
            {
                aux3 = nuevo;
                while (aux3->siguiente != NULL)
                {
                    aux3 = aux3->siguiente;
                }
                aux2 = aux2->siguiente;
                while (aux2 != NULL)
                {
                    Nodo *n = new Nodo();
                    if (numerosRepetidos(aux2->dato, nom))
                    {
                        n->dato = aux2->dato;
                        aux3->siguiente = n;
                        aux3 = aux3->siguiente;
                        aux2 = aux2->siguiente;
                    }
                    else
                    {
                        aux2 = aux2->siguiente;
                    }
                }
            }
        }

        aux = aux->siguienteConjunto;
    }

    return nuevo->nombre;
}

