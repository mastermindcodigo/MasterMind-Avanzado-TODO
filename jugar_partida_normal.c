//MODO DE JUEGO NORMAL

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "idiomas.h"
#include "gestion_juego.h"

int partida_normal(int oportunidades, char codigo[4], int *idioma, Inicial *inicial, Fin *fin, Apuestas apuestas[100]){
  

  void felicitaciones(int intentos, char codigo[4], int indice1, int *idiomas){
  
    float puntos;
    
    if(intentos<=3)puntos=10;
    else if(intentos>=12)puntos=0;
    else if(intentos>3 && intentos<12)puntos=10-10*(intentos - 3)/9.;

    //printf("\n\nHa descubierto el codigo secreto (");
    imprimir(9, idioma); 
    fin->puntuacion=puntos; //Asignamos la puntuacion al struct y tambien los intentos
    fin->intentos=intentos;

    for(indice1=0; indice1<4; indice1++){
      printf("%c", codigo[indice1]);
    }
    if(intentos!=1){
      //printf(") en %i intentos\nHa obtenido %.2f puntos\n\n", intentos, puntos)
      imprimir(10, idioma);
      printf("%i", intentos);
      imprimir(11, idioma);
      imprimir(15, idioma);
      printf("%.2f", puntos);
      imprimir(16, idioma);
      
      //escrituratxt(intentos, puntos);
    }
    else{ 
      //printf(") en %i intento\nHa obtenido %.2f puntos\n\n", intentos, puntos);
        imprimir(10, idioma);
      printf("%i", intentos);
      imprimir(14, idiomas);
      imprimir(15, idioma);
      printf("%.2f", puntos);
      imprimir(16, idioma);
      // escrituratxt(intentos, puntos);
    }
  }

  void derrota(char codigo[4], int indice1, int intentos, int *idiomas){
    
    float puntos=0;

    //printf("\n\nNO ha descubierto el codigo secreto (");
    imprimir(12, idioma);
    fin->puntuacion=puntos;//Asignamos la puntuacion al struct y tambien los intentos
    fin->intentos=intentos;

    for(indice1=0; indice1<4; indice1++){
      printf("%c", codigo[indice1]);
    }
    if(intentos!=1){
      //printf(") tras %i intentos\nHa obtenido %.2f puntos\n\n", intentos, puntos);
      imprimir(17, idiomas);
       printf("%i", intentos);
      imprimir(13, idiomas);
      imprimir(15, idioma);
      printf("%.2f", puntos);
      imprimir(16, idioma);
      //escrituratxt(intentos, puntos);
    }
    else{
      //printf(") tras %i intento\nHa obtenido %.2f puntos\n\n", intentos, puntos);
      imprimir(17, idiomas);
       printf("%i", intentos);
      imprimir(14, idiomas);
      imprimir(15, idioma);
      printf("%.2f", puntos);
      imprimir(16, idioma);
      //escrituratxt(intentos, puntos);
    }
  }

  srand(time(NULL));
  //char codigo[4];
  char apuesta[4];
  char apuesta_c[4];
  char apuesta_final[4];
  int indice1, indice2, error, a, b, perder, t=0;
  int ganar=0;
  int intentos=0;
  int contimpresion=0; //CONTADOR AUX PARA NUMERO DE VALORES DISTINTOS DE _ 

  //GENERAMOS LOS CUATRO NUMEROS ALEATORIOS
  /*do{
    error=0;
    for(indice1=0; indice1<4; indice1++){
    *(codigo+indice1) = '0'+(rand() % (':'-'0'));//NUMEROS ALEATORIOS ENTRE 0 Y 9
    }
    //COMPROBAMOS QUE NO HAYA DOS ELEMENTOS IGUALES EN EL CODIGO SECRETO
    for(indice1=0; indice1<5; indice1++){
    for(indice2=0; indice2<5; indice2++){
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
    }while(error==1);*/
  /* for(indice=0; indice<4; indice++){
     printf(" %i", *(codigo+indice));
     }*/

  /*txt=fopen("partidas.txt","a+"); //GUARDADO EN FICHERO DEL CODIGO SECRETO Y COLOCACIÓN DE GUIONES.
  fprintf(txt,"------------\n");
  //fprintf(txt, "El codigo secreto es:");
  for(indice1=0; indice1<4; indice1++){
    fprintf(txt,"%c",codigo[indice1]);
  } 
  fprintf(txt,"\n");
  fclose(txt);*/

  //INICIALMOS EL STRUCT INICIAL CON LOS GUIONES Y EL CODIGO SECRETO
  strcpy(inicial->guiones, "------------");
  strcpy(inicial->codigo, codigo);

 
  //YA TENEMOS CREADO  SECRETO
  do{
    ganar=0;
    perder=0;
    do{
      do{
	error=0;
	
	//printf("\nEscriba un número de 4 dígitos diferentes + ENTER:");
	imprimir(4, idioma);
	scanf(" %s", apuesta);
	printf("\n");
      
	while(strlen(apuesta)!=4){
	
	  //  printf("\nLa longitud de la apuesta es incorrecta\n");
	  imprimir(5, idioma);
	  //printf("\nEscriba un número de 4 dígitos diferentes + ENTER:");
	  imprimir(4, idioma);
	  scanf(" %s", apuesta);
	  printf("\n");
	}

	for(indice1=0; indice1<4; indice1++){
	  if(apuesta[indice1]>='0'  && apuesta[indice1]<='9') continue;
	  else{
	    error=1;
	    // printf("La apuesta solo debe contener dígitos\n");
	    imprimir(6, idioma);
	    break;
	  }
	}
      }while(error==1);

      error=0;
  
      for(indice1=0; indice1<4; indice1++){
	for(indice2=0; indice2<4; indice2++){
	  if(indice1==indice2)continue;
	  if(apuesta[indice2]==apuesta[indice1]){
	    //  printf("\nLos digitos de la apuesta deben ser diferentes\n");
	    error=1;
	    break;
	  }
	  if(error==1)break;
	}
      }
      if(error==1)imprimir(7, idioma);
    }while(error==1);

    /*PASAMOS LA BATERÍA DE PRUEBAS PARA SABER SI EL CODIGO INTRODUCIDO ES CORRECTO*/
  
    //AHORA MIRAMOS LOS ELEMENTOS DEL CODIGO QUE SE ACERTARON O NO 
  /*  printf("El codigo secreto es: ");
    for(indice1=0; indice1<4; indice1++){
      printf("%c", codigo[indice1]);
    }
  */
    //printf("\nSu apuesta es: <");
    imprimir(8, idioma);
    for(indice1=0; indice1<4; indice1++){
      printf("%c", apuesta[indice1]);
    }
    printf("  <");
 

    for(indice1=0; indice1<4; indice1++){
      a=0;
      b=0;
      for(indice2=0; indice2<4; indice2++){
	if(apuesta[indice1]==codigo[indice2]){
	  if(indice1==indice2){
	    a=1; // printf("*");
	    // break;
	  }
	  else{
	    b=1;// printf("|");
	    //  break;
	  }
	}
	else{
	  //	break;
	}
      }
      if(a==1){
	apuesta_c[indice1]='*'; //printf("*");
      }
      else{
	if(b==1)apuesta_c[indice1]='|';//printf("|");
	else apuesta_c[indice1]='_';//printf("_");
      }
    }

    for(indice1=0; indice1<4; indice1++){ //IMPRESION DE LOS CARACTERES DE SALIDA.
      if(apuesta_c[indice1]=='*'){
	printf("%c", apuesta_c[indice1]);
	apuesta_final[contimpresion]='*';
	
	contimpresion++;
      } }
		
    for(indice1=0; indice1<4; indice1++) {
      if(apuesta_c[indice1]=='|')	{
	printf("%c", apuesta_c[indice1]);
	apuesta_final[contimpresion]='|';
	contimpresion++;
      } }
		
    for(indice1=0; indice1<(4-contimpresion); indice1++) {
      printf("_");
      apuesta_final[indice1+contimpresion]='_';
    }
    contimpresion=0; //Ponemos contador a 0 para la siguiente ejecución de la impresión de salida.
    printf(">\n"); //ACABAMOS DE COMPROBAR LA APUESTA CON EL CODIGO
    oportunidades--;    //QUITAMOS UN INTENTO
  //  printf(" Quedan %i", oportunidades); 
    intentos++;
    
    /*txt=fopen("partidas.txt","a+"); //ESCRITURA EN FICHERO DE LAS APUESTAS Y ACIERTOS.
    for(indice1=0; indice1<4; indice1++){
      fprintf(txt,"%c", apuesta[indice1]);
    }
    fprintf(txt,"  <");
    for(indice1=0; indice1<4; indice1++){
      fprintf(txt, "%c", apuesta_final[indice1]);
    }
    fprintf(txt,">  \n");
    fclose(txt);*/

    //ESCRIBIMOS LA APUESTA Y LOS ACIERTOS

    strcpy(apuestas[t].apuesta, apuesta);
    apuestas[t].aciertos[0]='<';
    apuestas[t].aciertos[5]='>';
    for(indice1=1; indice1<5; indice1++){
      apuestas[t].aciertos[indice1]=apuesta_final[indice1-1];
    }
    

    t++; 

    /* for(indice1=0; indice1<4; indice1++){
       printf("%c", apuesta_c[indice1]);
       }
       printf(">"); //ACABAMOS DE COMPROBAR LA APUESTA CON EL CODIGO
  
       //QUITAMOS UN INTENTO
       oportunidades--;
       printf("%i", oportunidades);
       intentos++;*/
    
    if(oportunidades==0)perder=1; //PIERDE LA PARTIDA

    for(indice1=0; indice1<4; indice1++){ //COMPROBAMOS SI TODOS SON ASTERISCOS*
      if(apuesta_c[indice1]=='*')ganar=ganar+1;
    }
    
  }while(ganar!=4 && perder!=1);

  if(perder==1)derrota(codigo, indice1, intentos, idioma); //PIERDE
  else felicitaciones(intentos, codigo, indice1, idioma); //GANA

  return t;
  
}




/*int main(){
  
  partida_normal();
  return 0;
  }*/
