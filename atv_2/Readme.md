#  Mudança de estado dos LEDS através de Push-Button.

Este projeto implementa a funcionalidade de controle de LEDs RGB utilizando o **Raspberry Pi Pico W** através do pressionamento de 1 botão. O código é desenvolvido em **C** para sistemas embarcados e foi implementado na placa voltada a aprendizagem BitDogLab.

## Estrutura do Projeto

- **CMakeLists.txt**: Definição dos processos de compilação e requisitos necessários.
- **pico_sdk_import.cmake**: Arquivo com as configurações de importação do Pico SDK.
- **atv_2.c**: Arquivo com o código C para o Firmware.

## Funcionalidades

- **Botão A**: Ativa o processo de ligamento dos LEDS.  
- **Led RBG**: A cada 3 segundos, um dos LEDS é desligado até que sejam todos desligados.  

## Requisitos

- **Hardware**:
  - Computador pessoal.
  - Raspberry Pi Pico W (RP2040).
  - 1 Botão.
  - 1 Led RGB ou 3 Leds de cores distintas.
  - Cabo micro-USB para USB-A.

- **Software**:
  - Visual Studio Code
  - Pico SDK
  - Compilador ARM GCC
  - Extensão Wokwi para simulação de Circuitos

