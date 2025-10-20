# 🤖 Projeto Robótico com ESP32 e Câmera em Tempo Real

## 🧠 Descrição Geral
Este projeto consiste em **um sistema robótico controlado via controle PS3**, utilizando **dois ESP32** conectados em rede.  
Um dos módulos ESP32 é responsável pelo **controle dos motores e servos**, enquanto o outro gerencia uma **câmera com transmissão de vídeo em tempo real** por meio de um **servidor web** embutido.

O robô é projetado para **movimentação direcional**, **controle de câmera pan/tilt**, e **transmissão de vídeo ao vivo**, permitindo operação remota com resposta em tempo real.

---

## ⚙️ Estrutura do Sistema

### 🔹 ESP32 - Controle do Robô
Responsável por:
- Conexão com controle PS3 via Bluetooth.  
- Controle de motores (movimento para frente/trás).  
- Controle de servos (direção e movimentação da câmera).  
- Feedback no console serial sobre status e bateria do controle.

### 🔹 ESP32 - Câmera IP
Responsável por:
- Captura de vídeo em tempo real.  
- Hospedagem de um **servidor web** para visualização via navegador.  
- Controle de **servo motores** da câmera para ajuste de ângulo.  

---

## 🔌 Componentes Utilizados
| Componente | Função |
|-------------|--------|
| ESP32 (x2) | Um para controle e outro para vídeo |
| Controle PS3 | Interface de controle Bluetooth |
| Servo Motor (x3) | Direção e controle da câmera (pan/tilt) |
| Driver de Motor (L298N ou similar) | Controle de motores DC |
| Motores DC | Movimentação do robô |
| Módulo de câmera ESP32-CAM | Transmissão de vídeo em tempo real |
| LED indicador | Status de operação |

---

## 🧩 Ligações (ESP32 de Controle)

| Pino ESP32 | Função | Descrição |
|-------------|--------|-----------|
| 12 | M1D1 | Direção do motor |
| 14 | M1D2 | Direção oposta do motor |
| 13 | PWM1 | Velocidade dos motores (pwm) |
| 16 | ServoD | Direção do robô |
| 4 | ServoCam | Controle de rotação da câmera |
| 19 | ServoCam1 | Controle de inclinação da câmera |
| 2 | LED | Indicador de status |

---

## 🕹️ Controles (PS3)
| Botão / Eixo | Função |
|---------------|--------|
| **Lx** | Direção das rodas |
| **R2** | Movimento para frente |
| **L2** | Movimento para trás |
| **Rx** | Rotação horizontal da câmera |
| **Ry** | Rotação vertical da câmera |
| **Status da bateria** | Exibido no console serial |

---

## 💻 Principais Bibliotecas
- [`Ps3Controller.h`](https://github.com/jvpernis/ESP32-PS3) — Comunicação Bluetooth com controle PS3.  
- [`ESP32Servo.h`](https://github.com/madhephaestus/ESP32Servo) — Controle de servos via PWM.  

---

## 🧠 Funcionamento do Código

1. **Inicialização**  
   - O ESP32 se conecta ao controle PS3.  
   - Servos e motores são configurados e posicionados em 90°.  
   - Um LED é ativado como indicador de funcionamento.

2. **Loop principal (`loop`)**  
   - Executa duas funções principais:
     - `servos()` → Controla os movimentos de direção e câmera.  
     - `motores()` → Controla a movimentação do robô.  

3. **Função `servos()`**
   - Lê os valores analógicos dos joysticks do controle PS3.  
   - Converte e mapeia para ângulos de rotação entre **0° e 180°**.  
   - Atualiza a posição dos servos gradualmente para suavizar o movimento.

4. **Função `motores()`**
   - Lê os botões R2 e L2 para determinar direção e intensidade de velocidade.  
   - Controla os pinos de direção (M1D1 e M1D2) e a saída PWM do motor.

---

## 🌐 Transmissão de Vídeo (Segundo ESP32)
O segundo ESP32, equipado com **ESP32-CAM**, hospeda um **webserver** que transmite vídeo em tempo real.  
O acesso é feito via navegador, digitando o IP do ESP32 na mesma rede local.

**Recursos típicos do servidor de vídeo:**
- Visualização ao vivo.  
- Controle remoto de ângulos via servos (pan/tilt).  
- Ajuste de qualidade e taxa de quadros.  

---

## 📸 Exemplo de Uso
1. Ligue o ESP32 principal e aguarde a mensagem “**Gralha online!!!**”.  
2. Conecte o controle PS3 (a conexão é automática).  
3. Acesse o IP do segundo ESP32 no navegador para visualizar o vídeo.  
4. Controle o robô com o joystick — direção, movimento e câmera em tempo real.

---

## 🚀 Melhorias Futuras
- Transmissão de dados de telemetria (velocidade, sinal, bateria).  
- Modo autônomo com sensores ultrassônicos.  
- Gravação de vídeo direto no servidor.  
- Interface web integrada com controle remoto.  

---


