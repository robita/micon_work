void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
}

int x = 0;
int delta = 100;
//bool test = false;

void loop() {
  if(x == 0){
    x = 1;
  } else if(x == 1) {
    x = 0;
  }
  Serial.println(x);
  delay(200);
  
//  for(;; x=x+delta){    // ASCIIコード表を出力
//    Serial.println(x);          // ASCIIコードを十進数で出力
//    Serial.print("\t");
//    Serial.print(x, DEC);  // ASCIIコードを十進数で出力
//    Serial.print("\t");
//    Serial.print(x, HEX);  // ASCIIコードを十六進数で出力
//    Serial.print("\t");
//    Serial.print(x, OCT);  // ASCIIコードを八進数で出力
//    Serial.print("\t");
//    Serial.println(x, BIN);  // ASCIIコードを二進数で出力し改行
    
//  }
//  Serial.println("");      // 改行
}
