#define RED_ONE 4
#define YELLOW_ONE 3
#define GREEN_ONE 2

#define RED_TWO 7
#define YELLOW_TWO 6
#define GREEN_TWO 5

#define WALK 8


/* В схеме идет расчитана на 2 дорожных светофора (трехсветовых)
 * и на один пешеходный
 * 
 * Последовательность работы зеленых сигналов:
 * 1) Второй дорожный
 * 2) Первый дорожный
 * 3) Пешеходный
 * 
 * Пешеходный светофор загорается только тогда, когда
 * дорожные светофоры последовательно показали зеленый сигнал
 * 
 * Схема работы дорожного светофора:
 * 1) Только красный
 * 2) К красному добавляется желтый
 * 3) Только зеленый
 * 4) Зеленый моргает
 * 5) Только желтый
*/
void setup() {
  // Определяем режимы работы пинов
  pinMode(RED_ONE, OUTPUT);
  pinMode(YELLOW_ONE, OUTPUT);
  pinMode(GREEN_ONE, OUTPUT);

  pinMode(RED_TWO, OUTPUT);
  pinMode(YELLOW_TWO, OUTPUT);
  pinMode(GREEN_TWO, OUTPUT);

  pinMode(WALK, OUTPUT);
}


// Моргание пина
// По итогу оставляет пин выключенным
// pin_number -- номер пина на Arduino
void blindPin(int pin_number) {
  for (int i = 0; i <= 3; i++) {
    digitalWrite(pin_number, HIGH);
    delay(250);
    digitalWrite(pin_number, LOW);
    delay(250);
  }
}


// Шаг 1
// Первый и пешеходный -- красный
void stepOne() {
  digitalWrite(RED_ONE, HIGH);
  digitalWrite(GREEN_TWO, HIGH);

  digitalWrite(WALK, HIGH);

  digitalWrite(YELLOW_ONE, LOW);
  digitalWrite(GREEN_ONE, LOW);
  digitalWrite(YELLOW_TWO, LOW);
  digitalWrite(RED_TWO, LOW);

  delay(2000);
}


// Шаг 2
// Второй моргает зеленым, первый -- + желтый
void stepTwo() {
  digitalWrite(YELLOW_ONE, HIGH);  // Не менять местами со следующей строкой!
  blindPin(GREEN_TWO);
}


// Шаг 3
// Второй -- только желтый
void stepThree() {
  digitalWrite(YELLOW_TWO, HIGH);
  delay(3000);
}


// Шаг 4
// Первый -- зеленый, остальные красные
void stepFour() {
  digitalWrite(RED_ONE, LOW);
  digitalWrite(YELLOW_ONE, LOW);
  digitalWrite(GREEN_ONE, HIGH);

  digitalWrite(RED_TWO, HIGH);
  digitalWrite(YELLOW_TWO, LOW);

  delay(2000);
}


// Шаг 5
// Первый моргает зеленым
void stepFive() {
  blindPin(GREEN_ONE);
}


// Шаг 6
// Первый -- только желтый
void stepSix() {
  digitalWrite(YELLOW_ONE, HIGH);
  delay(3000);
}


// Шаг 7
// Все дорожные -- красный, пешеходный зеленый
void stepSeven() {
  digitalWrite(RED_ONE, HIGH);
  digitalWrite(YELLOW_ONE, LOW);
  delay(1500);
}


// Шаг 8
// Пешеходный моргает зеленым, Второй -- + желтый
void stepEight() {
  digitalWrite(YELLOW_TWO, HIGH);
  blindPin(WALK);
  blindPin(WALK);
}


void loop() {
  stepOne();
  stepTwo();
  stepThree();
  stepFour();
  stepFive();
  stepSix();
  stepSeven();
  stepEight();
}
