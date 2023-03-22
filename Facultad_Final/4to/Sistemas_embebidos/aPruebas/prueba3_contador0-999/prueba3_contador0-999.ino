#include <SevSeg.h>
SevSeg sevseg; //Instanciamos el objeto SevSeg

void setup() {
  // put your setup code here, to run once:
  byte Numdigits=4;
  byte Comunes[]={2,3,4,5};
  byte Segmentos[]={6,7,8,9,10,11,12,13};
  byte Tipo=COMMON_CATHODE;
  sevseg.begin(Tipo,Numdigits,Comunes,Segmentos);
  pinMode(A0, INPUT);  

}

void loop() {
  static unsigned long tiempoejec=millis()+100; //proximo evento
  static int contador=0;

  if(millis()>=tiempoejec){
    tiempoejec+=100;//proximo evento
    while(!digitalRead(A0));
    delay(10);
    contador++;
    if(contador==10000){
      contador=0;//reseteamos contador
    }
    sevseg.setNumber(contador,1);
  }
  sevseg.refreshDisplay();
  // put your main code here, to run repeatedly:

}
