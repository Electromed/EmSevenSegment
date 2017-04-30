/*Error 

10 = blank

*/


int data=2;
int clk=3;
int strobe=4;

int digits=4;
int nums=2; //total number to be printed
boolean leadingZeros=false;

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
    delay(1000);
  }
}
void writeNumbers(int num[],int len[]){
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
  int arr[]={256,4};
  int len[]={2,2};
  writeNumbers(arr,len);
  delay(1000);
}
