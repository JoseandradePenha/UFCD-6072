// Definições dos pinos dos LEDs e botão
const int pinVermelho = 9;
const int pinVerde = 10;
const int pinAzul = 11;
const int botao = 2;

bool estadoBotao = false;  // Estado do botão

void setup() {
  // Configurar os pinos dos LEDs como saídas
  pinMode(pinVermelho, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAzul, OUTPUT);

  // Configurar o pino do botão como entrada com pull-up
  pinMode(botao, INPUT_PULLUP);

  // Inicialmente, apagar todos os LEDs
  apagarLeds();
}

void loop() {
  // Liga o LED vermelho por 5 segundos
  ligarVermelho();
  delay(5000);

  // Liga o LED verde por 5 segundos
  ligarVerde();
  delay(5000);

  // Verifica se o botão foi pressionado para acionar o LED azul
  if (digitalRead(botao) == LOW) {
    estadoBotao = true;
  }

  if (estadoBotao) {
    ligarAzul();
    delay(5000);  // Mantém o LED azul aceso por 5 segundos
    estadoBotao = false;  // Reseta o estado do botão
  }
}

// Função para ligar o LED vermelho e apagar os outros
void ligarVermelho() {
  digitalWrite(pinVermelho, HIGH);
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAzul, LOW);
}

// Função para ligar o LED verde e apagar os outros
void ligarVerde() {
  digitalWrite(pinVermelho, LOW);
  digitalWrite(pinVerde, HIGH);
  digitalWrite(pinAzul, LOW);
}

// Função para ligar o LED azul e apagar os outros
void ligarAzul() {
  digitalWrite(pinVermelho, LOW);
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAzul, HIGH);
}

// Função para apagar todos os LEDs
void apagarLeds() {
  digitalWrite(pinVermelho, LOW);
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAzul, LOW);
}

