#include <SparkFun_RHT03.h>

/*
  Include this library  https://github.com/sparkfun/SparkFun_RHT03_Arduino_Library
*/

int RHT03_DATA_PIN;
float humidity, temper; //temp F
RHT03 rht;

EnvironmentalSensor::EnvironmentalSensor(){
  
}

void EnvironmentalSensor::envUpdate(int dataPin){
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

float EnvironmentalSensor::getHumidity(){
  return humidity;
}

float EnvironmentalSensor::getTemper(){
  return temper;
}
