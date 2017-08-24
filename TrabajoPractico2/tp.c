#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
La idea es construir un menú que permite ingresar el grafo y construya la multilista y
luego insertar un vertice con sus aristas,
eliminar un vertice, calcular el grado de cada vertice y determinar si es completo.
*/

typedef struct node {
    int data;
    struct node *sig;
    struct subnode *sublista;
}node;

typedef struct subnode {
    int data;
    struct subnode *sig;
}subnode;

struct node *raiz = NULL;



node *borrarSubLista(node *cabeza){
    if (cabeza->sublista == NULL)
        return cabeza;

    subnode *subtemp = cabeza->sublista;
    cabeza->sublista = subtemp->sig;
    free(subtemp);
    cabeza = borrarSubLista(cabeza);
    return cabeza;
}

subnode *borrarNodoSubLista(subnode *cabeza, int valor){
    if (cabeza == NULL)
        return cabeza;

    printf("data: %c == valor: %c \n", cabeza->data, valor);
    if (cabeza->data == valor) {
        subnode *subtemp = cabeza->sig;
        free(cabeza);
        return subtemp;
    }
    cabeza->sig = borrarNodoSubLista(cabeza->sig, valor);
    return cabeza;
}

node *borrarNodo(node *cabeza,int valor) {

  if (cabeza == NULL)
    return NULL;

  if (cabeza->data == valor) {
    node *temp;

    temp = cabeza->sig;
    cabeza = borrarSubLista(cabeza);
    free(cabeza);
    return temp;
  }
  cabeza->sig = borrarNodo(cabeza->sig, valor);

  return cabeza;
}

void borrarArista(int valor){
    node *aux = raiz;

    while(aux != NULL){
        printf("aux->data: %c  \n",aux->data);
        subnode *subaux = aux->sublista;
        aux->sublista = borrarNodoSubLista(subaux,valor);
        aux = aux->sig;
    }

}

bool opcionValida(int a){
    if(a < 96 || a > 123){
        printf("\n  La opcion debe estar entre [a...z]: ");
        return true;
    }
    return false;
}

int menu(){
		int opcion = 0;
		while(opcion < 1 || opcion > 7)
		{
            printf("\n  -------------- MENU --------------  \n");
            printf("  1. Crear grafo\n");
            printf("  2. Mostrar lista \n");
            printf("  3. Agregando un vertice \n");
            printf("  4. Remover un vertice \n");
            printf("  5. Determinar si es completo \n");
            printf("  6. Borrar lista\n");
            printf("  7. Salir\n");
            printf("  ----------------------------------  \n");
            printf("  Seleccione una opcion [1 - 7]:      ");
            scanf("%i",&opcion);
		}
		return opcion;

}

void mostrar() {

    node *aux = raiz;
    subnode *subaux;
    printf("\n  El Grafo:\n [ \n");
    while(aux != NULL) {
        subaux = aux->sublista;
        printf("(%c) ",aux->data);
        while(subaux != NULL) {
            printf("=(%c)",subaux->data);
            subaux= subaux->sig;
        }
        printf("\n");
        aux = aux->sig;
    }
    printf(" ]\n");

}

void insertar(int data) {
    node *link = (struct node*) malloc(sizeof(struct node));
    link->data = data;
    link->sig = NULL;
    link->sublista = NULL;

    if(raiz == NULL){

        raiz = link;
    }else{
        node *aux = raiz;
        while(aux->sig != NULL ) {
            aux = aux->sig;
        }
        aux->sig = link;
    }
}

bool esVacio() {
   return raiz == NULL;
}

int longitud() {
   int longitud = 0;
   node *aux;

   for(aux = raiz; aux != NULL; aux = aux->sig) {
      longitud++;
   }

   return longitud;
}

void insertarArista(int data, node *cabeza){

    subnode *subaux = (struct subnode*) malloc(sizeof(struct subnode));
    subaux->data = data;
    subaux->sig = NULL;

    if(cabeza->sublista == NULL){
        cabeza->sublista = subaux;
    }else{
        struct subnode *subauxbis = cabeza->sublista;
        while (true) {
            if(subauxbis->sig == NULL)
            {
                subauxbis->sig = subaux;
                break;
            }
            subauxbis = subauxbis->sig;
        }
    }
}

bool buscar(int valor){

    struct node* aux = raiz;
    if(raiz == NULL) {
        return false;
    }

    while(aux->data != valor) {
        if(aux->sig == NULL) {
            return false;
        }
        aux = aux->sig;
    }
    return true;
}

struct node* buscarNodo(int valor){
    struct node* aux = raiz;
    if(raiz == NULL) {
        return NULL;
    }
    while(aux->data != valor) {
        if(aux->sig == NULL) {
            return NULL;
        }
        aux = aux->sig;
    }
    return aux;
}


int contarSubLista(int valor, struct node *cabeza){
    int count = 0;
    struct subnode* aux = cabeza->sublista;
    while(aux != NULL) {
        if(aux->data == valor) {
            count++;
        }
        aux = aux->sig;
    }

    return count;
}


