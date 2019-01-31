int val = 0; //value for storing moisture value 
int soilPin = A0;//Declare a variable for the soil moisture sensor 
int soilPower = 6;//Variable for Soil moisture Power
int ledPin = D2;
int buttonPin = D3;

bool state = false;

void setup() 
{
  Particle.variable("val", val);
  pinMode(soilPower, OUTPUT);//Set D6 as an OUTPUT
  digitalWrite(soilPower, LOW);//Set to LOW so no power is flowing through the sensor
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

//This is a function used to get the soil moisture content
int readSoil()
{
    digitalWrite(soilPower, HIGH);//turn D6 "On"
    delay(10);//wait 10 milliseconds 
    val = analogRead(soilPin);//Read the SIG value form sensor 
    digitalWrite(soilPower, LOW);//turn D6 "Off"
    return val;//send current moisture value
}

void loop() 
{
  Serial.print("Soil Moisture = ");    
  //get soil moisture value from the function below and print it
  Serial.println(readSoil());

  //This 1 second timefrme is used so you can test the sensor and see it change in real-time.
  delay(1000);//take a reading every second
  
  if (val > 200){
      
      digitalWrite(ledPin, HIGH); //Turn on LED
      
      int buttonState = digitalRead(buttonPin);
      delay(50);
  
      if (buttonState == LOW){
          state =! state;
          delay(50);
      }
      
      if (state == true)
      {
          digitalWrite(ledPin, LOW); //Turn off LED
      }
      else{
          digitalWrite(ledPin, HIGH); //Turn on LED
      }
    

  }
  else{
      digitalWrite(ledPin, LOW); //Turn off LED
  }
  
}

