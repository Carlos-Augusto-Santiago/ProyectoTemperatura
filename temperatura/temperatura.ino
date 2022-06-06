// Incluimos librería
#include <DHT.h>
#include <SoftwareSerial.h>  

#define DHTTYPE DHT11 //tipo de sensor

SoftwareSerial miBT(2, 3);  // pin 3 como RX, pin 2 como TX
                            
// Temperatura
const int DHTPin = 5;     // puerto conectado a la resistencia
float h; //variable de humedad
float t ;  //variable de temperatura
DHT dht(DHTPin, DHTTYPE); //libreria que define el pin de conexion

String msg; //variable que envia los datos a la app

void setup(){
  miBT.begin(9600);    // comunicacion serie entre Arduino y el modulo a 38400 bps
  Serial.begin(9600);             // initialize serial transmission for debugging 
  dht.begin(); // inicias el puerto 
}

void loop(){  
  if (miBT.available() > 0){ 
    msg = miBT.readString();     
  }  
  Temp();  
  enviarlecturas();
  
  delay(50);
}

void enviarlecturas(){
  
   miBT.println(String(h)+ "&" + String(t));
}

//Medir Temperatura
void Temp(){
    // Reading temperature or humidity takes about 250 milliseconds!
    h = dht.readHumidity();
    t = dht.readTemperature();

   if (isnan(h) || isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
   }
}
