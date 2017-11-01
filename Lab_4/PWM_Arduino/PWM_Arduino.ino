const int MAX_8_INT = 255;
const int MAX_10_INT = 1024;
const int led = 10;
const int PWM = 9;
int brightness;
int fade_amount;
int value;
int scale;

void setup() {

  analogWriteResolution(8);
  analogReadResolution(10);

  pinMode(A0, INPUT); 
  pinMode(PWM, OUTPUT); 
  
  brightness = 0;
  fade_amount = 1;
}

void loop() {
  
  analogWrite(led,brightness);
  brightness=brightness+fade_amount;
  
  if (brightness == 0 or brightness == MAX_8_INT)
  {
    fade_amount = -fade_amount;
  }
 
  value = analogRead(A0); 
  //scale = MAX_8_INT*(value/MAX_10_INT);
  scale = value >> 2;

  analogWrite(PWM, scale);
  analogWrite(LED_BUILTIN, scale);
  delay(30);
} 
