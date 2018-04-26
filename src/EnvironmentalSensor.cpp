#include <SparkFun_RHT03.h>
/*
  Include this library  https://github.com/sparkfun/SparkFun_RHT03_Arduino_Library

  Looking at the front (grated side) of the RHT03, the pinout is as follows:
   1     2        3       4
  VCC  DATA  No-Connect  GND
  
  Connect the data pin to Arduino pin D4. Power the RHT03 off the 3.3V bus.
  
  A 10k pullup resistor can be added to the data pin, though it seems to
  work without it. 
*/

class EnvironmentalReader {
  int RHT03_DATA_PIN;
  float humidity, temper; //temp F
  RHT03 rht;

  public: 
  EnvironmentalReader(int dataPin){
    RHT03_DATA_PIN = dataPin;
    rht.begin(RHT03_DATA_PIN); //init sensor
  }
  
  void envUpdate() {
    if (rht.update() == 1) {
      humidity = rht.humidity();
      temper = rht.tempF();
    } else {
      // If the update failed, try delaying for RHT_READ_INTERVAL_MS ms before
      // trying again.
      delay(RHT_READ_INTERVAL_MS);
    }
    delay(1000);
  }
  
  float getHumidity(){
    return humidity;
  }
  
  float getTemper(){
    return temper;
  }
};

EnvironmentalReader sen(2);

void setup(){
  Serial.begin(9600);
}

void loop(){
  sen.envUpdate();
  Serial.print("humidity: ");
  Serial.println(sen.getHumidity());
}

