#include <Ps3Controller.h>
#include <ESP32Servo.h>

#define servod 16
#define m1d1 12
#define m1d2 14
#define pwm1 13
#define servocam 4
#define servocam1 19
#define led 2

Servo meuservo;
Servo meuservo1;
Servo meuservocam1;

int anguloa = 90;
int angulod = 90;
int angucama = 90;
int angucamd = 90;
int angucam1a = 90;
int angucam1d = 90;
char battery = Ps3.data.status.battery;


void conect(){

    Serial.println("CONTROLE CONECTADO!!!");
        Serial.print("A BATERIA DO CONTROLE ESTÁ ");
        if( battery == ps3_status_battery_charging )      Serial.println("CARREGANDO");
        else if( battery == ps3_status_battery_full )     Serial.println("CHEIA");
        else if( battery == ps3_status_battery_high )     Serial.println("ALTA");
        else if( battery == ps3_status_battery_low)       Serial.println("BAIXA");
        else if( battery == ps3_status_battery_dying )    Serial.println("DESCARREGADA");
        else if( battery == ps3_status_battery_shutdown ) Serial.println("DESLIGADO");
        else Serial.println("NAO INFORMADA");
    }




//prints
void setup(){
  Serial.begin(115200);
  Ps3.attachOnConnect(conect);
  Ps3.begin("a0:dd:6c:85:c5:8a");
  Serial.println("Gralha online!!!!");
  meuservo.attach(servod);
  meuservo.write(90);
  meuservo1.attach(servocam);
  meuservo1.write(90);
  meuservocam1.attach(servocam1);
  meuservocam1.write(90);


  pinMode(m1d1, OUTPUT);
  pinMode(m1d2, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(led, OUTPUT);
}

// Comandos
void loop(){
   servos();
   motores();
   delay(5);

}
void servos(){
   // Servo da direçao
    int joy = Ps3.data.analog.stick.lx;
      angulod = map(joy, 90, 0, 120, 90);

    if (joy != 0 ){
      Serial.print("Valor recebido = ");
      Serial.println(joy);
      Serial.print("Angulo do servo = ");
      Serial.println(anguloa);
    }

    if (anguloa < angulod) {
      anguloa++;
    } else if (anguloa > angulod) {
      anguloa--;
    }
    meuservo.write(anguloa);

//Servo da camera

    int joy1 = Ps3.data.analog.stick.rx;
    angucamd = map(joy1, 90, 0, 120, 90);
    if (joy1 != 0 ){
        Serial.print("Valor recebido da camera  = ");
        Serial.println(joy1);
        Serial.print("Angulo do servo camera = ");
        Serial.println(angucama);
    }

    if (angucama < angucamd) {
        angucama++;
        } else if (angucama > angucamd) {
        angucama--;
        }
        meuservo1.write(angucama);

  //Servo da camera1

  int joycam1 = Ps3.data.analog.stick.ry;
    angucam1d = map(joycam1, 90, 0, 120, 90);
    if (joycam1 != 0 ){
        Serial.print("Valor recebido da camera servo (A)  = ");
        Serial.println(joycam1);
        Serial.print("Angulo do servo camera (A) = ");
        Serial.println(angucam1a);


    if (angucam1a < angucam1d) {
        angucam1a++;
        } else if (angucam1a > angucam1d) {
        angucam1a--;
        }
        meuservocam1.write(angucam1a);
    }

}
void motores(){
  //Motores
    if (Ps3.data.analog.button.r2 > 0) {
      digitalWrite(m1d1, HIGH);
      int pwm = Ps3.data.analog.button.r2;
      Serial.print("Pwm R2 = ");
      Serial.println(pwm);
      analogWrite(pwm1, pwm);
    } else if (Ps3.event.button_up.r2) {
      digitalWrite(m1d1, LOW);
    }

    if (Ps3.data.analog.button.l2 > 0) {
      digitalWrite(m1d2, HIGH);
      int pw1 = Ps3.data.analog.button.l2;
      Serial.print("Pwm L2 = ");
      Serial.println(pw1);
      analogWrite(pwm1, pw1);
    } else if (Ps3.event.button_up.l2) {
      digitalWrite(m1d2, LOW);
    }
    digitalWrite(led, HIGH);

}