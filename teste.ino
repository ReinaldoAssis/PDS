const int ledPin = 2;  // Pino do LED embutido na ESP32 (geralmente 2)

void setup() {
  Serial.begin(115200);  // Inicializa a comunicação serial
  pinMode(ledPin, OUTPUT);  // Configura o pino do LED como saída
}

void loop() {
  // Liga o LED
  digitalWrite(ledPin, HIGH);
  delay(1000);  // Mantém o LED ligado por 1 segundo
  
  // Envia mensagem "pisquei" via serial
  Serial.println("pisquei");
  
  // Desliga o LED
  digitalWrite(ledPin, LOW);
  delay(1000);  // Mantém o LED desligado por 1 segundo
}