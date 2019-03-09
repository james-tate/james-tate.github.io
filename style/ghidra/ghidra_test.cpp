#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <iostream>

class Base{
public:
  virtual void count(int16_t incNumber) = 0;
  virtual uint16_t getWordCount() = 0;
  virtual uint16_t getDWordCount() = 0;
  virtual void testCase(uint16_t c) = 0;
};

class Derived:Base{
public:
  const char *s_charPointer;
  uint16_t u16_counter; 
  uint32_t u32_counter;  

  Derived(){
    s_charPointer = "Hello, This is a string\n";
    u16_counter = 0;
    u32_counter = 0;
  }

  virtual ~Derived(){
    return;
  }
  
  virtual void count(int16_t incNumber){
    int16_t i = 0;
    do{
      this->u16_counter++;
      this->u32_counter = u16_counter * i;
      i++;
    }while(i < incNumber);
  }

  virtual uint16_t getWordCount(){
    return this->u16_counter;
  }

  virtual uint16_t getDWordCount(){
    return this->u32_counter;
  }

  virtual void testCase(uint16_t c){
    uint8_t caseChoose = c % 3;
    switch (caseChoose){
      case 0:
        printf("Case 0\n");
        return;
      case 1:
        printf("Case 1\n");
        return;
      case 2:
        printf("Case 2\n");
        return;
      case 3:
        printf("Case3\n");
        return;
    }
    return;
  }
};

int main(void){

  Derived *d;
  d = new Derived();
  srand(time(0));
  int ran = rand();
  d->count(ran);
  d->testCase(ran);
  printf("Word = %d ", d->getWordCount());
  printf("DWord = %d\n", d->getDWordCount());
  int i = 0;
  const char* cp = d->s_charPointer;
  while (*cp){
    printf("%c", *cp);
    *cp++;
  }
  std::cout << std::endl;

  delete d;

  return 0;

}
