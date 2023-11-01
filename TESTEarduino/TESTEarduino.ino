int BUZZ = 9; 

int LED_0 = 2; 
int LED_1 = 3; 
int LED_2 = 4; 
int LED_3 = 5; 

int BTN_0 = 6; 
int BTN_1 = 7; 
int BTN_2 = 8; 
int BTN_3 = 9; 

int mem[10];   
int stagio = 0; 
int aux = 0;    
int botao = 4;  
int sort = 0;   

void setup() {
  pinMode(BUZZ, OUTPUT);
  pinMode(LED_0, OUTPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(BTN_0, INPUT_PULLUP);
  pinMode(BTN_1, INPUT_PULLUP);
  pinMode(BTN_2, INPUT_PULLUP);
  pinMode(BTN_3, INPUT_PULLUP);
}

void loop() {
  if (stagio == 4) {
    while (digitalRead(BTN_0) && digitalRead(BTN_1) && digitalRead(BTN_2) && digitalRead(BTN_3)) {
      Sort();
    }
    while (!digitalRead(BTN_0) || !digitalRead(BTN_1) || !digitalRead(BTN_2) || !digitalRead(BTN_3)) {
      leds(4);
    }
  }
  mem[stagio] = sort;

  for (int i = 0; i <= stagio; i++) {
    leds(mem[i]);
  }

  while (aux <= stagio) {
    while (!(digitalRead(BTN_0) && digitalRead(BTN_1) && digitalRead(BTN_2) && digitalRead(BTN_3))) {
      if (!digitalRead(BTN_0)) botao = 0;
      if (!digitalRead(BTN_1)) botao = 1;
      if (!digitalRead(BTN_2)) botao = 2;
      if (!digitalRead(BTN_3)) botao = 3;
      Sort();
    }
    if (botao < 4) {
      leds(botao);
      if (botao != mem[aux]) {
        digitalWrite(LED_0, HIGH);
        digitalWrite(LED_1, HIGH);
        digitalWrite(LED_2, HIGH);
        digitalWrite(LED_3, HIGH);
        tone(BUZZ, 80);
        delay(1000);
        noTone(BUZZ);
        delay(500);
        leds(4);
        stagio = -1;
      }
      aux++;
    }
    botao = 4;
  }
  delay(200);
  stagio++;
}

void leds(int led) {
  if (led < 4) {
    tone(BUZZ, (led + 2) * 100);
    digitalWrite(LED_0, led == 0);
    digitalWrite(LED_1, led == 1);
    digitalWrite(LED_2, led == 2);
    digitalWrite(LED_3, led == 3);
    delay(500);
    noTone(BUZZ);
  } else {
    digitalWrite(LED_0, LOW);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
  }
}
void Sort() {
  if (sort)
    sort--;
  else
    sort = 3;
  delayMicroseconds(500);
}
