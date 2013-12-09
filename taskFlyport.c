#include "taskFlyport.h"
#include "grovelib.h"
#include "analog_temp.h"
double temp;
BOOL estado = FALSE;

void FlyportTask()
{	
	vTaskDelay(100);
	char msg[100];
	UARTWrite(1,"Welcome to GROVE NEST example!\r\n");
	WFConnect(WF_DEFAULT);
	
	// GROVE board
	void *boardNest = new(GroveNest);

	// Ejemplo 1: Encendido de led y medición de temperatura
	// GROVE devices	
	// Digital Input
	// Creación dispositivos
	// Dispositivo de luz
	void * sensorLuz;
	sensorLuz = new(Dig_io, OUT);
	// Dispositivo de temperatura
	void *sensorTemperatura = new(An_Temp);
	
	
	// Conectar dispositivos a señales 
	attachToBoard(boardNest, sensorLuz, DIG1);
	attachToBoard (boardNest, sensorTemperatura, AN1);
	
	// Inicialización de la luz a apagada
	set(sensorLuz,off);
	while(1)
	{
		UARTWrite(1, "Midiendo...");
		// Dependiendo del estado encendemos o apagamos la luz
		if(estado == TRUE)
			set(sensorLuz, on);
		else
			set(sensorLuz, off);
			
		//Medimos la temperatura
		temp = (double)get(sensorTemperatura);
		sprintf(msg, "temperature: %2.1f\r\n", (double)(get(sensorTemperatura)));
		UARTWrite(1, msg);
		
		vTaskDelay(100);		
	}
	
}

