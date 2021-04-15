/*
 Name:		Bulbe.ino
 Created:	15/04/2021 09:57:47
 Author:	axou
*/

/*
 Name:		HCSR04_com.ino
 Created:	12/04/2021 09:57:47
 Author:	pc_technique_swarmz
*/


#include "Sensor_system.h"

 // Cair ? (331.3 + 0.606 ? ?) m/s
capteur_struct caca;

void setup()
{
    init_sensor();
    Serial.begin(9600);
}

void loop()
{

    trig_sensor();
    caca = get_sensor();
    Serial.print("FACE");
    Serial.println(caca.face );
    Serial.print("ARRIERE");
    Serial.println(caca.arriere);
    Serial.print("DROITE");
    Serial.println(caca.droite);
    Serial.print("GAUCHE");
    Serial.println(caca.gauche);

}

