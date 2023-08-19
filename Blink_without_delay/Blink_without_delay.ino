int led = 5;
unsigned long time1; 
unsigned long time2 = 0;
const long interval = 500;

void setup(){
  pinMode(led,OUTPUT);
  }

void loop () {
  time1 = millis();
  int ledstatus = digitalRead(led);
  if(time1-time2 >= interval){
    time2 = time1;
    if(ledstatus == HIGH){
      digitalWrite(led,LOW);
      }else if (ledstatus == LOW){
        digitalWrite(led,HIGH);
        }
    }
  } 
