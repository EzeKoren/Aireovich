#include <DHT.h>

#include <ESP8266WiFi.h>

#define 2 LedAire
#define 3 ButtonPlus
#define 4 ButtonLess
DHT dht(dht_pin, DHTTYPE);

int maxmimo = 30;
int minimo = 19;
int temp = 24;
float temperatura;
    
void setup(){
    dht.begin();
    pinMode(ButtonPlus, INPUT_PULLUP);
    pinMode(ButtonLess, INPUT_PULLUP);
    pinMode(LedAire, OUTPUT);
}

void loop(){
    //chequear si aprieta boton
    
    temperatura = dht.readTemperature();
    while(temperatura < 1 || temperatura(isnan)){
        temperatura = dht.readTemperature();
    }
    
    if (digitalRead(ButtonPlus) == LOW && temp < maximo) {
        temp++;
    }
    else if (digitalRead(ButtonLess) == LOW && temp > minimo) {
        temp--;
    }
    
    if (temperatura > temp)
    {
        //prende aire
        digitalWrite(LedAire, HIGH);
    } 
    else if (temperatura < temp) {
        //apaga aire
        digitalWrite(LedAire, LOW);
    }
}