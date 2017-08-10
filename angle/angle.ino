#include <JY901.h>
#include <Wire.h>

float base_angle;
float angle[20];
int i;


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

}

void loop() 
{
  float base = 0;
  float judge;
  int situation;
  int count_up = 0;
  int count_down = 0;
  
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

}
