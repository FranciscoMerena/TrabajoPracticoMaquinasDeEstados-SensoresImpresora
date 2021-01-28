#ifndef CODIGO_LIB_LIB_H_
#define CODIGO_LIB_LIB_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include <stdbool.h>


typedef struct{/*tipo de datos de sensores*/
int sensor_rojo;
int sensor_azul;
int sensor_amarillo;
int sensor_negro;
bool sensor_papel;
}sensores_t;
typedef enum{/*tipo de datos de estados de la impresra*/
impresora_error,/*enumera este estado a 0*/
impresora_lista/*enumera este estado a 1*/
}estados_t;

sensores_t leerSensores(void);
void MensajeImpresora(sensores_t);//mensaje impresora
sensores_t inicio (void);/*header de la funcon inicio*/
sensores_t seteo (char*);/*header de la funcion seteo*/
estados_t funcionimpresora_lista(sensores_t*);/*header del estado de la funcion impresora lista*/
estados_t funcionimpresora_error(sensores_t*);/*header de la funcion de la impresora fuera de funcionamiento*/
 
 #endif
