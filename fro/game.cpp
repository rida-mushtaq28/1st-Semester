// BATTLE FIELD

#include <iostream>
#include <windows.h>
using namespace std;

// player character(Solider)
char box = 219;
char gun = 214;
char line = 215;
char cap = 234;
char leg=172;
char arrow=17;
char Arrow=16;
char smile=2;
char leaf=5;
char dia=4;
char solider1[4] = {' ', smile, ' ', ' '};                        // Player Character(Solider)
char solider2[4] = {' ', box, Arrow, Arrow};
char solider3[4] = {' ', box, ' ', ' '};
char solider4[4] = {leg, ' ', leg, ' '};
                       


// enemy Character1(Gun Champ)
char enemy1[4] = {' ', dia, ' ', dia};
char enemy2[4] = {' ', box, box, box};
char enemy3[4] = {' ', '&', ' ', '&'};

// enemy Character2(Terrorist)
char enemy4[4] = {' ', leaf, leaf, ' '};
char enemy5[4] = {arrow, box, box, ' '};
char enemy6[4] = {' ', gun, gun, ' '};

// enemy Character3(Shooter)
char enemy7[4] = {arrow, arrow, box, box};
char enemy8[4] = {' ', ' ', box, box};
char enemy9[4] = {' ', ' ', line, line};

// player coordinates

int soliderX = 6;
int soliderY = 6;

// Gun champ Coordinates
int champX = 20;
int champY = 20;

// Terrorist Coordinates
int teroX = 120;
int teroY = 18;

// Shooter Coordinates
int shooterX = 60;
int shooterY = 20;

// Shooter Controller
string shooterDirection = "Down";

// Terriorist Controller
string enemyDirection = "Right";

// Champ Controller
string champDirection = "Up";

// Solider Bullets
int bulletX[100];
int bulletY[100];
bool isBulletActive[100];
int bulletCount = 0;

// Terrorist Bullets
int teroBulletX[100000];
int teroBulletY[100000];
bool isTeroBulletActive[100000];
int teroBulletCount = 0;

// Shooter Bullets
int shooterBulletX[1000000];
int shooterBulletY[100000];
bool isShooterBulletActive[100000];
int shooterBulletCount = 0;

// Champ Bullets
int champBulletX[1000000];
int champBulletY[100000];
bool isChampBulletActive[100000];
int champBulletCount = 0;

// Counts
int score = 0;
int lifeCount = 5;
int teroLifeCount = 3;
int shooterLifeCount = 3;
int champLifeCount = 3;

// Functions
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
// Prints
void printSolider();
void printField();
void printChamp();
void printTerrorist();
void printShooter();
void printheader();
// Movements
void moveSoliderDown();
void moveSoliderUp();
void moveSoliderLeft();
void moveSoliderRight();
void moveChamp();
void moveChampDown();
void moveChampUp();
void moveChampLeft();
void moveChampRight();
void moveTerrorist();
void moveTerroristLeft();
void moveTerroristRight();
void moveShooter();
void moveShooterUp();
void moveShooterDown();

// Erase
void eraseSolider();
void eraseChamp();
void eraseTerrorist();
void eraseShooter();
// Bullets
void moveBullet();
void generateBullet();
void printBullet(int x, int y);
void eraseBullet(int x, int y);
void makeBulletInactive(int idx);
void makeTeroBulletInactive(int idx);
void moveTeroBullet();
void generateTeroBullet();
void printTeroBullet(int x, int y);
void eraseTeroBullet(int x, int y);
void makeShooterBulletInactive(int idx);
void moveShooterBullet();
void generateShooterBullet();
void printShooterBullet(int x, int y);
void eraseShooterBullet(int x, int y);
void makeChampBulletInactive(int idx);
void moveChampBullet();
void generateChampBullet();
void printChampBullet(int x, int y);
void eraseChampBullet(int x, int y);

//Collisions
void bulletTeroCollisionWithSolider();
void bulletShooterCollisionWithSolider();
void bulletCollisionWithTero();
void bulletSoliderCollisionWithChamp();
void bulletSoliderCollisionWithTero();
void bulletSoliderCollisionWithShooter();
// bool soliderTeroCollision();
// bool soliderShooterCollision();

