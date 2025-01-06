// Pin definitions for motor control
const int motorPin1 = 8;  // Motor direction pin 1
const int motorPin2 = 13; // Motor direction pin 2

// Define duration for motor operation
const int motorRunTime = 3000; // Time in milliseconds (3 seconds)

// Bluetooth serial communication
void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  // Initialize Bluetooth communication
  Serial.begin(9600);

  // Stop motor initially
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}

void loop() {
  // Check if data is available from Bluetooth
  while (Serial.available()) {
    String command = Serial.readStringUntil('\n'); // Read the command from the app

    command.trim(); // Remove any whitespace or newline characters

    if (command.equalsIgnoreCase("LOCK")) {
      lockMotor();
    } else if (command.equalsIgnoreCase("UNLOCK")) {
      unlockMotor();
    }
  }
}

// Function to rotate the motor clockwise (lock)
void lockMotor() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  delay(200); // Run the motor for the specified duration
  stopMotor();
}

// Function to rotate the motor counterclockwise (unlock)
void unlockMotor() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  delay(200); // Run the motor for the specified duration
  stopMotor();
}

// Function to stop the motor
void stopMotor() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}

// #include<Servo.h>
// Servo my_servo;
// char incoming_data ;
// String data;
// int angle=10;
// // int data;
// void setup() {
//  Serial.begin(9600);
//  my_servo.attach(8);
//  my_servo.write(0);
//  pinMode(7,OUTPUT);
// }

// void loop() {
//   // if(Serial.available() > 0)
//   // {
//   //   data = Serial.read();
//   //   Serial.println(data);
//  while(Serial.available()) 
//  {
//   delay(10);
//   String incoming_data = Serial.readString();
//   data=incoming_data;
//   Serial.println(data);

//   if((data=="lock"))//Change this line According to your need
//   {
//     Serial.println("door close");
//     for(angle=120;angle>10;angle--)
//     {
//       digitalWrite(7,HIGH);
//       delay(10);
//       digitalWrite(7,LOW);
//       delay(10);
//     }
//     delay(500);//change delay accroding to your need
// //    my_servo.write(180);//if you want to close the lock automatically then uncomment this line and also adjust delay 
   
//   }
//   else if((data=="unlock"))//Change this line According to your need
  
//   {
//     Serial.println("door open");
//     my_servo.write(120);
//     delay(500);
 
//   }
  
//  }
// }
// #include <Servo.h>
// Servo servo;
// int angle=10;

// void setup()
// {
//   pinMode(7,OUTPUT);
//   Serial.begin(115200); // opens serial port, sets data rate to 9600 bps
//   servo.attach(9);
//   servo.write(90);
// }

// void loop() {

//   for(angle=10;angle<180;angle++)
//   {
//     digitalWrite(7,HIGH);
//     delay(200);
//     digitalWrite(7,LOW);
//     delay(200);
//   //   servo.write(angle);
//   //   delay(1500);
//   //   Serial.println(angle);
//   }

//   // for(angle=180;angle>10;angle--)
//   // {
//   //   servo.write(angle);
//   //   delay(1500);
//   //   Serial.println(angle);
//   // }
//   // // bool button = digitalRead(2);
//   // // if (button)
//   // // {
//   // //   Serial.println(button);

//   // // }
// }