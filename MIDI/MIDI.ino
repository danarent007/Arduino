
 
 int velocity = 0;//velocity of MIDI notes, must be between 0 and 127
 //higher velocity usually makes MIDI instruments louder
 
 int noteON = 144;//144 = 10010000 in binary, note on command
 int noteOFF = 128;//128 = 10000000 in binary, note off command

void setup() {
  //  Set MIDI baud rate:
  Serial.begin(38400);
}

void loop() {

    int val = (analogRead(3)/1023)*127;
    MIDImessage(noteON, 1, val);//turn note on
    delay(300);//hold note for 300ms

  
}

//send MIDI message
void MIDImessage(int command, int MIDInote, int MIDIvelocity) {
  Serial.write(command);//send note on or note off command 
  Serial.write(MIDInote);//send pitch data
  Serial.write(MIDIvelocity);//send velocity data
}

//(analogRead(A2)/1023)*127