bool validarCompleto(int head){
    int count = 0;
    subnode *aux = buscarNodo(head)->sublista;
    while(aux != NULL){
        if(contarSubLista(aux->data,buscarNodo(head))!= 1){
            return false;
        }

        if(!buscar(aux->data)){
            return false;
        }
        count++;
        aux = aux->sig;
    }

    //valido que tengo n-1 de tamño la sublista
    if(count != (longitud()-1)){
        return false;
    }

    return true;
}

void removerArista(){
    // buscar si el vertice existe en la lista
    // remover este vertice de la lista
    int a;
    printf("\n  Ingrese el vertice a eliminare: ");
    do{
        a = getchar();
        fflush(stdin);
    }while(opcionValida(a) || !buscar(a));

    raiz = borrarNodo(raiz,a);
    borrarArista(a);


}

void esCompleto(){
    node *aux = raiz;
    bool completo = true;

    if(longitud() == 1){
        printf("  ***No es completo***");
        return;
    }

    while(aux != NULL){
        completo = validarCompleto(aux->data);
        if(!completo){
            printf("  ***No es completo***");
            return;
        }
        aux = aux->sig;
    }

    printf("  ***Es completo***");
}


struct node* borrar(int valor){

   struct node* aux = raiz;
   struct node* anterior = NULL;

   if(raiz == NULL) {
      return NULL;
   }
   while(aux->data != valor) {

      if(aux->sig == NULL) {
         return NULL;
      } else {
         anterior = aux;
         aux = aux->sig;
      }
   }
   if(aux == raiz) {
      raiz = raiz->sig;
   } else {
      anterior->sig = aux->sig;
   }
   return aux;
}

void crearArista(int a){

    int tam, n;
    node* aux = buscarNodo(a);
    printf("\n  Con cuantos vertices se conecta %c?: ", aux->data);
    scanf("%d", &tam);
    fflush(stdin);
    for( n=0;  n < tam; n++){
        printf("\n  Ingresar el vertice numero %d: ",(n+1));
        do{
            printf("  ");
            a = getchar();
            fflush(stdin);
        }while(opcionValida(a) || !buscar(a));
        insertarArista(a,aux);
        if(a != aux->data){
            insertarArista(aux->data,buscarNodo(a));
        }
    }
}

void crearVertice(){
    int a;
    fflush(stdin);
    printf("\n  Ingrese una letra [a...z] para identificar el vertice: ");
    do{ //97
        a = getchar();
        fflush(stdin);
    }while(opcionValida(a) || buscar(a));
    insertar(a);
    crearArista(a);
}


void cargandoAristas(){
    int tam= -1,a = 0, n;
    node* aux = raiz;

    while(aux != NULL){
        printf("\n  Con cuantos vertices se conecta %c?: ", aux->data); // preguntas cuantas aristas conecta este vertice
        scanf("%d", &tam); // tam = 3
        fflush(stdin);
        for( n=0;  n < tam; n++){
            printf("\n  Ingresar el vertice numero %d: ",(n+1));
            do{
                printf("  ");
                a = getchar();
                fflush(stdin);
            }while(opcionValida(a) || !buscar(a));
            insertarArista(a,aux);
        }
        aux = aux->sig;
    }
}

void creandoGrafo(){
    int tam,i,a = 0;
    printf("\n  Elegir cuantos vertices tiene el grafo: ");
    scanf("%d", &tam);
    fflush(stdin);
    for(i = 0; i < tam; i++ ){
        printf("\n  Ingrese una letra [a...z] para el vertice (%d): ", (i+1));
        do{ //97
            a = getchar();
            fflush(stdin);
        }while(opcionValida(a) || buscar(a)); // correct seleccion seria un valor numerico entre 96 y 123 menos los numeros ya ingresados
        insertar(a);
    }
}

void borrarLista(){
   struct node* aux;
   while (raiz != NULL){
       aux = raiz;
       raiz = raiz->sig;
       free(aux);
    }
}


int main(){

    int opcion;
	do {

	    opcion = menu();
		switch (opcion){

            case 1 :
                printf("  Creando Grafo...");
                if(raiz == NULL){
                   creandoGrafo();
                   cargandoAristas();
                }else{
                    printf(  "  El grafo ya existe");
                }
                printf(  "  \n");
                break;
            case 2 :
                printf(  "  Mostrando Grafo...");
                printf(  "  \n");

                if(esVacio()){
                     printf(  "  El grafo esta vacio debe crear uno, opcion 1\n");
                }else{
                    mostrar();
                }
                break;
            case 3 :
                printf("  Agregando un vertice...");
                printf(  "  \n");
                crearVertice();
                break;
            case 4 :
                printf("  Remover un vertice...");
                printf(  "  \n");
                removerArista();
                break;
            case 5 :
                printf("  Determinar si es completo...");
                printf(  "  \n");
                esCompleto();
                break;
            case 6 :
                printf("  Borrando Lista...");
                borrarLista();
                printf(  "  \n");
                break;
             case 7 :
                printf("  Saliendo...");
                printf(  "  \n");
                break;
            default:
                printf("  La opcion %d, no existe elegir un valor entre (1-6) \n", opcion );
                printf(  "  \n");
                break;

        }
       // sleep(1);
	}while(opcion != 7);

    return 0;
}
