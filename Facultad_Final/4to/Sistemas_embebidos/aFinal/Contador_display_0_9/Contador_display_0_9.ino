const int pins [7] = {3,4,5,6,7,8,9};
                                       //gfedcba 
const byte numbersDsiplayAnode[10] = { 0b0111111,   //0
                                       0b0000110,   //1   
                                       0b1011011,   //2
                                       0b1001111,   //3
                                       0b1100110,   //4
                                       0b1101101,   //5
                                       0b1111101,   //6
                                       0b0000111,   //7
                                       0b1111111,   //8
                                       0b1101111};  //9

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 7; i++){
    pinMode(pins[i], OUTPUT);
  }
  lightSegments(0); 
}
void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i < 10; i++){
    lightSegments(i);
    delay(600);
  }  
}

void lightSegments(int number){
  byte numberBit = numbersDsiplayAnode[number];
  for (int i =0; i < 7; i++){
    int bit = bitRead(numberBit, i);
    digitalWrite(pins[i], bit);
  }
}





