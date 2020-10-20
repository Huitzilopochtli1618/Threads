/*
**    Programa para ilustrar el uso de los hilos
**    y la memoria compartida
**    
**    El hilo principal crea dos hilos mas. Se usa una variable compartida 
**    que el hilo padre modifica y los hilos hijos leen, en cada caso el valor
**    de la variable es reportado a la pantala. Se usa la funcion 
**    sleep para hacer trabajar a cada hilo a una velocidad diferente. 
**    Los accesos a las variables compartidas NO están sincronizados.    
^*   
**    Por: Elizabeth Pérez Cortés 
**    
**    compilar con : gcc hilera.c -lpthread -o hilera 
**
*/

#include "pthread.h"
#include <stdio.h>
#include <unistd.h>

int var_compartida = 0;

void imprimepar( void *ptr ); 
void imprimeimpar( void *ptr ); 


int main()
{ 
   int i;

   pthread_t thread1, thread2;

   /* Se crea el hilo que imprime pares */
   
   int var1=3;
   pthread_create( &thread1, NULL, (void *) imprimepar, (void *) &var1);
   
   /* Se crea el hilo que imprime impares */
   int var2=5;
   pthread_create(&thread2, NULL, (void *) imprimeimpar, (void *) &var2);

   /* El padre puede hacer trabajo simultaneo al de los hilos hijos */ 
   //sleep(3);
   for (i = 0; i < 6; i++)
   {
      printf("hilo padre : %d \n", var_compartida = i);
      sleep(1);
   }  
   printf("\nEspero a que terminen mis hijos\n");
   /* El hilo padre espera a que terminen los hilos que creo */
   pthread_join(thread1, NULL);
   pthread_join(thread2, NULL);
   printf("\nTerminaron\n\n");
   
   return 0;
}


/* 
** Funcion que imprime numeros pares
** entrada : numero de iteraciones a realizar
** salida  : nada
*/
void imprimepar( void *ptr ) 
{ 
   int i; 
   int *iteraciones = (int*) ptr;
   printf("Fpar iteraciones=%d\n", *iteraciones);
   for (i = 0; i < *iteraciones ; i++)
   { 
         printf("hilo par %d \n", var_compartida*2); 
         sleep(3);
   } 
   printf("FIN Fpar iteraciones=%d\n", *iteraciones);
   pthread_exit(0); 
}  


/* 
** Funcion que imprime numeros impares
** entrada : numero de iteraciones a realizar
** salida  : nada
*/
void imprimeimpar( void *ptr ) 
{ 
   int i;
   int *iteraciones = (int*) ptr;
   printf("Fimpar iteraciones=%d\n", *iteraciones);
   for (i = 0; i < *iteraciones ; i++) 
   {        
         printf("hilo impar %d \n", var_compartida*2+1); 
         sleep(2);
   }
   printf("FIN Fimpar iteraciones=%d\n", *iteraciones);
   pthread_exit(0);
}