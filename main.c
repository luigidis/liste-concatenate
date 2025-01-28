#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void list_insert(struct node**, int);
void list_display(struct node*);
int list_search(struct node**, int);
void list_delete(struct node**, int);

int main()
{
    // Inizializzazione dei node
    struct node *head = NULL;
    int nodoCercato, nodoCancellato;

    list_insert(&head, 53);
    list_insert(&head, 86);
    list_insert(&head, 17);

    list_display(head);
    list_insert(&head, 12);
    list_display(head);
    
    nodoCercato = 86;
    if (list_search(&head, nodoCercato)) {
        printf("Nodo %d trovato!\n", nodoCercato);
    }
    else
    {
        printf("Nodo %d non trovato\n", nodoCercato);
    }

    nodoCercato = 90;
    if (list_search(&head, nodoCercato)) 
    {
        printf("Nodo %d trovato!\n", nodoCercato);
    }
    else
    {
        printf("Nodo %d non trovato\n", nodoCercato);
    }

    return 0;
}

void list_insert(struct node **head, int new_data)
{
    // Alloco memoria per il nuovo nodo e preparo i suoi campi
    struct node *nuovo = (struct node*)malloc(sizeof(struct node));
    if (nuovo == NULL)
    {
        printf("Errore nell'allocazione di memoria");
        exit(0);
    }
    // Se l'allocazione è andata a buon fine adesso avrò un nuova porzione di memoria dinamica che sarà di dimensioni pari al mio nod
    // Quindi adesso dovrò dargli le proprietà a questo nodo che voglio
    nuovo->data = new_data;
    nuovo->next = (*head);

    // La nuova testa è il nuovo nodo che ho inserito
    (*head) = nuovo;
}

void list_display(struct node *p) {
    printf("\n");

    //In questo modo scorro tutta la lista stampando ogni nodo
    while(p != NULL)
    {
        printf("|%d|-->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int list_search(struct node **head, int ricercato) {
    struct node* current = *head;

    while(current != NULL)
    {
        if (current->data == ricercato)
            return 1;
        
        current = current->next;
    }

    return 0;
}

int list_delete(struct node **head, int key) {
    struct node *tmp = *head;
    struct node *prev = NULL;
    //tmp diverso da NULL vuol dire che nella nostra lista c'è almeno un elemento
    // tmp data = a key vuol dire che il dato della mia testa è ciò che cerco, non mi serve scorrere la lista
    if(tmp != NULL && tmp->data == key) {
        *head = tmp->next; //Cambio il valore della head
        free(tmp); // Libero la memoria in ciò che devo eliminare
        return;
    }

    //Ricerca il nodo da elminare, tenendo traccia del precedente per poter "ricollegare la lista"
    while(tmp != NULL && tmp->data != key) {
        prev = temp;
        tmp = tmp->next;
    }

    //Quando esco da while posso avere due casi
    //Ho scorso tutta la lista e non ho trovato il valore OPPURE ho trovato il valore

    //Ho scroso tutta la lista sono arrivato a NULL
    if (tmp == NULL) {
        return; //Non trovato nessun valore uguale a quel dato
    }

    //ALtrimenti quello che faccio è
    prev->next = tmp->next;
    free(tmp);
    
}
