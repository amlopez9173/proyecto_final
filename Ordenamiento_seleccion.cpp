#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo{
    int dato;
    nodo *sig;
};

void insertar(nodo *&,nodo *&,int);
void imprimir(nodo *);
void ordenar_lista(nodo *);
void buscar(nodo *);

int main(){
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
    strftime(output,128,"%H:%M:%S",tlocal);

    nodo *cabeza=NULL, *cola=NULL;

    FILE *archivo;
    archivo=fopen("archivo_numeros2.txt","w");

    int i=0, n;
    char numero[7];
    srand(time(NULL));

    while(i<10){
        n=rand() % (19998+1)-9999;
        sprintf(numero,"%d",n);
        fputs(numero,archivo);
        putc(',',archivo);
        insertar(cabeza,cola,n);
        i++;
    }

    printf("%s\n\n",output);
    imprimir(cabeza);
    printf("\nOrdenados\n");
    ordenar_lista(cabeza);
    imprimir(cabeza);
    printf("\n%s\n",output);
    buscar(cabeza);

    return 0;
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

void ordenar_lista(nodo *cabeza){
    if(cabeza != NULL){
		nodo *p=(nodo*)malloc(sizeof(nodo));
		nodo *j=(nodo*)malloc(sizeof(nodo));
		int aux, minimo;
		p=cabeza;
		while(p!=NULL){
            minimo=p->dato;
            j=p;
            while(j!=NULL){
                if(minimo>j->dato){
                    minimo=j->dato;
                    aux=p->dato;
                    p->dato=minimo;
                    j->dato=aux;
                }
                j=j->sig;
            }
            p=p->sig;
		}

	}else{
		printf("La lista esta vacia");
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

void buscar(nodo *cabeza){
    int a;
    if(cabeza!=NULL){
            int c=0;
            printf("Ingrese dato que desea buscar: ");
            scanf("%d",&a);
            nodo *aux=cabeza;
            while(aux!=NULL){
                if(aux->dato==a){
                    printf("El numero %d esta en la lista\n",aux->dato);
                    c++;
                }
                aux=aux->sig;
            }
            if(c==0){
                printf("El numero no se encuentra en la lista\n");
            }
        }
        else{
            printf("La lista esta vacia\n");
        }
}


