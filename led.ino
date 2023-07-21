

// LED'in bağlı olduğu pin
const int ledPin = 18;

void setup() {
  // Seri haberleşmeyi başlat
  Serial.begin(9600);
  
  // LED pinini çıkış olarak ayarla
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Seri haberleşmede veri var mı kontrol et
  if (Serial.available() > 0) {
    // Veriyi oku
    char data = Serial.read();
    
    // Veri 1 ise LED'i yak, 0 ise LED'i kapat
    if (data == '1') {
      digitalWrite(ledPin, HIGH);  // LED'i yak
      Serial.println("LED ON");
    } else if (data == '0') {
      digitalWrite(ledPin, LOW);   // LED'i kapat
      Serial.println("LED OFF");
    }
     else if (data == '2') {
      digitalWrite(ledPin, HIGH);   // LED'i  yak bekle
      delay(1000);
      digitalWrite(ledPin,LOW);   // LED'i kapat
      delay(500);

      Serial.println("LED sureli");
    }
  }
}

