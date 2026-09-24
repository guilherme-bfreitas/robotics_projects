
// Definição dos Pinos de Comando
const int pinoPIR = 2;      // Sensor de movimento
const int pinoLampada = 13;
const int pinoLDR = A0; // Sensor de luz
const int dp1 = 3; 
const int dp2 = 4; 
const int dp3 = 5; 
const int dp4 = 6; 
const int dp5 = 7; 
const int dp6 = 8; 

// Configuração de Sensibilidade
const int limiarEscuro = 300;// Valor para considerar "escuro" 

void setup() {
 
  pinMode(pinoPIR, INPUT);
  pinMode(pinoLampada, OUTPUT);
 
  pinMode(dp1, INPUT); pinMode(dp2, INPUT); pinMode(dp3, INPUT);
  pinMode(dp4, INPUT); pinMode(dp5, INPUT); pinMode(dp6, INPUT);

  Serial.begin(9600);
}

void loop() {
  // 1. Verifica se há presença
  int presenca = digitalRead(pinoPIR);
  int nivelLuz = analogRead(pinoLDR);

  if (presenca == HIGH && nivelLuz <500) {
    // 2. Calcula o tempo somando os switches ativados
    int tempoTotal = 0;
    if (digitalRead(dp1) == HIGH) tempoTotal += 1;
    if (digitalRead(dp2) == HIGH) tempoTotal += 2;
    if (digitalRead(dp3) == HIGH) tempoTotal += 3;
    if (digitalRead(dp4) == HIGH) tempoTotal += 4;
    if (digitalRead(dp5) == HIGH) tempoTotal += 5;
    
    // Se nenhum switch de tempo estiver ligado, define o mínimo de 1s
    if (tempoTotal == 0) tempoTotal = 1;

    // 3. Verifica a Fotocélula (DP6)
    int usarLDR = digitalRead(dp6);
    bool estaEscuro = (nivelLuz > limiarEscuro);

    // 4. Lógica de Acendimento
    // Acende se: (DP6 desligado) OU (DP6 ligado E está escuro)
    if (usarLDR == LOW || (usarLDR == HIGH && estaEscuro == true))
      Serial.print("Presença Detectada! Lampada acesa por: ");
      Serial.print(tempoTotal);
      Serial.println(" segundos.");
      
      digitalWrite(pinoLampada, HIGH);
      delay(tempoTotal * 1000); // Converte segundos para milissegundos
      digitalWrite(pinoLampada, LOW);
      
      Serial.println("Tempo encerrado. Lampada desligada.");
    } 
    else {
      Serial.print("Movimento ignorado: Fotocelula ativa e esta CLARO (Luz: ");
      Serial.println(")");
    }
  }
