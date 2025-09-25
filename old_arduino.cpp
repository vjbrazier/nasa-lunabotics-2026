/*

 NASA Lunabotics Motor Control

*/

#define SPEED 50

class MotorController {

private:

 int p1, a1, b1;

public:

 MotorController(int p1, int a1, int b1) {

   this->p1 = p1;

   this->a1 = a1;

   this->b1 = b1;

   pinMode(p1, OUTPUT);

   pinMode(a1, OUTPUT);

   pinMode(b1, OUTPUT);

 }

 void forward() {

   digitalWrite(this->a1, HIGH);

   digitalWrite(this->b1, LOW);

   digitalWrite(this->p1, SPEED*2);

 }

 void backward() {

   digitalWrite(this->a1, LOW);

   digitalWrite(this->b1, HIGH);

   digitalWrite(this->p1, SPEED);

 }

 void halt() {

   digitalWrite(this->a1, LOW);

   digitalWrite(this->b1, LOW);

 }

};

class Rover {

private:

 MotorController *frontLeft, *frontRight;

 MotorController *backLeft, *backRight;

public:

 Rover() {

   backLeft = new MotorController(2,22,23);

   frontRight = new MotorController(3,24,25);

   frontLeft = new MotorController(4,26,27);

   backRight = new MotorController(5,28,29);

 }

 void forward() {

   backLeft->forward();

   frontRight->backward();

   frontLeft->forward();

   backRight->backward();

 }

 void backward() {

   backLeft->backward();

   frontRight->forward();

   frontLeft->backward();

   backRight->forward();

 }

 void right() {

   backLeft->forward();

   frontRight->forward();

   frontLeft->forward();

   backRight->forward();

 }

 void left() {

   backLeft->backward();

   frontRight->backward();

   frontLeft->backward();

   backRight->backward();

 }

 void halt() {

   backLeft->halt();

   frontRight->halt();

   frontLeft->halt();

   backRight->halt();

 }

};

void setup() {

 // Rover rover;

 // rover.right();

 // delay(2000);

 // rover.halt();

 MotorController backLeft(2,22,23);

 MotorController frontLeft(3,24,25);

 MotorController frontRight(4,28,29);

 MotorController backRight(5,30,31);

 backLeft.forward();

 frontLeft.forward();

 frontRight.forward();

}

void loop() {

}