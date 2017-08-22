#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
La idea es construir un menú que permite ingresar el grafo y construya la multilista y luego insertar un vertice con sus aristas,
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
struct node *current = NULL;

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

    int size = length();

    printf("\n  El Grafo: [ ");

    //start from the beginning
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
// insertar el nodo principal
void insertar(char data) {
   //create a link
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->data = data;
    link->next = NULL;
    link->,.klñ = NULL;
    //FALTA VALIDAR SI ES EL PRIMERO
    if(raiz == NULL){
   //point first to new first node
        raiz = link;
    }else{
        struct node *aux = raiz;
        while(aux->next != NULL ) {
            aux = aux->next;
        }
        aux->next = link;
    }
}
//delete first item
struct node* borrarNodo() {
   struct node *temp = raiz;
   raiz = raiz->next;
   return temp;
}
//is list empty
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
void insertarArista(struct subnode *lista, char data){

    struct subnode *sublist = (struct subnode*) malloc(sizeof(struct subnode));
    sublist->data = data;
    sublist->next = NULL;
    subnode *aux = lista;
    if(aux == NULL){
        aux = sublist;
    }else{
        while(aux->next != NULL ) {
            aux = aux->next;
        }
        aux->next = sublist;
    }
}
bool buscar(int key){

    struct node* current = raiz;
    if(raiz == NULL) {
        printf("\n  La lista esta vacia ");
        return false;
    }

    while(current->data != key) {
        if(current->next == NULL) {
            printf("\n  No se encontro el vertice (%c) en la lista ", key);
            return false;
        }
        current = current->next;
    }
    printf("\n  Se encontro el vertice (%c) ", key);
    return true;
}

bool buscarSubLista(int key){

    struct subnode* aux = raiz->sublista;
    if(aux == NULL) {
        printf("\n  La Sublista esta vacia");
        return false;
    }

    while(aux->data != key) {
        if(aux->next == NULL) {
            printf("\n  No se encontro el vertice (%c) en la sublista", key);
            return false;
        }
        aux = aux->next;
    }
    printf("\n  Se encontro el vertice (%c) ", key);
    return true;
}
//delete a link with given key
struct node* borrar(int key){

   //start from the first link
   struct node* current = raiz;
   struct node* previous = NULL;

   //if list is empty
   if(raiz == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->data != key) {

      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }

   //found a match, update the link
   if(current == raiz) {
      //change first to point to next link
      raiz = raiz->next;
   } else {
      //bypass the current link
      previous->next = current->next;
   }

   return current;
}

void sort(){

   int i, j, k, tempData;
   struct node *current;
   struct node *next;

   int size = length();
   k = size ;

   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = raiz;
      next = raiz->next;

      for ( j = 1 ; j < k ; j++ ) {

         if ( current->data > next->data ) {
            tempData = current->data;
            current->data = next->data;
            next->data = tempData;
         }

         current = current->next;
         next = next->next;
      }
   }
}

bool opcionValida(int a){
    if(a < 96 || a > 123){ // a = 97
        printf("\n  La opcion debe estar entre [a...z]: ");
        return true;
    }
    return false;
}

void creandoAristas(){
    int size= -1,i = length(),a = 0, n;
    struct node* aux = raiz;

    while(aux != NULL){

        do{
            printf("\n  Con cuantos vertices se conecta %c? (No debe ser mayor a %d): ", aux->data, (i-1)); // preguntas cuantas aristas conecta este vertice
            scanf("%d", &size); // size = 3
            fflush(stdin);
        }while(size > (i-1)); // size=-3

        for( n=0;  n < size; n++){
            printf("\n  Ingresar el vertice numero %d: ",(n+1));
            do{
                printf("  ");
                a = getchar();
                fflush(stdin);
                printf("\n  %d",size);
            }while(opcionValida(a) || (a) == (aux->data) || buscarSubLista(a) || !buscar(a)); // Tres validaciones, es un char valido, no es raiz, no se eleigio ya

            insertarArista(aux->sublista,a); // que sea unico el valor
            mostrarSubList(aux->sublista);
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
        insertar(a); // que sea unico el valor
    }
    creandoAristas();

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



//   insertFirst(1,10);
//   insertFirst(2,20);
//   insertFirst(3,30);
//   insertFirst(4,1);
//   insertFirst(5,40);
//   insertFirst(6,56);
//
//   printf("Original List: ");
//
//   //print list
//   printList();
//
//   while(!isEmpty()) {
//      struct node *temp = deleteFirst();
//      printf("\nDeleted value:");
//      printf("(%d,%d) ",temp->key,temp->data);
//   }
//
//   printf("\nList after deleting all items: ");
//   printList();
//   insertFirst(1,10);
//   insertFirst(2,20);
//   insertFirst(3,30);
//   insertFirst(4,1);
//   insertFirst(5,40);
//   insertFirst(6,56);
//
//   printf("\nRestored List: ");
//   printList();
//   printf("\n");
//
//   struct node *foundLink = find(4);
//
//   if(foundLink != NULL) {
//      printf("Element found: ");
//      printf("(%d,%d) ",foundLink->key,foundLink->data);
//      printf("\n");
//   } else {
//      printf("Element not found.");
//   }
//
//   delete(4);
//   printf("List after deleting an item: ");
//   printList();
//   printf("\n");
//   foundLink = find(4);
//
//   if(foundLink != NULL) {
//      printf("Element found: ");
//      printf("(%d,%d) ",foundLink->key,foundLink->data);
//      printf("\n");
//   } else {
//      printf("Element not found.");
//   }
//
//   printf("\n");
//   sort();
//
//   printf("List after sorting the data: ");
//   printList();
//
//   reverse(&raiz);
//   printf("\nList after reversing the data: ");
//   printList();
}