// Points
void decLifeCount();
void decLifeCount1();
void decLifeCount2();
void decLifeCount3();
void printLifeCount();
void printTeroLifeCount();
void printShooterLifeCount();
void printChampLifeCount();
void printScore();
void addScore();

//Solider Score
void scoreSoliderDown();
void scoreSoliderUp();
void scoreSoliderLeft();
void scoreSoliderRight();

//Solider LifeCount
void countSoliderDown();
void countSoliderUp();
void countSoliderLeft();
void countSoliderRight();

main()
{
   bool gamerunning = true;
   system("cls");
   printField();
   printSolider();
   int timer = 0;
   while (gamerunning)
   {
      countSoliderRight();
      countSoliderDown();
      countSoliderLeft();
      countSoliderUp();
      printScore();
      printLifeCount();
      printTeroLifeCount();
      printShooterLifeCount();
      printChampLifeCount();
      if(teroLifeCount > 0)
      {
         printTerrorist();
      }
      else if (teroLifeCount == 0 )
      {
       eraseTerrorist();
      }

      if(champLifeCount > 0)
      {
         printChamp();
      }
      else if (champLifeCount == 0 )
      {
       eraseChamp();
      }

      if(shooterLifeCount > 0)
      {
         printShooter();
      }
      else if (shooterLifeCount == 0 )
      {
       eraseShooter();
      }
      if (GetAsyncKeyState(VK_RIGHT))
      {
         moveSoliderRight();
      }

      if (GetAsyncKeyState(VK_LEFT))
      {
         moveSoliderLeft();
      }

      if (GetAsyncKeyState(VK_UP))
      {
         moveSoliderUp();
      }

      if (GetAsyncKeyState(VK_DOWN))
      {
         moveSoliderDown();
      }
      if (GetAsyncKeyState(VK_SPACE))
      {
         generateBullet();
      }
      if (lifeCount==0)
      {
         system("cls");
         cout<<"gAME OVER";
         break;   
      }
    //   bool collisionT=soliderTeroCollision();
    //   if (collisionT==true)
    //   {
    //      system("cls");
    //      cout<<"gAME OVER";
    //      printScore();
    //      break;   
    //   }
      // bool collisionS=soliderShooterCollision();
      // if (collisionS==true)
      // {
      //    system("cls");
      //    cout<<"gAME OVER";
      //    printScore();
      //    break;   
      // }
      if (timer == 3)
      {
         timer = 0;
         if(teroLifeCount > 0)
         {
            moveTerrorist();
         }
         if(champLifeCount > 0)
         {
             moveChamp();
         }
         if(shooterLifeCount > 0)
         {
            moveShooter();
         }
  
      }
      

      moveBullet();
      bulletTeroCollisionWithSolider();
      bulletShooterCollisionWithSolider();
      if(teroLifeCount > 0)
      {
         bulletSoliderCollisionWithTero();
      }
      if(shooterLifeCount > 0)
      {
         bulletSoliderCollisionWithShooter();
      }
      if(shooterLifeCount > 0)
      {
         bulletSoliderCollisionWithChamp();
      }
      
      timer++;
      Sleep(5);
   }
}

// DEFINITION OF FUNCTIONS

void gotoxy(int x, int y)
{
   COORD coordinates;
   coordinates.X = x;
   coordinates.Y = y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char getCharAtxy(short int x, short int y)
{
   CHAR_INFO ci;
   COORD xy = {0, 0};
   SMALL_RECT rect = {x, y, x, y};
   COORD coordBufSize;
   coordBufSize.X = 1;
   coordBufSize.Y = 1;
   return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

// Print Solider
void printSolider()
{
   gotoxy(soliderX, soliderY);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << solider1[idx];
   }
   gotoxy(soliderX, soliderY + 1);
   for (int idx = 0; idx < 4; idx++)
   {
      cout <<solider2[idx];
   }
   gotoxy(soliderX, soliderY + 2);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << solider3[idx];
   }
   gotoxy(soliderX, soliderY + 3);
   for (int idx = 0; idx < 4; idx++)
   {
      cout <<solider4[idx];
   }
}
// Erase Solider
void eraseSolider()
{
   gotoxy(soliderX, soliderY);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << " ";
   }
   gotoxy(soliderX, soliderY + 1);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << " ";
   }
   gotoxy(soliderX, soliderY + 2);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << " ";
   }
   gotoxy(soliderX, soliderY + 3);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << " ";
   }
}
// Erase GunChamp
void eraseChamp()
{
   gotoxy(champX, champY);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << " ";
   }
   gotoxy(champX, champY + 1);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << " ";
   }
   gotoxy(champX, champY + 2);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << " ";
   }
}

