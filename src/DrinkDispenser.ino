/*
 * Project DrinkDispenser
 * Description:
 * Author:
 * Date:
 */
int firstInput = D0;
int secondInput = D1;
bool pump1On = false;
bool pump2On = false;
// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(firstInput,OUTPUT);
  pinMode(secondInput,OUTPUT);
  Particle.function("setPump1", setPump1);
  Particle.function("setPump2", setPump2);
  digitalWrite(firstInput, HIGH);
  digitalWrite(secondInput, HIGH);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {



  // The core of your code will likely live here.

}
/*
int publishState(String arg) {

   String data = "{";
     data += "\"stat\":";
     data += String(d);
     data += ", ";
   if(light == true) {
     data += "\"light\":true";
   } else {
     data += "\"light\":false";
   }
   data += "}";

   Serial.println("Publishing:");
   Serial.println(data);

   Particle.publish(topic, data, 60, PRIVATE);
   return 0;
 }
*/
 int setPump1(String val){
   if(val == "true"){
     pump1Start();
     //publishState("");
   }
   else{
     pump1Stop();
     //publishState("");
   }
 }
 int setPump2(String val){
   if(val == "true"){
     pump2Start();
     //publishState("");
   }
   else{
     pump2Stop();
     //publishState("");
   }
 }

void pump1Start(){
  digitalWrite(firstInput,LOW);
  pump1On = true;;
}
void pump1Stop(){
  digitalWrite(firstInput,HIGH);
  pump1On = false;
}
void pump2Start(){
  digitalWrite(secondInput,LOW);
  pump2On = true;
}
void pump2Stop(){
  digitalWrite(secondInput,HIGH);
  pump2On = false;
}
