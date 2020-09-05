#include "Arduino.h"
#include "utils.h"

char* combineStringWithDigit(const char* string, int num, bool digitAfterString) {
  char digitBuf[sizeof(num) + 1];
  snprintf(digitBuf, sizeof(digitBuf), "%f", num);

  char* stringWithDigit  =(char*) malloc(strlen(string) + strlen(digitBuf) + 1);
  // Combine string with digit, determine which comes first
  if (digitAfterString) {
    strcpy(stringWithDigit, string);
    strcat(stringWithDigit, digitBuf);
  } else {
    strcpy(stringWithDigit, digitBuf);
    strcat(stringWithDigit, string);
  } 

  return stringWithDigit;
}

char* concatenate(const char *first, const char *second) {
  const size_t len1 = strlen(first);
  const size_t len2 = strlen(second);
  char* result = (char*) malloc(len1 + len2 + 1);

  memcpy(result, first, len1);
  memcpy(result + len1, second, len2 + 1);

  return result;
}