// Erase Terrorist
void eraseTerrorist()
{
   gotoxy(teroX, teroY);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << " ";
   }
   gotoxy(teroX, teroY + 1);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << " ";
   }
   gotoxy(teroX, teroY + 2);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << " ";
   }
}

// Erase Shooter
void eraseShooter()
{
   gotoxy(shooterX, shooterY);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << " ";
   }
   gotoxy(shooterX, shooterY + 1);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << " ";
   }
   gotoxy(shooterX, shooterY + 2);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << " ";
   }
}

// Print Champ
void printChamp()
{
   gotoxy(champX, champY);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << enemy1[idx];
   }
   gotoxy(champX, champY + 1);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << enemy2[idx];
   }
   gotoxy(champX, champY + 2);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << enemy3[idx];
   }
}

// Print Terrrorist
void printTerrorist()
{
   gotoxy(teroX, teroY);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << enemy4[idx];
   }
   gotoxy(teroX, teroY + 1);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << enemy5[idx];
   }
   gotoxy(teroX, teroY + 2);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << enemy6[idx];
   }
}

// Print Shooter
void printShooter()
{
   gotoxy(shooterX, shooterY);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << enemy7[idx];
   }
   gotoxy(shooterX, shooterY + 1);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << enemy8[idx];
   }
   gotoxy(shooterX, shooterY + 2);
   for (int idx = 0; idx < 4; idx++)
   {
      cout << enemy9[idx];
   }
}

// Print Field

void printField()
{

   cout << "                                 ____                                                                                                            " << endl;
   cout << "                                (    )                                                                                                           " << endl;
   cout << "                               (      )                                                                                                          " << endl;
   cout << "                               |      |                                                                                                          " << endl;
   cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
   cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                                         %%" << endl;
   cout << "%%                                                                                                                                             %%" << endl;
   cout << "%%                                                                                                     o o o o o o o o o                       %%" << endl;
   cout << "%%          o o o o o o o o o o o o                                                                               o o o o o o o                %%" << endl;
   cout << "%%                                                                                                                       o o o o o o o         %%" << endl;
   cout << "%%                                                                                                                                             %%" << endl;
   cout << "%%                                 %%%%%%%%%%%%%%%%                                                      $                                     %%" << endl;
   cout << "%%                  $              %%%%%%%%%%%%%%%%                        o                                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
   cout << "%%                                 %%%%%%%%%%%%%%%%                      o   o                                %%            o                  %%" << endl;
   cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                    o   o   o                              %%          o   o                %%" << endl;
   cout << "%%                                                                    o o o o o o                             %%        o   o   o              %%" << endl;
   cout << "%%                                                                                                            %%       o o o o o o             %%" << endl;
   cout << "%%                                                                                                                                             %%" << endl;
   cout << "%%                                                                                                                                             %%" << endl;
   cout << "%%                                                                                                                                             %%" << endl;
   cout << "%%                                                                                                                                             %%" << endl;
   cout << "%%                                                                o o o o o o o o o o o o                                                      %%" << endl;
   cout << "%%                                                                o o o o o o o o o o o o                                                      %%" << endl;
   cout << "%%%%%%%%%%%%%%|         o o o o o o o o o o o                     o o %%%%%%%%%%%%%%% o o                     o o o o o o o o o o o            %%" << endl;
   cout << "%%                                                                o o %%%%%%%%%%%%%%% o o                                                      %%" << endl;
   cout << "%%                           %%%%%%%%%%%%%                        o o %%%%%%%%%%%%%%% o o                          %%%%%%%%%%%%%               %%" << endl;
   cout << "%%                                                                o o o o o o o o o o o o                                                      %%" << endl;
   cout << "%%                                                                o o o o o o o o o o o o                                                      %%" << endl;
   cout << "%%               |%|                                                                                                          %%%%%%%%%%%%%%%%%%%" << endl;
   cout << "%%               |%|                                                                           |%|                            %%               %%" << endl;
   cout << "%%               |%|                                                                           |%|                            %%               %%" << endl;
   cout << "%%               |%|                                                                           |%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
   cout << "%%               |%|                                                                           |%|                                             %%" << endl;
   cout << "%%                                                                                             |%|       o o o o o o o o o o o o o o           %%" << endl;
   cout << "%%                                                                                             |%|       o                         o           %%" << endl;
   cout << "%%%%%%%%%%%%%%%%                                                                                         o                         o           %%" << endl;
   cout << "%%            %%                      o o o                                                              o           $             o           %%" << endl;
   cout << "%%            %%                      o | o                 $                                            o                         o           %%" << endl;
   cout << "%%            %%                      o % o                                                              o                         o           %%" << endl;
   cout << "%%                                    o % o                                                              o o o o o o o o o o o o o o           %%" << endl;
   cout << "%%                                    o % o                                                                                                    %%" << endl;
   cout << "%%                                    o % o                     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
   cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
   cout << "                                                                        %     %      %                     |           |                         " << endl;
   cout << "                                                                        %     %      %                      |         |                          " << endl;
   cout << "                                                                        %%%%%%%%%%%%%%                        |______|                           " << endl;
}
// Score Addition
void addScore()
{
   score++;
}

