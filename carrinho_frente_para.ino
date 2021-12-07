#include <AFMotor.h>


AF_DCMotor motor_esq(2);
AF_DCMotor motor_dir(3); 

int SEN1, SEN2, SEN3;
int startSpeed = 100, brake = 40;

int senlimiar = 5;

int left = startSpeed, rigth = startSpeed;



void setup() {
  // put your setup code here, to run once:
  motor_esq.setSpeed(startSpeed);
  motor_dir.setSpeed(startSpeed);
  delay(1000);
  delay(3000);
  Serial.begin(9600);
  Serial.print("hello word!");
}

void loop() {
  // put your main code here, to run repeatedly:

  rigth = left = startSpeed;
  SEN1 = analogRead(3); // ta ao contrário
  SEN2 = analogRead(4);
  SEN3 = analogRead(5);
  
  
  if(SEN1 > SEN2 + senlimiar){
     rigth = startSpeed - brake;
   }else{
     if(SEN3 > SEN2 + senlimiar){
      left = startSpeed - 45;
     } 
   }
   motor_esq.setSpeed(left);
   motor_dir.setSpeed(rigth);
   motor_esq.run(FORWARD);
   motor_dir.run(FORWARD);


}
