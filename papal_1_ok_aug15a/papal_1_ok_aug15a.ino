""" #include "arduino_secrets.h" """
/*
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/0900b5bd-01e1-41ea-8ccf-f62ab923106f

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  int color1;
  int color2;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

""" #include "thingProperties.h" """

const int red = 2;
const int blue = 3;
const int green = 4;

const int pot1 = A1;

int previousPotValue_1 = 0;
int previousPotValue_2 = 0;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(pot1, INPUT);
  //pinMode(pot2, INPUT);

  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here
  int potVal1 = analogRead(pot1);
  int potRange1 = map(potVal1, 0, 1023, 0, 255);
  color1 = map(potRange1, 0, 255, 0, 5);

  if (color1 != previousPotValue_1) {

    switch (color1) {
      case 0:
        digitalWrite(green, LOW); // red 
        digitalWrite(blue, LOW);
        digitalWrite(red, HIGH);
        break;

      case 1:
        digitalWrite(green, HIGH); // yellow 
        digitalWrite(blue, LOW);
        digitalWrite(red, HIGH);
        break;

      case 2:
        digitalWrite(green, HIGH); // green
        digitalWrite(blue, LOW);
        digitalWrite(red, LOW);
        break;

      case 3:
        digitalWrite(green, HIGH); // turquoise
        digitalWrite(blue, HIGH);
        digitalWrite(red, LOW);
        break;

      case 4:
        digitalWrite(green, LOW); // blue
        digitalWrite(blue, HIGH);
        digitalWrite(red, LOW);
        break; // wait for a second

      case 5:
        digitalWrite(green, LOW); // purle
        digitalWrite(blue, HIGH);
        digitalWrite(red, HIGH);
        break;
    }

    delay(50);
    previousPotValue_1 = color1;

  }
}

/*
  Since Color1 is READ_WRITE variable, onColor1Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onColor1Change()  {
  // Add your code here to act upon Color1 change
   
}
/*
  Since Color2 is READ_WRITE variable, onColor2Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onColor2Change()  {
  // Add your code here to act upon Color2 change

  if (color2 != previousPotValue_2) {

    switch (color2) {
      case 0:
        digitalWrite(green, LOW); // red
        digitalWrite(blue, LOW);
        digitalWrite(red, HIGH);
        break;

      case 1:
        digitalWrite(green, HIGH); // yellow
        digitalWrite(blue, LOW);
        digitalWrite(red, HIGH);
        break;

      case 2:
        digitalWrite(green, HIGH); // green
        digitalWrite(blue, LOW);
        digitalWrite(red, LOW);
        break;

      case 3:
        digitalWrite(green, HIGH); // turquoise
        digitalWrite(blue, HIGH);
        digitalWrite(red, LOW);
        break;

      case 4:
        digitalWrite(green, LOW); // blue
        digitalWrite(blue, HIGH);
        digitalWrite(red, LOW);
        break;

      case 5:
        digitalWrite(green, LOW); // purple
        digitalWrite(blue, HIGH);
        digitalWrite(red, HIGH);
        break;
    }

    delay(50);
    previousPotValue_2 = color2;

  }
}

















