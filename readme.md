# SERVO.-JOYSTK

## 🕹️ وصف المشروع

مشروع **SERVO.-JOYSTK** يهدف إلى التحكم باتجاه محرك **سيرفو** باستخدام **عصا تحكم (Joystick)**.  
من خلال تحريك عصا التحكم في الاتجاه الأفقي (X-axis)، يتم تغيير زاوية دوران السيرفو بسلاسة.

## 🧰 المتطلبات

- لوحة تطوير (مثل Arduino Uno)
- محرك سيرفو (Servo Motor)
- عصا تحكم (Joystick Module)
- أسلاك توصيل
- برنامج Arduino IDE

## ⚙️ التوصيل

### 🧩 توصيل عصا التحكم (Joystick):

| طرف الجويستيك | إلى منفذ Arduino |
|---------------|------------------|
| VCC           | 5V               |
| GND           | GND              |
| VRx           | A0               |
| VRy           | A1 *(اختياري)*   |
| SW *(زر الضغط)*| D2 *(اختياري)*  |

### 🔌 توصيل السيرفو:

| طرف السيرفو | إلى منفذ Arduino |
|-------------|------------------|
| VCC         | 5V               |
| GND         | GND              |
| Signal      | D9               |

## 💻 كود Arduino

```cpp
#include <Servo.h>

Servo myServo;
int joyX = A0;  // قراءة المحور الأفقي

void setup() {
  myServo.attach(9);   // توصيل السيرفو بالمنفذ 9
  pinMode(joyX, INPUT);
}

void loop() {
  int xValue = analogRead(joyX);         // قراءة قيمة الجويستيك (0 إلى 1023)
  int angle = map(xValue, 0, 1023, 0, 180); // تحويل القيمة إلى زاوية (0 - 180)
  myServo.write(angle);                  // توجيه السيرفو
  delay(15);                             // تأخير بسيط لتجنب الاهتزاز
}
