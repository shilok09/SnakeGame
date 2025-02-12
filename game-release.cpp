//============================================================================
// Name        : Shilok Kumar
// Roll-No     : 23I-2502
// Project     : Snake Game
//============================================================================

#ifndef SNAKEGAME_CPP_
#define SNAKEGAME_CPP_

#include "util.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <sstream>
#include <cmath>

using namespace std;

int width = 650, height = 650; // window
int TileSize = 10;
int TileCount = 65;
int score=0;

// Position of snake
int snakeX[65];
int snakeY[65];
int snakeLength = 5; // Initial length of the snake


//Hurdle Array
int hurdles[5][2] = {{200, 200}, {200, 220}, {200, 240}, {220, 240}, {240, 240}};


int time_count=0;   
char direction;
bool gameOver = false;

// Array to store Food
int food[10][2];
int food_count = 5; // Initial number of food

void SetCanvasSize(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Food()
 {
    for (int i = 0; i<food_count; i++) 
         DrawSquare(food[i][0], food[i][1], 20, colors[RED]);
    
 }


void Snake() 
  {
    for (int i = 0; i<snakeLength; i++) 
        DrawSquare(snakeX[i], snakeY[i], 20, colors[35]);
  }

void Hurdles() 
  {
    for (int i = 0; i<5; i++) 
        DrawSquare(hurdles[i][0], hurdles[i][1], 30, colors[BLUE]); 
    
  }

void Display() 
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    Snake();
    Hurdles(); 
    Food();
  
    //Border
    DrawLine(0, 0, width - 1, 0, 20, colors[GRAY]);        // top
    DrawLine(0, height - 1, width - 1, height - 1, 20, colors[GRAY]);  // bottom
    DrawLine(0, 0, 0, height - 1, 20, colors[GRAY]);        // left
    DrawLine(width - 1, 0, width - 1, height - 1, 20, colors[GRAY]);  // right


   //Score
    stringstream ss;
    ss << "SCORE " << score;
    DrawString(10, height - 30, ss.str(), colors[WHITE]);
    
    //Displaying GameOver Message
     if (gameOver) 
     { 
        DrawString(250, 325, "GAME OVER! ", colors[RED]);
        DrawString(250, 300,  ss.str() , colors[GREEN]);
     }

    glutSwapBuffers();
}





void Timer(int m) {

     //Condition to Stop Game if GameOver
      if (gameOver) {
        glutPostRedisplay();
        glutTimerFunc(1000.0/8, Timer, 0);
        return;
    }
    // Moving snake based on the user's input
    switch(direction)
    {
    
      case 'U':
          snakeY[0]+=25; 
          break;

      case 'D':
            snakeY[0]-=25;
             break;
      case 'R':
            snakeX[0]+=25;
             break;
      case 'L':
            snakeX[0]-=25;
             break;
    }
    
    //check for crossing border
    if (snakeX[0] >= width) 
        snakeX[0] = 0;

    if (snakeX[0] < 0) 
        snakeX[0] = width - TileSize;
    

    if (snakeY[0] >= height) 
        snakeY[0] = 0;

    if (snakeY[0] < 0) 
        snakeY[0] = height - TileSize;
int i = 0;
   // Check if the snake has collided with any food
while(i<food_count) 
{
    if ((snakeX[0] <= food[i][0] + 10 ) && (snakeX[0]+ 30 >= food[i][0]))
        if((snakeY[0] <= food[i][1] + 10) && (snakeY[0] + 30 >= food[i][1]))
    {
        
	    food[i][0] = rand()%(width - 30)+15;
	    food[i][1] = rand()%(height - 30)+15;

      // Adding Score 
        score += 5;
      // Increment in Length of Snake
        snakeLength += 1;

      // Add new segments at the end of the array
        snakeX[snakeLength - 2] = snakeX[snakeLength - 3];
        snakeY[snakeLength - 2] = snakeY[snakeLength - 3];
        snakeX[snakeLength - 1] = snakeX[snakeLength - 3];
        snakeY[snakeLength - 1] = snakeY[snakeLength - 3];

    }
  i++;
}

    // Check For updating position of Food
    if (time_count >= 15000 ) 
    {
        for (int i = 0; i<food_count; i++) 
        {
            food[i][0] = rand()%(width - 10);
            food[i][1] = rand()%(height - 10);
        }
        time_count=0;
      
    }
    else
    time_count +=1000.0/8;
    
  
    
   // Check if the snake has collided with its own body
for (int i = 1; i<snakeLength; i++) 
{
    if (snakeX[0] == snakeX[i])
        if(snakeY[0] == snakeY[i]) 
            gameOver = true;
    
}

// Check if the snake has collided with hurdle
for (int i=0; i<5; i++) 
{
    for (int j=1; j<snakeLength; j++) 
    {
        if (snakeX[j] >= hurdles[i][0] && snakeX[j] <= hurdles[i][0] + 20) 
           if(snakeY[j] >= hurdles[i][1] && snakeY[j] <= hurdles[i][1] + 20)  
              gameOver = true;
        
    }
}



//changing position of tail
if((direction == 'U' || direction == 'D') || ( direction == 'R' || direction == 'L'))
{
for (int i=snakeLength-1; i>0; i--) 
    {
        snakeX[i] = snakeX[i - 1]; //Updating the position of the snake parts;
        snakeY[i] = snakeY[i - 1];
    }
}
    glutPostRedisplay();
   glutTimerFunc(1000.0/8, Timer, 0);
}

void NonPrintableKeys(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT && direction != 'R') 
        direction = 'L';
        
    if (key == GLUT_KEY_RIGHT && direction != 'L') 
        direction = 'R';
        
    if (key == GLUT_KEY_UP && direction != 'D') 
        direction = 'U';
        
    if (key == GLUT_KEY_DOWN && direction != 'U') 
        direction = 'D';
    

    glutPostRedisplay();
}


void PrintableKeys(unsigned char key, int x, int y) {
    if (key == KEY_ESC) {
        exit(1);
    }

    glutPostRedisplay();
}

int main(int argc, char* argv[]) {
    
    //Moving snake initially 
    direction = 'U';

    InitRandomizer();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(TileSize * TileCount, TileSize * TileCount);
    glutCreateWindow("Snake Game");
    SetCanvasSize(width, height);
    

    //Initial positions  of Food
    for (int i = 0; i<food_count; i++) 
    {
        food[i][0] = rand()%(width - 10);
        food[i][1] = rand()%(height - 10);
    }

    for(int i=0; i<5; i++)
    {
      snakeX[i]=320;
      snakeY[i]=320-(i*20);
    }
    
    
    glutDisplayFunc(Display);
    glutSpecialFunc(NonPrintableKeys);
    glutKeyboardFunc(PrintableKeys);
    glutTimerFunc(1000.0/8, Timer, 0);
    glutMainLoop();

    return 1;
}

#endif 

