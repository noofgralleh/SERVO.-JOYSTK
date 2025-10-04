# SERVO.-JOYSTK
#include <Servo.h>

Servo myServo;   

int joyPin = A0;   // نوصل محور X أو Y للـ A0
int val;

void setup() {
  myServo.attach(9); // السيرفو على Pin 9
}

void loop() {
  val = analogRead(joyPin);         // قراءة قيمة الجويستك (0 - 1023)
  val = map(val, 0, 1023, 0, 180);  // تحويل القيمة لمدى السيرفو (0 - 180 درجة)
  myServo.write(val);               // إرسال الزاوية للسيرفو
  delay(15);                        // تهدئة الحركة
}
