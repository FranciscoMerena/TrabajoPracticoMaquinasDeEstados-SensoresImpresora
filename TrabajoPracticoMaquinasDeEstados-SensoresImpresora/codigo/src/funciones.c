#include "../lib/lib.h"
char* obtenerClave (char* clave){
	char i=0;
	while (*(clave+i)!=' '){
		i++;
	}
	*(clave+i)=0;
	return clave+i+1;
}
sensores_t seteo(char* archivoseteo){/*lee el puntero al archivoseteo*/
FILE* archivo;
char *clave,*valor,cadena[40];
int i=0;
sensores_t config;
char Variables[4][30]={"NivelMinimoDeTintaRojo","NivelMinimoDeTintaNegro","NivelMinimoDeTintaAmarillo","NivelMinimoDeTintaAzul"};/*crea el dato tipo sensores_t para la configuracion*/
/*seteo inicial,antes de leer el archivo*/
	


	if ((archivo = fopen (archivoseteo,"rt")) == NULL){
		printf ("Error en la apertura archivo configuracion : %s \n",archivoseteo);

	}else{

		fgets (cadena,40,archivo);
		
		do{
			clave = cadena;
			if (*(clave)!='#'&& strlen(clave)>0){
				valor=obtenerClave (clave);
				for(i=0;i<4;i++){
					if (!strcmp(clave,Variables[i])){
						switch (i){
							case 0:
								config.sensor_rojo=atoi(valor);
								break;
								
							case 1:
								config.sensor_negro=atoi(valor);
								break;
								
							case 2:
								config.sensor_amarillo=atoi(valor);
								break;
								
							case 3:
								config.sensor_azul=atoi(valor);
								break;
						}
					}
					}
			}
			fgets (cadena,40,archivo);
		}while(!feof(archivo));
	}
	fclose (archivo);
	printf("%i,%i,%i,%i",config.sensor_amarillo,config.sensor_azul,config.sensor_negro,config.sensor_rojo);
	return config;
}

sensores_t inicio (void){
	sensores_t configuracionInicial;/*creas la variable tipo sensores_t*/
	configuracionInicial = seteo ("configuracion.conf"); /*la rellenas con lo que tiene el archivo de configuracion*/
	return configuracionInicial;/*devuelve el valor que leyo del archivo*/
	}

    void MensajeImpresora(sensores_t sensores){
    printf("sus niveles de tinta son \n Negro:%i  Azul: %i Amarillo:%i Rojo: %i\n",sensores.sensor_negro, sensores.sensor_azul,sensores.sensor_amarillo, sensores.sensor_rojo);
    if (sensores.sensor_papel==0){
    printf("su impresora no tiene papel \n");
   }
   else {
   printf("su impresora tiene papel \n");
   }
}

sensores_t leerSensores(){
	sensores_t lectura;
	int i=0;
		printf("ingrese tinta amarillo=");//los printf los agrego para que al correr el programa se pueda visualizar lo que ocurre
        scanf("%i",&lectura.sensor_amarillo);
        fflush(stdin);//los fflush los tuve que agregar obligado porque no permitia la carga de datos
        printf("ingrese tinta azul=");
        scanf("%i",&lectura.sensor_azul);
        fflush(stdin);
        printf("ingrese tinta negro=");
        scanf("%i",&lectura.sensor_negro);
        fflush(stdin);
        printf("ingrese tinta rojo=");
        scanf("%i",&lectura.sensor_rojo);
        fflush(stdin);
        printf("ingrese papel 1 o 0?=");
       scanf("%i",&i);
       fflush(stdin);
        if(i!=0&&i!=1){
                printf("el sensor de papel esta fallando, por favor llame a su tecnico de confianza \n");
        }else
        lectura.sensor_papel=i;
		MensajeImpresora(lectura);
return lectura;
}

estados_t funcionimpresora_lista(sensores_t ss){
	sensores_t sensor;
	sensor=leerSensores();
	if (sensor.sensor_amarillo <=ss.sensor_amarillo||sensor.sensor_rojo <=ss.sensor_rojo ||sensor.sensor_negro <=ss.sensor_negro|| sensor.sensor_azul <=ss.sensor_azul||sensor.sensor_papel==0){
		printf("su impresora no esta lista para imprimir\n");
		return impresora_error;
	}else{
		printf("su impresora esta lista para imprimir\n");
	return impresora_lista;
    }
}

estados_t funcionimpresora_error(sensores_t ss){
	sensores_t sensor;
	sensor=leerSensores();
	if (sensor.sensor_amarillo <ss.sensor_amarillo||sensor.sensor_rojo <ss.sensor_rojo ||sensor.sensor_negro <ss.sensor_negro|| sensor.sensor_azul <ss.sensor_azul||sensor.sensor_papel==0){
        printf("su impresora no esta lista para imprimir\n");
		return impresora_error;
	}else{
		printf("su impresora esta lista para imprimir\n");
	return impresora_lista;
    }
}
