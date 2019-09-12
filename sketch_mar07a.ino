#include <stdio.h>
#include <stdlib.h>

int Sensor1 = 4;
int Sensor2 = 7;
int Sensor3 = 8;
int Sensor4 = 12;
unsigned long timeSensor3;
unsigned long timeSensor2;  
unsigned long timeSensor4;
unsigned long Time;

int relogio() {
  int milisegundos = 0;
  
  delay(1);
  milisegundos++;
  
  return milisegundos;
}

void setup() {
  // put your setup code here, to run once:
  pinMode (Sensor1, INPUT);
  pinMode (Sensor2, INPUT);
  pinMode (Sensor3, INPUT);
  pinMode (Sensor4, INPUT);
  Serial.begin(9600);
}

void loop() {
    while (digitalRead(Sensor4) == HIGH){ // COndiçao para a contagem dos sensores, o ultimo sensor nao recebe sinal.
      if (digitalRead(Sensor1) == LOW){ // Quando o sensor1 nao ler, iniciara a contagem
        Serial.println(Time);
      }
       else{
        Serial.println (Time);
        Time += relogio();
        if (digitalRead(Sensor2) == LOW){ // Gravaçao do primeiro tempo (sensor2)
          timeSensor2 = Time;
          Serial.println ("O time do sensor2: " + String (timeSensor2));
        }
        if (digitalRead(Sensor3) == LOW){ // Gravaçao do segundo tempo (Sensor3)
          timeSensor3 = Time;
          Serial.println ("O time do sensor3: " + String ( timeSensor3));
        }
        if (digitalRead(Sensor4) == LOW){ //Gravaçao do terceiro tempo (Sensor4) e fim da condiçao
          timeSensor4 = Time;
          Serial.println ("O time do sensor4: " + String (timeSensor4));
        }
       }
    }
}
