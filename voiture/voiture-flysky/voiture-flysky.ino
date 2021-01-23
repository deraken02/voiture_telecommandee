int motor1Left = 5;// defines pin 5 as connected to the motor
int motor1Right= 6;// defines pin 6 as connected to the motor


int channel1 = 9; // defines the channels that are connected

int Channel1 ; // Used later to 

void  setup ()
{
   pinMode (motor1Left, OUTPUT);// initialises the motor pins
   pinMode (motor1Right, OUTPUT);
   pinMode (channel1, INPUT);// initialises the channels
   Serial.begin (9600); // Sets the baud rate to 9600 bps
}

void  loop ()
{
  Channel1 = (pulseIn (channel1, HIGH)); // Checks the value of channel1
  Serial.print(channel1); //Prints the channels value on the serial monitor

  if (Channel1 > 1300 && Channel1 < 1500 ) /*If these conditions are true, do the following. These are the values that I got from my transmitter, which you may customize according to your transmitter values */
  {
    digitalWrite (motor1Left, LOW); // Sets both the
    digitalWrite (motor1Right, LOW);// motors to low
  }

  if (Channel1 < 1300) // Checks if Channel1 is lesser than 1300
  {
    digitalWrite (motor1Left, HIGH);// Turns the left
    digitalWrite (motor1Right, LOW); // motor forward
  }
  if (Channel1 > 1500) // Checks if Channel1 is greater than 1500
  {
    digitalWrite (motor1Left, LOW);// Turns the right
    digitalWrite (motor1Right, HIGH);// motor forward
  }
}