// Print Score
void printScore()
{
   gotoxy(148, 4);
   cout << "Score: " << score;
}

// Life Count DEcrease (Solider)
void decLifeCount()
{
   lifeCount--;
}

// Life Count DEcrease (Enemies)
void decLifeCount1()
{
   champLifeCount--;
}

void decLifeCount2()
{
   teroLifeCount--;
}

void decLifeCount3()
{
   shooterLifeCount--;
}

// Print LifeCount of Solider
void printLifeCount()
{
   gotoxy(148, 6);
   cout << "LifeCount: " << lifeCount;
}

// Print LifeCount of Enemies
void printTeroLifeCount()
{
   gotoxy(148, 8);
   cout << "TeroLifeCount: " << teroLifeCount;
}

void printShooterLifeCount()
{
   gotoxy(148, 10);
   cout << "ShooterLifeCount:" << shooterLifeCount;
}

void printChampLifeCount()
{
   gotoxy(148, 12);
   cout << "ChampLifeCount: " << champLifeCount;
}

// Solider Movement

void moveSoliderRight()
{
   for (int y = 0; y < 4; y++)
   {
      char next = getCharAtxy(soliderX + sizeof(solider4), soliderY + y);
      if (next != ' ' && next != '$' && next != 'o' && next != '-' && next != '`')
      {
         return;
      }
   }
   eraseSolider();
   soliderX = soliderX + 1;
   printSolider();
   scoreSoliderRight();

}
void moveSoliderLeft()
{
   for (int y = 0; y < 4; y++)
   {
      char next = getCharAtxy(soliderX - 1, soliderY + y);
      if (next != ' ' && next != '$' && next != 'o' && next != '-' && next != '`')
      {
         return;
      }
   }
   eraseSolider();
   soliderX = soliderX - 1;
   printSolider();
   scoreSoliderLeft();
}
void moveSoliderUp()
{
   for (int x = 0; x < sizeof(solider4); x++)
   {
      char next = getCharAtxy(soliderX + x, soliderY - 1);
      if (next != ' ' && next != '$' && next != 'o' && next != '-' && next != '`')
      {
         return;
      }
   }

   eraseSolider();
   soliderY = soliderY - 1;
   printSolider();
   scoreSoliderUp();

}
void moveSoliderDown()
{
   for (int x = 0; x < sizeof(solider4); x++)
   {
      char next = getCharAtxy(soliderX + x, soliderY + 4);
      if (next != ' ' && next != '$' && next != 'o' && next != '-' && next != '`')
      {
         return;
      }
   }
   eraseSolider();
   soliderY = soliderY + 1;
   printSolider();
   scoreSoliderDown();

}

// Solider Firing

void printBullet(int x, int y)
{
   gotoxy(x, y);
   cout << ".";
}
void eraseBullet(int x, int y)
{
   gotoxy(x, y);
   cout << " ";
}

void generateBullet()
{
   bulletX[bulletCount] = soliderX + 4;
   bulletY[bulletCount] = soliderY;
   isBulletActive[bulletCount] = true;
   gotoxy(soliderX + 4, soliderY);
   cout << ".";
   bulletCount++;
}

