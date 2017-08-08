#include <Wire.h>
#include <JY901.h>
/*
Test on Uno R3.
JY901    UnoR3
SDA <---> SDA
SCL <---> SCL
*/
void setup() 
{
  Serial.begin(115200);
  JY901.StartIIC();
} 

int previous = 0;
int current = 0;

void loop() 
{
  //print received data. Data was received in serialEvent;
  JY901.GetTime();
  //Serial.print("Time:20");Serial.print(JY901.stcTime.ucYear);Serial.print("-");Serial.print(JY901.stcTime.ucMonth);Serial.print("-");Serial.print(JY901.stcTime.ucDay);
  current = (int)JY901.stcTime.usMiliSecond;
  if (current - previous < 0 && previous >= 950) {
    previous -= 1000;
  }
  if ( current - previous >= 10 && current - previous <= 25) {
  previous = current;
  //Serial.print(JY901.stcTime.ucMinute);Serial.print(":");
  Serial.print(JY901.stcTime.ucSecond);Serial.print(".");Serial.print(JY901.stcTime.usMiliSecond);
          
  JY901.GetAcc();
  Serial.print(" Acc:");Serial.print((float)JY901.stcAcc.a[0]);Serial.print(" ");Serial.print((float)JY901.stcAcc.a[1]);Serial.print(" ");Serial.print((float)JY901.stcAcc.a[2]);
  
  
  JY901.GetGyro();  
  Serial.print(" Gyro:");Serial.print((float)JY901.stcGyro.w[0]);Serial.print(" ");Serial.print((float)JY901.stcGyro.w[1]);Serial.print(" ");Serial.print((float)JY901.stcGyro.w[2]);
  
  JY901.GetAngle();
  Serial.print(" Angle:");Serial.print((float)JY901.stcAngle.Angle[0]);Serial.print(" ");Serial.print((float)JY901.stcAngle.Angle[1]);Serial.print(" ");Serial.print((float)JY901.stcAngle.Angle[2]);
  
  //JY901.GetMag();
  //Serial.print("Mag:");Serial.print(JY901.stcMag.h[0]);Serial.print(" ");Serial.print(JY901.stcMag.h[1]);Serial.print(" ");Serial.println(JY901.stcMag.h[2]);
  
JY901.GetPress();
  Serial.print(" Pressure:");Serial.println(JY901.stcPress.lPressure);//Serial.print(" ");Serial.println((float)JY901.stcPress.lAltitude/100);
  
/*/JY901.GetDStatus();
 // Serial.print("DStatus:");Serial.print(JY901.stcDStatus.sDStatus[0]);Serial.print(" ");Serial.print(JY901.stcDStatus.sDStatus[1]);Serial.print(" ");Serial.print(JY901.stcDStatus.sDStatus[2]);Serial.print(" ");Serial.println(JY901.stcDStatus.sDStatus[3]);
  
//JY901.GetLonLat();
 // Serial.print("Longitude:");Serial.print(JY901.stcLonLat.lLon/10000000);Serial.print("Deg");Serial.print((double)(JY901.stcLonLat.lLon % 10000000)/1e5);Serial.print("m Lattitude:");
  Serial.print(JY901.stcLonLat.lLat/10000000);Serial.print("Deg");Serial.print((double)(JY901.stcLonLat.lLat % 10000000)/1e5);Serial.println("m");
  
JY901.GetGPSV();
  Serial.print("GPSHeight:");Serial.print((float)JY901.stcGPSV.sGPSHeight/10);Serial.print("m GPSYaw:");Serial.print((float)JY901.stcGPSV.sGPSYaw/10);Serial.print("Deg GPSV:");Serial.print((float)JY901.stcGPSV.lGPSVelocity/1000);Serial.println("km/h");
  
  Serial.println("");
  //delay(500);*/
  
  }
  
}



