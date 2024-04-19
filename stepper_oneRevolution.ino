// подключение библиотеки
#include <AccelStepper.h>
// создаем экземпляр AccelStepper
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 10
AccelStepper LeftMotor(8, IN1, IN3, IN2, IN4);

void setup(){
  LeftMotor.setMaxSpeed(900.0);
  LeftMotor.setAcceleration(1000.0);
  //LeftMotor.setSpeed(200);
  LeftMotor.moveTo(2000);
}

void loop(){
  // Изменяем направление, если пройдено заданное число шагов
  if(LeftMotor.distanceToGo()==0)
    LeftMotor.moveTo(-LeftMotor.currentPosition());
  LeftMotor.run();
}
