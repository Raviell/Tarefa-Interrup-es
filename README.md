# Projeto: Controle de LEDs e Botões com RP2040

## 📌 Descrição do Projeto
Este projeto implementa um sistema utilizando a placa **BitDogLab** e o microcontrolador **RP2040**, controlando LEDs comuns e uma matriz de LEDs **WS2812**. Além disso, dois botões são utilizados para incrementar e decrementar números exibidos na matriz de LEDs.

## 🛠️ Componentes Utilizados
- Placa de desenvolvimento **BitDogLab**
- Matriz 5x5 de LEDs WS2812 (conectada à GPIO 7)
- LED RGB (conectado às GPIOs 11, 12 e 13)
- Botão A (conectado à GPIO 5)
- Botão B (conectado à GPIO 6)

## 🚀 Funcionalidades Implementadas
- O **LED vermelho** pisca **5 vezes por segundo**.
- O **Botão A** incrementa o número exibido na matriz de LEDs.
- O **Botão B** decrementa o número exibido na matriz de LEDs.
- A **matriz de LEDs WS2812** exibe os números de **0 a 9**.
- Utilização de **interrupções** (IRQs) para capturar eventos dos botões.
- Implementação de **debouncing via software** para evitar acionamentos falsos.

## 🔧 Configuração do Ambiente
1. Instale o **Arduino IDE** ou **VS Code com PlatformIO**.
2. Adicione o suporte para **RP2040** no Arduino IDE.
3. Instale as bibliotecas necessárias:
   - **Adafruit_NeoPixel** (para controlar os LEDs WS2812)
4. Conecte a placa **BitDogLab** ao computador via USB.

## ▶️ Como Compilar e Executar
1. Abra o arquivo do projeto no **Arduino IDE**.
2. Selecione a placa **RP2040 (Raspberry Pi Pico)**.
3. Conecte a **BitDogLab** e carregue o código.
4. Pressione os botões para testar a funcionalidade.

## 📜 Autor
- Nome: Brunna Barreto da Silva
- Contato: 20241bsifsa0027@ifba.edu.br

