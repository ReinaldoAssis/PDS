#include <Filters.h>

const int ledPin = 13;  // Pino do LED interno
const int threshold = 10000;  // Limiar de amplitude

// Configuração do filtro passa-faixa
float sampleRate = 44100.0;
float lowCutoff = 1700.0;    // Frequência de corte inferior
float highCutoff = 6000.0;   // Frequência de corte superior
BandPass myFilter(lowCutoff, highCutoff, sampleRate);

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  if (Serial.available() >= 2) {  // Espera até que dois bytes estejam disponíveis
    // Recebe o sinal (16 bits)
    int16_t audioSample = Serial.read() | (Serial.read() << 8);
    
    // Aplica o filtro passa-faixa
    float filteredSample = myFilter.input(audioSample);

    // Verifica se o valor filtrado excede o limiar
    if (abs(filteredSample) > threshold) {
      digitalWrite(ledPin, HIGH);  // Liga o LED
    } else {
      digitalWrite(ledPin, LOW);   // Desliga o LED
    }
  }
}