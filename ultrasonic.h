#include <Arduino.h>

class UltraSonic { // On définie une classe appellée UltraSonic
  private:
  const int echo= A4; // On définie echo sur le pin A4, le récepteur ultrasons
  const int trig = A5; // On définie trig sur le pin A5, l'émetteur ultrasons

  public:
  UltraSonic(){ // Constructeur de la classe UltraSonic
    pinMode(echo,INPUT); // On définie le pin echo en entrée
    pinMode(trig,OUTPUT); // On définie le plin trig en sortie
  }

  float getDistance(){ // Méthode getDistance permettant de récupérer la distance par rapport à un obstacle
    digitalWrite(trig,LOW); // On définie le pin trig avec l'état LOW
    delayMicroseconds(2); // On met un délai de d'attente avant l'exécution suivante de 2 microsecondes
    digitalWrite(trig, HIGH); // On définie le pin trig avec l'état HIGH
    delayMicroseconds(20); // On met un délai d'attente avant l'exécution suivante de 2 microsecondes
    digitalWrite(trig,LOW); // On définie le ping trig avec l'état LOW
    float d=pulseIn(echo,HIGH); // On créé une variable d de type float, met la durée de l'impulsion de niveau HIGH dans la variable d
    d/=5.8f; // On divise ce nombre par 5.8 pour obtenir la distance
    return d; // On retourne le résultat du calcul contenu dans la variable
  }
};
