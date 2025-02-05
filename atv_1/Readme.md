#  Mudança de estado dos LEDS através de Push-Button.

Este projeto implementa a funcionalidade de controle temporizado de LEDs RGB utilizando o **Raspberry Pi Pico W**. O código é desenvolvido em **C** para sistemas embarcados e foi implementado na placa voltada a aprendizagem BitDogLab.

## Estrutura do Projeto

- **CMakeLists.txt**: Definição dos processos de compilação e requisitos necessários.
- **pico_sdk_import.cmake**: Arquivo com as configurações de importação do Pico SDK.
- **atv_1.c**: Arquivo com o código C para o Firmware.

## Funcionalidades

- **Led RBG**: A cada 3 segundos, um led diferente é ligado, de modo a simular um semáforo.  

## Requisitos

- **Hardware**:
  - Computador pessoal.
  - Raspberry Pi Pico W (RP2040).
  - 1 Led RGB ou 3 Leds de cores diferentes.
  - Cabo micro-USB para USB-A.

- **Software**:
  - Visual Studio Code
  - Pico SDK
  - Compilador ARM GCC
  - Extensão Wokwi para simulação de Circuitos

