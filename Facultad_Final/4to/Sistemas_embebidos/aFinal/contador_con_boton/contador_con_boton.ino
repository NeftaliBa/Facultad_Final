//segmentos del display
int a = 12, b = 8, c = 4, d = 6, e = 7, f = 11, g = 3;

int led = 0;

//Digitos del display
int d1 = 2, d2 = 9, d3 = 10, d4 = 13;

int dot = 5;

int vel = 5;

//Unidades (recuerda que "mil" no tiene que estar)
int cen, dec, uni;

byte segmentos[7] = {a, b, c, d, e, f, g};
byte orden_digitos[4] = {d1, d2, d3, d4};
byte digitos[3][4] = {
                     {0,0,0,1},
                     {0,0,1,0},
                     {0,1,0,0}
                     };


//precargar los numeros
byte digitos_de_display[10][7] = { //a,b,c,d,e,f,g 
                                   { 1,1,1,1,1,1,0 },  // = 0
                                   { 0,1,1,0,0,0,0 },  // = 1
                                   { 1,1,0,1,1,0,1 },  // = 2
                                   { 1,1,1,1,0,0,1 },  // = 3
                                   { 0,1,1,0,0,1,1 },  // = 4
                                   { 1,0,1,1,0,1,1 },  // = 5
                                   { 1,0,1,1,1,1,1 },  // = 6
                                   { 1,1,1,0,0,0,0 },  // = 7
                                   { 1,1,1,1,1,1,1 },  // = 8
                                   { 1,1,1,0,0,1,1 }   // = 9
                                  };  

//encender los numeros
void EscribirDigito (byte digito, byte numero) {
  int secuencia = 0;
  ActivarDigito(digito);
  //digitalWrite(dot, 1);
    for (byte i = 0; i < 7; i++){
        digitalWrite(segmentos[secuencia], digitos_de_display[numero][i]);
        ++secuencia;
  }
}

void ActivarDigito(int x){
  digitalWrite(d1, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, HIGH);
  switch(x){
    case 1:
    digitalWrite(d1, LOW);
    break;  
    
    case 2:
    digitalWrite(d2, LOW);
    break; 
    
    case 3:
    digitalWrite(d3, LOW);
    break; 
   
    default:
    digitalWrite(d4, LOW);
    break; 
    
  }

}


void setup() {
 //   pinMode(1, INPUT);// presionar el boton
  // put your setup code here, to run once

   pinMode(led,OUTPUT);
  
  int i;  
  for( i = 2; i <= 13; i++){
    pinMode(i, OUTPUT);    
  }  


}



void loop() {
  start();
}

void pausar(){   
  // Apagar los leds
  digitalWrite(d1, HIGH); // A
  digitalWrite(d2, HIGH); // B
  digitalWrite(d3, HIGH); // C

  // Encender los leds

  digitalWrite(led, HIGH);
  vel=9999;
  delay(100);

}


// 0 - 9999 (borra mil)
void start(){
    for(cen=0;cen<=9;cen++){
      for(dec=0;dec<=9;dec++){
        for(uni=0;uni<=9;uni++){
          
            if(digitalRead(1)==HIGH)
            { pausar();}
            else
            {
              
            vel=5;
            digitalWrite(led, LOW);                                    
            EscribirDigito(1, uni);
            delay(vel);          
            EscribirDigito(2, dec);          
            delay(vel);          
            EscribirDigito(3, cen);          
            delay(vel);
            }  
        }
      }
    }
}



