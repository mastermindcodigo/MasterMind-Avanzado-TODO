typedef struct apuestas{
    char apuesta[4];
    char aciertos[9];
  }Apuestas;

typedef struct inicial{
   char guiones[16];
   char codigo[4];
 }Inicial;

typedef struct fin{
   int intentos;
   float puntuacion;
 }Fin;


int jugar_partida(int, int*, int*, char*, int, Inicial* , Fin*, Apuestas*);
int establecer_nivel(int, int*, int*);
int listar_historial(int*);
int partida_normal(int, char*, int*, Inicial*, Fin*, Apuestas*);
void guardar_partida(Apuestas*, Inicial*, Fin*, int);
void idioma(int*);
