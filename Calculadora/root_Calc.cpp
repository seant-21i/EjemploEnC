/*  Calculadora algebraica
    Autor: Villanueva Mejia Sebastian Antonio (seant-21i)   */
/*  El programa calcula las raices reales y complejas de
    una funcion lineal, cuadratica o cubica.
    La entrada de datos esta descrita en cada caso.     */
    
#include <iostream> //Biblioteca para entrada y salida de datos.
#include <cmath>    //Biblioteca para operaciones matematicas.
using namespace std;

//Estructura que contiene variables recurretes en los tres tipos de ecuaciones.
struct{
    float c_1 = 0;
    float c_2 = 0;
    float c_3 = 0;
    int sgn = 0;
    float i = 0;
    double X[3] = {0,0,0};
}equ;

//Funcion para realizar una pausa despues de mostrar raices de una ecuacion.
void pausa(){
    cin.ignore();
    cin.get();
}

/*  Funcion para resolver ecuaciones lineales de la forma:
    aX+b=0  */
void linear(){
    cout << "\nEcuacion de la forma:" << endl;
    cout << "aX+b=0" <<endl;
    cout << "a: ";
    cin >> equ.c_2;
    cout << "b: ";
    cin >> equ.c_1;
    equ.X[0] = (-equ.c_1) / (equ.c_2);
    cout << "\nRaiz: " <<endl;
    cout << "X: " << equ.X[0] << endl;
    cout << "presione Enter para continuar...";
}

/*  Funcion para resolver ecuaciones cuadraticas de la forma:
    aX²+bX+c=0  */
void quadratic(){
    float disc = 0; //variable para determinar el tipo de raices.
    cout << "\nEcuacion de la forma:" << endl;
    cout << "aX²+bX+c=0" <<endl;
    cout << "a: ";
    cin >> equ.c_3;
    cout << "b: ";
    cin >> equ.c_2;
    cout << "c: ";
    cin >> equ.c_1;
    disc = pow(equ.c_2,2)-4*equ.c_3*equ.c_1;
    //cout << "\nDiscriminante: " << disc << endl;
    //  if anidado para los 3 tipos de soluciones posibles.
    if (disc >= 0){
        if (disc == 0){
            equ.X[0] = -equ.c_2 / (2*equ.c_3);
            cout << "\nRaiz unica:" << endl;
            cout << "X: " << equ.X[0] << endl;
            cout << "presione Enter para continuar...";
        }
        else{
            equ.X[0] = (-equ.c_2 + sqrt(pow(equ.c_2, 2) - (4 * equ.c_3 * (equ.c_1)))) / (2 * equ.c_3);
            equ.X[1] = (-equ.c_2 - sqrt(pow(equ.c_2, 2) - (4 * equ.c_3 * (equ.c_1)))) / (2 * equ.c_3);
            cout << "\nRaices: " << endl;
            cout << "X1: " << equ.X[0] << endl;
            cout << "X2: " << equ.X[1] << endl;
            cout << "presione Enter para continuar...";
        }
    }
    else{
        equ.X[0] = -equ.c_2 / (2*equ.c_3);
        equ.i = sqrt(abs(disc))/(2*equ.c_3);
        //cout << "i: " << equ.i << endl;
        cout << "\nRaices complejas: " << endl;
        cout << "X1: " << equ.X[0] << "+" << equ.i << "j" <<endl;
        cout << "X1: " << equ.X[0] << "-" << equ.i << "j" <<endl;
        cout << "presione Enter para continuar...";
    }
}

/*  Funcion para resolver ecuaciones cubicas de la forma:
    aX³+bX²+cX+d=0  */
void cubic(){
    cout << "\nEcuacion de la forma:" << endl;
    cout << "aX³+bX²+cX+d=0 ; con Coeficiente \"a\" = 1 " <<endl;
    cout << "b: ";
    cin >> equ.c_3;
    cout << "c: ";
    cin >> equ.c_2;
    cout << "d: ";
    cin >> equ.c_1;
    //  Variables para determinarl el tipo de raices.
    double Q = (pow(equ.c_3, 2) - 3 * equ.c_2) / (9);
    double R = (2*pow(equ.c_3, 3) - 9 * equ.c_3 * equ.c_2 + 27 * equ.c_1) / (54);
    //  Condicional para las diferentes soluciones.
    if(pow(R,2) < pow(Q,3)){
        double theta = acos(R/ sqrt(pow(Q,3)));
        cout << "Theta: " << theta << endl;
        cout << "\nRaices: " << endl;
        for(int i = 0; i < 3; i++){
            equ.X[i] = -2 * sqrt(Q) * cos((theta + 2 * (i - 1) * (M_PI)) / 3) - (equ.c_3 / 3);
            cout << equ.X[i] << endl;
        }
        cout << "presione Enter para continuar...";
    }
    else if(pow(R,2) >= pow(Q,3)){
        equ.sgn = (R > 0) - (R < 0);    //Equivalente del la funcion matematica signo.
        double A,B = 0;
        A = -equ.sgn*cbrt((abs(R)+ sqrt(pow(R,2)- pow(Q,3))));
        if(A != 0){
            B = Q/A;
        }
        else{
            B = 0;
        }
        equ.X[0] = (A+B)-(equ.c_3/3);
        equ.X[1] = ((-1)*(A+B))/2-(equ.c_3/3);
        equ.i = abs((sqrt(3)/2)*(A-B));
        cout << "\nRaiz real: " << endl;
        cout << "X1: " << equ.X[0] << endl;
        cout << "Raices complejas: " << endl;
        cout << "X2: " << equ.X[1] << "+" << equ.i << "i" << endl;
        cout << "X3: " << equ.X[1] << "-" << equ.i << "i" << endl;
        cout << "presione Enter para continuar...";
    }
}

//Funcion main, implementacion del menu y llamada a las funciones solucion.
int main() {
    int opcion;
    bool repeat = true;
    do {
        system("clear");    //limpia la consola terminal en Linux.
        cout << "Menu de Opciones" << endl;
        cout << "................" << endl;
        cout << "1. Ecuación lineal" << endl;
        cout << "2. Ecuación cuadrática" << endl;
        cout << "3. Ecuación cúbica" << endl;
        cout << "----------------" << endl;
        cout << "0. SALIR" << endl;
        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                linear();
                pausa();
            break;
            case 2:
                quadratic();
                pausa();
            break;
            case 3:
                cubic();
                pausa();
            break;
            case 0:
                repeat = false;
            break;
        }
    } while (repeat);
    return 0;
}