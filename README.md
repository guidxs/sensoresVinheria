# Projeto Arduino - Monitor de Ambiente

Este é um projeto Arduino desenvolvido no Tinkercad que consiste em um monitor de ambiente. O código implementa funcionalidades relacionadas à iluminação, temperatura e umidade, exibindo informações em um display LCD e acionando LEDs e um buzzer conforme as condições do ambiente.

## Funcionalidades

O monitor de ambiente possui as seguintes funcionalidades:

- Enquanto o ambiente estiver escuro, o LED Verde fica aceso.
- Enquanto o ambiente estiver a meia luz, o LED Amarelo fica aceso e exibe a mensagem "Ambiente a meia luz" no Display.
- Enquanto o ambiente estiver totalmente iluminado, o LED Vermelho fica aceso e exibe a mensagem "Ambiente muito claro" no Display.
- Enquanto o ambiente estiver com uma temperatura entre 10°C e 15°C, o Display exibe "Temperatura OK" e o valor da temperatura.
- Enquanto o ambiente estiver com uma umidade entre 50% e 70%, o Display exibe "Umidade OK" e o valor da umidade.
- Os valores apresentados no Display são a média de pelo menos 5 leituras dos sensores, atualizados a cada 5 segundos.
- Caso a temperatura esteja fora da faixa ideal, o LED Amarelo fica aceso, o Buzzer é acionado continuamente e o Display exibe "Temp. Alta" ou "Temp. Baixa", dependendo do valor medido.
- Caso a umidade esteja fora da faixa ideal, o LED Vermelho fica aceso, o Buzzer é acionado continuamente e o Display exibe "Umidade. Alta" ou "Umidade. Baixa", dependendo do valor medido.

## Componentes Utilizados

O projeto utiliza os seguintes componentes:

- Arduino Uno
- LED Verde
- LED Amarelo
- LED Vermelho
- Buzzer
- Potenciômetro (simulando o sensor de temperatura)
- Fotoresistor (simulando o sensor de iluminação)
- Display LCD 16x2

## Configuração do Tinkercad

1. Adicione os componentes listados acima ao seu projeto no Tinkercad.
2. Conecte os componentes conforme mostrado no diagrama de circuito incluído neste repositório.
3. Abra o código `sensores.c` neste repositório e copie-o.
4. Cole o código no Arduino IDE no Tinkercad.
5. Compile e faça o upload do código para o Arduino Uno.

## Observações

- O Tinkercad não possui um componente específico para o sensor de temperatura (DHT11) utilizado neste projeto. Portanto, um potenciômetro foi utilizado para simular o sensor de temperatura.
- O Tinkercad também não possui um componente específico para o fotoresistor (sensor de iluminação). Por esse motivo, a leitura de um pino analógico é utilizada para simular a detecção de iluminação.

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir problemas (issues) ou enviar pull requests para aprimorar este projeto.

---

# Arduino Project - Environment Monitor

This is an Arduino project developed in Tinkercad that serves as an environment monitor. The code implements functionalities related to lighting, temperature, and humidity, displaying information on an LCD and activating LEDs and a buzzer according to the ambient conditions.

## Features

The environment monitor includes the following features:

- While the environment is dark, the Green LED remains on.
- While the environment is dimly lit, the Yellow LED remains on, and the message "Dimly lit environment" is displayed on the LCD.
- While the environment is well-lit, the Red LED remains on, and the message "Bright environment" is displayed on the LCD.
- While the temperature is between 10°C and 15°C, the Display shows "Temperature OK" and the temperature value.
- While the humidity is between 50% and 70%, the Display shows "Humidity OK" and the humidity value.
- The values displayed on the LCD are the average of at least 5 sensor readings, updated every 5 seconds.
- If the temperature is outside the ideal range, the Yellow LED remains on, the Buzzer continuously sounds, and the Display shows "High Temp" or "Low Temp", depending on the measured value.
- If the humidity is outside the ideal range, the Red LED remains on, the Buzzer continuously sounds, and the Display shows "High Humidity" or "Low Humidity", depending on the measured value.

## Components Used

The project utilizes the following components:

- Arduino Uno
- Green LED
- Yellow LED
- Red LED
- Buzzer
- Potentiometer (simulating the temperature sensor)
- Photoresistor (simulating the light sensor)
- LCD Display 16x2

## Tinkercad Setup

1. Add the listed components to your project in Tinkercad.
2. Connect the components as shown in the circuit diagram included in this repository.
3. Open the `sensores.c` code in this repository and copy it.
4. Paste the code into the Arduino IDE in Tinkercad.
5. Compile and upload the code to the Arduino Uno.

## Notes

- Tinkercad does not have a specific component for the DHT11 temperature sensor used in this project. Therefore, a potentiometer is used to simulate the temperature sensor.
- Tinkercad also does not have a specific component for the photoresistor (light sensor). For this reason, reading an analog pin is used to simulate light detection.

## Contribution

Contributions are welcome! Feel free to open issues or send pull requests to enhance this project.

