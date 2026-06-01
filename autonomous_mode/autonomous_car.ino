#include <SoftwareSerial.h>

// --- BLUETOOTH PİNLERİ ---
SoftwareSerial BTSerial(6, 7);  // Arduino D6 -> BT TX, Arduino D7 -> BT RX

// --- MOTOR PİNLERİ ---
#define ENA 11 // Sol motor hız kontrolü (PWM)
#define IN1 12 // Sol motor ileri/geri
#define IN2 13 // Sol motor ileri/geri
#define IN3 2  // Sağ motor ileri/geri
#define IN4 4  // Sağ motor ileri/geri
#define ENB 3  // Sağ motor hız kontrolü (PWM)

// Uygulamadan gelecek veri
char command;

// --- HIZ AYARLARI VE KALİBRASYON ---
// Araç sola çektiği için sağ motor daha güçlü dönüyor demektir.
// Bu yüzden sağ motorun gücünü kısarak dengeyi sağlıyoruz.
int normalHizSol = 155; 
int normalHizSag = 145; 
int donusHizi = 120;

void setup() {
  // Motor pinlerini çıkış olarak ayarla
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Başlangıçta motorları durdur
  motorDurdur();

  // Seri haberleşmeyi başlat
  Serial.begin(9600);    
  BTSerial.begin(9600);  
}

void loop() {
  // Bluetooth'tan veri geliyorsa oku
  if (BTSerial.available()) {
    command = BTSerial.read();
    Serial.println(command);  

    switch (command) {
      case 'B':  // İleri (Forward)
        ileriGit(normalHizSol, normalHizSag);
        break;
      case 'F':  // Geri (Back)
        geriGit(normalHizSol, normalHizSag);
        break;
      case 'L':  // Sol (Left)
        solaDon(donusHizi, donusHizi);
        break;
      case 'R':  // Sağ (Right)
        sagaDon(donusHizi, donusHizi);
        break;
      case 'S':  // Dur (Stop)
        motorDurdur();
        break;
    }
  }
}

// ==========================================
// --- MOTOR KONTROL FONKSİYONLARI ---
// ==========================================

void geriGit(int solHiz, int sagHiz) {
  analogWrite(ENA, solHiz);
  analogWrite(ENB, sagHiz);
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void ileriGit(int solHiz, int sagHiz) {
  analogWrite(ENA, solHiz);
  analogWrite(ENB, sagHiz);
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

// Yumuşak Sola Dönüş (İki motor da ileri, ancak sol motor yarı hızda)
void solaDon(int solHiz, int sagHiz) {
  analogWrite(ENA, solHiz / 2); // İçte kalan motoru yavaşlatıyoruz
  analogWrite(ENB, sagHiz);
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH); // Sol İleri (Artık geri değil)
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH); // Sağ İleri
}

// Yumuşak Sağa Dönüş (İki motor da ileri, ancak sağ motor yarı hızda)
void sagaDon(int solHiz, int sagHiz) {
  analogWrite(ENA, solHiz);
  analogWrite(ENB, sagHiz / 2); // İçte kalan motoru yavaşlatıyoruz
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH); // Sol İleri
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH); // Sağ İleri (Artık geri değil)
}

void motorDurdur() {
  analogWrite(ENA, 0); 
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}
