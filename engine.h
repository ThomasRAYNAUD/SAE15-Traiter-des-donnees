#include <Arduino.h>
class Engine{ // On définie une classe appellée Engine

 private: // Les arguments privés sont définis ci-dessous, ils ne sont utilisables que pour les objets de type Engine
  const int in1=6; // On définie la constante in1 sur le pin 6
  const int in2=7; // On définie la constante in2 sur le pin 7
  const int in3=8; // On définie la constante in3 sur le pin 8
  const int in4=9; // On définie la constante in4 sur le pin 9
  const int ENA=5; // On définie la constante ENA sur le pin 5
  const int ENB=11; // On définie la constante ENB sur le pin 11 
  int velocity; // On définie une variable velocity de type entier

 public: // Les arguments publique sont définis ci-dessous
 Engine(int s){ // On définie le constructeur de la classe Engine, avec un argument entier s
    velocity=s; // On récupère l'argument dans la variable velocity
    pinMode(in1, OUTPUT); // On définie le pin in1 sur OUTPUT
    pinMode(in2, OUTPUT); // On définie le pin in2 sur OUTPUT
    pinMode(in3, OUTPUT); // On définie le pin in3 sur OUTPUT
    pinMode(in4, OUTPUT); // On définie le pin in4 sur OUTPUT
    pinMode(ENA, OUTPUT); // On définie le pin in5 sur OUTPUT
    pinMode(ENB, OUTPUT); // On définie le pin in6 sur OUTPUT
    stop(); // On arrête le robot avec la fonction stop() définie ci-dessous
  }

  void stop(){ // On créé une fonction pour arrêter le robot
    digitalWrite(ENA,LOW); // On définie l'état des moteurs de droite sur LOW
    digitalWrite(ENB,LOW); // On définie l'état des moteurs de gauche sur LOW
    Serial.println("stop"); // On affiche stop en console

  }
  
  void goForward(){ // On créé une fonction pour faire avancer le robot
    analogWrite(ENA,velocity); // On fait tourner le moteur de droite sur la vitesse velocity
    analogWrite(ENB,velocity); // On fait tourner le moteur de gauche sur la vitesse velocity
    digitalWrite(in1,HIGH); // On met le pin in1 sur l'état HIGH
    digitalWrite(in2,LOW);  // On met le pin in2 sur l'état LOW
    digitalWrite(in3,LOW); // On met le pin in3 sur l'état LOW
    digitalWrite(in4,HIGH); // On met le pin in4 sur l'état HIGH
    Serial.println("goForward"); // On affiche goForward en console
  }
  void goBackward(){ // On créé une fonction pour faire reculer le robot
    analogWrite(ENA,velocity); // On fait tourner le moteur de gauche sur la vitesse velocity
    analogWrite(ENB,velocity); // On fait tourner le moteur de gauche sur la vitesse velocity
    digitalWrite(in1,LOW); // On met le pin in4 sur l'état LOW
    digitalWrite(in2,HIGH); // On met le pin in4 sur l'état HIGH
    digitalWrite(in3,HIGH); // On met le pin in4 sur l'état HIGH
    digitalWrite(in4,LOW); // On met le pin in4 sur l'état LOW
    Serial.println("goBackward"); // On affiche goBackward en console
  }
 
  void turnLeft(){ // On créé une fonction pour faire tourner le robot à gauche
    int old=velocity; // On créé une variable old qui va stocker l'ancienne vitesse du robot
    velocity=194; // Puis on définie une nouvelle vitesse qui sera utilisée pour faire les virages afin de les rendre plus fluides
    analogWrite(ENA,velocity); // On fait tourner le moteur de gauche à la vitesse velocity
    analogWrite(ENB,velocity); // On fait tourner le moteur de droite à la vitesse velocity
    digitalWrite(in1,HIGH); // On met le pin in1 sur l'état HIGH
    digitalWrite(in2,LOW); // On met le pin in2 sur l'état LOW
    digitalWrite(in3,HIGH); // On met le pin in3 sur l'état HIGH
    digitalWrite(in4,LOW); // On met le pin in4 sur l'état LOW
    Serial.println("turnleft"); // On affiche turnLeft en console
    velocity=old; // On redéfinie velocity sur son ancienne valeur
    
  }

  void turnRight(){ // On créé une fonction pour faire tourner le robot à droite
    int old=velocity; // On créé une variable old qui va stocker l'ancienne vitesse du robot
    velocity=194; // Puis on définie une nouvelle vitesse qui sera utilisée pour faire les virages afin de les rendre plus fluides
    analogWrite(ENA,velocity); // On fait tourner le moteur de gauche à la vitesse velocity
    analogWrite(ENB,velocity); // On fait tourner le moteur de droite à la vitesse velocity
    digitalWrite(in1,LOW); // On met le pin in1 sur l'état LOW
    digitalWrite(in2,HIGH); // On met le pin in2 sur l'état HIGH
    digitalWrite(in3,LOW); // On met le pin in3 sur l'état LOW
    digitalWrite(in4,HIGH); // On met le pin in4 sur l'état HIGH
    Serial.println("turnright"); // On affiche turnRight en console
    velocity=old; // On redéfinie velocity sur son ancienne valeur
  }




};
