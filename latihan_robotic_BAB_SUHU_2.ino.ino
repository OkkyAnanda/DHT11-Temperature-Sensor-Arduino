#include <DHT11.h>
int pin=9;
DHT11 dht11(pin); 
int LED1=7;
int Speaker =3;

void setup()
{
   Serial.begin(9600);
   pinMode(7,OUTPUT);
  while (!Serial) {
      ; // wait for serial port to connect. Needed for Leonardo only
    }
}

void loop()
{
  int err;
  float temp, humi;
  if((err=dht11.read(humi, temp))==0)
  {
    
    if (temp>=29){
Serial.println("26");

}else{
 Serial.println("Aman");

}
  }
  else
  {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();    
  }
  delay(DHT11_RETRY_DELAY); //delay for reread
}



