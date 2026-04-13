// Pines actualizados para ESP32
const int trigPin = 4;   // Tu D5
const int echoPin = 18;  // Tu D18 (donde están las resistencias)
const int motorPin = 25; // Tu D25 (donde está el motor)

long duration;
int distanceCm;

// Umbrales de distancia
const int NIVEL1 = 130; 
const int NIVEL2 = 105;  
const int NIVEL3 = 80;  
const int NIVEL4 = 50;  
const int NIVEL5 = 20;  

// Intensidades 
const int INTENSIDAD1 = 80; 
const int INTENSIDAD2 = 100; 
const int INTENSIDAD3 = 130;
const int INTENSIDAD4 = 170;
const int INTENSIDAD5 = 220;

void setup() {
    // El ESP32 funciona mejor a 115200 baudios
    Serial.begin(115200); 
    
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(motorPin, OUTPUT);
    
    Serial.println("VisioAlerta ESP32 Iniciado...");
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

    // Monitor Serial
    Serial.print("Distancia: ");
    Serial.print(distanceCm);
    Serial.print(" cm -> ");

    // Control del motor
    if (distanceCm > 0 && distanceCm < 400) { 
        if (distanceCm <= NIVEL5) {
            analogWrite(motorPin, INTENSIDAD5);
            Serial.println("Nivel 5: Máximo");
        } 
        else if (distanceCm <= NIVEL4) {
            analogWrite(motorPin, INTENSIDAD4);
            Serial.println("Nivel 4: Alto");
        }
        else if (distanceCm <= NIVEL3) {
            analogWrite(motorPin, INTENSIDAD3);
            Serial.println("Nivel 3: Medio");
        }
        else if (distanceCm <= NIVEL2) {
            analogWrite(motorPin, INTENSIDAD2);
            Serial.println("Nivel 2: Bajo");
        }
        else if (distanceCm <= NIVEL1) {
            analogWrite(motorPin, INTENSIDAD1);
            Serial.println("Nivel 1: Suave");
        }
        else {
            analogWrite(motorPin, 0);
            Serial.println("Fuera de rango");
        }
    } else {
        analogWrite(motorPin, 0);
        Serial.println("Error de lectura");
    }

    delay(200); // Un poco más de tiempo para que el motor alcance a reaccionar
}