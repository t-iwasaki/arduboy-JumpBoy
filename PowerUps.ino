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
} powerup;


void initPowerUp(){
  powerup.spCount = 0;
  powerup.active = false;
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
    //
    createPowerUp(random(3));
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
        arduboy.tunes.tone(NOTE_C4, 80);
        lives++;
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
  }
}


