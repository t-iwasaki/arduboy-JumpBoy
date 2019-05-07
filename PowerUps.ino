/*----------------------
    PowerUps
  --------------------- */

struct PowerUps
{
  float x = 128;
  float y = 32;
  uint8_t type = 0;
  bool active = false;
  float xspd = 0;
  float yspd = 0;
  uint8_t spCount = 0;
  uint8_t no = 0;
  uint8_t types[10] = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4};
} powerup;


void initPowerUp() {
  powerup.no = 0;
  powerup.spCount = 0;
  powerup.active = false;
  shuffle();
}


void shuffle() {
  uint8_t work;
  for (int i = 0; i < 10; i++) {
    swap(&powerup.types[i], &powerup.types[random(10)]);
  }
}


void swap(uint8_t *x, uint8_t *y) {
  uint8_t  work;
  work = *x;
  *x = *y;
  *y = work;
}


void createPowerUp(uint8_t type)
{
  powerup.xspd = 1;
  powerup.yspd = 1.5;

  powerup.x = 10 + random(110);
  powerup.y = 10 + random(34);

  powerup.type = type;
  powerup.active = true;
}

void movePowerUp()
{
  powerup.spCount++;

  if (powerup.spCount == 50) {
    powerup.active = false;
  }

  if (powerup.spCount == 200) {
    powerup.spCount = 0;
  }

  if (getCoinQty() % 5 == 0) {
    if (getCoinQty() / 5 > powerup.no) {
      //createPowerUp(random(5));
      createPowerUp(powerup.types[powerup.no]);
      powerup.spCount = 0;
      powerup.no++;
    }
  }
  collisionPowerUp();
}


void collisionPowerUp()
{
  if (powerup.active) {
    if (powerup.x < pX + 8 &&
        powerup.x + 8 > pX &&
        powerup.y < pY + 8 &&
        8 + powerup.y > pY)
    {
      if (powerup.type == 0) // heart
      {
        if (lives <= MAXLIVES) {
          arduboy.tunes.tone(NOTE_C4, 80);
          lives++;
        }
        powerup.active = false;
        powerup.x = 128;
      }
      if (powerup.type == 1) // spring=+1
      {
        setAddSpring();
        arduboy.tunes.tone(NOTE_C4, 80);
        powerup.active = false;
      }
      if (powerup.type == 2) // spring=-1
      {
        // setAllOneSpring();
        // setOddSpring();
        setDelSpring();
        arduboy.tunes.tone(NOTE_C2, 80);
        powerup.active = false;
      }

      if (powerup.type == 3) // coin add item
      {
        resetSpCount();
        updateCurrentCoinMax(3);
        arduboy.tunes.tone(NOTE_C3, 80);
        powerup.active = false;
      }

      if (powerup.type == 4) // flag item
      {
        setAddMaxSpring();
        arduboy.tunes.tone(NOTE_C4, 80);
        powerup.active = false;
      }

    }
  }
}
/*------------------
    Draw Power Up
  ----------------- */
void drawPowerUp()
{
  if (powerup.active) {
    if (powerup.type == 0) {
      arduboy.drawBitmap(powerup.x, powerup.y, bHeart, 8, 8, 1);
    }
    if (powerup.type == 1) {
      arduboy.drawSlowXYBitmap(powerup.x, powerup.y, bItemPlus, 8, 8, 1);
    }
    if (powerup.type == 2) {
      arduboy.drawSlowXYBitmap(powerup.x, powerup.y, bItemMinus, 8, 8, 1);
    }
    if (powerup.type == 3) {
      arduboy.drawSlowXYBitmap(powerup.x, powerup.y, bItemAddCoins, 8, 8, 1);
    }
    if (powerup.type == 4) {
      arduboy.drawSlowXYBitmap(powerup.x, powerup.y, bItemFlag, 8, 8, 1);
    }
  }
}


