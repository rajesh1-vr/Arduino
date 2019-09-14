
char chover = 8;
char solar = 6;
char  eb =7;
char inc;
int solarvolt,ebvolt;
void setup() {
  
  // initialize serial communication at 9600 bits per second:
 // Serial.begin(9600);

// pinMode(2,OUTPUT);//ALE
 //pinMode(3,OUTPUT);//OE
 //pinMode(4,OUTPUT);//SC
 pinMode(solar,OUTPUT);//SOLAR
 pinMode(eb,OUTPUT);//EB
 pinMode(chover,INPUT);//CHOVER
}

// the loop routine runs over and over again forever:
void loop() {

  if(digitalRead(chover)==HIGH)
  {
digitalWrite(solar,LOW);
delay(1000);
digitalWrite(eb,HIGH);  
  }

else
{
digitalWrite(solar,LOW);
delay(1000);
digitalWrite(eb,HIGH); 
solarvolt=0; 
for(inc=0;inc<8;inc++)

solarvolt+=analogRead(A0);
solarvolt=(solarvolt/8);

while(solarvolt<850 && digitalRead(chover)==LOW)  //// check for solar voltage
{          
solarvolt=0;
for(inc=0;inc<8;inc++)
solarvolt+=analogRead(A0);
solarvolt=(solarvolt/8);
}



if(solarvolt>=850 && solarvolt<=1000) //macro SOLARLL ,SOLARHL
{
delay(1000);
 digitalWrite(eb,LOW); 
 delay(1000);
 digitalWrite(solar,HIGH);
}
for(inc=0;inc<8;inc++)
solarvolt+=analogRead(A0);
solarvolt=(solarvolt/8);

while(solarvolt>800 && digitalRead(chover)==LOW)     // MACRO SOLARWL
{
solarvolt=0;
for(inc=0;inc<8;inc++)
solarvolt+=analogRead(A0);
solarvolt=(solarvolt/8);        
}

ebvolt=0;

for(inc=0;inc<8;inc++)
ebvolt+=analogRead(A1);
       //eb checking

ebvolt=(ebvolt/8);

if(ebvolt>850)    //eb available
                         // MACRO EBLIMIT;    

{

digitalWrite(solar,LOW);
delay(1000);
digitalWrite(eb,HIGH);  
loop();

}


else

{
 solarvolt=0;
 for(inc=0;inc<8;inc++)
solarvolt+=analogRead(A0); 
solarvolt=(solarvolt/8);


while(solarvolt >750 && digitalRead(chover)==LOW )//ebsolarll

{

solarvolt=0;
 for(inc=0;inc<8;inc++)
solarvolt+=analogRead(A0); 
solarvolt=(solarvolt/8);
  
}
 digitalWrite(solar,LOW);
 delay(1000);
 digitalWrite(eb,HIGH);
while(1)
{
   if(digitalRead(chover)==HIGH)
  {
 loop();
  }
  ebvolt=0;
  for(inc=0;inc<8;inc++)
ebvolt+=analogRead(A1); // eb checking
ebvolt=(ebvolt/8);

if(ebvolt>850)
{
digitalWrite(solar,LOW);
delay(1000);
digitalWrite(eb,HIGH);  
loop();
}
else
{
solarvolt=0;
for(inc=0;inc<8;inc++)
solarvolt+=analogRead(A0);       //solar checking
solarvolt=(solarvolt/8);
if(solarvolt>850 && solarvolt<1000)  // macro SOLARLL  SOLARHL
{
 //eb=0;
// MSDelay(20);
// solar=1;
 loop();


}


}
  
}


  
}

} 

}
  // read the input on analog pin 0:
 // int sensorValue = analogRead(A0);
  // print out the value you read:
 // Serial.println(sensorValue);
 // delay(1);        // delay in between reads for stability
