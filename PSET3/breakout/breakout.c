//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// height and width of the game's paddle in pixel
#define PADDLEHEIGHT 15
#define PADDLEWIDTH 75


// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// brick height
#define BRICKHEIGHT 15

// brick width
#define BRICKWIDTH 35

// brick spacing
#define BRICKSPACE (50/10)

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));
    
    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    // initialize velocity variable as random number between 0.0 and 1.0 times the constant 2
    double hvelocity = drand48() * .9;
    
    double vvelocity = -0.5; //drand48() + .1  * 5;
    
    waitForClick();

    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        // follow mouse forever
        // check for mouse event
        GEvent event = getNextEvent(MOUSE_EVENT);

        // if we heard one
        if (event != NULL)
        {
            // if the event was movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                // ensure paddle follows cursor 
                // TODO Fix paddle so it doesn't fall outside window
                double x = getX(event) - (getWidth(paddle) / 2);
                double y = getY(paddle); 
                setLocation(paddle, x, y);
            }
        }
 
        // move ball
        move(ball, hvelocity, vvelocity);

        // bounce off right edge of window
        if (getX(ball) + getWidth(ball) >= getWidth(window))
        {
            hvelocity = -hvelocity;
        }

        // bounce off left edge of window
        else if (getX(ball) <= 0)
        {
            hvelocity = -hvelocity;
        }
        
        // bounce off bottom edge of window (not sure why?)
        else if (getY(ball) + getHeight(ball) >= getHeight(window))
        {
            lives--;
            setLocation(ball, WIDTH/2 - RADIUS/2, (getHeight(window)/2));
            setLocation(paddle, .5*WIDTH - .5*PADDLEWIDTH, .8*HEIGHT);
            waitForClick();
            hvelocity = drand48() * .01;
            vvelocity = -.05; //drand48() + .1  * 5;
        }
        
        // bounce off top edge of window
        else if (getY(ball) <= 0)
        {
            vvelocity = -vvelocity;
        }

        GObject collisionObject = detectCollision(window, ball);
        
        if (collisionObject != NULL && (strcmp(getType(collisionObject), "GRect") == 0))
        {
           vvelocity = -vvelocity;
           
           
           if (collisionObject != paddle)
           {
            removeGWindow(window, collisionObject);
            
            bricks--;
            points++;
            updateScoreboard(window, label, points);
            
           }
         } 
           
        /** Why do I get a segmentation fault by doing this?--code above works fine, but I am 
        just curious why I get an segmentation fault error by splitting this check into two 
        separate 'if' statements instead of one as I did above
        // TODO
        
        if (collisionObject == paddle)
        {
            vvelocity = -vvelocity;
        }
        
        if (strcmp(getType(collisionObject), "GRect") == 0)
        {
            vvelocity = -vvelocity;
        }
        
        */
        
     
    }
   

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // Loop for columns of bricks 
     for (int i = 0; i < ROWS; i++)
     {
     
        for (int j = 0; j < COLS; j++)
        {
            GRect brick = newGRect (BRICKSPACE + j*(BRICKSPACE + BRICKWIDTH), ((BRICKSPACE + i*(BRICKSPACE + BRICKHEIGHT) + 40)), BRICKWIDTH, BRICKHEIGHT); 
            setFilled(brick, true);
            setColor(brick, "BLACK");
            add(window, brick);
            
        }
     
     }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    
    // instantiate circle
    GOval ball = newGOval((getWidth(window)/2) - RADIUS, (getHeight(window)/2) - RADIUS, 2*RADIUS, 2*RADIUS);
    setColor(ball, "BLACK");
    setFilled(ball, true);
    add(window, ball);
    
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
   
    // First step.
    GRect paddle = newGRect (.5*WIDTH - .5*PADDLEWIDTH, .8*HEIGHT, PADDLEWIDTH, PADDLEHEIGHT); 
    setFilled(paddle, true);
    setColor(paddle, "BLACK");
    add(window, paddle);
    
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel("0");
    setFont(label, "SansSerif-18");
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = ((getHeight(window) + getFontAscent(label)) / 2) - 40;
    setLocation(label, x, y);
    add(window, label);
    
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = ((getHeight(window) + getFontAscent(label)) / 2) - 40;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
