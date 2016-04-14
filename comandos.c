//COMANDOS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void help(char *arg){

   FILE *help;
  int indice1, c;
  char argumento[6]="--help";

  if(strlen(arg)!=6){
    printf("\nUso: ./principal [--help | codigo_prueba]");
    return;
  }

  for(indice1=0; indice1<6; indice1++){
    if(argumento[indice1]!=arg[indice1]){ //BUSCAMOS DIFERENCIAS ENTRE EL ARGUMENTO CORRECTO Y LO INTRODUCIDO POR EL USUARIO
      printf("\nUso: ./principal [--help | codigo_prueba]");
      return; //FINALIZAMOS LA EJECUCION
    } 
    //SI LLEGA HASTA AQUÍ EL ARGUMENTO INTRODUCIDO ES CORRECTO
  }
	
  help=fopen("help.txt","r");

  while((c=fgetc(help))!=EOF){ //Comparamos con fin de fichero.
    printf("%c",c);
  }
  printf("\n");
  fclose(help);
  return;
}


int prueba(char *arg){

  int indice1, indice2, error;

  if(strlen(arg)!=4) {
    printf("\nLa longitud del código de prueba es incorrecta\n");
    return 1;
  }
  for(indice1=0; indice1<4; indice1++){
    if(arg[indice1]>='0'  &&  arg[indice1]<='9') continue;
    else{
      printf("\nEl código de prueba sólo debe contener dígitos\n");
      return 1;
    }
  }
  for(indice1=0; indice1<4; indice1++){
    for(indice2=0; indice2<4; indice2++){
      if(indice1==indice2)continue;
      if(arg[indice2]==arg[indice1]){
	error=1;
	break;
      }
      if(error==1)break;
    }
  }
  if(error==1){
	printf("\nLos dígitos del código de prueba deben ser diferentes\n");
	return 1;
  }
  return 0;
}
