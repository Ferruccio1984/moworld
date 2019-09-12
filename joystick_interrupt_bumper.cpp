int front_back=0;
int left_right=0;
int threshold = 200;
int stato_bumper[4];

void setup() {
   Serial.begin(9600);
   pinMode(2, OUTPUT); // bumper posteriore
   pinMode(3, OUTPUT); //bumper anteriore
   pinMode(4, OUTPUT); //bumper destro
   pinMode(5, OUTPUT); //bumper sinistro
}

void loop() {
  

  // input analogici
  front_back = analogRead(0);
  left_right = analogRead(1);
  /*Serial.println ("avanti_dietro");
  Serial.println (front_back);
  delay (1000);
  Serial.println ("destra_sinistra");
  Serial.println (left_right);
  delay (1000);
  */

   // output digitali
   
   if (front_back > 516 + 50){
    if (stato_bumper[0]== 0){
       stato_bumper[0]=1;
       digitalWrite (2,HIGH);
       digitalWrite (3,LOW);
       Serial.println ("impatto posteriore");
       delay (100);
       digitalWrite (3,HIGH);
    }else{
       stato_bumper[0]=1;
       digitalWrite (2,HIGH);
       digitalWrite (3,HIGH);
    }
   }else if(front_back < 516 - threshold){
      if (stato_bumper[1]== 0){
       stato_bumper[1]=1;
       digitalWrite (2,LOW);
       digitalWrite (3,HIGH);
       Serial.println ("impatto frontale");
       delay (100);
       digitalWrite (2,HIGH);
    }else{
       stato_bumper[1]=1;
       digitalWrite (2,HIGH);
       digitalWrite (3,HIGH);
    }
   }else{
       digitalWrite (2,HIGH);
       digitalWrite (3,HIGH);
       stato_bumper[0]= 0;
       stato_bumper[1]= 0;
   }
 
    if (left_right > 516 + threshold){
      if (stato_bumper[2]== 0){
       stato_bumper[2]=1;
       digitalWrite (4,HIGH);
       digitalWrite (5,LOW);
       Serial.println ("impatto sinistro");
       delay (100);
       digitalWrite (5,HIGH);
    }else{
       stato_bumper[2]=1;
       digitalWrite (4,HIGH);
       digitalWrite (5,HIGH);
    }}else if (left_right < 516 - threshold){
       if (stato_bumper[3]== 0){
       stato_bumper[3]=1;
       digitalWrite (4,LOW);
       digitalWrite (5,HIGH);
       Serial.println ("impatto destro");
       delay (100);
       digitalWrite (4,HIGH);
       }else{
       stato_bumper[3]=1;
       digitalWrite (4,HIGH);
       digitalWrite (5,HIGH);    
       }
    }else{
       digitalWrite (4,HIGH);
       digitalWrite (5,HIGH);
       stato_bumper[2]= 0;
       stato_bumper[3]= 0;
    }
    
    


 /* 
  
 

  if (front_back > 516 + threshold){
    digitalWrite (2,HIGH);
    digitalWrite (3,LOW);
    delay (10);
    digitalWrite (3,HIGH);
    Serial.println ("impatto posteriore");
    }else if (front_back < 516 - threshold){
    digitalWrite (2,LOW);
    delay (10);
    digitalWrite (2,HIGH);
    digitalWrite (3,HIGH);
    Serial.println ("impatto frontale");
    }else{
    digitalWrite (2,HIGH);
    digitalWrite (3,HIGH);  

     if (left_right > 516 + threshold){
    digitalWrite (4,HIGH);
    digitalWrite (5,LOW);
    delay(10);
    digitalWrite (5,HIGH);
    Serial.println ("impatto sinistro");
    }else if (left_right < 516 - threshold){
    digitalWrite (4,LOW);
    delay(10);
    digitalWrite (4,HIGH);
    digitalWrite (5,HIGH);
    Serial.println ("impatto destro");
    }else{
    digitalWrite (4,HIGH);
    digitalWrite (5,HIGH);  
    } 
  }
  */
}
