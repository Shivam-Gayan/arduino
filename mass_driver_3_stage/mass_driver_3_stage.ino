// example code for 2-stage mass driver

// define constants for pins

const int coil1_pin = 2;
const int coil2_pin = 3;

const int sensor1_pin = 8;
const int sensor2_pin = 9;

// variables for sensor readings

int sensor1;
int sensor2;

// other variables

unsigned long start_time;
unsigned long current_time;
unsigned long elapsed_time;
unsigned long stop_time = 2000;

void setup() {
  // put your setup code here, to run once:

  // set coil pins as outputs

  pinMode(coil1_pin,OUTPUT);
  pinMode(coil2_pin,OUTPUT);

  // turn coil 1 on, others off
  digitalWrite(coil1_pin, HIGH);
  digitalWrite(coil2_pin, LOW);


  // get start time
  start_time = millis();

}

void loop() {
  // put your main code here, to run repeatedly:

  // get elapsed time since program started
  current_time = millis();
  elapsed_time = current_time - start_time;

  if(elapsed_time > stop_time){
    // turn all coils off as a safety measure if program has been running for too long
    digitalWrite(coil1_pin, LOW);
    digitalWrite(coil2_pin, LOW);

  }
  else{
    // read all 3 sensors
    sensor1 = digitalRead(sensor1_pin);
    sensor2 = digitalRead(sensor2_pin);

    // sensors are pulled high by default, go LOW when they detect magnetic field

    // when sensor 1 goes low, turn coil 1 off and turn coil 2 on
    if(sensor1 == LOW){
      digitalWrite(coil1_pin, LOW);
      digitalWrite(coil2_pin, HIGH);
    }

    // when sensor 2 goes low, turn coil 2 off
    if(sensor2 == LOW){
      digitalWrite(coil2_pin, LOW);
    }
  } 
}
  

  
