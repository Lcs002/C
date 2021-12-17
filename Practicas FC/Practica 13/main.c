#include <stdio.h>
#include <stdlib.h>
#include "rotar.h"

//Para mandar un nombre de fichero al programa, ejecutalo desde la terminal
int main(int argc, char* argv[])
{
    FILE* f_out;
    char mat[M][N];

    if (argc != 2)
    {
        printf("ERROR: Maximo dos argumentos");
        return 1;
    }

    if (!(f_out = fopen(argv[1], "w")))
    {
        printf("ERROR: No ha sido posible abrir/crear el fichero");
        return 2;
    }

    mat_rellenar (mat);
    mat_imprimir (mat);
    mat_toFile   (mat, f_out);
    mat_rotar    (mat);
    mat_imprimir (mat);
    mat_toFile   (mat, f_out);
    mat_desrotar (mat);
    mat_imprimir (mat);
    mat_toFile   (mat, f_out);

    fclose(f_out);

    return 0;
}
