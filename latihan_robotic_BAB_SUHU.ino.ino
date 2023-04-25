#include <DHT11.h>
DHT11 DHT;

#define DHT11_pin 4;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("DHT TEST PROGRAM");
Serial.print("LIBRARY VERSION");
Serial.println(DHT11LIB_VERSION);
Serial.println();
Serial.println("type,\tstatus,\tHumidity (%),\tTemperature (C)");
}

void loop() {
  // put your main code here, to run repeatedly:
int chk;
Serial.print("DHT11, \t");  
chk = DHT.read(DHT11_PIN);  //read data
switch (chk){
  case DHTLIB_OK:
               Serial.print("OK,\t");
               break;
  case DHTLIB_ERROR_CHECKSUM:
               Serial.print("Checksum error,\t");
               break;
  case DHTLIB_ERROR_TIMEOUT:
               Serial.print("Time out error,\t");
               break;

  default:
               Serial.print("Uknown error,\t");
               break;
}
//DISLAY DATA
Serial.print(DHT,humidity,1);
Serial.print(",\t");
Serial.print(DHT,temperature,1);

delay(1000);
}
