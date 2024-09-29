// Here are defined the connection pins and variables.
int Foc_analog = A5;
int Foc_digital = 7;
int LedRosu = 2;
int LedAlbastru = 4;
int BuzzerLoud = 11;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600); //aici
    pinMode(Foc_analog, INPUT);
    pinMode(Foc_digital, INPUT);
    pinMode(LedAlbastru, OUTPUT);
    pinMode(LedRosu, OUTPUT);
    pinMode(BuzzerLoud, OUTPUT);
}

void loop() {
    float intensitate = analogRead(Foc_analog);
    bool light_presence = digitalRead(Foc_digital);
    
Serial.print(intensitate);
Serial.print(" ");
Serial.println(light_presence);

//analog

    if(intensitate < 1000)
    {
        for(int i = 0 ; i < 10; ++i) //in acest for aprind cele 2 led-uri, cel rosu si cel albastru concomitent atunci cand 
                                    //  intensitatea lumioasa scade sub pragul de 1000 nm, moment cand buzzer-ul incepe sa emita un sunet de atentionare 
        {
            digitalWrite(LedRosu, HIGH);

            digitalWrite(BuzzerLoud, HIGH);
            delay(100);
            digitalWrite(LedRosu, LOW);

            digitalWrite(BuzzerLoud, LOW);
            delay(100);
            digitalWrite(LedAlbastru, HIGH);

            digitalWrite(BuzzerLoud, HIGH);
            delay(100);
            digitalWrite(LedAlbastru, LOW);
  
            digitalWrite(BuzzerLoud, LOW);
            delay(100);

        }
    }
    else
    { //in acest else arat ca senzorul functioneaza prin aprinderea si stingerea led-ului albastru atunci cand intensitatea luminoasa este deasupra pragului 
      digitalWrite(LedAlbastru, HIGH);
      delay(100);
      digitalWrite(LedAlbastru, LOW);
    }

 //digital se intamplasi in if si in else acelasi lucru doar ca pentru pinul digital

     if(light_presence)
    {
        for(int i = 0 ; i < 10; ++i)
        {
            digitalWrite(LedRosu, HIGH);

            digitalWrite(BuzzerLoud, HIGH);
            delay(100);
            digitalWrite(LedRosu, LOW);
 
            digitalWrite(BuzzerLoud, LOW);
            delay(100);
            digitalWrite(LedAlbastru, HIGH);

            digitalWrite(BuzzerLoud, HIGH);
            delay(100);
            digitalWrite(LedAlbastru, LOW);

            digitalWrite(BuzzerLoud, LOW);
            delay(100);

        }
    }
    else
    {
      digitalWrite(LedAlbastru, HIGH);
      delay(100);
      digitalWrite(LedAlbastru, LOW);
    }
   delay(1000);

}
