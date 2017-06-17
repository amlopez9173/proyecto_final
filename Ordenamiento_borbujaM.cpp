#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define reservar_memoria (Nodo *)malloc(sizeof(Nodo))

struct nodo{
    int dato;
    nodo *sig;
};

struct Nodo{
	int dato;
	Nodo *derecho;
	Nodo *izquierdo;
};
void insertarElementosArbol(Nodo *&Arbol, int n);
void imprimirArbol(Nodo *Arbol);
void insertar(nodo *&,nodo *&,int);
void imprimir(nodo *);
//void ordenar_lista(nodo *);
Nodo *Arbol = NULL;
nodo *cabeza=NULL, *cola=NULL;

int main(){
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
    strftime(output,128,"%H:%M:%S",tlocal);
    Nodo *Arbol = NULL;
    nodo *cabeza=NULL, *cola=NULL;
    FILE *archivo;
    archivo=fopen("archivo_numeros.txt","w");

    int i=0, n,cont=0;
    char numero[7];
    srand(time(NULL));

    while(i<10){
        n=rand() % (59998+1)-29999;
        sprintf(numero,"%d",n);
        fputs(numero,archivo);
        putc(',',archivo);
        insertarElementosArbol(Arbol,n);
        //insertar(cabeza,cola,n);
        i++;
    }

    printf("%s\n\n",output);
    printf("\n\n");
    printf("numeros ordenados\n");
    imprimirArbol(Arbol);

    //ordenar_lista(cabeza);
    printf("\n\n");
    //imprimir(cabeza);
    printf("\n%s\n",output);

    return 0;
}

void insertarElementosArbol(Nodo *&Arbol, int n){
	int valorRaiz,m;
	if(Arbol == NULL){
		Nodo *nuevoNodo = reservar_memoria;
		nuevoNodo -> dato = n;
		nuevoNodo -> izquierdo = NULL;
		nuevoNodo -> derecho = NULL;
		Arbol = nuevoNodo;
	}else{
		valorRaiz = Arbol -> dato;
		if(n > valorRaiz){
			insertarElementosArbol(Arbol -> derecho, n);
		}else{
			insertarElementosArbol(Arbol -> izquierdo, n);
        }
	}
}

void imprimirArbol(Nodo *Arbol){
     FILE *archivo;
    archivo=fopen("archivo_numeros10.txt","w");
     char numero[7];
    if(Arbol==NULL){
        return;
    }else{
        imprimirArbol(Arbol->izquierdo);
        sprintf(numero,"%d",Arbol->dato);
        fputs(numero,archivo);
        putc(',',archivo);
        printf("%d ",Arbol->dato);
        imprimirArbol(Arbol->derecho);
    }
    sprintf(numero,"%d",Arbol->dato);
        fputs(numero,archivo);
        putc(',',archivo);
}

void insertar(nodo *&cabeza, nodo *&cola, int n){
    nodo *nuevo=(nodo*)malloc(sizeof(nodo));
    nuevo->dato=n;
    nuevo->sig=NULL;
    if(cabeza==NULL){
        cabeza=nuevo;
        cola=cabeza;
    }else{
        cola->sig=nuevo;
        cola=nuevo;
    }
}

void imprimir(nodo *cabeza){
    if(cabeza!=NULL){
        nodo *actual=(nodo*)malloc(sizeof(nodo));
        actual=cabeza;
        while(actual!=NULL){
            printf("%d, ",actual->dato);
            actual=actual->sig;
        }
    }else{
        printf("La lista esta vacia\n");
    }
}

/*void ordenar_lista(nodo *cabeza){
    if(cabeza != NULL){
		nodo *p=(nodo*)malloc(sizeof(nodo));
		nodo *j=(nodo*)malloc(sizeof(nodo));
		int aux;
		p = cabeza;
		while(p != NULL){
			j = p -> sig;
			while(j != NULL){
				if(p -> dato > j -> dato){
					aux = j -> dato;
					j -> dato = p -> dato;
					p -> dato = aux;
				}
				j = j -> sig;
			}
			p = p -> sig;
		}
	}else{
		printf("La lista esta vacia");
	}
}*/

