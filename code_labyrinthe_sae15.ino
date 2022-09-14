#include <Servo.h>  // On importe la librairie Servo.h qui permet de gérer la caméra ultrason du robot, cela nous sera utile pour capter les distances
#include <Arduino.h> //
#include "ultrasonic.h" // On importe le module ultrasonic.h que nous avons créé pour définir les fonctions relatives aux capteurs
#include "engine.h" // On importe le module engine.h qui permet de gérer les déplacements du robot

Servo servoMoteur; // On créé une variable servoMoteur de type Servo qui sera utilisée la position de la caméra
UltraSonic robot; // On créé une variable robot de type UltraSonic qui sera utilisée pour les fonctions relatives à la caméra et aux distances
int vitesse = 165; // On initialise la vitesse du robot sur 165
Engine moteur(vitsse); // On créé une variable moteur de type Engine qui va gérer les déplacements du robot
int distance_centre = 0; // On créé trois variables, distance_centre, distance_droite et distance_gauche qui vont contenir les mesures de la caméra du robot ->
int distance_droite = 0; // -> En fonction des trois angles de mesure
int distance_gauche = 0;
int distance_mur = 355; // Cette valeur correspond à la distance par rapport au mur à laquelle le robot va s'arrêter
int distance_centre2 ; // On initialise distance_centre2 qui contiendra la distance disponible derrière le robot

void setup() {
  Serial.begin(9600); // On définie la vitesse d'écriture sur le robot via le câble sur 9600
  servoMoteur.attach(3); // On affecte le pin 3 à servoMoteur
  servoMoteur.write(100); // Initialisation de la caméra au centre
  distance_centre = robot.getDistance(); // On récupère la distance libre au centre
  moteur.stop(); // On arrête le moteur le robot
  moteur.turnRight(); // On le fait tourner à droite pour faire un demi-tour
  delay (980);
  distance_centre2 = robot.getDistance(); // On récupère la distance derrière le robot
  if (distance_centre2 < distance_centre) { // Si la distance derrière le robot est inférieure à la distance devant lui, il se retourne
    moteur.turnRight(); // Cela permet au robot de partir directement dans la direction avec le plus de place
    delay (980);  // On ajoute un delai de 980ms avant l'exécution de la commande suivante
  }
}


void loop() {
  distance_centre = robot.getDistance(); // On récupère la distance au centre
  Serial.print("Distance = ");         // On affiche cette distance dans la console
  Serial.println(distance_centre);
  delay(10);                           // On ajoute un delai de 10ms avant l'exécution de la commande suivante



  if (distance_centre > distance_mur) { // Si la distance au centre est supérieure à la distance par rapport au mur à laquelle le robot doit s'arrêter, on laisse ->
    moteur.goForward();                 // -> le robot avancer
  } else if (distance_centre <= distance_mur) { // Sinon si la distance_centre est inférieure ou égale à la distance_mur on arrête le robot pour ne pas qu'il entre ->
    moteur.stop(); // -> en collision , on arrête le robot avec moteur.stop()
    delay(500);  // On ajoute un delai de 500ms avant l'exécution de la commande suivante

    servoMoteur.write(100); // On met la caméra au centre
    distance_centre = robot.getDistance(); //On récupère la distance au centre
    Serial.print("distance_centre = ");  //On affiche la distance au centre
    Serial.println(distance_centre);

    servoMoteur.write(40); // On met la caméra à droite
    delay(500); // On attend 500ms avant de prendre la mesure, cela permet d'avoir une mesure précise, car si on analyse la distance en tournant la caméra on ->
    // -> trouve des distances faussées
    distance_droite = robot.getDistance(); //On récupère la distance à droite
    Serial.print("distance_droite = ");//On affiche la distance à droite
    Serial.println(distance_droite);


    servoMoteur.write(150); // On met la caméra à gauche
    delay(500); // On attend 500ms avant de prendre la mesure, cela permet d'avoir une mesure précise, car si on analyse la distance en tournant la caméra on ->
    // -> trouve des distances faussées
    distance_gauche = robot.getDistance(); //On récupère la distance à gauche
    Serial.print("distance_gauche = ");//On affiche la distance à gauche
    Serial.println(distance_gauche);

    servoMoteur.write(100); // On met la caméra au centre
    moteur.stop(); // On arrête le robot
    delay(157); // On attend 157ms avant d'exécuter la ligne suivante

    if (distance_droite >= 150 && distance_gauche < distance_droite) { // Si la distance_droite est inférieure ou égale à 150 et que la distance_gauche est inférieure->
      // ->à la distance droite. Pour simplifier, si la place à droite est suffisante et si il y a plus de place à droite qu'à gauche
      moteur.turnRight(); // On tourne à droite
      delay(165); // Pendant 165ms
    } else if (distance_gauche >= 150 && distance_gauche > distance_droite) { // Dans l'autre cas, si la distance_gauche est supérieure ou égale à 150 et que la distance ->
      // -> est supérieure à la distance droite. Pour simplifier, si la place à gauche est suffisante et si il y a plus de place à gauche qu'à droite
      moteur.turnLeft(); // On tourne à gauche
      delay(165); // Pendant 165ms
    }

  }
}
