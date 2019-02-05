#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  
SoftwareSerial BT(8,9);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth
 
char val; // variable to receive data from the serial port
int ledpin = 13; // LED connected to pin 48 (on-board LED)

int sensorpin = 0; //Analog pin

unsigned long lastConnectionTime = 0;
const unsigned long postingInterval = 1000;


void setup() {

  pinMode(ledpin, OUTPUT);  // pin 48 (on-board LED) as OUTPUT
  BT.begin(9600);  
  Serial.begin(9600);       // start serial communication at 9600bps
}

void loop() {

 if (BT.available()){
    val = BT.read();         // read it and store it in 'val'
    Serial.println(val);
 }
  if( val == 'h' )               // if 'H' was received
  {
    digitalWrite(ledpin, HIGH);  // turn ON the LED
  } else { 
    digitalWrite(ledpin, LOW);   // otherwise turn it OFF
  }
  delay(100);                    // wait 100ms for next reading

  /*
  if((millis() - lastConnectionTime > postingInterval)) {
            int ana_A = analogRead(sensorpin);
            BT.print("Sensor reading: ");
            BT.println(ana_A);
            lastConnectionTime = millis();
  }
  */
} 
