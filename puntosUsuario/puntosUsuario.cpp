/*  Grafica de valores introducidos por el usuario
    Autor: Villanueva Mejia Sebastian Antonio (seant-21i)
    El usuario ingresa N puntos, y el sistema los guarda en dos arreglos
    dedicados especificamente a X, Y. posteriormente los grafica con 
    ayuda de GNUplot.   */
#include <cstdio>
#include <iostream>
#include <random>
using namespace std;

//Constantes para definir el maximo de puntos a generar
#define max_Puntos 13
//Constante para definir el numero de comandos para GNUplot
#define num_Comandos 5

//Estructura de arreglos para los valores X, Y
struct{
    double vX[max_Puntos];
    double vY[max_Puntos];
}pnts;


int main(){
    int i = 0;

    //Estructura para guardar duplas de valores en los arreglos
    for (i = 0; i < max_Puntos; i++){
        cout << "X(" << i+1 << "): ";
        cin >> pnts.vX[i];
        cout << "Y(" << i+1 << "): ";
        cin >> pnts.vY[i];
    }
    
    /*  se crea y se abre el archivo dupla.dat en modo escritura
        para almacenar los valores de X, Y  */
    FILE * archivoPuntos = fopen("dupla.dat", "w");
    system("clear");
    //Guardar los puntos X, Y en el archivo .dat creado y abierto previamente
    for (i=0;i<max_Puntos;i++){
        //Comandos para imprimir los valores generados en consola
        cout << i << ": ";
        cout << pnts.vX[i];
        cout << "," << pnts.vY[i] << endl;
        fprintf(archivoPuntos, "%lf %lf \n", pnts.vX[i], pnts.vY[i]);
    }
    /*  Lista de comandos para ejecutar y configurar la visualización que tendrán
        los puntos en la gráfica con GNUplot    */
    char * configGnuplot[] = {"set title \"Grafica de puntos ingresados\"",
                              "set ylabel \"eje Y\"",
                              "set xlabel \"eje X\"",
                              "set zeroaxis",
                              "plot \"dupla.dat\" using 1:2 with lp ps 1 title \"Puntos ingresados\""
    };

    /*  Se crea una archivo de tipo popen, es pipe streams que se usa, para
        ejecutar GNUplot y enviar los datos para graficar   */
    FILE * ventanaGnuplot = popen ("gnuplot -persist", "w");

    //Ejecuta los comandos de GNUplot uno a uno.
    for (i=0; i < num_Comandos; i++){
        fprintf(ventanaGnuplot, "%s \n", configGnuplot[i]);
    }
    fclose(archivoPuntos);

    return 0;
}