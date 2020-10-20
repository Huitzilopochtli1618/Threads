#include <stdio.h>     /* funciones de I/O standard                      */
#include <unistd.h>    /* funciones standard de unix como alarm()        */
#include <signal.h>    /* nombres de macros de señales, y el prototipo de signal() */

#include <fstream>
#include <iostream>

#include <string>
using namespace std;


int main(int argc, char* argv[])
{
    int N1;
    int N2;
    int N;
    int m1[20][20];
    int m2[20][20];
    int m3[20][20];

    system("clear");

    ifstream archivo;
    //ahora no existe forma de que el archivo matrices no exista, a menos que ocurra un error al abrir el archivo
    archivo.open("matrizA.txt",ios::in);//modo lectura
    if(archivo.fail()){
        cout<<"\n\nNo se encontro a la matriz A\n\n";
        exit(0);
    }else{

        archivo>>N1;   //Obtengo el tamaño
        for (int i = 0; i < N1;i++)
        {
            for (int j = 0; j < N1; j++)
            {
                archivo>>m1[i][j];
            }
        }
        archivo.close();
    }

    ifstream archivo2;
    //ahora no existe forma de que el archivo matrices no exista, a menos que ocurra un error al abrir el archivo
    archivo2.open("matrizB.txt",ios::in);//modo lectura
    if(archivo2.fail()){
        cout<<"\n\nNo se encontro a la matriz B\n\n";
        exit(0);
    }else{

        archivo2>>N2;   //Obtengo el tamaño
        for (int i = 0; i < N2;i++)
        {
            for (int j = 0; j < N2; j++)
            {
                archivo2>>m2[i][j];
            }
        }
        archivo2.close();
    }


    if(N1!=N2)
    {
        printf("\nLas matrices cuadradas A y B no son compatibles para multiplicarce");
        exit(0);
    }else{
        N=N1;
    }


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            m3[i][j]=0;
            for (int k = 0; k < N; k++)
            {
                m3[i][j]+=m1[i][k]*m2[k][j]; 
            }
            sleep(1);   //para simular procesamiento
        }
    }

    fstream archivoResultado;
    archivoResultado.open("matrizC.txt",ios::out);//modo escritura
    for (int i = 0; i < N; i++)//Guardo matriz C
    {
        for (int j = 0; j < N; j++)
        {
            archivoResultado<<m3[i][j]<<" ";
        }
        archivoResultado<<"\n";
    }
   

    return 0;
}