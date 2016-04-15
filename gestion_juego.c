//GESTION DE JUEGO

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "gestion_juego.h"
#include "idiomas.h"

int jugar_partida(int modo, int *lifes, int *lengua, char *arg, int argument, Inicial *inicial, Fin *fin, Apuestas apuestas[100]){

  int t;

   if(modo==0){ //MODO NORMAL DE JUEGO
     
    int oportunidades=*lifes;
    char codigo[4];
    int indice1, indice2, error;
    srand(time(NULL));
    

    //GENERAMOS EL CODIGO SECRETO
    do{
      error=0;
      for(indice1=0; indice1<4; indice1++){
	*(codigo+indice1) = '0'+(rand() % (':'-'0'));//NUMEROS ALEATORIOS ENTRE 0 Y 9
      }
      //COMPROBAMOS QUE NO HAYA DOS ELEMENTOS IGUALES EN EL CODIGO SECRETO
      for(indice1=0; indice1<4; indice1++){
	for(indice2=0; indice2<4; indice2++){
	  if(indice1==indice2){
	    continue;
	  }
	  else if(codigo[indice1]==codigo[indice2]){
	    //	  printf("\nLas letras de las posiciones %i y %i son iguales\n\n", indice1+1, indice2 +1);
	    error=1;
	    break;
	  }
	}
	if(error==1)break;
      }
    }while(error==1);

    t=partida_normal(oportunidades, codigo, lengua, inicial, fin, apuestas);
    return t;
  }
 
  else{ //PARTIDA DE PRUEBA 
 int oportunidades=*lifes;
    if(argument==1){
      t=partida_normal(oportunidades, arg, lengua, inicial, fin, apuestas);
    }
    else{
    char codigo_p[4]="1234";
    t=partida_normal(oportunidades, codigo_p, lengua, inicial, fin, apuestas);
    }
  }
  return t;
}

int establecer_nivel(int error, int *lifes, int *lengua){

  int modo=error;
  imprimir(18, lengua);
  printf("%i\n", *lifes);

  while(modo==1){
    imprimir(19, lengua);
    //printf("Elige nuevo nivel [1..100]:");
    scanf(" %i", lifes);
    if(*lifes>=1 && *lifes<=100){
      imprimir(20,lengua);
      printf("%i\n", *lifes);
      modo=0;
    }
    else{
      //printf("\nNivel seleccionado no vÃÂÃÂ¡lido\n");
      imprimir(21, lengua);
      modo=1; 
    }
  }
  return 0;
}

int listar_historial(int *lengua){

  FILE *txt;
  char c;
  txt=fopen("partidas.txt","r");
  if( txt == NULL) {
    //printf("No puedo leer el fichero del historial\n");
    imprimir(22, lengua);
    return 0;
  }
  while((c=fgetc(txt))!=EOF){ //Comparamos con fin de fichero.
    printf("%c",c);
  }
  fclose(txt);
  return 0;
}

void guardar_partida(Apuestas apuestas[100], Inicial *inicial, Fin *fin, int t){

  FILE *txt;
  int indice1, indice2;
  txt=fopen("partidas.txt", "a");
  

  for(indice1=0; indice1<12; indice1++){ //IMPRIMO GUIONES
    fprintf(txt,"%c", inicial->guiones[indice1]);
  }

  fprintf(txt, "\n");

    for(indice1=0; indice1<4; indice1++){ //IMPRIMO EL CODIGO SECRETO
    fprintf(txt,"%c", inicial->codigo[indice1]);
    }

  fprintf(txt, "\n");

  for(indice1=0; indice1<t; indice1++){
    for(indice2=0; indice2<4; indice2++){//HACEMOS ESTE FOR PARA LIMITAR LA CADENA , YA QUE NO TENEMOS FINAL DE CADENA EN EL ARRAY
    fprintf(txt,"%c", apuestas[indice1].apuesta[indice2]);
    }
    fprintf(txt, "  ");
    
    for(indice2=0; indice2<6; indice2++){
    fprintf(txt,"%c", apuestas[indice1].aciertos[indice2]);
    }
    fprintf(txt,"\n");
  }
  for(indice1=0; indice1<1; indice1++){
  fprintf(txt, "%i\n", fin->intentos);
  fprintf(txt, "%.2f", fin->puntuacion);
  }
	fprintf(txt, "\n");

  fclose(txt);

}

void idioma(int *lengua){


  char *idioma[3]={" \n 0) Español \n 1) Gallego \n 2) Inglés\n\n  Elige idioma:"," 0) Español \n 1) Galego \n 2) Inglés\n\n  Elixe idioma:"," 0) Spanish \n 1) Galician \n 2) English \n\n  Select language:"};

  printf("%s", idioma[*lengua]);
  scanf(" %i", lengua);
  return;
  
}
