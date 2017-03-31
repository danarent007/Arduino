#include <EEPROM.h>


//Declaration

char currentKey = 0;
String entered = "";
boolean states[] = {false,false,false,false,false,false,false,false};
boolean astates[] = {false,false,false,true,false,false,false,false};
boolean bstates[] = {false,false,false,true,false,false,false,false};
boolean cstates[] = {false,false,false,true,false,false,false,false};
boolean dstates[] = {false,false,false,true,false,false,false,false};
unsigned char datapin  = 10;  
unsigned char clockpin  = 11;
unsigned char latchpin  = 12;
unsigned char outpins[]  = {A0,A1,A2,A3,A4,A5,13};
boolean program = false;
int i = 0;
int a = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initKeypad();
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  presetload();




pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);

i = 0;
for(i;i<7;i++)
{
  pinMode(outpins[i], OUTPUT);
}


showstates();
}



void presetload() //Loads all presets from EEPROM to arrays on startup
{

  i = 0;
  a = 0;
  for (a,i;i<8;i++,a++)
  {
    if (EEPROM.read(a) == 1)
    {
      astates[i] = true;
    }
    else
    {
      astates[i] = false;
    }
  }


  i = 0;
  a = 8;
  for (a,i;i<8;i++,a++)
  {
    if (EEPROM.read(a) == 1)
    {
      bstates[i] = true;
    }
    else
    {
      bstates[i] = false;
    }
  }


  i = 0;
  a = 16;
  for (a,i;i<8;i++,a++)
  {
    if (EEPROM.read(a) == 1)
    {
      cstates[i] = true;
    }
    else
    {
      cstates[i] = false;
    }
  }


  i = 0;
  a = 24;
  for (a,i;i<8;i++,a++)
  {
    if (EEPROM.read(a) == 1)
    {
      dstates[i] = true;
    }
    else
    {
      dstates[i] = false;
    }
  }

//Serial.println("Read all presets");
}


//START LOOP---------------------------
void loop() 
{



  
if (checkNewKey() == true)
 {

int i = 0;
int j = 0;
//Serial.println("------");

switch (currentKey) {
  case 'A':
  showxstates('A');
  showstates();
  break;

  case 'B':
  showxstates('B');
  showstates();
  break;

  case 'C':
  showxstates('C');
  showstates();
  break;

  case 'D':
  showxstates('D');
  showstates();
  break;

  case '0':
  for (j;j<8;j++)
  {
    states[j] = false;
  }
  showstates();
  break;

  case '1':
  states[0] = !states[0];
  showstates();
  break;

  case '2':
  states[1] = !states[1];
  showstates();
  break;

  case '3':
  states[2] = !states[2];
  showstates();
  break;

  case '4':
  states[3] = !states[3];
  showstates();
  break;

  case '5':
  states[4] = !states[4];
  showstates();
  break;

  case '6':
  states[5] = !states[5];
  showstates();
  break;

  case '7':
  states[6] = !states[6];
  showstates();
  break;

  case 'bbb':
  states[7] = !states[7];
  showstates();
  break;

  case '9':
  break;

  case '*'://If followed by #, then local preset saving
  while(checkNewKey() == false)
  {
  }
  if (currentKey == '#')
  {
    //TODO Implement local preset saving HERE
    while(checkNewKey() == false)
    {
    }
    switch (currentKey)
    {
      
      case 'A':
      presetsavelocal('A');
      break;

      case 'B':
      presetsavelocal('B');
      break;

      case 'C':
      presetsavelocal('C');
      break;

      case 'D':
      presetsavelocal('D');
      break;
    }  
  }
  break;

  case '#'://If followed by *, then master save (save all xstates to EEPROM)
  while(checkNewKey() == false)
  {
  }
  if (currentKey == '*')
  {
    //Serial.println("Saved Presets to EEPROM");
    //TODO Implement EEPROM saving HERE
    presetsave();
  }
  break;
}

 }
}
//END LOOP-----------------------------





//Start Keypad-------------------------
int colPin[] = {5, 4, 3, 2};
int rowPin[] = {9, 8, 7, 6};
int rows = 4;
int cols = 4;
char keys[4][4] = {
  {'1','4','7','*'},
  {'2','5','8','0'},
  {'3','6','9','#'},
  {'A','B','C','D'}
};


void initKeypad()
{
  int col = 0;
  while(col != cols)
  {
    pinMode(colPin[col], INPUT_PULLUP);
    col++;
  }
  int row = 0;
  while(row != rows)
  {
    pinMode(rowPin[row], INPUT);
    row++;
  }
}











