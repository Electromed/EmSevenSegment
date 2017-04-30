/*Error 

10 = blank
thisswitch returns 255 if no switch is pressed
else number of switch

*/

#define DEBOUNCE 10  // ms to debounce.

int digits=4;
int nums=3; //total number to be printed
boolean leadingZeros=false;

int numbers[]={26,4,5};
int lengths[]={2,1,1};  

int data=10;
int clk=11;
int strobe=12;

unsigned long lastBlinkTime = 0;

#define NUMBUTTONS 2
int buttonPin[]={3,4};
byte pressed[NUMBUTTONS], justpressed[NUMBUTTONS], justreleased[NUMBUTTONS];
byte previous_keystate[NUMBUTTONS], current_keystate[NUMBUTTONS];

char mode='n';

void setup(){
  Serial.begin(9600);
  Serial.print("Start");
  pinMode(strobe,OUTPUT);
  pinMode(data,OUTPUT);
  pinMode(clk,OUTPUT);
  buttonInit();
  setInterruptButton(2);
}

//==============================================================//
/*
void writeNum(unsigned long num, uint8_t c){
  int arr[digits];
  int len=0,x=num;
  while (x!=0){
    len++;
    x/=10;
  }
  Serial.println(len);
  if (len <= digits){
    x=num;
    for (int i=0;i<digits;i++){
      if (i>=len){
        arr[i]=10;
      }
      else{
        arr[i]=x%10;
        x/=10;
      }
    }
    arr[c]=10;
    writeArray(arr);
  }
  else{
    Serial.print(num);
    Serial.println("num larger than digits");
  }

}
void writeNum(unsigned long num){
  int arr[digits];
  uint8_t len=0;
  Serial.println(num);
  int x=num;
  len=findLength(num);
  if (len <= digits){
    x=num;
  }
  else{
    Serial.println("num larger than digits");
    for (int j=0;j<len-digits;j++){
      x/=10;
    }
  }
  for (int i=0;i<digits;i++){
    if (i>=len){
      arr[i]=10;
    }
    else{
      if (leadingZeros==false){
        arr[i]=x%10;
        x/=10;
      }
    }
  }
  writeArray(arr);
}
*/
int findLength(int n){
  uint8_t l=0;
  while(n!=0){
    l++;
    n/=10;
  }
  return l;
}
void writeArray(int arr[]){
  byte segment[]={63, 6, 91, 79, 102, 109, 125, 7, 127, 111,0};
  digitalWrite(strobe,LOW);
  for (int i=0;i<digits;i++){
    byte digit=segment[arr[i]];
    shiftOut(data,clk,MSBFIRST,digit);
  }
  digitalWrite(strobe,HIGH);
}
void test(){
  int arr[digits];
  for(int i=0;i<10;i++){
    for(int j=0;j<digits;j++){
      arr[j]=i;
    }
    writeArray(arr);
    delay(100);
  }
}
void writeNumbers(int nums,int num[],int len[]){
  int arr[digits];
  int t1=0,t2=-1,t3;
  for(int i=0;i<nums;i++){
    Serial.println(num[i]);
    t1=num[i];
    t2+=len[i];
    t3=findLength(t1);
    for (int j=0;j<t3-len[i];j++){
      t1/=10;
    }
    for(int j=0;j<len[i];j++){
      arr[digits-1-(t2-j)]=t1%10;
      t1/=10;
      if(j>=t3 && leadingZeros==false){
        arr[digits-1-(t2-j)]=10;
      }
    }    
  }
  writeArray(arr);
}
void writeNumbers(int nums,int num[],int len[],int off){
  int arr[digits];
  int t1=0,t2=-1,t3;
  for(int i=0;i<nums;i++){
    Serial.println(num[i]);
    t1=num[i];
    t2+=len[i];
    t3=findLength(t1);
    if (i == off-1){
      for(int j=0;j<len[i];j++){
        arr[digits-1-(t2-j)]=10;
      }      
    }
    else{
      for (int j=0;j<t3-len[i];j++){
        t1/=10;
      }
      for(int j=0;j<len[i];j++){
        arr[digits-1-(t2-j)]=t1%10;
        t1/=10;
        if(j>=t3 && leadingZeros==false){
          arr[digits-1-(t2-j)]=10;
        }
      }
    }
  }
  writeArray(arr);
}
void createBlink(int nums, int num[],int len[],int off,int blinkDelay){
  if ((millis() - lastBlinkTime) > blinkDelay) {
    lastBlinkTime=millis();
    if ((millis()/1000)%2 == 0){
      writeNumbers(nums,num,len,off);
    }
    else{
      writeNumbers(nums,num,len);
    }
  }
}
/*void checkUP(){
  writeNum(12345);
  delay(1000);
  writeNum(645);
  delay(1000);
  writeNum(2);
  delay(1000);
  writeNum(90);
  delay(1000);
}*/

//============================================================//

void setInterruptButton(uint8_t x){
  attachInterrupt(digitalPinToInterrupt(2),modeChange,RISING);
}
void buttonInit(){
 for (int i=0;i<NUMBUTTONS;i++){
  pinMode(buttonPin[i],INPUT);
 }
}
void modeChange(){
  if (mode == 'n'){
    mode='s';
  }
  else if (mode == 's'){
    mode='n';
  }
}
void check_switches(){
  static byte previousstate[NUMBUTTONS];
  static byte currentstate[NUMBUTTONS];
  static long lasttime;
  byte index;
  if (millis() < lasttime) {
    // we wrapped around, lets just try again
    lasttime = millis();
  }
  if ((lasttime + DEBOUNCE) > millis()) {
    // not enough time has passed to debounce
    return; 
  }
  // ok we have waited DEBOUNCE milliseconds, lets reset the timer
  lasttime = millis();
  for (index = 0; index < NUMBUTTONS; index++) {
    justpressed[index] = 0;       //when we start, we clear out the "just" indicators
    justreleased[index] = 0;
    currentstate[index] = digitalRead(buttonPin[index]);   //read the button
    if (currentstate[index] == previousstate[index]) {
      if ((pressed[index] == LOW) && (currentstate[index] == LOW)) {
        // just pressed
        justpressed[index] = 1;
      }
      else if ((pressed[index] == HIGH) && (currentstate[index] == HIGH)) {
        justreleased[index] = 1; // just released
      }
      pressed[index] = !currentstate[index];  //remember, digital HIGH means NOT pressed
    }
    previousstate[index] = currentstate[index]; //keep a running tally of the buttons
  }
}
byte thisSwitch_justPressed() {
  byte thisSwitch = 255;
  check_switches();  //check the switches &amp; get the current state
  for (byte i = 0; i < NUMBUTTONS; i++) {
    current_keystate[i]=justpressed[i];
    if (current_keystate[i] != previous_keystate[i]) {
      if (current_keystate[i]) thisSwitch=i;
    }
    previous_keystate[i]=current_keystate[i];
  }  
  return thisSwitch;
}

//=============================================================//
void loop(){
  //checkUP();
  //test();
  if (mode == 'n')
    writeNumbers(nums,numbers,lengths);
  else if (mode == 's'){
    byte thisSwitch=thisSwitch_justPressed();
    if (thisSwitch!=255)
      Serial.println(thisSwitch);
    createBlink(nums,numbers,lengths,2,500);
    
    //delay(1000);
  }
}


