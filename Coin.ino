/*----------------------
    Coin:
  --------------------- */

struct Coin
{
  float x = 64;
  float y = 16;
  bool active = false;
  uint8_t spCount = 0;
  uint8_t qty = 0;
  uint8_t init_norma = 20;
  uint8_t norma = 20;  
} coin;



uint8_t getCoinQty()
{
  return coin.qty;
}

void initCoin()
{
  coin.qty = 0;
  coin.active = false;
  coin.norma = coin.init_norma;
}


void createCoin()
{
  coin.x = 10 + random(110);
  coin.y = 10 + random(34);
  coin.active = true;
}

void moveCoin()
{
  coin.spCount++;
  if (coin.spCount == 50)
  {
    coin.spCount = 0;
    createCoin();
  }
  collisionCoin();
}

void collisionCoin()
{
  if (coin.active) {
    if (coin.x < pX + 8 &&
        coin.x + 8 > pX &&
        coin.y < pY + 8 &&
        8 + coin.y > pY)
    {
      arduboy.tunes.tone(NOTE_G3, 80);
      coin.qty++;
      if (coin.qty >= coin.norma) {
        stageClear();
      }
      coin.active = false;
    }
  }
}

void drawCoin()
{
  if (coin.active) {
    arduboy.drawBitmap(coin.x, coin.y, bCoin, 8, 8, 1);
  }
}


