
int motorLPin1 = 3; 
int motorLPin2 = 4; 
int motorRPin1 = 11;
int motorRPin2 = 10;
int state;
int flag=0;        //makes sure that the serial only prints once the state
int stateStop=0;
void setup() {
    // sets the pins as outputs:
    pinMode(motorLPin1, OUTPUT);
    pinMode(motorLPin2, OUTPUT);
    pinMode(motorRPin1, OUTPUT);
    pinMode(motorRPin2, OUTPUT);
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}

void loop() {
    //if some date is sent, reads it and saves in state
    if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
    }   
    // if the state is 'A' the DC motor will go forward
    if (state == 'F') {
        digitalWrite(motorLPin1, HIGH);
        digitalWrite(motorLPin2, LOW); 
        digitalWrite(motorRPin1, HIGH);
        digitalWrite(motorRPin2, LOW);
        if(flag == 0){
          Serial.println("Go Forward!");
          flag=1;
        }
    }
    
    // if the state is 'C' the motor will turn left
    else if (state == 'L') {
        digitalWrite(motorLPin1, LOW); 
        digitalWrite(motorLPin2, HIGH); 
        digitalWrite(motorRPin1, HIGH);
        digitalWrite(motorRPin2, LOW);
        if(flag == 0){
          Serial.println("Turn LEFT");
          flag=1;
        }
        delay(100);
        state=3;
        stateStop=1;
    }
    // if the state is 'E' the motor will Stop
    else if (state == 'S' || stateStop == 1) {
        digitalWrite(motorLPin1, LOW); 
        digitalWrite(motorLPin2, LOW); 
        digitalWrite(motorRPin1, LOW);
        digitalWrite(motorRPin2, LOW);
        if(flag == 0){
          Serial.println("STOP!");
          flag=1;
        }
        stateStop=0;
    }
    // if the state is 'D' the motor will turn right
    else if (state == 'R') {
        digitalWrite(motorLPin1, HIGH); 
        digitalWrite(motorLPin2, LOW); 
        digitalWrite(motorRPin1, LOW);
        digitalWrite(motorRPin2, HIGH);
        if(flag == 0){
          Serial.println("Turn RIGHT");
          flag=1;
        }
        delay(100);
        state=3;
        stateStop=1;
    }
    // if the state is 'B' the motor will Reverse
    else if (state == 'B') {
        digitalWrite(motorLPin1, LOW); 
        digitalWrite(motorLPin2, HIGH);
        digitalWrite(motorRPin1, LOW);
        digitalWrite(motorRPin2, HIGH);
        if(flag == 0){
          Serial.println("Reverse!");
          flag=1;
        }
    }
    //For debugging purpose
    Serial.println(state);
}
