#include <AFMotor.h>


AF_DCMotor motor_esq(2);
AF_DCMotor motor_dir(3); 

int SEN1, SEN2, SEN3;
int leftOfset = 0, rigthOfset = 0, center = 0;
int startSpeed = 100, brake = 40;

int senlimiar = 5;

int left = startSpeed, rigth = startSpeed;

/*void calibrate (){
  for(int x = 0; x<10; x++){
      delay(200);
      SEN1 = analogRead(3);
      SEN2 = analogRead(4);
      SEN3 =  analogRead(5);

      leftOfset += SEN1;
      center += SEN2;
      rigth += SEN3;
  }
  
  leftOfset = leftOfset/10;
  center = center/10;
  rigthOfset = rigthOfset/10;

  leftOfset = center - leftOfset;
  rigthOfset = center - rigthOfset;
}*/

void setup() {
  // put your setup code here, to run once:
  motor_esq.setSpeed(startSpeed);
  motor_dir.setSpeed(startSpeed);
  delay(1000);
  //calibrate();
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
