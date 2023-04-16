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

struct Nodo{
    tarea T;
    struct Nodo* Siguiente;
};
typedef struct Nodo Nodo;


Nodo* CrearListaVacia();

Nodo* cargarTarea(int tareaID) ;
void insertarAPendiente(Nodo ** Starpend, Nodo* tareaACargar);
Nodo * quitarNodo(Nodo** Starpendm);
Nodo* moverARealizado(Nodo* Starpend, Nodo** StarRealizado);
void mostrarTareas(Nodo* Starpend, Nodo* StarRealizado);
Nodo* buscaTarea(Nodo* Starpend, Nodo* StarRealizado, int numID);
Nodo* buscaTareaPPalabra(Nodo* Starpend, Nodo* StarRealizado, char needle[]);
int main(){
    printf("Comenzar actividad");
    srand(time(NULL));
    Nodo * StarPendiente;
    Nodo * StarRealizado;

    StarPendiente = CrearListaVacia();
    StarRealizado = CrearListaVacia();

    int cargar = 1;
    char buffer[TAMA];
    int tareaID = 0;
    int realizado;
    int numID;
    char palabrabusqueda[TAMA];

    while (cargar != 0)
    {
            //DATOS DE LA TAREA


        Nodo* NuevaTarea= cargarTarea(tareaID);
        tareaID++;
        insertarAPendiente(&StarPendiente, NuevaTarea);
        printf("Desea cargar una nueva tarea (1:SI, 0:NO)\n");
        scanf("%d", &cargar);
    }

    StarPendiente = moverARealizado(StarPendiente, &StarRealizado);

    //  MOSTRAR TAREAS  
    mostrarTareas(StarPendiente, StarRealizado);

    
    printf("Ingrese el numero de ID de la tarea que quiere buscar:\n");
    scanf("%d", &numID);

    Nodo* buscada = buscaTarea(StarPendiente, StarRealizado, numID);

    printf("Num ID: %d\n", buscada->T.tareaID);
    printf("Descripcion: %s\n", buscada->T.descripcion);
    printf("Duracion: %d\n", buscada->T.duracion);
    
    printf("Ingrese la palabra clave para buscar la tarea:\n");
    scanf("%s", palabrabusqueda);

    Nodo* BuscadaPPlabra = buscaTareaPPalabra(StarPendiente,StarRealizado, palabrabusqueda);
    printf("Num ID: %d\n", BuscadaPPlabra->T.tareaID);
    printf("Descripcion: %s\n", BuscadaPPlabra->T.descripcion);
    printf("Duracion: %d\n", BuscadaPPlabra->T.duracion);


    
     return 0;
}

Nodo* CrearListaVacia(){
    return NULL;
}
Nodo* cargarTarea(int tareaID ){
    char buffer[TAMA];
    tarea *nuevaTarea = malloc(sizeof(tarea));
    nuevaTarea->tareaID= tareaID + 1; 
    printf("Ingrese la descripcion de la tarea\n");
    scanf("%s", &buffer);
    fflush(stdin);
    nuevaTarea->descripcion = malloc(sizeof(buffer+1));
    strcpy(nuevaTarea->descripcion, buffer);
    nuevaTarea->duracion= 10 + rand() % 90;
/*     printf("%d", nuevaTarea->duracion); */
    Nodo* NuevoNodo = malloc(sizeof(Nodo));
    NuevoNodo->T = *nuevaTarea;
    NuevoNodo->Siguiente = NULL;
/*     printf("%d", NuevoNodo->T.duracion); */

return NuevoNodo;
}
void insertarAPendiente(Nodo ** Starpend, Nodo* tareaACargar){
    Nodo* nuevaTarea = tareaACargar;
    nuevaTarea->Siguiente = *Starpend;
    *Starpend = nuevaTarea;
}
Nodo * quitarNodo(Nodo** Starpend){
    Nodo* Aux = *Starpend;
    (*Starpend) = (*Starpend)->Siguiente;
    return Aux; 
}

Nodo* moverARealizado(Nodo* StarPend, Nodo** StarRealizado){
    Nodo* LP = CrearListaVacia();
    Nodo* aux;
    int realizado;
    while (StarPend)
    {
        printf("No de ID: %d\n", StarPend->T.tareaID);
        printf("Descripcion: %s\n", StarPend->T.descripcion);
        printf("Duracion: %d\n", StarPend->T.duracion);
        printf("Realizo la tarea (1:Verdadero 0:Falso):%d\n",StarPend->T.tareaID);
        scanf("%d",&realizado);
        fflush(stdin);
        if (realizado == 1)
        {
            aux = quitarNodo(&StarPend);
            aux->Siguiente = (*StarRealizado);
            (*StarRealizado) = aux;
        } else
        {
            aux = quitarNodo(&StarPend);
            aux->Siguiente = LP;
            LP = aux;
        }
    }
    return LP;
    

}
void mostrarTareas(Nodo* Starpend, Nodo* StarRealizado){
    while (StarRealizado != NULL)
    {
        printf("TAREAS REALIZADAS:\n");
        printf("No de ID: %d\n", StarRealizado->T.tareaID);
        printf("Descripcion: %s\n", StarRealizado->T.descripcion);
        printf("Duracion: %d\n", StarRealizado->T.duracion);
        StarRealizado = StarRealizado->Siguiente; 
    }
    
    while (Starpend != NULL)
    {
         printf("TAREAS PENDIENTES:\n");
         printf("No de ID: %d\n", Starpend->T.tareaID);
        printf("Descripcion: %s\n", Starpend->T.descripcion);
        printf("Duracion: %d\n", Starpend->T.duracion);
        Starpend = Starpend->Siguiente; 
    }
    
}

Nodo* buscaTarea(Nodo* Starpend, Nodo* StarRealizado, int numID){
    while (Starpend != NULL)
    {
        if ((Starpend)->T.tareaID == numID)
        {
            return (Starpend);
        }
        Starpend = Starpend->Siguiente;
    }
    while (StarRealizado != NULL)
    {
        if ((StarRealizado)->T.tareaID == numID)
        {
            return (StarRealizado);
        }
        StarRealizado = StarRealizado->Siguiente;
    }
    return NULL;
}
Nodo* buscaTareaPPalabra(Nodo* Starpend, Nodo* StarRealizado, char needle[]){
    while (Starpend != NULL)
    {
        if (strstr(Starpend->T.descripcion, needle) != NULL)
        {
            return Starpend;
        }
        Starpend = Starpend->Siguiente;
    }
    while (StarRealizado != NULL)
    {
        if (strstr(StarRealizado->T.descripcion, needle) != NULL)
        {
            return StarRealizado;
        }
        StarRealizado = StarRealizado->Siguiente;
    }
 return NULL;
}
