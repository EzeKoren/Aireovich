#include <DHT.h>

#include <ESP8266WiFi.h>

#define LedAire 2
#define ButtonPlus 4
#define ButtonLess 0 
#define Sensor 5
#define DHTTYPE DHT22

DHT dht(Sensor, DHTTYPE);

int maximo = 30;
int minimo = 19;
int temp = 24;
float temperatura;



void setup(){
    dht.begin();
    pinMode(ButtonPlus, INPUT_PULLUP);
    pinMode(ButtonLess, INPUT_PULLUP);
    pinMode(LedAire, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    //chequear si aprieta boton


    temperatura = dht.readTemperature();
    while(temperatura < 1 || isnan(temperatura)){
        temperatura = dht.readTemperature();
    }
    
    Serial.println(temperatura);

    if (digitalRead(ButtonPlus) == LOW && temp < maximo) {
        temp++;
    }
    else if (digitalRead(ButtonLess) == LOW && temp > minimo) {
        temp--;
    }
    
    if (temperatura > temp)
    {
        //prende aire
        digitalWrite(LedAire, LOW);
    } 
    else if (temperatura < temp) {
        //apaga aire
        digitalWrite(LedAire, HIGH);
    }

    delay(1000);
}