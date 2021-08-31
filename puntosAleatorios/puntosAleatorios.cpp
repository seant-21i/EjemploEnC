/*  Grafica de 20 valores aleatorios
    Autor: Villanueva Mejia Sebastian Antonio (seant-21i)
    El programa genera 20 numeros aleatorios, los guarda en dos arreglos
    dedicados especificamente a X, Y. posteriormente los grafica con 
    ayuda de GNUplot.   */
#include <cstdio>
#include <iostream>
#include <random>
using namespace std;

//Constantes para definir el maximo d epuntos a generar
#define max_Puntos 20
//Constante para definir el numero de comandos para GNUplot
#define num_Comandos 4

int main(){
    //Creacion de dos arreglos para guardar combinaciones de valores de X, Y
    double valoresX[max_Puntos];
    double valoresY[max_Puntos];
    int i = 0;

    random_device rd;   //Semilla
    mt19937 mt(rd());   //Generador
    uniform_real_distribution<float> dist(0.0, 20.0);   //Generacion de aleatorios entre 2 valores dados

    //estructura para guardar duplas de valores en los arreglos
    for (i = 0; i < max_Puntos; i++){
        valoresX[i]=dist(mt);
        valoresY[i]=dist(mt);

        //Comandos para imprimir los valores generados en la consola
        cout << i << ": ";
        cout << valoresX[i];
        cout << "," << valoresY[i] << endl;
    }
    
    /*  se crea y se abre el archivo puntos.txt en modo escritura
        para almacenar los valores de X, Y  */
    FILE * archivoPuntos = fopen("puntos.txt", "w");

    //Guardar los puntos X, Y en el archivo de texto creado y abierto previamente
    for (i=0;i<max_Puntos;i++){
        fprintf(archivoPuntos, "%lf %lf \n", valoresX[i], valoresY[i]);
    }

    /*  Lista de comandos para ejecutar y configurar la visualización que tendrán
        los puntos en la gráfica con GNUplot    */
    char * configGnuplot[] = {"set title \"Grafica de puntos Aleatorios\"",
                              "set ylabel \"eje Y\"",
                              "set xlabel \"eje X\"",
                              "plot \"puntos.txt\" using 1:2 with lp ps 1"
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