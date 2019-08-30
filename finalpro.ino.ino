/* add the librarie for EEPROM*/
#include <EEPROM.h>

/*  I have not used the Buzzer but included the code in the file */


boolean stringComplete = false;
String inputString = "";
int n = 0;
#define BUZZ 8    /* initialize the buzzer pin as d8 */
#define led 13    /*initialize the led pin as D13 */
#define SW1 3     /*initialize the SW1 pin of the RFID reader as D3 */

/* add the library for RTC module*/
#include<DS3231.h>


DS3231 rtc(SDA,SCL);
int count1=0;                                  /* add the number of counters based on the number of names added */
int count2=0;
int count3=0;
char* names[]={"RANIT","LAL","ANDY"};        /* add the names to the database to keep track */
int i=0;

void setup() {
  Serial.begin(9600);
  rtc.begin();
  rtc.setDOW(THURSDAY);                           /* set the DATE OF WEEK */
  rtc.setTime(12,0,0);                            /* set the present time */
  rtc.setDate(1,1,2019);                           /* set the present date */
  pinMode(BUZZ,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(SW1,INPUT);
  
  inputString.reserve(200);
}

void loop() {
  
  
  
    
    
  if(stringComplete){
    Serial.println(inputString);
    if(inputString.equals("270016FAAA61")){//A                               
      count1+=1;                                                  /*  RFID tag for the first person and if the string printed in the serial window matches with the RFID tag the increment*/
      digitalWrite(BUZZ,HIGH);
      digitalWrite(led,HIGH);
      delay(500);
      digitalWrite(led,LOW);
      if(count1%2!=0)                                                /*  if the count1 is odd it means an 'ENTRY' is made by person 1 assuming the room is initially empty */
      {
        Serial.println("A IS MARKED PRESENT");
      }
      else
      {
        Serial.println("A IS MARKED ABSENT");
        
      }
      Serial.println(rtc.getDOWStr());                             /*  prints the DATE OF THE WEEK in the serial monitor*/
      Serial.print(" ");
      Serial.println(rtc.getTimeStr());                             /*  prints the  TIME in the serial monitor */
      Serial.print("--");
      Serial.println(rtc.getDateStr());                              /*  prints the DATE in the serial monitor  */
      Serial.print("--");
      Serial.print(count1);
      
    }
    if(inputString.equals("270022B39620")){//B
      count2+=1;
      digitalWrite(BUZZ,LOW);
      digitalWrite(led,HIGH);
      delay(500);
      digitalWrite(led,LOW);
      if(count2%2!=0)
      {
        Serial.println("B IS MARKED PRESENT");
      }
      else
      {
        Serial.println("B IS MARKED ABSENT");
      }
      Serial.println(rtc.getDOWStr());
      Serial.print(" ");
      Serial.println(rtc.getTimeStr());
      Serial.print("--");
      Serial.println(rtc.getDateStr());
      Serial.print("--");
      Serial.print(count2);
    
      
    }
    if(inputString.equals("27001674B8FD")){//c
      count3+=1;
      digitalWrite(BUZZ,LOW);
      digitalWrite(led,HIGH);
      delay(500);
      digitalWrite(led,LOW);
      if(count3%2!=0)
      {
        Serial.println("C IS MARKED PRESENT");
      }
      else
      {
        Serial.println("C IS MARKED ABSENT");
      }
      
      Serial.println(rtc.getDOWStr());
      Serial.print(" ");
      Serial.println(rtc.getTimeStr());
      Serial.print("--");
      Serial.println(rtc.getDateStr());
      Serial.print("--");
      Serial.print(count3);
    
      
    }
    
   

   
   
    
   
    stringComplete = false;
    inputString = "";
  }
  
    
  }
  
   
    
     
        
  

void serialEvent(){
  while(Serial.available()){
    n++;
    char inChar = (char) Serial.read();
    inputString += inChar;
    if(n>=12){
      n=0;
      stringComplete = true;
    }
  }
}
