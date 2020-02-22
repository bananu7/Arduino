

void setupDisp(int a, int b, int c, int d, int e, int f, int g, int h) {
   pinMode(a, OUTPUT);
   pinMode(b, OUTPUT);
   pinMode(c, OUTPUT);
   pinMode(d, OUTPUT);
   pinMode(e, OUTPUT);
   pinMode(f, OUTPUT);
   pinMode(g, OUTPUT);
   pinMode(h, OUTPUT);
}

const int digits[10][8] = 
  {
    /*
         5 
      6     4
         7
      3     1
         2  0
    */
    /*0  1  2  3  4  5  6  7   */
    { 0, 1, 1, 1, 1, 1, 1, 0 }, // 0
    { 0, 1, 0, 0, 1, 0, 0, 0 }, // 1
    { 0, 0, 1, 1, 1, 1, 0, 1 }, // 2
    { 0, 1, 1, 0, 1, 1, 0, 1 }, // 3
    { 0, 1, 0, 0, 1, 0, 1, 1 }, // 4
    { 0, 1, 1, 0, 0, 1, 1, 1 }, // 5
    { 0, 1, 1, 1, 0, 1, 1, 1 }, // 6
    { 0, 1, 0, 0, 1, 1, 0, 0 }, // 7
    { 0, 1, 1, 1, 1, 1, 1, 1 }, // 8
    { 0, 1, 1, 0, 1, 1, 1, 1 }, // 9
  };

void dispNum(int num) {
  for (int i = 0; i <= 7; ++i) {
    digitalWrite(i, digits[num][i]);
  }
}

int i = 0;

void setup()
{
  setupDisp(0,1,2,3,4,5,6,7);
}
 
void loop()
{
 i += 1;
 if (i > 9) i = 0;
 dispNum(i);
 delay(1000);
}