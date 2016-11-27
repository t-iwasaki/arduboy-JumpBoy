/*----------------------
    spring:
  --------------------- */
uint8_t pSprings[]   = {1, 2, 3, 4, 3, 4, 3, 2, 1, 2, 1, 2, 3, 3, 4, 3};
uint8_t pSprings_1[] = {1, 2, 3, 4, 3, 4, 3, 2, 1, 2, 1, 2, 3, 3, 4, 3};


/*-----------------------
    initSpring
  ----------------------*/
//TODO:引数でN面を対応する
void initSpring() {
  for (int i = 0; i < 16; i++) {
    pSprings[i] = pSprings_1[i];
  }
}

/*-----------------------
    setAllOneSpring
  ----------------------*/
void setAllOneSpring() {
  for (int i = 0; i < 16; i++) {
    pSprings[i] = 1;
  }
}

/*-----------------------
    setAddSpring
  ----------------------*/
void setAddSpring() {
  for (int i = 0; i < 16; i++) {
    if (pSprings[i] < 4) {
      pSprings[i] += 1;
    }
  }
}

/*-----------------------
    setAddMaxSpring
  ----------------------*/
void setAddMaxSpring() {
  for (int i = 0; i < 16; i++) {
    pSprings[i] = 4;
  }
}



/*-----------------------
    setDelSpring
  ----------------------*/
void setDelSpring() {
  for (int i = 0; i < 16; i++) {
    if (pSprings[i] > 0) {
      pSprings[i] -= 1;
    }
  }
}


/*-----------------------
    setAllOneSpring
  ----------------------*/
void setOddSpring() {
  for (int i = 0; i < 16; i++) {
    if (i % 2 == 0) {
      pSprings[i] = 0;
    } else {
      pSprings[i] = 1;
    }
  }
}


/*-------------------------
    collisionSpring
  ------------------------ */
void collisionSpring(bool &is_miss)
{
  arduboy.tunes.tone(NOTE_A1, 80);

  // スプリングを減らす
  int a = (int)(pX + 4) / 8;
  if (pSprings[a] <= 0) {
    //miss
    is_miss = true;
    
    pSprings[a] = 0;
  } else {
    pSprings[a] -= 1;
  }

  //
  int s = 0;
  for (int i = 0; i < 16; i++) {
    s += pSprings[i];
  }
  if (s == 0) {
    //init
    initSpring();
  }
}

/*-----------------------
    drawSpring
  ----------------------*/
void drawSpring()
{
  arduboy.fillRect(0, 56, 127, 64, 1);
  for (int i = 0; i < 16; i++)
  {
    //
    switch ( pSprings[i] )
    {
      case 0:
        arduboy.drawSlowXYBitmap(i * 8 , 56 , bEmpty, 8, 8, 0);
        break;
      case 1:
        arduboy.drawSlowXYBitmap(i * 8 , 56 , bSpring1, 8, 8, 0);
        break;
      case 2:
        arduboy.drawSlowXYBitmap(i * 8 , 56 , bSpring2, 8, 8, 0);
        break;
      case 3:
        arduboy.drawSlowXYBitmap(i * 8 , 56 , bSpring3, 8, 8, 0);
        break;
      case 4:
        arduboy.drawSlowXYBitmap(i * 8 , 56 , bSpring4, 8, 8, 0);
        break;
    }
  }
}
