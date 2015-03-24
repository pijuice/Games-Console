// Analogue Joystick to D-PAD Converter
// John Whittington 2015 john@jbrengineering.co.uk
//
// analogue inputs
#define YAXIS_PIN 0 // (1) P2
#define XAXIS_PIN 1 // (3) P3
// digital outputs
#define UP 3 // up DO
#define DOWN 2 // down DO
#define LEFT 5 // left DO
#define RIGHT 4 // right DO
// code defines
#define DZONE 128 // zero dead zone

int caliy = 512;
int calix = 512;

void setup() {
  // put your setup code here, to run once:
  pinMode(UP,OUTPUT);
  pinMode(DOWN,OUTPUT);
  pinMode(LEFT,OUTPUT);
  pinMode(RIGHT,OUTPUT);
  
  caliy = analogRead(YAXIS_PIN);
  calix = analogRead(XAXIS_PIN);
}

void loop() {
  int yaxis; // y axis reading
  int xaxis; // x axis reading
  
  // get analog stick reading
  yaxis = analogRead(YAXIS_PIN);
  xaxis = analogRead(XAXIS_PIN);
  
  // convert direction to digital states
  digitalJoy(yaxis, caliy, UP, DOWN);
  digitalJoy(xaxis, calix, LEFT, RIGHT);
}

void digitalJoy(int axis, int cal, int dir1, int dir2) {
  // joystick rests at Vref/2 (512)
  // UP >512 DOWN <512 but we include a dead zone to allow zero  
  if (axis > (cal + DZONE)) { 
    digitalWrite(dir1,LOW);
  } else if (axis < (cal - DZONE)) {
    digitalWrite(dir2,LOW);
  } else {
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,HIGH);
  }
}
