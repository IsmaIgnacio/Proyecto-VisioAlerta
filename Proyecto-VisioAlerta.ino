// Pines del sensor ultrasónico
const int trigPin = 9;
const int echoPin = 10;
const int motorPin = 3; // Pin PWM para el motor vibrador

long duration;
int distanceCm;

// Definición de los umbrales de distancia (en cm)
const int NIVEL1 = 120; // Distancia máxima para nivel 1 (lejano)
const int NIVEL2 = 90;  // Distancia máxima para nivel 2
const int NIVEL3 = 60;  // Distancia máxima para nivel 3
const int NIVEL4 = 30;  // Distancia máxima para nivel 4  
const int NIVEL5 = 10;  // Distancia máxima para nivel 5 (cercano)

// Intensidades del motor (0-255)
const int INTENSIDAD1 = 25;   // Nivel 1: vibración suave
const int INTENSIDAD2 = 50;   // Nivel 2: vibración baja-media
const int INTENSIDAD3 = 100;  // Nivel 3: vibración media
const int INTENSIDAD4 = 150;  // Nivel 4: vibración media-alta
const int INTENSIDAD5 = 200;  // Nivel 5: vibración máxima

void setup() {
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(motorPin, OUTPUT);
}

void loop() {
    // Generar pulso ultrasónico
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Medir duración del eco
    duration = pulseIn(echoPin, HIGH);

    // Calcular distancia en cm
    distanceCm = duration * 0.034 / 2;

    Serial.print("Distancia: ");
    Serial.print(distanceCm);
    Serial.println(" cm");

    // Control del motor vibrador con 5 niveles de intensidad
    if (distanceCm > 0) { // Solo si hay una lectura válida
        if (distanceCm <= NIVEL5) { // Menos de 10 cm
            analogWrite(motorPin, INTENSIDAD5);
            Serial.println("Nivel 5: Muy cerca - Vibración máxima");
        } 
        else if (distanceCm <= NIVEL4) { // Entre 10 y 30 cm
            analogWrite(motorPin, INTENSIDAD4);
            Serial.println("Nivel 4: Cerca - Vibración alta");
        }
        else if (distanceCm <= NIVEL3) { // Entre 30 y 60 cm
            analogWrite(motorPin, INTENSIDAD3);
            Serial.println("Nivel 3: Distancia media - Vibración media");
        }
        else if (distanceCm <= NIVEL2) { // Entre 60 y 90 cm
            analogWrite(motorPin, INTENSIDAD2);
            Serial.println("Nivel 2: Algo lejos - Vibración baja");
        }
        else if (distanceCm <= NIVEL1) { // Entre 90 y 120 cm
            analogWrite(motorPin, INTENSIDAD1);
            Serial.println("Nivel 1: Lejos - Vibración suave");
        }
        else { // Más de 120 cm
            analogWrite(motorPin, 0);
            Serial.println("Fuera de rango - Motor apagado");
        }
    } else {
        // Lectura inválida (distancia = 0)
        analogWrite(motorPin, 0);
        Serial.println("Error en lectura - Motor apagado");
    }

    delay(100); // Pequeña pausa para estabilidad
}