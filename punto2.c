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

tarea * cargarTareas(int cantTareas, tarea** tareaspend);
void moverARealizado(int cantTareas, tarea** tareaspend, tarea** tarearaliz);
void mostrarTodasTareas(int cantTareas, tarea** tareaspend, tarea** tarearaliz);

tarea* buscaTarea(tarea** tareaPend, tarea** tareaRlzda, int numID, int cantTareas);
tarea* buscaTareaPPalabra(tarea** tareaPend, tarea** tareaRlzda, char needle[], int cantTareas);
int main(){
    srand(time(NULL));
    int canttareas,realizado;
    char buffer[TAMA];
    printf("Cuanta cantidad de tareas desea realizar?");
    scanf("%d",&canttareas);
    fflush(stdin);
    tarea ** tareaspend=(tarea **)malloc(sizeof(tarea)*canttareas);
    tarea ** tareasraliz=(tarea **)malloc(sizeof(tarea)*canttareas);

    // INICIAR TAREAS EN NULL
    for (int i = 0; i < canttareas; i++)
    {
        tareaspend[i]=NULL;
        tareasraliz[i]=NULL;
    }

    tarea* Cargar = cargarTareas(canttareas, tareaspend);
    moverARealizado(canttareas, tareaspend, tareasraliz);
    mostrarTodasTareas(canttareas, tareaspend, tareasraliz);



    //Mostrar


    // BUSCA-TAREA

    tarea* aBuscar = buscaTarea(tareaspend, tareasraliz, 1, canttareas);
    printf("Tarea buscada:\n");
    printf("No de ID: %d\n", aBuscar->tareaID);
    printf("Descripcion: %s\n", aBuscar->descripcion);
    printf("Duracion: %d\n", aBuscar->duracion);

    //////////////////////////////////////

    // BUSCA-TAREA STRSTR
    char palabra[TAMA];
    printf("Buscar tarea por palabra clave - Ingresar Palabra:\n");
    scanf("%s", &palabra);

    tarea* aBuscarPPalabra = buscaTareaPPalabra(tareaspend, tareasraliz, palabra, canttareas);
    if (aBuscarPPalabra != NULL)
    {
        printf("Tarea buscada:\n");
        printf("No de ID: %d\n", aBuscarPPalabra->tareaID);
        printf("Descripcion: %s\n", aBuscarPPalabra->descripcion);
        printf("Duracion: %d\n", aBuscarPPalabra->duracion);
    }else
    {
        printf("No se encuentro tal tarea");
    }
    
    

    //////////////////////////////////////



    
    return 0;
}
tarea * cargarTareas(int cantTareas, tarea** tareaspend){
    char buffer[TAMA];
    for (int i = 0; i < cantTareas; i++)
    {
        tareaspend[i] = malloc(sizeof(tarea));
        tareaspend[i]->tareaID= i + 1; 
        printf("Ingrese la descripcion de la tarea\n");
        scanf("%s", &buffer);
        fflush(stdin);
        tareaspend[i]->descripcion = malloc(sizeof(buffer+1));
        strcpy(tareaspend[i]->descripcion, buffer);
        tareaspend[i]->duracion= 10 + rand() % 90;
    }
}
void moverARealizado(int cantTareas, tarea** tareaspend, tarea** tarearaliz){
    int realizado;
    for (int i = 0; i < cantTareas; i++)
    {
        printf("Realizo la tarea (1:Verdadero 0:Falso):%d\n",tareaspend[i]->tareaID);
        scanf("%d",&realizado);
        fflush(stdin);
        if (realizado==1)
        {
            tarearaliz[i]=tareaspend[i];
            tareaspend[i]=NULL;
        }
        
    }
}
void mostrarTodasTareas(int cantTareas, tarea** tareaspend, tarea** tarearaliz){
        printf("Tareas realizadas\n");
    for (int i = 0; i < cantTareas; i++)
    {
         if (tarearaliz[i] != NULL)
        {
             printf("No de ID: %d\n", tarearaliz[i]->tareaID);     
        }
           
    }
    printf("Tareas pendientes\n");
    for (int i = 0; i < cantTareas; i++)
    {
        if (tareaspend[i] != NULL)
        {
            printf("No de ID: %d\n", tareaspend[i]->tareaID);     
        }
        
          
    }
}

tarea* buscaTarea(tarea** tareaPend, tarea** tareaRlzda, int numID, int cantTareas){
    
    
    for (int i = 0; i < cantTareas; i++)
    {
        if (tareaPend[i]!= NULL)
        {
           if (tareaPend[i]->tareaID == numID)
           {
            return tareaPend[i];
           }
           
        }
        if (tareaRlzda[i]!= NULL)
        {
           if (tareaRlzda[i]->tareaID == numID)
           {
            return tareaRlzda[i];
           }
           
        }
        
        
        
    }
    
}

tarea* buscaTareaPPalabra(tarea** tareaPend, tarea** tareaRlzda, char needle[], int cantTareas){
     for (int i = 0; i < cantTareas; i++)
     {
         if (tareaPend[i]!= NULL)
        {
            if (strstr(tareaPend[i]->descripcion, needle) != NULL)
            {
                return tareaPend[i];
            }
        }
        if (tareaRlzda[i]!= NULL)
        {
             if (strstr(tareaRlzda[i]->descripcion, needle)!= NULL)
            {
                return tareaRlzda[i];
            }
        }
     }
 return NULL;
}
