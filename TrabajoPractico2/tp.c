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
    char data;
    struct node *next;
    struct subnode *sublista;
}node;

typedef struct subnode {
    char data;
    struct subnode *next;
}subnode;

struct node *raiz = NULL;

int menu(){
		int opcion = 0;
		while(opcion < 1 || opcion > 7)
		{
            printf("\n  -------------- MENU --------------  \n");
            printf("  1. Crear grafo\n"); // preguntar cuantos nodos -- asignarle un valor a cada nodo -- determinar que nodo esta conectado con que otro nodo
            printf("  2. Mostrar grafo \n");
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
//display the list

void mostrarSubList(struct subnode *lista){
    struct subnode *sbl = lista;
    while(sbl != NULL) {
            printf("=(%c)",sbl->data);
            sbl= sbl->next;
        }
}
void mostrar() {

    struct node *ptr = raiz;
    struct subnode *sbl;
    printf("\n  El Grafo:\n [ \n");
    while(ptr != NULL) {
        sbl = ptr->sublista;
        printf("(%c) ",ptr->data);
        while(sbl != NULL) {
            printf("=(%c)",sbl->data);
            sbl= sbl->next;
        }
        printf("\n");
        ptr = ptr->next;
    }
    printf(" ]\n");

}

void insertar(char data) {
   //create a link
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->data = data;
    link->next = NULL;
    link->sublista = NULL;

    if(raiz == NULL){

        raiz = link;
    }else{
        struct node *aux = raiz;
        while(aux->next != NULL ) {
            aux = aux->next;
        }
        aux->next = link;
    }
}

struct node* borrarNodo() {
   struct node *temp = raiz;
   raiz = raiz->next;
   return temp;
}

bool isEmpty() {
   return raiz == NULL;
}
int length() {
   int length = 0;
   struct node *current;

   for(current = raiz; current != NULL; current = current->next) {
      length++;
   }

   return length;
}
void insertarArista(char data, struct node *cabeza){

    subnode *subnode = (struct subnode*) malloc(sizeof(struct subnode));
    subnode->data = data;
    subnode->next = NULL;

    if(cabeza->sublista == NULL){
        cabeza->sublista = subnode;
    }else{
        struct subnode *current = cabeza->sublista;
        while (true) {
            if(current->next == NULL)
            {
                current->next = subnode;
                break;
            }
            current = current->next;
        };

    }

}
struct node* buscarNodo(char key){
    struct node* current = raiz;
    if(raiz == NULL) {
        printf("La lista esta vacia");
        return NULL;
    }
    while(current->data != key) {
        if(current->next == NULL) {
            printf("El elemento no esta presente");
            return NULL;
        }
        current = current->next;
    }
    return current;
}

bool buscar(int key){

    struct node* current = raiz;
    if(raiz == NULL) {
        return false;
    }

    while(current->data != key) {
        if(current->next == NULL) {
            return false;
        }
        current = current->next;
    }
    return true;
}

int buscarSubLista(int key, struct node *cabeza){
    int count = 0;
    struct subnode* aux = cabeza->sublista;
    while(aux != NULL) {
        if(aux->data == key) {
            count++;
        }
        aux = aux->next;
    }

    return count;
}

struct node* borrar(int key){

   struct node* current = raiz;
   struct node* previous = NULL;

   if(raiz == NULL) {
      return NULL;
   }
   while(current->data != key) {

      if(current->next == NULL) {
         return NULL;
      } else {
         previous = current;
         current = current->next;
      }
   }
   if(current == raiz) {
      raiz = raiz->next;
   } else {
      previous->next = current->next;
   }
   return current;
}

bool opcionValida(int a){
    if(a < 96 || a > 123){
        printf("\n  La opcion debe estar entre [a...z]: ");
        return true;
    }
    return false;
}

int generarAristasAutomaticamente(int size, char key){
    int count = 0;
    node* aux = raiz;
    while(aux != NULL){
        count += buscarSubLista():

    }
}

/*
*** TODO; NEED TO FINISH verificar si el vertices ya definio en algunas de las sublistas
*/
void crearArista(char a){

    int size, n;
    node* aux = buscarNodo(a);
    printf("\n  Con cuantos vertices se conecta %c?: ", aux->data);
    scanf("%d", &size);
    fflush(stdin);
    for( n=0;  n < size; n++){
        printf("\n  Ingresar el vertice numero %d: ",(n+1));
        do{
            printf("  ");
            a = getchar();
            fflush(stdin);
        }while(opcionValida(a) || !buscar(a));
        insertarArista(a,aux);

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


/*
*** TODO; NEED TO FINISH verificar si el vertices ya definio en algunas de las sublistas
*/

void cargandoAristas(){
    int size= -1,a = 0, n;
    node* aux = raiz;

    while(aux != NULL){
        printf("\n  Con cuantos vertices se conecta %c?: ", aux->data); // preguntas cuantas aristas conecta este vertice
        scanf("%d", &size); // size = 3
        fflush(stdin);
        for( n=0;  n < size; n++){
            printf("\n  Ingresar el vertice numero %d: ",(n+1));
            do{
                printf("  ");
                a = getchar();
                fflush(stdin);
            }while(opcionValida(a) || !buscar(a));
            insertarArista(a,aux);
        }
        aux = aux->next;
    }
}

void creandoGrafo(){
    int size,i,a = 0;
    printf("\n  Elegir cuantos vertices tiene el grafo: ");
    scanf("%d", &size);
    fflush(stdin);
    for(i = 0; i < size; i++ ){
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
   while (raiz != NULL)
    {
       aux = raiz;
       raiz = raiz->next;
       free(aux);
    }

}

int main(){

    int opcion;
	do {

	    opcion = menu();
		switch (opcion){

            case 1 :
                printf("  Creando Grafo...", opcion);
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
                if(isEmpty()){
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
                break;
            case 5 :
                printf("  Determinar si es completo...");
                printf(  "  \n");
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


}
