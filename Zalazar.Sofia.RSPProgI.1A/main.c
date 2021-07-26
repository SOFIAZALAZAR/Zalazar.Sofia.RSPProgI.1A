#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int id;
    char marca[20];
    int tipo;
    float peso;
}eVehiculo;

eVehiculo* newVehiculo();
eVehiculo* newVehiculoParam(int id, char* marca, int tipo, float peso);
int main()
{
    int cant;
    eVehiculo* auxVehiculo = newVehiculoParam(1234,"FIAT",450,1638545.86);
    FILE* f = fopen("vehiculo.bin","wb");
    if(f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
            exit(1);
        }
    if(fwrite(auxVehiculo, sizeof(eVehiculo),1, f) == 1)
    {
      printf("ok archivo binario!\n");
    }
    fclose(f);

    FILE* f = fopen("vehiculo.txt", "w");
    if(f == NULL)
    {
        printf("no se pudo abrir el archivo");
        exit(1);
    }
    cant = fprintf(f,"%d,%s,%d,%f\n",auxVehiculo->id,auxVehiculo->marca,auxVehiculo->tipo,auxVehiculo->peso);
    if(cant !=0)
    {
     printf("Se guardaron los datos correctamente\n")   ;
    }else{
    printf("Ocurrio un error");
    }
    fclose(f);
    return 0;
}


eVehiculo* newVehiculo()
{

    eVehiculo* nuevoVehiculo = (eVehiculo*) malloc(sizeof(eVehiculo));
    if(nuevoVehiculo != NULL)
    {
        nuevoVehiculo->id =0;
        strcpy(nuevoVehiculo->marca," ");
        nuevoVehiculo->tipo= 0;
        nuevoVehiculo->peso = 0;

    }
    return nuevoVehiculo;
}


eVehiculo* newVehiculoParam(int id, char* marca, int tipo, float peso)
{
    eVehiculo* nuevoVehiculo = newVehiculo();
    if(nuevoVehiculo != NULL)
    {
        nuevoVehiculo->id =id;
        strcpy(nuevoVehiculo->marca, marca);
        nuevoVehiculo->tipo= tipo;
        nuevoVehiculo->peso = peso;

    }

    return nuevoVehiculo;
}
