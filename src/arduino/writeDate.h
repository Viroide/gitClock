#include "writeNumber.h"

void writeDate() {
  for (int i = 0; i < TIME_BUFFER_SIZE; i++) {
    writeNumber(6 + i * 4, 1, timeBuffer[i], CYAN);
  }

  const int dayOfTheWeek = now.dayOfTheWeek();
  for (int i = 0; i < 7; i++) {
    uint16_t color = CYAN; 
    if ((i + 1) % 7 == dayOfTheWeek) {
      color = MAGENTA;
    }
    matrix.drawLine(2 + 4 * i, 7, 4 + 4 * i, 7, color);
  }
}