// Inactive Bullet
void makeBulletInactive(int idx)
{
   isBulletActive[idx] = false;
}

// Solider Bullet Movement
void moveBullet()
{
   for (int x = 0; x < bulletCount; x++)
   {
      if (isBulletActive[x] == true)
      {
         char next = getCharAtxy(bulletX[x] + 1, bulletY[x]);
         if (next != ' ')
         {
            eraseBullet(bulletX[x], bulletY[x]);
            makeBulletInactive(x);
         }
         else
         {
            eraseBullet(bulletX[x], bulletY[x]);
            bulletX[x] = bulletX[x] + 1;
            printBullet(bulletX[x], bulletY[x]);
         }
      }
   }
}

// Enemy Movement

// Shooter Movement

void moveShooterUp()
{
   if (shooterDirection == "Up")
   {
      char next = getCharAtxy(shooterX, shooterY - 1);
      if (next == ' ' || next == 'o')
      {
         eraseShooter();
         shooterY--;
         printShooter();
      }
      if (next == '%' || next == '|' || next == '$')
      {
         shooterDirection = "Down";
      }
   }
}   
void moveShooterDown()
{
   if (shooterDirection == "Down")
   {
      char next = getCharAtxy(shooterX, shooterY + 3);
      if (next == ' ' || next == 'o')
      {
         eraseShooter();
         shooterY++;
         printShooter();
      }
      if (next == '%' || next == '|' || next == '$')
      {
         shooterDirection = "Up";
      }
   }
}
void moveShooter()
{
    moveShooterUp();
    moveShooterDown();
    generateShooterBullet();
    moveShooterBullet();
    Sleep(10);
}

// Terrorist Movement

void moveTerroristLeft()
{
      if (enemyDirection == "Left")
      {
         char next = getCharAtxy(teroX - 1, teroY);
         if (next == ' ')
         {
            eraseTerrorist();
            teroX--;
            printTerrorist();
         }
         if (next == '%' || next == 'o' || next == '$')
         {
            enemyDirection = "Right";
         }
      }
}

void moveTerroristRight()
{ 
      if (enemyDirection == "Right")
      {
         char next = getCharAtxy(teroX + 4, teroY);
         if (next == ' ')
         {
            eraseTerrorist();
            teroX++;
            printTerrorist();
         }
         else if (next == '%' || next == 'o' || next == '-' || next == '$')
         {
            enemyDirection = "Left";
         }
      }
}
void moveTerrorist()
{
    moveTerroristLeft();
    moveTerroristRight();
    generateTeroBullet();
    moveTeroBullet();
    Sleep(10);
}

void moveChamp()
{
   int diffX=champX-soliderX;
   int diffY=champY-soliderY;
   if(diffX>0)
    {
      moveChampLeft();
    }
    if(diffX<0)
    {
      moveChampRight();
    }
    if(diffY>0)
    {
      moveChampUp();
    }
    if(diffY<0)
    {
      moveChampDown();
    }

}

