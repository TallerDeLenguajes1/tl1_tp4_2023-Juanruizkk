#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAMA 200

struct Tarea {
    int tareaID; //Numerado en ciclo iterativo
    char *descripcion;
    int duracion; // entre 10 – 100
}typedef tarea;

int main(){
    srand(time(NULL));
    int canttareas,realizado;
    char buffer[TAMA];
    printf("Cuanta cantidad de tareas desea realizar?");
    scanf("%d",&canttareas);
    fflush(stdin);
    tarea ** tareaspend=(tarea **)malloc(sizeof(tarea)*canttareas);
    tarea ** tareasraliz=(tarea **)malloc(sizeof(tarea)*canttareas);
    for (int i = 0; i < canttareas; i++)
    {
        tareaspend[i]=NULL;
        tareasraliz[i]=NULL;
    }
    for (int i = 0; i < canttareas; i++)
    {
        tareaspend[i] = malloc(sizeof(tarea));
        tareaspend[i]->tareaID= i + 1; 
        printf("Ingrese la descripcion de la tarea\n");
        scanf("%c", &buffer);
        fflush(stdin);
        tareaspend[i]->descripcion = malloc(sizeof(buffer+1));
        strcpy(tareaspend[i]->descripcion, buffer);
        tareaspend[i]->duracion= 10 + rand() % 90;
    }
    for (int i = 0; i < canttareas; i++)
    {
        printf("Realizo la tarea (1:Verdadero 0:Falso):%d\n",tareaspend[i]->tareaID);
        scanf("%d",&realizado);
        fflush(stdin);
        if (realizado==1)
        {
            tareasraliz[i]=tareaspend[i];
            tareaspend[i]=NULL;
        }
        
    }
    //Mostrar
    printf("Tareas realizadas\n");
    for (int i = 0; i < canttareas; i++)
    {
         if (tareasraliz[i] != NULL)
        {
             printf("No de ID: %d\n", tareasraliz[i]->tareaID);     
        }
           
    }
    printf("Tareas pendientes\n");
    for (int i = 0; i < canttareas; i++)
    {
        if (tareaspend[i] != NULL)
        {
            printf("No de ID: %d\n", tareaspend[i]->tareaID);     
        }
        
          
    }
    
    return 0;
}