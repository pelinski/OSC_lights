#define amount 9 // amount + 1 

void setup() {
  for(int pin = 2; pin <= amount; pin++){
    pinMode (pin, OUTPUT); 
  }
  pinMode(12,OUTPUT);
  allOn();
  delay(1000);
  allOff();
}

void loop() { // Main loop
  int i = 0;
  while(true){
   if(i > 200){
    i = 0;
   }
   i ++;
  randomSeed(analogRead(0)*i);
  digitalWrite(12,0);
  delay(1000);
  digitalWrite(12,1);
  switch (random(0,10)){
    default:
        delay(random(10,30)*10);
        break; 
    case 1:
       flashFast();
       break;
    case 2:
       blinkOrder();
       break;
    case 3:
       blinkRandom();
      break; 
    case 4: 
        flashSlow();
      break;
    case 5:
        allRandom();
        break;
    case 6:
        runOrder();
        break;
    case 7:
        blinkOrderSwitch();
        break; 
  }
 }
}

void allRandom(){
  int numPin = 0; 
  bool varStop = true;
  for(int i = 0; i < random (20, 100); i++){
    numPin = random(2,amount); 
    digitalWrite(numPin,!digitalRead(numPin));
    delay(random(1,4)*1000);    
  }
  allOff();
}

void flashFast(){
  int wait = random(1,3) * 100;
  for(int i = 0; i< random(10,20); i++){
    allOn();
    delay(wait);
    allOff();
    delay(wait);
  }
  allOff();
}

void blinkOrder(){
  int wait = 500; 
  bool choose = true; 
  if(random(0,10) < 5){
    choose= false;
  }
  for ( int i = 0; i < random(5,10); i++){
    for ( int x = 2; x <=amount; x ++) {
      digitalWrite(x,0);
      delay(wait);
      digitalWrite(x,1);
      if(choose){
    delay(wait);
    }
    }
  }
  allOff();
}
void blinkRandom(){
  int wait = random(3,20)*100;
  int numPin = 0; 
  bool choose = true; 
  if(random(0,10) < 5){
    choose= false;
  }
  for(int i = 0; i< random(20, 80); i++){
    numPin = random(2,amount);
    digitalWrite(numPin,0); 
    delay(wait);
    digitalWrite(numPin,1); 
    if(choose){
    delay(wait);
    }
  }
}

void flashSlow(){
  for(int i = 0; i< random(10,20); i++){
    allOn();
    delay(300);
    allOff();
    delay(1500);
  }
}

void runOrder(){
  int wait = 500; 
  for ( int i = 0; i < random(5,10); i++){
    for ( int x = 2; x <=amount; x ++) {
      digitalWrite(x,0);
      delay(wait);
    }
     for ( int x = 2; x <=amount; x ++) {
      digitalWrite(x,1);
      delay(wait);
    }
  }
  allOff();
}

void blinkOrderSwitch(){
  int wait = 500; 
  bool choose = true; 
  if(random(0,10) < 5){
    choose= false;
  }
  for ( int i = 0; i < random(5,10); i++){
    for ( int x = 2; x <=amount; x ++) {
      digitalWrite(x,0);
      delay(wait);
      digitalWrite(x,1);
      if(choose){
      delay(wait);
      }
    }
    for ( int x = amount; x >= 2 ; x --) {
      digitalWrite(x,0);
      delay(wait);
      digitalWrite(x,1);
      if(choose){
      delay(wait);
      }
    }
  }
  allOff();
}


void allOn(){
  for(int pin = 2; pin <=amount; pin++){
    digitalWrite(pin,0);
  }
}

void allOff(){
  for(int pin = 2; pin <= amount; pin++){
    digitalWrite(pin,1 );
  }
}


