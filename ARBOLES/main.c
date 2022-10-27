#include <stdio.h>
#include <stdlib.h>

typedef int telemento;

typedef struct nodoArbol
{
    telemento dato;
    struct nodoArbol*izq;
    struct nodoArbol*der;
}nodoArbol;

nodoArbol* crearNodo (telemento dato);
//RECORRIDOS DE ARBOLES
void preorder (nodoArbol*arbolito);
void inorder (nodoArbol*arbolito);
void posorder (nodoArbol*arbolito);
int contarNodos (nodoArbol*arbolito);
int contarNodos2 (nodoArbol*arbolito);



int main()
{
   nodoArbol*arbolito = NULL; //inicializo
   //cargo datos a mano
   arbolito = crearNodo(25);
   //cargo subarbol izquierdo
   arbolito->izq = crearNodo(13);
   arbolito->der = crearNodo(46);
   arbolito->izq->izq = crearNodo(12);
   arbolito->izq->der= crearNodo(14);
   //cargo subarbol derecho
   arbolito->der->izq = crearNodo(44);
   arbolito->der->der= crearNodo(68);
   arbolito->der->der->izq= crearNodo(67);

   printf("%i", contarNodos2(arbolito)); //funciona

    return 0;
}


nodoArbol* crearNodo (telemento dato)
{
    nodoArbol*nuevo=(nodoArbol*)malloc(sizeof(nodoArbol));
    nuevo->dato=dato;
    nuevo->der=NULL;
    nuevo->izq=NULL;
    return nuevo;
}

/*      RECORRIDOS
preorder: visito, izq, der
inorder: izq, visito, der
posorder: izq, der, visito
 */

void preorder (nodoArbol*arbolito)
{
    if(arbolito!=NULL)
    {
        printf("%i", arbolito->dato);
        preorder(arbolito->izq);
        preorder(arbolito->der);
    }
}

void inorder (nodoArbol*arbolito)
{
    if(arbolito!=NULL)
    {
        inorder(arbolito->izq);
        printf("%i", arbolito->dato);
        inorder(arbolito->der);
    }
}

void posorder (nodoArbol*arbolito)
{
    if(arbolito!=NULL)
    {
        posorder(arbolito->izq);
        posorder(arbolito->der);
        printf("%i", arbolito->dato);
    }
}


int contarNodos (nodoArbol*arbolito)
{
    if (arbolito!=NULL) //si hay datos voy sumando 1 mientras recorro
    {
        return 1 + contarNodos(arbolito->izq) + contarNodos(arbolito->der);
    }else
    {
        return 0;
    }
}

//OTRA FORMA ES ESTA Y RETORNO CANTIDAD
int contarNodos2 (nodoArbol*arbolito)
{
    int cantidad=0;
    if (arbolito!=NULL) //si hay datos voy sumando 1 mientras recorro
    {
        cantidad=1;
        cantidad=cantidad+contarNodos(arbolito->izq);
        cantidad=cantidad+contarNodos(arbolito->der);
    }

    return cantidad;
}











