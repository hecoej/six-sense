// Define pins for ultrasonic and buzzer
int const trigPin = 13;
int const echoPin = 12;
int const buzzPin = 11; 

void setup()
{
  Serial.begin(9600);
   pinMode(trigPin, OUTPUT); // trig pin will have pulses output
   pinMode(echoPin, INPUT); // echo pin should be input to get pulse width
   pinMode(buzzPin, OUTPUT); // buzz pin is output to control buzzering
}

void loop()
{
   // Duration will be the input pulse width and distance will be the distance to the obstacle in centimeters
   int duration, distance;
   // Output pulse with 1ms width on trigPin
   digitalWrite(trigPin, HIGH); 
   delay(1);
   digitalWrite(trigPin, LOW);
   // Measure the pulse input in echo pin
   duration = pulseIn(echoPin, HIGH);
   // Distance is half the duration devided by 29.1 (from datasheet)
   distance = (duration/2) / 29.1;
   // if distance less than 0.5 meter and more than 0 (0 or less means over range) 
    if (distance <= 100 && distance >= 50) {
       // Buzz
       digitalWrite(buzzPin, LOW);
    } else {
       // Don't buzz
       digitalWrite(buzzPin, HIGH);
    }
    Serial.println(distance);
    // Waiting 60 ms won't hurt any one
    delay(60);
}
