

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  float c=0;
  float cr=0;
  float vt=0;
  float vlt=0;
  float time = micros()/1e6;

  for(int i=0; i<100; i++)
  {
    int cu= analogRead(A0);
    float vol_c= cu*5/1023.0;
    float current= (vol_c-2.5)/0.185;
    c+=current;

    int v= analogRead(A1);
    float vol_v= v*(25.0/1023.0);
    vt+=vol_v;
    delay(1);
  }
  cr=c/100;
  cr-=0.06;
  vlt=vt/100;
  
   if (vlt<0.16)
   {
     vlt =0.0; 
   } 
  Serial.print(time);
  Serial.print(", ");
  Serial.print(cr);
  Serial.print(", "); 
  Serial.println(vlt);
         // put your main code here, to run repeatedly:

}