char getCurrentKey()
{
  int row = 0;
  while(row != rows)
  {
    pinMode(rowPin[row], OUTPUT);
    int col = 0;
    while(col != cols)
    {
      if(digitalRead(colPin[col]) == LOW)
      {
        pinMode(rowPin[row], INPUT);//put this back
        return keys[row][col];
        delay(400);
      }
      col++;
    }
    pinMode(rowPin[row], INPUT);
    row++;
  }
  return 0;//no key pressed
}









boolean checkNewKey()
{
  char newKey = getCurrentKey();
  if(newKey != currentKey)
  {
    currentKey = newKey;
    if(currentKey != 0)
    {
      return true;
    }
  }
  return false;
}











void presetsave() //Saves all xstates to EEPROM
{
  
  i = 0;
  a = 0;
  for (a,i;i<8;i++,a++)
  {
    EEPROM.write(a,astates[i]);
  }

  
  i = 0;
  a = 8;
  for (a,i;i<8;i++,a++)
  {
    EEPROM.write(a,bstates[i]);
  }

 
  i = 0;
  a = 16;
  for (a,i;i<8;i++,a++)
  {
    EEPROM.write(a,cstates[i]);
  }

  
  i = 0;
  a = 24;
  for (a,i;i<8;i++,a++)
  {
    EEPROM.write(a,dstates[i]);
  }
  
  
}








void presetsavelocal(char letter)
{
  i=0;
    switch (letter) 
  {
  case 'A':
  i = 0;
  a = 0;
  for (i;i<8;i++)
  {
    astates[i] = states[i];
  }
  break;
  
  case 'B':
  i = 0;
  a = 8;
  for (i;i<8;i++)
  {
    bstates[i] = states[i];
  }
  break;

  case 'C':
  i = 0;
  a = 16;
  for (i;i<8;i++)
  {
    cstates[i] = states[i];
  }
  break;

  case 'D':
  i = 0;
  a = 24;
  for (i;i<8;i++)
  {
    dstates[i] = states[i];
  }
  break;
  
}
}










void showxstates(char letter) //Show state from xstates to states
{
  
  int k = 0;
  
  switch(letter)
  {
    case 'A':
    for (k;k<8;k++)
    {
      states[k] = astates[k];
      
    }
    break;

    
    case 'B':
    for (k;k<8;k++)
    {
      states[k] = bstates[k];
    }
    break;

    
    case 'C':
    for (k;k<8;k++)
    {
      states[k] = cstates[k];
    }
    break;

    
    case 'D':
    for (k;k<8;k++)
    {
      states[k] = dstates[k];
    }
    break;
  }
  



  
}













void presetread(char letter)//Reads specific preset from EEPROM
{
switch (letter) 
  {
  case 'A':
  i = 0;
  a = 0;
  for (a,i;i<8;i++,a++)
  {
    if (EEPROM.read(a) == 1)
    {
      states[i] = true;
    }
    else
    {
      states[i] = false;
    }
  }
  break;
  
  case 'B':
  i = 0;
  a = 8;
  for (a,i;i<8;i++,a++)
  {
    if (EEPROM.read(a) == 1)
    {
      states[i] = true;
    }
    else
    {
      states[i] = false;
    }
  }
  break;

  case 'C':
  i = 0;
  a = 16;
  for (a,i;i<8;i++,a++)
  {
    if (EEPROM.read(a) == 1)
    {
      states[i] = true;
    }
    else
    {
      states[i] = false;
    }
  }
  break;

  case 'D':
  i = 0;
  a = 24;
  for (a,i;i<8;i++,a++)
  {
    if (EEPROM.read(a) == 1)
    {
      states[i] = true;
    }
    else
    {
      states[i] = false;
    }
  }
  break;
  }
}








void showstates()
{
  
  Serial.println("Working...?");
  
  i = 0;
  for (i;i<8;i++)
{
  if (states[i] == true)
  {
    //TODO PIN LOW
    digitalWrite(outpins[i],HIGH);
    digitalWrite(datapin,HIGH);
    digitalWrite(clockpin,HIGH);
    digitalWrite(clockpin,LOW);
    digitalWrite(datapin,LOW);
  }
  else
  {
    //TODO PIN LOW
    digitalWrite(outpins[i],LOW);
    digitalWrite(datapin,LOW);
    digitalWrite(clockpin,HIGH);
    digitalWrite(clockpin,LOW);
    digitalWrite(datapin,LOW);
  }
 
  
  
}

digitalWrite(latchpin,HIGH);
  digitalWrite(latchpin,LOW); 
}














