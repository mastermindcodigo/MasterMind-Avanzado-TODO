#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "gestion_juego.h"
#include "idiomas.h"
#include "comandos.h"
//#include "gestion.h"
#define JUGAR '1'
#define PROBAR '2'
#define NIVEL '3'
#define LISTAR '4'
#define GUARDAR '5'
#define IDIOMA '6'
#define SALIR '0'

int main(int argc, char *argv[]){

  char opcion[800];
  int error, t, argumento=0;
  int error2,error3;
  int dificultad;
  int *lives;
  int *vez; //Variable para salir sin guardar.
  // char accion;
  int *lenguaje;
  lives=malloc(80*sizeof(int));
  *lives=100;
  vez=malloc(80*sizeof(int));
  *vez=0;
  lenguaje=malloc(80*sizeof(int));
  *lenguaje=0;

  /* struct apuestas{
    char apuesta[4];
    char aciertos[4];
  };

 struct inicial{
   char guiones[16];
   char codigo[4]
 };

 struct fin{
   int intentos;
   float puntuacion;
   }*/
//DECLARACION DE LOS STRUCT.
  Inicial inicial_;
  Inicial *inicial=&inicial_;
  Apuestas apuestas[100];
  Fin fin_;
  Fin *fin=&fin_; //declaro struct fin

  //EMPIEZA LA EJECUCION DEL PROGRAMA

  if(argc>=3){
    printf("\nUso: ./principal [--help | codigo_prueba]\n");
    return 3;
  }
  else if(argc==2){

    if(*(argv[1])=='-') {
      help(argv[1]);
      return 0;
    }
    else {
      int x;
      argumento=1;
      x=prueba(argv[1]);
      if(x==1)return 0;
      //else partida_normal(*lives, argv[1], lenguaje, argumento);
    }
  }


  pantalla();
  
  do{  

    error=0;
  
    if(*vez==0){
      menu_nguardar(lenguaje);
    }
    else{
      menu_guardar(lenguaje);
    }
	
    fscanf(stdin," %s", opcion);
    if(strlen(opcion)!=1)opcion[0]=7;

    error=0;

    switch (opcion[0]) {

    case SALIR: { //salir
	if(*vez==1 && *lenguaje!=2) {
  do{
	 imprimir(3, lenguaje);
	scanf(" %s",opcion);
	error3=0;
	if(strlen(opcion)!=1)error3=1; //Si la longitud de la cadena no es uno, error.
	if(tolower(opcion[0])!='s' && tolower(opcion[0])!='n')error3=1; //si el primer elemento no es s y no es n, error.
  }while(error3==1);
	} else if(*vez==1 && *lenguaje==2) 
	{
	  do{
	imprimir(3, lenguaje);
	scanf(" %s",opcion);
	error3=0;
	if(strlen(opcion)!=1)error3=1; //Si la longitud de la cadena no es uno, error.
	if(tolower(opcion[0])!='y' && tolower(opcion[0])!='n')error3=1; //si el primer elemento no es s y no es n, error.
  }while(error3==1);
}
	error=0;
	if(tolower(opcion[0])=='n'){
	error=1;
	}
      
    break; 
    }

    case JUGAR : {
      //  fprintf(stdout," \nHas seleccionado Jugar partida\n\n");
      dificultad=0;
      error=1;
      *vez=1;
      t=jugar_partida(dificultad, lives, lenguaje, argv[1], argumento, inicial, fin, apuestas); //MODO NORMAL DE JUEGO
      break;
    }
    case PROBAR: {
      // fprintf(stdout," \nHas seleccionado Jugar partida de prueba\n\n");
      dificultad=1;
      *vez=1;
      t=jugar_partida(dificultad, lives, lenguaje, argv[1], argumento, inicial, fin, apuestas);
      error=1;
      break;
    }
    case NIVEL: {
      //  fprintf(stdout," \nHas seleccionado establecer nivel de dificultad\n\n");
      error=1;
      establecer_nivel(error, lives, lenguaje); //MODIFICAMOS EL NUMERO DE OPORTUNIDADES Y VOLVEMOS A LANZAR EL MENU DE OPCIONES
    
      break;
    }
    case LISTAR: {
      // fprintf(stdout,"\nHas seleccionado listar historial de partidas\n\n");
      listar_historial(lenguaje);
      error=1;
      break;
    }
    case GUARDAR: {
      guardar_partida(apuestas, inicial, fin, t);
      *vez=0;
      error=1;
      break;
    }
    case IDIOMA: {
      do{
	error2=0;
	idioma(lenguaje);
	if(*lenguaje!=0 && *lenguaje!=1 && *lenguaje!=2){
	  error2=1;
	  imprimir(24, lenguaje);
	}
      }while(error2==1);
      error=1;
      break;
    }
    default : {
      //fprintf(stdout," \nOpcion no valida\n\n");
      imprimir(1, lenguaje);
      error=1;
      break;
    }
    }
  }while (error == 1 );
  return 0;


}
