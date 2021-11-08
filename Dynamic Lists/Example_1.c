// ===============================================  LISTAS DINAMICAS CON NODOS

// =========== INCLUDES

#include <stdio.h>
#include <stdlib.h>


// =========== STRUCTS

typedef struct Tfecha
{
    unsigned dia, mes, anio;
} FECHA;

typedef struct Tnodo_fecha
{
    FECHA fecha;             // contenido tipo fecha
    struct Tnodo_fecha *nxt; // NODO siguiente
    struct Tnodo_fecha *bck; // NODO anterior
} NODO_FECHA;

typedef struct Tlst_fecha
{
    NODO_FECHA *head; // primer NODO
    NODO_FECHA *tail; // ultimo NODO
    unsigned    size; // Tamaño de la lista
} LST_FECHA;


// =========== PROTOTYPES

void   scan_fecha        (FECHA *);                      // Scan de struct tipo FECHA
void   print_fecha       (FECHA);                        // Print de struct tipo FECHA
void   addf_fecha        (FECHA, LST_FECHA*);            // Adicionar fecha a principio de lista
void   addl_fecha        (FECHA, LST_FECHA*);            // Adicionar fecha al final de lista
void   addn_fecha        (unsigned, FECHA, LST_FECHA*);  // Adicionar fecha en una posición dada
void   reverse_lst_fecha (LST_FECHA *);                  // Invertir la lista
void   remove_fecha      (unsigned, LST_FECHA *);        // Remover una fecha de la lista dada su posición
FECHA* get_lst_fecha     (unsigned, LST_FECHA *);        // Retorna valor de fecha en una posición dada de la lista
void   init_lst_fecha    (LST_FECHA *);                  // Inicializa la lista
void   clear_lst_fecha   (LST_FECHA *);                  // Reseta la lista
void   print_lst_fecha   (LST_FECHA);                    // Printea la lista


// =========== MAIN

void main()
{
    FECHA fecha;                  // Crear variable tipo FECHA
    LST_FECHA lst_fecha;         // Crear variable tipo LST_FECHA
    init_lst_fecha(&lst_fecha); // Inicializar la lista

    // Añadir valores en la lista hasta que el usuario no introduzca un 's'
    do
    {
        scan_fecha(&fecha);             // Pedir fehca
        addl_fecha (fecha, &lst_fecha); // Añadir NODO_FECHA al final de la lista con los valores de fecha
        printf    ("\nQuieres seguir añadiendo fechas? (s/n)");
        fflush    (stdin);
    } while(getch() == 's');

    system("cls");               // Limpiar pantalla
    print_lst_fecha(lst_fecha); // Muestra la lista

    // ESCRIBIR ABAJO OTRAS FUNCIONES ...






}


// =========== FUNCS

void scan_fecha(FECHA * fecha)
{
    printf("\n\ndia? "); scanf("%u", &fecha->dia);
    printf("mes? ");     scanf("%u", &fecha->mes);
    printf("anio? ");    scanf("%u", &fecha->anio);
    fflush(stdin);
}


void print_fecha(FECHA fecha)
{
    printf("%d / %d / %d ", fecha.dia, fecha.mes, fecha.anio);
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
        new->nxt        = lst_fecha->head;
        new->nxt->bck   = new;
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


void addn_fecha(unsigned index, FECHA fecha, LST_FECHA * lst_fecha) // add in n position
{
    unsigned i;
    NODO_FECHA *new, * curr_nodo;
    new = malloc( sizeof( NODO_FECHA ) );
    new->fecha = fecha;
    new->nxt   = NULL;
    new->bck   = NULL;
    for (i = 0; curr_nodo != NULL && i < index; curr_nodo = &curr_nodo->nxt, i++);
    if (curr_nodo != NULL)
    {
        if (curr_nodo->bck != NULL)
        {
            new->bck            = curr_nodo->bck;
            curr_nodo->bck->nxt = new;
        }
        new->nxt       = curr_nodo;
        curr_nodo->bck = new;
        lst_fecha->size++;
    }
}


void remove_fecha(unsigned index, LST_FECHA * lst_fecha)
{
    int i;
    NODO_FECHA * curr_nodo = lst_fecha->head;
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


FECHA * get_lst_fecha(unsigned index, LST_FECHA * lst_fecha)
{
    unsigned i;
    NODO_FECHA * curr_nodo = lst_fecha->head;
    for (i = 0; curr_nodo != NULL && i < index; curr_nodo = &curr_nodo->nxt, i++);
    return curr_nodo;
}


void print_lst_fecha(LST_FECHA lst_fecha)
{
    unsigned i = 0;
    NODO_FECHA * curr_nodo = lst_fecha.head; // curr para current
    while (curr_nodo != NULL)
    {
        printf("\nFECHA %2u:  ", i++);
        print_fecha(curr_nodo->fecha);
        curr_nodo = curr_nodo->nxt;
    }
}


void reverse_lst_fecha(LST_FECHA * lst_fecha)
{
    NODO_FECHA * curr_nodo = lst_fecha->head, * bck, * nxt;
    bck = curr_nodo->bck;
    while (curr_nodo != NULL)
    {
        nxt            = curr_nodo->nxt;
        curr_nodo->nxt = bck;
        curr_nodo->bck = nxt;
        bck            = curr_nodo;
        curr_nodo      = nxt;
    }
    bck             = lst_fecha->tail;
    lst_fecha->tail = lst_fecha->head;
    lst_fecha->head = bck;
}


void clear_lst_fecha(LST_FECHA * lst_fecha)
{
    NODO_FECHA * curr_nodo = lst_fecha->head, * bck;
    while (curr_nodo != NULL)
    {
        bck       = curr_nodo;
        curr_nodo = curr_nodo->nxt;
        free(bck);
    }
    lst_fecha->size = 0;
    lst_fecha->head = NULL;
    lst_fecha->tail = NULL;
}