void moveChampRight()
{
   for (int y = 0; y < 4; y++)
   {
      char next = getCharAtxy(champX + sizeof(enemy9), champY + y);
      if (next != ' ' && next != '$' && next != 'o' && next != '-' && next != '`')
      {
         return;
      }
   }
   eraseChamp();
   champX = champX + 1;
   printChamp();
   
}
void moveChampLeft()
{
   for (int y = 0; y < 4; y++)
   {
      char next = getCharAtxy(champX - 1, champY + y);
      if (next != ' ' && next != '$' && next != 'o' && next != '-' && next != '`')
      {
         return;
      }
   }
   eraseChamp();
   champX = champX - 1;
   printChamp();

}
void moveChampUp()
{
   for (int x = 0; x < sizeof(enemy9); x++)
   {
      char next = getCharAtxy(champX + x, champY - 1);
      if (next != ' ' && next != '$' && next != 'o' && next != '-' && next != '`')
      {
         return;
      }
   }

   eraseChamp();
   champY = champY - 1;
   printChamp();

}
void moveChampDown()
{
   for (int x = 0; x < sizeof(enemy9); x++)
   {
      char next = getCharAtxy(champX + x, champY + 4);
      if (next != ' ' && next != '$' && next != 'o' && next != '-' && next != '`')
      {
         return;
      }
   }
   eraseChamp();
   champY = champY + 1;
   printChamp();

}

   // Enemies Firing

   // Terrorist Firing
   void printTeroBullet(int x, int y)
   {
      gotoxy(x, y);
      cout << "-";
   }
   void eraseTeroBullet(int x, int y)
   {
      gotoxy(x, y);
      cout << " ";
   }

   void generateTeroBullet()
   {
      teroBulletX[teroBulletCount] = teroX;
      teroBulletY[teroBulletCount] = teroY - 1;
      isTeroBulletActive[teroBulletCount] = true;
      gotoxy(teroX, teroY - 1);
      cout << "-";
      teroBulletCount++;
   }

   void makeTeroBulletInactive(int idx)
   {
      isTeroBulletActive[idx] = false;
   }

   void moveTeroBullet()
   {
      for (int x = 0; x < teroBulletCount; x++)
      {
         if (isTeroBulletActive[x] == true)
         {
            char next = getCharAtxy(teroBulletX[x], teroBulletY[x] - 1);
            if (next != ' ')
            {
               eraseTeroBullet(teroBulletX[x], teroBulletY[x]);
               makeTeroBulletInactive(x);
            }
            else
            {
               eraseTeroBullet(teroBulletX[x], teroBulletY[x]);
               teroBulletY[x] = teroBulletY[x] - 1;
               printTeroBullet(teroBulletX[x], teroBulletY[x]);
            }
         }
      }
   }

   // Shooter Firing
   void printShooterBullet(int x, int y)
   {
      gotoxy(x, y);
      cout << "`";
   }
   void eraseShooterBullet(int x, int y)
   {
      gotoxy(x, y);
      cout << " ";
   }

   void generateShooterBullet()
   {
      shooterBulletX[shooterBulletCount] = shooterX - 1;
      shooterBulletY[shooterBulletCount] = shooterY;
      isShooterBulletActive[shooterBulletCount] = true;
      gotoxy(shooterX - 1, shooterY);
      cout << "`";
      shooterBulletCount++;
   }

   void makeShooterBulletInactive(int idx)
   {
      isShooterBulletActive[idx] = false;
   }
   void moveShooterBullet()
   {
      for (int x = 0; x < shooterBulletCount; x++)
      {
         if (isShooterBulletActive[x] == true)
         {
            char next = getCharAtxy(shooterBulletX[x] - 1, shooterBulletY[x]);
            if (next != ' ')
            {
               eraseShooterBullet(shooterBulletX[x], shooterBulletY[x]);
               makeShooterBulletInactive(x);
            }
            else
            {
               eraseShooterBullet(shooterBulletX[x], shooterBulletY[x]);
               shooterBulletX[x] = shooterBulletX[x] - 1;
               printShooterBullet(shooterBulletX[x], shooterBulletY[x]);
            }
         }
      }
   }

   // GunChamp Firing
   void printChampBullet(int x, int y)
   {
      gotoxy(x, y);
      cout << "`";
   }
   void eraseChampBullet(int x, int y)
   {
      gotoxy(x, y);
      cout << " ";
   }

   void generateChampBullet()
   {
      champBulletX[champBulletCount] = champX - 1;
      champBulletY[champBulletCount] = champY;
      isChampBulletActive[champBulletCount] = true;
      gotoxy(champX - 1, champY);
      cout << "`";
      champBulletCount++;
   }

   void makeChampBulletInactive(int idx)
   {
      isChampBulletActive[idx] = false;
   }
   void moveChampBullet()
   {
      for (int x = 0; x < champBulletCount; x++)
      {
         if (isChampBulletActive[x] == true)
         {
            char next = getCharAtxy(champBulletX[x] - 1, champBulletY[x]);
            if (next != ' ')
            {
               eraseChampBullet(champBulletX[x], champBulletY[x]);
               makeChampBulletInactive(x);
            }
            else
            {
               eraseChampBullet(champBulletX[x], champBulletY[x]);
               champBulletX[x] = champBulletX[x] - 1;
               printChampBullet(champBulletX[x], champBulletY[x]);
            }
         }
      }
   }

