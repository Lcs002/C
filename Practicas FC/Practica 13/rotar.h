#ifndef ROTAR_H
    #define ROTAR_H

    #define N 10
    #define M 15
    
    void mat_imprimir (char[M][N]);
    void mat_rellenar (char[M][N]);
    void mat_rotar    (char[M][N]);
    void mat_desrotar (char[M][N]);
    void mat_toFile   (char[M][N], FILE*);
    int  random       (int, int);

#endif // ROTAR_QH
