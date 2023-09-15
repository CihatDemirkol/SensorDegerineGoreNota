int echoPin = 6;
int trigPin = 7;
int buzzerPin = 8;
long duration, distance;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  Serial.println(distance);
  int nota = 260; //nota değeri
  int ilkDeger = 2, degerSon,deger;

  if (distance > ilkDeger && distance < 26)
  {
    
    degerSon = distance - ilkDeger;
    nota = nota + (degerSon * 10);
    tone(buzzerPin, nota);
  }
  if (distance > 26)
  {
    noTone(buzzerPin);
  }




}