// Collision Detection of Enemies with Solider
   void bulletTeroCollisionWithSolider()
   {
      for (int x = 0; x < teroBulletCount; x++)
      {
         if (isTeroBulletActive[x] == true)
         {
            if (teroBulletX[x] + 1 == soliderX && teroBulletY[x] == soliderY)
            {
               decLifeCount();
            }
            if (soliderX - 1 == teroBulletX[x] && soliderY + 1 == teroBulletY[x])
            {
               decLifeCount();
            }
         }
      }
   }

   void bulletShooterCollisionWithSolider()
   {
      for (int x = 0; x < shooterBulletCount; x++)
      {
         if (isShooterBulletActive[x] == true)
         {
            if (shooterBulletX[x] + 1 == soliderX && shooterBulletY[x] == soliderY)
            {
               decLifeCount();
            }
            if (soliderX - 1 == shooterBulletX[x] && soliderY + 1 == shooterBulletY[x])
            {
               decLifeCount();
            }
         }
      }
   }

   // Solider Score

void scoreSoliderRight()
{
   for (int y = 0; y < 4; y++)
   {
      char next = getCharAtxy(soliderX + sizeof(solider4), soliderY + y);
      if (next == 'o' )
      {
         addScore();
      }
   }
   
}
void scoreSoliderLeft()
{
   for (int y = 0; y < 4; y++)
   {
      char next = getCharAtxy(soliderX - 1, soliderY + y);
      if (next == 'o')
      {
         addScore();
      }
   }
   
}
void scoreSoliderUp()
{
   for (int x = 0; x < sizeof(solider4); x++)
   {
      char next = getCharAtxy(soliderX + x, soliderY - 1);
      if (next == 'o')
      {
         addScore();
      }
   }

}
void scoreSoliderDown()
{
   for (int x = 0; x < sizeof(solider4); x++)
   {
      char next = getCharAtxy(soliderX + x, soliderY + 4);
      if (next == 'o')
      {
         addScore();
      }
   }
   
}

  // Solider LifeCount

void countSoliderRight()
{
   for (int y = 0; y < 4; y++)
   {
      char next = getCharAtxy(soliderX + sizeof(solider4), soliderY + y);
      if (next == '$' )
      {
         if(lifeCount<5)
         {
           lifeCount++;
         }

      }
   }
   
}
void countSoliderLeft()
{
   for (int y = 0; y < 4; y++)
   {
      char next = getCharAtxy(soliderX - 1, soliderY + y);
     if (next == '$' )
      {
         if(lifeCount<5)
         {
           lifeCount++;
         }

      }
   }
   
}
void countSoliderUp()
{
   for (int x = 0; x < sizeof(solider4); x++)
   {
      char next = getCharAtxy(soliderX + x, soliderY - 1);
      if (next == '$' )
      {
         if(lifeCount<5)
         {
           lifeCount++;
         }

      }
   }

}
void countSoliderDown()
{
   for (int x = 0; x < sizeof(solider4); x++)
   {
      char next = getCharAtxy(soliderX + x, soliderY + 4);
      if (next == '$' )
      {
         if(lifeCount<5)
         {
           lifeCount++;
         }

      }
   }
   
}

// Decrease in Enemies Life
   void bulletSoliderCollisionWithTero()
   {
      for (int x = 0; x < bulletCount; x++)
      {
         if (isBulletActive[x] == true)
         {
            if (bulletX[x] + 1 == teroX && bulletY[x] == teroY)
            {
               decLifeCount2();
            }
            if (teroX - 1 == bulletX[x] && teroY + 1 == bulletY[x])
            {
               decLifeCount2();
            }
         }
      }
   }

   void bulletSoliderCollisionWithShooter()
   {
      for (int x = 0; x < bulletCount; x++)
      {
         if (isBulletActive[x] == true)
         {
            if (bulletX[x] + 1 == shooterX && bulletY[x] == shooterY)
            {
               decLifeCount3();
            }
            if (shooterX - 1 == bulletX[x] && shooterY + 1 == bulletY[x])
            {
               decLifeCount3();
            }
         }
      }
   }

   void bulletSoliderCollisionWithChamp()
   {
      for (int x = 0; x < bulletCount; x++)
      {
         if (isBulletActive[x] == true)
         {
            if (bulletX[x] + 1 == champX && bulletY[x] == champY)
            {
               decLifeCount1();
            }
            if (champX - 1 == bulletX[x] && champY + 1 == bulletY[x])
            {
               decLifeCount1();
            }
         }
      }
   }

