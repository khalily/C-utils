#include <math.h>

#include <stdio.h>


#define TRUE 1
#define FALSE 0

typedef struct {
  long start;
  unsigned long end;
}Range;

typedef unsigned char bool;
typedef char* TypeStr;

typedef enum{
  kChar = 0,
  kUnsignedChar,
  kShort,
  kUnsignedShort,
  kInt,
  kUnsignedInt,
  kLong,
  kUnsignedLong,
  kUnknow
}kType;

const TypeStr g_type_str[] = {
  "char",
  "unsigned char",
  "short",
  "unsigned short",
  "int",
  "unsigned int",
  "long",
  "unsigned long"
};



Range getRange(int bytes, bool isSigned) {
  Range r;
  if (isSigned) {
    r.start = -pow(2, bytes - 1);
    r.end = powl(2, bytes - 1) - 1;

  } else {
    r.start = 0;
    r.end = powl(2, bytes) - 1;
  }
  return r;
}

#define GET_BYTES(x) sizeof(x) * 8

void printValueRange(kType t) {
  Range r;
  switch(t) {
    case kChar:
      r = getRange(GET_BYTES(char), TRUE);
      break;
    case kUnsignedChar:
      r = getRange(GET_BYTES(char), FALSE);
      break;
    case kShort:
      r = getRange(GET_BYTES(short), TRUE);
      break;
    case kUnsignedShort:
      r = getRange(GET_BYTES(short), FALSE);
      break;
    case kInt:
      r = getRange(GET_BYTES(int), TRUE);
      break;
    case kUnsignedInt:
      r = getRange(GET_BYTES(int), FALSE);
      break;
    case kLong:
      r = getRange(GET_BYTES(long), TRUE);
      break;
    case kUnsignedLong:
      r = getRange(GET_BYTES(long), FALSE);
      break;
    default:
      return;
  }
  printf("%s:\n\t\t%ld \t\t-\t%lu\n", g_type_str[t], r.start, r.end);
}

int main(int argc, char const *argv[])
{
  kType t = kChar;
  for( ;t < kUnknow; t++)
    printValueRange(t);

  return 0;
}

