#include <Wire.h>
//#include <math.h>
#include <JY901.h>
/*
Test on Uno R3.
JY901    UnoR3
SDA <---> SDA
SCL <---> SCL
*/


float base_angle;
float angle[20];
 int a[101]; int sum[25];
 int i,count,minus1 = 0;

void setup() 
{
  Serial.begin(115200);
  JY901.StartIIC();

  for (i = 0; i < 20; i++) 
{
  JY901.GetAngle();
  angle[19 - i] = (float) JY901.stcAngle.Angle[1]/32768*180;
  base_angle += angle[19-i];
  delay(100);
}

 int a[101]; int sum[25];
 int i,count,minus1 = 0;

          for ( i=0; i<100; i++)
     {
        JY901.GetPress();
        a[i]=(int)JY901.stcPress.lPressure;
     }
    for (count=0; count < 25; count ++)
    {

      JY901.GetPress();
      for ( i=0; i<100; i++)
     {
        sum[count] = sum[count] + a [i];

        a[i]=a[i+1];
     }
     a[100]= (int)JY901.stcPress.lPressure;
    }
} 

int previous = 0;
int current = 0;
/*
float coe[9] = { 0.04398f, 0.0975f, 0.14908f, 0.18639f, 0.2f, 0.18639f, 0.14908f, 0.0975f, 0.04398f };
float AccA = 0.0f, AccB = 0.0f, AccC = 0.0f;
float Acc[9] = { 0.0f };
float AccLPF = 0.0f;
float AccAll[150];
float AccMax = 1.2f, AccMin = 1.2f;
float AccTher = 1.2f;
float AccPP = 0.0f;
int index = 0;
int count1 = 0, count2 = 0;
int countStep = 0;
bool flag = true;*/

