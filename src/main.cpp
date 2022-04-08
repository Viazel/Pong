#include "headers/main.h"
#include <string>

RenderWindow window;
Input input;
Font font;
Text txt;

int posRaquettesLeftX = 50;
int posRaquettesRightX = WIN_WIDTH - 70;
int posRaquettesLeftY = WIN_HEIGHT /2;
int posRaquettesRightY = posRaquettesLeftY;
int raquettesSpeed = 5;
int raquettesHeight = 150;
int raquettesWidth = 20;

float ballSpeed = 4;
Vector2f ballDir = Vector2f(1.5f, 2);
float ballPosX = WIN_WIDTH / 2;
float ballPosY = WIN_HEIGHT / 2;

int scoreJ1 = 0;
int scoreJ2 = 0;

void UpdateBall(){
    ballPosX += ballDir.x * ballSpeed;
    ballPosY += ballDir.y * ballSpeed;

    if((ballPosX < posRaquettesLeftX + raquettesWidth && 
       ballPosX > posRaquettesLeftX && 
       ballPosY < posRaquettesLeftY + raquettesHeight && 
       ballPosY > posRaquettesLeftY) 
       || 
       (ballPosX > posRaquettesRightX - raquettesWidth && 
            ballPosX < posRaquettesRightX && 
            ballPosY < posRaquettesRightY + raquettesHeight && 
            ballPosY > posRaquettesRightY)){
        ballDir.x *= -1;
    }

    if(ballPosX <= 0){
        scoreJ2++;
        ballPosX = WIN_WIDTH / 2;
        ballPosY = WIN_HEIGHT / 2;
        ballDir.x = labs(ballDir.x);
        ballDir.y *= -1;
        setText(txt, to_string(scoreJ1) + " | " + to_string(scoreJ2));
    }

    if(ballPosX >= WIN_WIDTH){
        scoreJ1++;
        ballPosX = WIN_WIDTH / 2;
        ballPosY = WIN_HEIGHT / 2;
        ballDir.x = -labs(ballDir.x);
        ballDir.y *= -1;
        setText(txt, to_string(scoreJ1) + " | " + to_string(scoreJ2));
    }

    if(ballPosY >= WIN_HEIGHT ||ballPosY <= 0){
        ballDir.y *= -1;
    }
}

int main(int argc, char const *argv[])
{
    
    ContextSettings options;
    options.antialiasingLevel = 16;

    window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "Pong SFML", Style::Default, options);
    window.setFramerateLimit(60);
    font.loadFromFile("res/poppins.ttf");

    setText(txt, to_string(scoreJ1) + " | " + to_string(scoreJ2));

    CircleShape circleShape(15);
    circleShape.setPosition(ballPosX, ballPosY);

    RectangleShape rectangleShape(Vector2f(raquettesWidth, raquettesHeight));
    rectangleShape.setPosition(posRaquettesLeftX, posRaquettesLeftY);

    RectangleShape rectangleShape2(Vector2f(raquettesWidth, raquettesHeight));
    rectangleShape.setPosition(posRaquettesRightX, posRaquettesRightY);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            input.inputHandler(event, window);
        }

        checkButton();

        rectangleShape.setPosition(posRaquettesLeftX, posRaquettesLeftY);
        rectangleShape2.setPosition(posRaquettesRightX, posRaquettesRightY);

        UpdateBall();

        circleShape.setPosition(ballPosX, ballPosY);

        window.clear(Color::Black);
        window.draw(txt);
        window.draw(circleShape);
        window.draw(rectangleShape);
        window.draw(rectangleShape2);

        window.display();
        
    }

    return EXIT_SUCCESS;
}

void setText(Text &text, String str){
    text.setString(str);
    text.setFont(font);
    text.setCharacterSize(26);
    text.setFillColor(Color::White);
    text.setPosition((WIN_WIDTH / 2) - 40, 10);
}

void checkButton(){
    if(input.getButton().up == true){
        posRaquettesLeftY -= raquettesSpeed;
        if(posRaquettesLeftY < 0)
            posRaquettesLeftY = 0;
    }
    if(input.getButton().down == true){
        posRaquettesLeftY += raquettesSpeed;
        if(posRaquettesLeftY + raquettesHeight > WIN_HEIGHT)
            posRaquettesLeftY = WIN_HEIGHT - raquettesHeight;
    }

    if(input.getButton().left == true){
        posRaquettesRightY -= raquettesSpeed;
        if(posRaquettesRightY < 0)
            posRaquettesRightY = 0;
    }
    if(input.getButton().right == true){
        posRaquettesRightY += raquettesSpeed;
        if(posRaquettesRightY + raquettesHeight > WIN_HEIGHT)
            posRaquettesRightY = WIN_HEIGHT - raquettesHeight;
    }

    if(input.getButton().escape == true) {
        window.close();
    }

}