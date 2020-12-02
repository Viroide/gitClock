void writePrInfo()  {
    for (int i = 0; i < prList.length(); i++) { 
      uint16_t color = WHITE;
      const char* state = (const char*) prList[i]["state"];
      const char* lastState = (const char*) lastPrList[i]["state"];
      if (strcmp( state, "success") == 0) {
        if ((int) prList[i]["comments"] == 0) {
          color = GREEN;
        } else {
          color = BLUE;
        }
      }
      else if (strcmp(state, "unknown") == 0) {
        color = MAGENTA;
      }
      else if (strcmp(state , "error") == 0 || strcmp(state, "failure") == 0) {
        color = RED;
      }
      else if (strcmp(state , "pending") == 0) {
        color = YELLOW;
      } else {
        color = CYAN;
      }
      if(!strcmp( state, lastState)) {
        if (blink) {
          matrix.drawPixel(MATRIX_WIDTH - 1 - i*2, 0, color);
          blink = false;
        }
        blink = true;
      } else {
        matrix.drawPixel(MATRIX_WIDTH - 1 - i*2, 0, color);
      }
      
    }
}