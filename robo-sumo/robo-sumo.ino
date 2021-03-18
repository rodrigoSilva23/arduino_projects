#include <Servo.h>
// =====================
//      Variáveis 
// ======================

// Servo
#define SERVO 13 
Servo servo; // Instancia o servo

//Motores

#define motor_a_p1 2    // Motor A, rotação horária
#define motor_a_p2 3   // Motor A, rotação antihorária

#define motor_b_p1 4   // Motor B, rotação horária
#define motor_b_p2 5   // Motor B, rotação antihorária

//Sensores

#define sensor_de_linha_frente 9   // Sensor de linha da frente
#define sensor_de_linha_atras 8    // Sensor de linha de trás

#define sensor_de_infra_frente 6     // Sensor infravermelho frontal
#define sensor_de_infra_esquerdo 10   // Sensor infravermelho esquerdo
#define sensor_de_infra_direito 11    // Sensor infravermelho direito


// ==========================
//      Métodos padrões 
// ===========================

void setup(){
  pinosMotores();
  pinosSensores();  
}

void loop(){  
//afastaDaLinha();
ataque();
}

// ==========================
//      Métodos sensores 
// ===========================

void pinosSensores(){
  pinMode(sensor_de_linha_frente, INPUT);
  pinMode(sensor_de_linha_atras, INPUT);
  pinMode(sensor_de_infra_frente, INPUT);
  pinMode(sensor_de_infra_esquerdo, INPUT);
  pinMode(sensor_de_infra_direito, INPUT);
}

void afastaDaLinha(){
  bool sensor_frente = digitalRead(sensor_de_linha_frente);
  bool sensor_atras = digitalRead(sensor_de_linha_atras);

  if(!sensor_frente){
    ir_pra_tras();
  }else if(!sensor_atras){
    ir_pra_frente();
  }else{
    frear(); 
   }
}

void ataque(){
  bool infra_frente = digitalRead(sensor_de_infra_frente);  
  bool infra_esquerdo = digitalRead(sensor_de_infra_esquerdo);    
  bool infra_direito = digitalRead(sensor_de_infra_direito);

  if(!infra_frente) ir_pra_frente();
  else if(!infra_esquerdo) virar_direita();
  else if(!infra_direito) virar_esquerda();
  else frear(); 

}

// ==========================
//      Métodos motores 
// ===========================

void pinosMotores(){
  pinMode(motor_a_p1, OUTPUT);
  pinMode(motor_a_p2, OUTPUT);
  pinMode(motor_b_p1, OUTPUT);
  pinMode(motor_b_p2, OUTPUT);
}

// Referente ao robô

void ir_pra_frente(){
  frente_motor_a();
  frente_motor_b();
}

void ir_pra_tras(){
  re_motor_a();
  re_motor_b();
}

void frear(){
  freio_motor_a();
  freio_motor_b();
}

void virar_direita(){
  frente_motor_a();
  re_motor_b();
}

void virar_esquerda(){
  re_motor_a();
  frente_motor_b();
}


// Referente ao motor A 

void frente_motor_a(){
  digitalWrite(motor_a_p1, HIGH);
  digitalWrite(motor_a_p2, LOW);
}
void freio_motor_a(){
  digitalWrite(motor_a_p1, HIGH);
  digitalWrite(motor_a_p2, HIGH);
}
void re_motor_a(){
  digitalWrite(motor_a_p1, LOW);
  digitalWrite(motor_a_p2, HIGH);
}

// Referente ao motor B 

void frente_motor_b(){
  digitalWrite(motor_b_p1, HIGH);
  digitalWrite(motor_b_p2, LOW);
}
void freio_motor_b(){
  digitalWrite(motor_b_p1, HIGH);
  digitalWrite(motor_b_p2, HIGH);
}
void re_motor_b(){
  digitalWrite(motor_b_p1, LOW);
  digitalWrite(motor_b_p2, HIGH);
}
