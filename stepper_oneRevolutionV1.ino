// подключение библиотеки
#include <AccelStepper.h>
// создаем экземпляр AccelStepper
#define IN1 7
#define IN2 9
#define IN3 10
#define IN4 11

#define IN5 2
#define IN6 3
#define IN7 5
#define IN8 6

AccelStepper RightMotor(8, IN1, IN3, IN2, IN4);
AccelStepper LeftMotor(8, IN5, IN7, IN6, IN8);

void setup(){
  LeftMotor.setMaxSpeed(1600.0);
  LeftMotor.setAcceleration(1000.0);
  //LeftMotor.setSpeed(200);
  LeftMotor.moveTo(2000);

  RightMotor.setMaxSpeed(-1600.0);
  RightMotor.setAcceleration(-1000.0);
  //RightMotor.setSpeed(200);
  RightMotor.moveTo(-2000);
}

void loop(){
  // Изменяем направление, если пройдено заданное число шагов
  if(LeftMotor.distanceToGo()==0)
    LeftMotor.moveTo(-LeftMotor.currentPosition());
  LeftMotor.run();

  if(RightMotor.distanceToGo()==0)
    RightMotor.moveTo(-RightMotor.currentPosition());
  RightMotor.run();
}
