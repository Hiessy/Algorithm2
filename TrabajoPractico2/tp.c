#include <stdio.h>
#include <stdlib.h>


/*
La idea es construir un menú que permite ingresar el grafo y
construya la multilista y
luego insertar un vertice con sus aristas,
eliminar un vertice,
calcular el grado de cada vertice y determinar si es completo.
*/

typedef struct Node
{
        char data;
        struct Node *next;
        struct SubNode *subnext;
}node;

typedef struct SubNode
{
        char data;
        struct Node *next;
}subnode;

void insertar(node *pointer, char data)
{
        /* Iterate through the list till we encounter the last node.*/
        while(pointer->next!=NULL)
        {
                pointer = pointer -> next;
        }
        /* Allocate memory for the new node and put data in it.*/
        pointer->next = (node *)malloc(sizeof(node));
        pointer = pointer->next;
        pointer->data = data;
        pointer->next = NULL;
}
int find(node *pointer, char key)
{
        pointer =  pointer -> next; //First node is dummy node.
        /* Iterate through the entire linked list and search for the key. */
        while(pointer!=NULL)
        {
                if(pointer->data == key) //key is found.
                {
                        return 1;
                }
                pointer = pointer -> next;//Search in the next node.
        }
        /*Key is not found */
        return 0;
}
void delete(node *pointer, char data)
{
        /* Go to the node for which the node next to it has to be deleted */
        while(pointer->next!=NULL && (pointer->next)->data != data)
        {
                pointer = pointer -> next;
        }
        if(pointer->next==NULL)
        {
                printf("Element %d is not present in the list\n",data);
                return;
        }
        /* Now pointer points to a node and the node next to it has to be removed */
        node *temp;
        temp = pointer -> next;
        /*temp points to the node which has to be removed*/
        pointer->next = temp->next;
        /*We removed the node which is next to the pointer (which is also temp) */
        free(temp);
        /* Beacuse we deleted the node, we no longer require the memory used for it .
           free() will deallocate the memory.
         */
        return;
}
void print(node *pointer)
{
        if(pointer==NULL)
        {
                return;
        }
        printf("%c ",pointer->data);
        print(pointer->next);
}
int main()
{
        /* start always points to the first node of the linked list.
           temp is used to point to the last node of the linked list.*/
        node *start; //,*temp;
        start = (node *)malloc(sizeof(node));
     /*   temp = start;
        temp -> next = NULL;*/
        /* Here in this code, we take the first node as a dummy node.
           The first node does not contain data, but it used because to avoid handling special cases
           in insert and delete functions.
         */


        printf("Creando Grafo, ingresar el tamano: ");
        int o,n;
        scanf("%d",&n);
        fflush(stdin);

        for(o = 0; o < n; o++){
            printf("ingresar el character que idenfica al vertice numero %d: ", (o+1));
            fflush(stdin);
            insertar(start,getchar());
        }

    print(start);
}

