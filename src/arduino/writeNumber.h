void writeNumber(uint16_t x, uint16_t y, uint16_t number, uint16_t color) {
  switch (number) {
    case '1' :
      matrix.drawLine(x + 1, y, x + 1, y + 4, color);
      matrix.drawLine(x, y + 1, x + 1, y + 1, color);
      matrix.drawLine(x, y + 4, x + 2, y + 4, color);
      break; /* optional */

    case '2' :
      matrix.drawLine(x, y, x + 2, y, color);
      matrix.drawLine(x + 2, y, x + 2, y + 2, color);
      matrix.drawLine(x, y + 2, x + 2, y + 2, color);
      matrix.drawLine(x, y + 2, x, y + 4, color);
      matrix.drawLine(x, y + 4, x + 2, y + 4, color);
      break; /* optional */

    case '3' :
      matrix.drawLine(x, y, x + 2, y, color);
      matrix.drawLine(x + 2, y, x + 2, y + 4, color);
      matrix.drawLine(x + 1, y + 2, x + 2, y + 2, color);
      matrix.drawLine(x, y + 4, x + 2, y + 4, color);
      break; /* optional */

    case '4' :
      matrix.drawLine(x, y, x, y + 2, color);
      matrix.drawLine(x, y + 2, x + 2, y + 2, color);
      matrix.drawLine(x + 2, y, x + 2, y + 4, color);
      break; /* optional */

    case '5' :
      matrix.drawLine(x, y, x + 2, y, color);
      matrix.drawLine(x, y, x, y + 2, color);
      matrix.drawLine(x, y + 2, x + 2, y + 2, color);
      matrix.drawLine(x + 2, y + 2, x + 2, y + 4, color);
      matrix.drawLine(x, y + 4, x + 2, y + 4, color);
      break; /* optional */

    case '6' :
      matrix.drawLine(x, y, x + 2, y, color);
      matrix.drawLine(x, y, x, y + 4, color);
      matrix.drawLine(x, y + 2, x + 2, y + 2, color);
      matrix.drawLine(x + 2, y + 2, x + 2, y + 4, color);
      matrix.drawLine(x, y + 4, x + 2, y + 4, color);
      break; /* optional */

    case '7' :
      matrix.drawLine(x, y, x + 2, y, color);
      matrix.drawLine(x + 2, y, x + 2, y + 4, color);
      break; /* optional */

    case '8' :
      matrix.drawLine(x, y, x + 2, y, color);
      matrix.drawLine(x + 2, y, x + 2, y + 4, color);
      matrix.drawLine(x, y + 2, x + 2, y + 2, color);
      matrix.drawLine(x, y, x, y + 4, color);
      matrix.drawLine(x, y + 4, x + 2, y + 4, color);
      break; /* optional */

    case '9' :
      matrix.drawLine(x, y, x + 2, y, color);
      matrix.drawLine(x + 2, y, x + 2, y + 4, color);
      matrix.drawLine(x, y + 2, x + 2, y + 2, color);
      matrix.drawLine(x, y, x, y + 2, color);
      matrix.drawLine(x, y + 4, x + 2, y + 4, color);
      break; /* optional */

    case '0' :
      matrix.drawLine(x, y, x + 2, y, color);
      matrix.drawLine(x + 2, y, x + 2, y + 4, color);
      matrix.drawLine(x, y, x, y + 4, color);
      matrix.drawLine(x, y + 4, x + 2, y + 4, color);
      break; /* optional */

    case ':' :
      matrix.drawPixel(x + 1, y + 1, color);
      matrix.drawPixel(x + 1, y + 3, color);
      break; /* optional */
  }

}