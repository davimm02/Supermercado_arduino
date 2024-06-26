int a = 8;
int b = 9;
int c = 5;
int d = 4;
int e = 3;
int f = 7;
int g = 6;
int contador=0;
int PinTrigger = 12; // pino usado para disparar os pulsos do sensor
int PinEcho = 2;
int LB = 13;
float dist =0; // pino usado para ler a saida do sensor
float TempoEcho = 0; // variável tempo do eco
const float velocidadeSom_mps = 340; // em metros por segundo
const float velocidadeSom_mpus = 0.000340; // em metros por microssegundo

void apaga(){
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
void ascende1 (){
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
void ascende2 (){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}
void ascende3 (){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}
void ascende4 (){
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
void ascende5 (){
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
void ascende6 (){
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
void ascende7 (){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
void ascende8 (){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
void ascende9 (){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
void ascende0 (){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(LB,OUTPUT);
  pinMode(PinTrigger, OUTPUT); // configura pino Trigger como saída
  digitalWrite(PinTrigger, LOW); // pino trigger - nível baixo
  pinMode(PinEcho, INPUT); // configura pino ECHO como entrada
  delay(100); // atraso de 100 milisegundos
}
void loop() {
  digitalWrite(LB, LOW);
  DisparaPulsoUltrassonico(); // dispara pulso ultrassonico
  TempoEcho = pulseIn(PinEcho, HIGH); // mede duração do pulso em microsegundos
  dist = (CalculaDistancia(TempoEcho)); // mostra o calculo de distancia em metros
  if(dist < 0.1 && dist > 0.01){
    contador ++;
    if (contador == 0){
    ascende0();
    }
    if (contador == 1){
      ascende1();
    }
    if (contador == 2){
      ascende2();
    }
    if (contador == 3){
      ascende3();
    }
    if (contador == 4){
      ascende4();
    }
    if (contador == 5){
      ascende5();
    }
    if (contador == 6){
      ascende6();
    }
    if (contador == 7){
      ascende7();
    }
    if (contador == 8){
      ascende8();
    }
    if (contador == 9){
      ascende9();
    }
    if (contador > 9){
      contador = 0;
    }
    digitalWrite(LB,HIGH);
    delay(500);
    digitalWrite(LB,LOW);
    delay(1000);
  }
  if (contador == 0){
    ascende0();
  }
  if (contador == 1){
    ascende1();
  }
  if (contador == 2){
    ascende2();
  }
  if (contador == 3){
    ascende3();
  }
  if (contador == 4){
    ascende4();
  }
  if (contador == 5){
    ascende5();
  }
  if (contador == 6){
    ascende6();
  }
  if (contador == 7){
    ascende7();
  }
  if (contador == 8){
    ascende8();
  }
  if (contador == 9){
    ascende9();
  }
  if (contador > 9){
    contador = 0;
  }
}
void DisparaPulsoUltrassonico() {
  digitalWrite(PinTrigger, HIGH); // pulso alto de Trigger
  delayMicroseconds(10); // atraso de 10 milisegundos
  digitalWrite(PinTrigger, LOW); // pulso baixo de Trigger
}
  float CalculaDistancia(float tempo_us) {
  return ((tempo_us * velocidadeSom_mpus) / 2 ); // calcula distancia em metros
}
