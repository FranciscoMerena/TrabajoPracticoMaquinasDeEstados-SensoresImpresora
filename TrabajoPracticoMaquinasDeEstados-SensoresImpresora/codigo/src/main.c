#include "..\lib\lib.h"

int main(){

    estados_t estado=impresora_error;
    sensores_t configuracion; /*configoracion es un tipo de dato*/
    configuracion = inicio();

    printf("control de impresora de papel y tinta \n");
    estados_t (*impresora[])(sensores_t)={funcionimpresora_error,funcionimpresora_lista};
    while(1){
        estado=(*impresora[estado])(configuracion);
   
    }
 return 4;
}
