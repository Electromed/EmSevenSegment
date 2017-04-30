/*Error 

10 = blank

*/


int data=2;
int clk=3;
int strobe=4;

int digits=4;
int nums=4; //total number to be printed

void setup(){
  Serial.begin(9600);
  Serial.print("Start");
  pinMode(strobe,OUTPUT);
  pinMode(data,OUTPUT);
  pinMode(clk,OUTPUT);
}

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
    writeArray(arr);
  }
  else{
    Serial.print(num);
    Serial.println("num larger than digits");
    x=num;
    unsigned long y=0;
    while(x!=0){
      y=(y*10)+x%10;
      Serial.println(y);
      x/=10;
    }
    Serial.println(y);
    for(int i=0;i<digits;i++){
      arr[digits-1-i]=y%10;
      y/=10;
    }
    writeArray(arr);
  }
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
    delay(1000);
  }
}

void writeNumbers(int num[]){
  int arr[digits];
  for(int i=0;i<nums;i++)
    Serial.println(num[i]);
}

void checkUP(){
  writeNum(12345);
  delay(1000);
  writeNum(645);
  delay(1000);
  writeNum(2);
  delay(1000);
  writeNum(90);
  delay(1000);
}
void loop(){
  checkUP();
  //test();
  //int arr[]={2,3,4,5};
  //writeNumbers(arr);
}
