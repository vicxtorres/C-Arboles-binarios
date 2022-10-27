#include <stdio.h>
#include <stdlib.h>

typedef int telemento;

///STRUCT DE NODO ARBOL
typedef struct nodoArbol
{
    telemento dato;
    struct nodoArbol*izq;
    struct nodoArbol*der;
}nodoArbol;

///PROTOTIPADOS
nodoArbol* crearNodo (telemento dato);
void preorder (nodoArbol*arbolito);
void inorder (nodoArbol*arbolito);
void posorder (nodoArbol*arbolito);
int contarNodos (nodoArbol*arbolito);
int contarNodos2 (nodoArbol*arbolito);


int main()
{
   nodoArbol*arbolito = NULL; //inicializo
    
   /*** cargo datos a mano: a la derecha van los mayores, a la izquierda los menores ***/
    
   arbolito = crearNodo(25); //25 es mi raiz
   //cargo subarbol izquierdo:
   arbolito->izq = crearNodo(13);
   arbolito->izq->izq = crearNodo(12);
   arbolito->izq->der= crearNodo(14);
   //cargo subarbol derecho:
   arbolito->der = crearNodo(46);
   arbolito->der->izq = crearNodo(44);
   arbolito->der->der= crearNodo(68);
   arbolito->der->der->izq= crearNodo(67);

   printf("%i", contarNodos2(arbolito)); 

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

/*  RECORRIDOS (recursivos)  
    preorder: visito, izq, der
    inorder: izq, visito, der         *solo van cambiando el orden de las lineas*      
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


///OTRAS FUNCIONES
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











