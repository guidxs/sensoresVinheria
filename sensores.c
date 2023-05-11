#include <LiquidCrystal.h>

// Pinos dos componentes
const int ledVerdePin = 13;
const int ledAmareloPin = 12;
const int ledVermelhoPin = 11;
const int buzzerPin = 10;
const int tempSensorPin = A2;
const int lightSensorPin = A1;
const int displayRS = 9;
const int displayEN = 8;
const int displayD4 = 7;
const int displayD5 = 6;
const int displayD6 = 5;
const int displayD7 = 4;

// Constantes para cálculos de média
const int numLeituras = 5;
const int intervaloLeitura = 1000;

// Constantes para limites de temperatura e umidade
const int tempMinima = 10;
const int tempMaxima = 15;
const int umidadeMinima = 50;
const int umidadeMaxima = 70;

// Variáveis globais
int temperatura = 0;
int umidade = 0;
int mediaTemperatura = 0;
int mediaUmidade = 0;
int leituraTemperatura = 0;
int leituraUmidade = 0;
int contador = 0;

// Inicialização do LCD
LiquidCrystal lcd(displayRS, displayEN, displayD4, displayD5, displayD6, displayD7);

void setup() {
  // Inicialização dos pinos
  pinMode(ledVerdePin, OUTPUT);
  pinMode(ledAmareloPin, OUTPUT);
  pinMode(ledVermelhoPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Inicialização do LCD
  lcd.begin(16, 2);

  // Inicialização do monitor Serial
  Serial.begin(9600);
}

void loop() {
  // Leitura dos sensores
  leituraTemperatura = analogRead(tempSensorPin);
  leituraUmidade = random(0, 101);  // Simulação de umidade

  // Cálculo da média
  mediaTemperatura = (mediaTemperatura * contador + leituraTemperatura) / (contador + 1);
  mediaUmidade = (mediaUmidade * contador + leituraUmidade) / (contador + 1);
  contador++;

  // Verificação dos limites de temperatura
  if (mediaTemperatura < tempMinima || mediaTemperatura > tempMaxima) {
    digitalWrite(ledAmareloPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    lcd.clear();
    if (mediaTemperatura < tempMinima) {
      lcd.print("Temp. Baixa");
    } else {
      lcd.print("Temp. Alta");
    }
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(mediaTemperatura);
  } else {
    digitalWrite(ledAmareloPin, LOW);
    digitalWrite(buzzerPin, LOW);
    lcd.clear();
    lcd.print("Temperatura OK");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(mediaTemperatura);
  }

  // Verificação dos limites de umidade
  if (mediaUmidade < umidadeMinima || mediaUmidade > umidadeMaxima) {
    digitalWrite(ledVermelhoPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    lcd.clear();
    if (mediaUmidade < umidadeMinima) {
      lcd.print("Umidade. Baixa");
    } else {
      lcd.print("Umidade. Alta");
    }
    lcd.setCursor(0, 1);
    lcd.print("Umidade: ");
    lcd.print(mediaUmidade);
  } else {
    digitalWrite(ledVermelhoPin, LOW);
    digitalWrite(buzzerPin, LOW);
    lcd.clear();
    lcd.print("Umidade OK");
    lcd.setCursor(0, 1);
    lcd.print("Umidade: ");
    lcd.print(mediaUmidade);
  }

  // Verificação do ambiente (iluminação)
  if (analogRead(lightSensorPin) < 512) {  // Simulação de ambiente escuro
    digitalWrite(ledVerdePin, HIGH);
    digitalWrite(ledAmareloPin, LOW);
    digitalWrite(ledVermelhoPin, LOW);
    lcd.clear();
    lcd.print("Ambiente escuro");
  } else if (analogRead(lightSensorPin) < 768) {  // Simulação de ambiente a meia luz
    digitalWrite(ledVerdePin, LOW);
    digitalWrite(ledAmareloPin, HIGH);
    digitalWrite(ledVermelhoPin, LOW);
    lcd.clear();
    lcd.print("Ambiente a meia luz");
  } else {  // Simulação de ambiente iluminado
    digitalWrite(ledVerdePin, LOW);
    digitalWrite(ledAmareloPin, LOW);
    digitalWrite(ledVermelhoPin, HIGH);
    lcd.clear();
    lcd.print("Ambiente muito claro");
  }

  // Aguarda 5 segundos antes da próxima leitura
  delay(5000);
}

