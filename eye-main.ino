/*eye*/
#define VerticalStart 45
#define VerticalEnd 135
#define VerticalStep 2

#define HorizontalStart 0
#define HorizontalEnd 180
#define HorizontalStep 2


#include "Sensors.h"
#include "Servo.h"
#include "Coordinate.h"
#include "SEngine.h"

UltrasonicSensor Dsensor(4, 5);
SEngine VerticalServo(10); //Z-Y angels
SEngine HorizontalServo(11); // Z-X angels

void setup()
{
  Serial.begin(9600);
}

Coordinate lastCo(0.0, 0.0, 0.0);

void loop()
{
  HorizontalServo.Goto(HorizontalStart);
  VerticalServo.Goto(VerticalStart);
  while (HorizontalServo.GetDegrees() < HorizontalEnd)
  {
    HorizontalServo.Move(HorizontalStep);
    while (VerticalServo.GetDegrees() < VerticalEnd)
    {
      VerticalServo.Move(VerticalStep);
      lastCo = calculateCoordinate(VerticalServo.GetDegrees(), HorizontalServo.GetDegrees(), Dsensor.Get());
      Serial.print("There is an object in (");
      Serial.print(lastCo.x); Serial.print(", ");
      Serial.print(lastCo.y); Serial.print(", ");
      Serial.print(lastCo.z); 
      Serial.println(")");
    }
  }
}

Coordinate calculateCoordinate(int ZYangle, int ZXangle, float distance)
{
  float z = sqrt(pow(distance, 2) / (pow(tan(ZXangle), 2) + pow(tan(ZYangle), 2) + 1));
  Coordinate Answer(0.0, 0.0, 0.0);
  Answer.x = tan(ZXangle) * z;
  Answer.y = tan(ZYangle) * z;
  Answer.z = z;

  return (Answer);
}
