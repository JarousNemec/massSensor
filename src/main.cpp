#include "Arduino.h"
#include "../lib/HX711-0.1/HX711.h"

///main program
#define calibration_factor 11900 //This value is obtained using the SparkFun_HX711_Calibration sketch
#define DOUT 3
#define CLK 2
HX711 scale(DOUT, CLK);
void setup() {
    Serial.begin(9600);
    Serial.println("HX711 scale demo");
    scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
    scale.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0
    Serial.println("Readings:");
}
void loop() {
    Serial.print("Reading: ");
    Serial.print(scale.get_units()/2.2, 3);
    Serial.println(" kg");
    Serial.println();
}



///configuration program
//
//#define DOUT 3
//#define CLK 2
//HX711 scale(DOUT, CLK);
//float calibration_factor = 11920; //-7050 worked for my 440lb max scale setup
//void setup() {
//    Serial.begin(9600);
//    Serial.println("HX711 calibration sketch");
//    Serial.println("Remove all weight from scale");
//    Serial.println("After readings begin, place known weight on scale");
//    Serial.println("Press + or a to increase calibration factor");
//    Serial.println("Press - or z to decrease calibration factor");
//    scale.set_scale();
//    scale.tare(); //Reset the scale to 0
//    long zero_factor = scale.read_average(); //Get a baseline reading
//    Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
//    Serial.println(zero_factor);
//}
//void loop() {
//    scale.set_scale(calibration_factor); //Adjust to this calibration factor
//    Serial.print("Reading: ");
//    Serial.print(scale.get_units()/2.2, 3);
//    Serial.println(" kg");
////    Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
//    Serial.print(" calibration_factor: ");
//    Serial.print(calibration_factor);
//    Serial.println();
//    if(Serial.available())
//    {
//        char temp = Serial.read();
//        if(temp == '+' || temp == 'a')
//            calibration_factor += 10;
//        else if(temp == '-' || temp == 'z')
//            calibration_factor -= 10;
//    }
//}