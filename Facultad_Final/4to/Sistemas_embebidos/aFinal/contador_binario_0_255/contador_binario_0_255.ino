int outpin[]={13,12,11,10,9,8,7,6};

void setup() {
  // put your setup code here, to run once:
int i=0;
  for(i=0;i<8;i++){
    pinMode(outpin[i], OUTPUT);

}
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 0, j=0;
  for (i=0;i<256;i++){
    for(j=0;j<8;j++){
      if(((i>>j) & 1)==1){
        digitalWrite(outpin[j], HIGH);
        }
        else digitalWrite(outpin[j], LOW);
      }
      delay(1000);
    }
}