// 
// 
// 

#include "Sensor_system.h"



capteur_struct distance;

double speedOfSoundInCmPerMs = 0.03313 + 0.0000606 * 20; // 20 correspond a la température en degrès

const int trigPin = 13;

double t01 = 0;
double t02 = 0;

double t11 = 0;
double t12 = 0;

double t21 = 0;
double t22 = 0;

double t31 = 0;
double t32 = 0;




void init_sensor() {
    pinMode(trigPin, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(2), interrupt01, RISING); //AVANT
    attachInterrupt(digitalPinToInterrupt(3), interrupt11, RISING); //ARRIERE
    attachInterrupt(digitalPinToInterrupt(18), interrupt21, RISING); //DROIT
    attachInterrupt(digitalPinToInterrupt(19), interrupt31, RISING); //GAUCHE
}





void trig_sensor() {

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

}


capteur_struct get_sensor() {

    return distance;
}

//CAPTEUR FACE
void interrupt01()
{
    t01 = micros();
    attachInterrupt(digitalPinToInterrupt(2), interrupt02, FALLING);
}
void interrupt02()
{
    t02 = micros();

    distance.face = (t02 - t01) / 2 * speedOfSoundInCmPerMs;
    attachInterrupt(digitalPinToInterrupt(2), interrupt01, RISING);
}


//CAPTEUR ARRIERE

void interrupt11()
{
    t11 = micros();
    attachInterrupt(digitalPinToInterrupt(3), interrupt12, FALLING);
}

void interrupt12()
{
    t12 = micros();
    distance.arriere = (t12 - t11) / 2 * speedOfSoundInCmPerMs;
    attachInterrupt(digitalPinToInterrupt(3), interrupt11, RISING);
}



//CAPTEUR Droit

void interrupt21()
{
    t21 = micros();
    attachInterrupt(digitalPinToInterrupt(18), interrupt22, FALLING);
}

void interrupt22()
{
    t22 = micros();
    distance.droite = (t22 - t21) / 2 * speedOfSoundInCmPerMs;
    attachInterrupt(digitalPinToInterrupt(18), interrupt21, RISING);
}




//CAPTEUR gauche

void interrupt31()
{
    t31 = micros();
    attachInterrupt(digitalPinToInterrupt(19), interrupt32, FALLING);
}

void interrupt32()
{
    t32 = micros();
    distance.gauche = (t32 - t31) / 2 * speedOfSoundInCmPerMs;
    attachInterrupt(digitalPinToInterrupt(19), interrupt31, RISING);
}

