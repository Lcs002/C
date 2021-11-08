// ===============================================  LISTAS DINAMICAS CON NODOS

#include <stdio.h>
#include <stdlib.h>

// =========== STRUCTS

typedef struct Tfecha
{
    unsigned dia, mes, anio;
} FECHA;

typedef struct Tnodo_fecha
{
    FECHA fecha; // contenido tipo fecha
    struct Tnodo_fecha *nxt; // NODO siguiente
    struct Tnodo_fecha *bck; // NODO anterior
} NODO_FECHA;

typedef struct Tlst_fecha
{
    NODO_FECHA *head; // primer NODO
    NODO_FECHA *tail; // ultimo NODO
    unsigned    size; // Tamaño de la lista
} LST_FECHA;

// =========== PROTOTYPE

void scan_fecha      (FECHA *);
void addf_fecha      (FECHA, LST_FECHA*);
void addl_fecha      (FECHA, LST_FECHA*);
void remove_fecha    (unsigned, LST_FECHA *);
void init_lst_fecha  (LST_FECHA *);
void print_lst_fecha (LST_FECHA);


// =========== MAIN

void main()
{
    FECHA fecha; // crear variable tipo FECHA
    LST_FECHA lst_fecha; // crear variable tipo LST_FECHA
    init_lst_fecha(&lst_fecha); // inicializar la lista

    // añadir valores en la lista hasta que el usuario no introduzca un 's'
    do
    {
        scan_fecha(&fecha); // Pedir fehca
        addf_fecha (fecha, &lst_fecha); // Añadir NODO_FECHA al final de la lista con los valores de fecha
        printf    ("\nQuieres seguir añadiendo fechas? (s/n)");
        fflush    (stdin);
    } while(getch() == 's');

    system("cls"); // Limpiar pantalla

    int nodo_index;
    printf("\nRemover nodo (posición) [-1 = no]: ");
    scanf ("%d", &nodo_index);
    if (nodo_index >= 0)
        remove_fecha(nodo_index, &lst_fecha);

    print_lst_fecha(lst_fecha); // Muestra contenido de la lista

    printf("\n\nEl tamano de la lista es: %d", lst_fecha.size); // Muestra tamaño de la lista
}

// =========== FUNCS

void scan_fecha(FECHA * fecha)
{
    printf("\n\ndia? "); scanf("%u", &fecha->dia);
    printf("mes? ");     scanf("%u", &fecha->mes);
    printf("anio? ");    scanf("%u", &fecha->anio);
    fflush(stdin);
}


void init_lst_fecha(LST_FECHA * lst_fecha)
{
    lst_fecha->head = NULL;
    lst_fecha->tail = NULL;
    lst_fecha->size = 0;
}

void addf_fecha (FECHA fecha, LST_FECHA * lst_fecha) // addfirst
{
    NODO_FECHA *new;
    new = malloc( sizeof( NODO_FECHA ) );
    new->fecha = fecha;
    new->nxt   = NULL;
    new->bck   = NULL;

    if (lst_fecha->head == NULL)
    {
        lst_fecha->head = new;
        lst_fecha->tail = new;
    }
    else
    {
        new->nxt = lst_fecha->head;
        new->nxt->bck = new;
        lst_fecha->head = new;
    }
    lst_fecha->size++;
}


void addl_fecha(FECHA fecha, LST_FECHA * lst_fecha) // addlast
{
    NODO_FECHA *new;
    new = malloc( sizeof( NODO_FECHA ) );
    new->fecha = fecha;
    new->nxt   = NULL;
    new->bck   = NULL;
    if (lst_fecha->head == NULL)
    {
        lst_fecha->head = new;
        lst_fecha->tail = new;
    }
    else
    {
        lst_fecha->tail->nxt = new;
        new->bck             = lst_fecha->tail;
        lst_fecha->tail      = new;
    }
    lst_fecha->size++;
}


void remove_fecha(unsigned index, LST_FECHA * lst_fecha)
{
    int i;
    NODO_FECHA * curr_nodo;
    curr_nodo = lst_fecha->head;
    for (i = 0; curr_nodo != NULL && i < index; curr_nodo = &curr_nodo->nxt, i++);
    if (curr_nodo != NULL)
    {
        if (curr_nodo->bck == NULL)
        {
            if (curr_nodo->nxt != NULL)
            {
                curr_nodo->nxt->bck = NULL;
                lst_fecha->head     = curr_nodo->nxt;
            }
            else
            {
                lst_fecha->head = NULL;
                lst_fecha->tail = NULL;
            }
        }
        else
        {
            if (curr_nodo->nxt != NULL)
            {
                curr_nodo->bck->nxt = curr_nodo->nxt;
                curr_nodo->nxt->bck = curr_nodo->bck;
            }
            else
            {
                curr_nodo->bck->nxt = NULL;
                lst_fecha->tail     = curr_nodo->bck;
            }
        }
        free(curr_nodo);
        lst_fecha->size--;
    }
}


void print_lst_fecha(LST_FECHA lst_fecha)
{
    NODO_FECHA * curr_nodo; // curr para current
    curr_nodo = lst_fecha.head;
    while (curr_nodo != NULL)
    {
        printf("\n %d / %d / %d ", (*curr_nodo).fecha.dia, (*curr_nodo).fecha.mes, (*curr_nodo).fecha.anio);
        curr_nodo = (*curr_nodo).nxt;
    }
}
