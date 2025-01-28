int main()
{
    // Inizializzazione dei node
    struct node *testa;
    struct node *nodo1 = NULL;
    struct node *nodo2 = NULL;
    struct node *nodo3 = NULL;

    // Alloca lo spazione necessario nello HEAP
    nodo1 = malloc(sizeof(struct node));
    nodo2 = malloc(sizeof(struct node));
    nodo3 = malloc(sizeof(struct node));

    // Utilizzare l'arrow operator per andare a definire i niostri nodi
    nodo1->data = 17;
    nodo2->data = 86;
    nodo3->data = 53;

    // Collego i nodi tra di loro
    nodo1->next = nodo2;
    nodo2->next = nodo3;
    nodo3->next = NULL;

    testa = nodo1;

    return 0;
}
