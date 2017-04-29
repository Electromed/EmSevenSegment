long debouncing_time = 50; //Debouncing Time in Milliseconds
volatile unsigned long last_micros;
boolean state = false;


void setup() {
  pinMode(2,INPUT);
  attachInterrupt(digitalPinToInterrupt(2), debounceInterrupt, RISING);
  Serial.begin(9600);
  Serial.println("Start");
  pinMode(13,OUTPUT);
}

void loop() {
}

void debounceInterrupt() {
  if((long)(micros() - last_micros) >= debouncing_time * 1000) {
    Interrupt();
    last_micros = micros();
  }
}

void Interrupt() {
  //Do Something
//  Serial.println(count);
//  count++;  
  state=!state;
  digitalWrite(13,state);
}
