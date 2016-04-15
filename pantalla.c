//PANTALLA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void pantalla(){
  
int asteriscos; 
int linea_aste;

  for(asteriscos=0; asteriscos<7; asteriscos++){
   
    if(asteriscos<3 || asteriscos>=4 ){;
      for(linea_aste=0; linea_aste<80; linea_aste++){
	printf("*");
      }
    }
    else if(asteriscos==3){
      for(linea_aste=0; linea_aste<66; linea_aste++){
	if(linea_aste==32){
	  printf("  MASTER MIND  ");
	}
	else{
	  printf("*");
	}
      }
    }
    printf("\n");
  }
  printf("\n");
}

int confirmar(char opcion){

  opcion = tolower(opcion);
  switch(opcion){
    
  case 's':{
    return 1;
  }
  case 'n':{
    return 0;
  }
  default: {
    return -1;
  }
  }
} 

void menu_nguardar(int *idioma){

  char *menu[3]={" \n 1) Jugar partida \n 2) Jugar partida de prueba \n 3) Establecer nivel de dificultad \n 4) Listar historial de partidas \n 6) Establecer idioma \n 0) Salir\n \n¿Siguiente operación?" , "\n 1) Xogar partida \n 2) Xogar partida de proba \n 3) Establecer nivel de dificultade \n 4) Listar historial de partidas \n 6) Establecer idioma \n 0) Saír\n \nSeguinte operación?", "\n 1) Play game \n 2) Play test game \n 3) Set skill level \n 4) List game history \n 6) Set language \n 0) Quit\n\nNext command?"};

  fprintf(stdout,"%s", menu[*idioma]);

  printf("\n");
 return;

}

void menu_guardar(int *idioma){

  char *menu[3]={" \n 1) Jugar partida \n 2) Jugar partida de prueba \n 3) Establecer nivel de dificultad \n 4) Listar historial de partidas \n 5) Guardar partida jugada \n 6) Establecer idioma \n 0) Salir\n \n¿Siguiente operación?" , " \n 1) Xogar partida \n 2) Xogar partida de proba \n 3) Establecer nivel de dificultade \n 4) Listar historial de partidas \n 5) Gardar partida xogada \n 6) Establecer idioma \n 0) Saír\n \nSeguinte operación?", "\n 1) Play game \n 2) Play test game \n 3) Set skill level \n 4) List game history \n 5) Save played game \n 6) Set language \n 0) Quit\n \nNext command?"};

  printf("%s", menu[*idioma]);
  printf("\n");
 return;

}