void loop() 
{
  float base = 0;
  float judge;
  int situation;
  int count_up = 0;
  int count_down = 0;
  
  //print received data. Data was received in serialEvent;
  JY901.GetTime();
  //Serial.print("Time:20");Serial.print(JY901.stcTime.ucYear);Serial.print("-");Serial.print(JY901.stcTime.ucMonth);Serial.print("-");Serial.print(JY901.stcTime.ucDay);
  current = (int)JY901.stcTime.usMiliSecond;
  if (current - previous < 0 && previous >= 960) {
    previous -= 1000;
  }
  if ( current - previous >= 10 && current - previous <= 25) {
  previous = current;
  //Serial.print(JY901.stcTime.ucMinute);Serial.print(":");
  Serial.print(JY901.stcTime.ucSecond);Serial.print(".");Serial.println(JY901.stcTime.usMiliSecond);
     /*     
  JY901.GetAcc();
  AccA = JY901.stcAcc.a[0];
  AccB = JY901.stcAcc.a[1];
  AccC = JY901.stcAcc.a[2];
  //Serial.print(" ");Serial.print(AccA);Serial.print(" ");Serial.print(AccB);Serial.print(" ");Serial.print(AccC);
  Acc[8] = sqrt(AccA*AccA + AccB*AccB + AccC*AccC)/2048;
  AccLPF = 0.0f;
  for (int i = 0; i < 9; i++)
  {
    AccLPF += Acc[8 - i]*coe[i];
  }
  for (int i = 0; i < 8; i++)
  {
    Acc[i] = Acc[i + 1];
  }
  if (index >= 150)
  {
    //count1 = count2 = 0;
    //AccMax = AccMin = 1.2f;
    //AccTher = 1.2f;
    index = 0;
    //AccPP = 0.0f;
    //flag = true;
  }
  Serial.print(" Acc:");Serial.println(AccLPF);
  AccAll[index++] = AccLPF;
  if (flag && index == count2)
  {
    count1 = count2 = 0;
    index = 0;
  }
  if (!flag && index == count1)
  {
    count1 = count2 = 0;
    index = 0;
  }
  if (AccLPF > AccTher && flag)
  {
    flag = false;
    count1 = index - 1;
    AccMin = AccAll[count2];
    for (int i = count2 + 1; i != count1; i++)
    {
      if (i >= 150) i = 0;
      if (AccAll[i] < AccMin)
        AccMin = AccAll[i];
    }
    if (AccPP > 0.22f)
    {
      countStep++;
      Serial.print(" A step is noticed: ");Serial.println(countStep);
    }
  }
  else if (AccLPF <= AccTher && !flag)
  {
    flag = true;
    count2 = index - 1;
    AccMax = AccAll[count1];
    for (int i = count1 + 1; i != count2; i++)
    {
      if (i >= 150) i = 0;
      if (AccAll[i] > AccMax)
        AccMax = AccAll[i];
    }
  }
  AccTher = (AccMin + AccMax) / 2;
  if (AccTher < 1.2) AccTher = 1.2;
  AccPP = AccMax - AccMin;
  //
  /
  JY901.GetGyro();  
  Serial.print(" Gyro:");Serial.print((float)JY901.stcGyro.w[0]);Serial.print(" ");Serial.print((float)JY901.stcGyro.w[1]);Serial.print(" ");Serial.print((float)JY901.stcGyro.w[2]);
  */
  JY901.GetAngle();
  Serial.print(" Angle:");Serial.print((float)JY901.stcAngle.Angle[0]);Serial.print(" ");Serial.print((float)JY901.stcAngle.Angle[1]);Serial.print(" ");Serial.print((float)JY901.stcAngle.Angle[2]);
  
  //JY901.GetMag();
 //Serial.print("Mag:");Serial.print(JY901.stcMag.h[0]);Serial.print(" ");Serial.print(JY901.stcMag.h[1]);Serial.print(" ");Serial.println(JY901.stcMag.h[2]);
  
JY901.GetPress();
  Serial.print(" Pressure:");Serial.println(JY901.stcPress.lPressure);//Serial.print(" ");Serial.println((float)JY901.stcPress.lAltitude/100);
  
//JY901.GetDStatus();
 // Serial.print("DStatus:");Serial.print(JY901.stcDStatus.sDStatus[0]);Serial.print(" ");Serial.print(JY901.stcDStatus.sDStatus[1]);Serial.print(" ");Serial.print(JY901.stcDStatus.sDStatus[2]);Serial.print(" ");Serial.println(JY901.stcDStatus.sDStatus[3]);
  
//JY901.GetLonLat();
 // Serial.print("Longitude:");Serial.print(JY901.stcLonLat.lLon/10000000);Serial.print("Deg");Serial.print((double)(JY901.stcLonLat.lLon % 10000000)/1e5);Serial.print("m Lattitude:");
/*  Serial.print(JY901.stcLonLat.lLat/10000000);Serial.print("Deg");Serial.print((double)(JY901.stcLonLat.lLat % 10000000)/1e5);Serial.println("m");
  
JY901.GetGPSV();
  Serial.print("GPSHeight:");Serial.print((float)JY901.stcGPSV.sGPSHeight/10);Serial.print("m GPSYaw:");Serial.print((float)JY901.stcGPSV.sGPSYaw/10);Serial.print("Deg GPSV:");Serial.print((float)JY901.stcGPSV.lGPSVelocity/1000);Serial.println("km/h");
  
  Serial.println("");
  //delay(500);*/
  
  }
  
  for (i=19;i>0;i--)
  {
    base += angle[i];
    angle[i] = angle[i-1];
  }
  base += angle[0];
  JY901.GetAngle();
  angle[0] = (float)JY901.stcAngle.Angle[1]/32768*180;
  judge = (base - base_angle)/20;

  if (judge > 6)
  {
    situation = 1;
  }
  else if(judge <= -1)
  {
    situation = 2;
  }
  else
  {
    situation = 0;
  }

      switch (situation)
        {
        case 0:
          count_up = 0;
          count_down = 0;
          Serial.println("Walking.\n");
          break;
        case 1:
          count_up = 0;
          if (count_down >= 50)
          {
            Serial.println("downstairs.\n");
          }
          else
          {
            count_down++;
          }
          break;
        case 2:
          count_down = 0;
          if (count_up >= 50)
          {
            Serial.println("upstairs.\n");
          }
          else
          {
            count_up++;
          }
          break;
        default:
          break;
        }

//pressure test
        minus1 = sum[0]-sum[24];

        if(minus1 > 0.7)
        {
            Serial.println("upstairs/n");
        }

        else if (minus1 < 0.9)
        {
            Serial.println("downstairs/n");
        }

        for (count=0 ; count<24 ; count++)
        {
            sum[count]=sum[count+1];
        }
        sum[24]= sum[24]-a[0]+a[100];

       for ( i=0; i<100; i++)
        {
            a[i]=a[i+1];
        }
        JY901.GetPress();
      a[100]= (int)JY901.stcPress.lPressure;

         
}






