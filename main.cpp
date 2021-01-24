#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Ttexture.h"
#include "Map.h"
#include "Player.h"
using namespace sf;
void addTexture(Ttexture &texture)
{
    texture.pushTexture("../Pic/Background/bar.png"); //0
    texture.pushTexture("../Pic/Background/cyberpunkstreet.png"); //1
    texture.pushTexture("../Pic/Background/city.jpg"); //2
    texture.pushTexture("../Pic/Background/urbansnow.png"); //3

    texture.pushTexture("../Pic/Player/DinoSprites - mort.png");//4
    texture.pushTexture("../Pic/Player/DinoSprites - doux.png");//5
    texture.pushTexture("../Pic/Player/DinoSprites - vita.png");//6
    texture.pushTexture("../Pic/Player/DinoSprites - tard.png");//7

    texture.pushTexture("../Pic/Startmenu/Button (7).png");//8
    texture.pushTexture("../Pic/Startmenu/pixelart_P1_900x420.jpg.img.jpg");//9

    texture.pushTexture("../Pic/Heart/emptyheart.png");//10
    texture.pushTexture("../Pic/Heart/heartboder.png");//11
    texture.pushTexture("../Pic/Heart/heart.png");//12

    texture.pushTexture("../Pic/Background/cave.jpg");//13
    texture.pushTexture("../Pic/Background/lake.jpg");//14

    texture.pushTexture("../Pic/Background/hole.png");//15
    texture.pushTexture("../Pic/Background/way.png");//16

    texture.pushTexture("../Pic/Startmenu/fin1.jpeg");//17
    texture.pushTexture("../Pic/Startmenu/fin2.jpeg");//18
    texture.pushTexture("../Pic/Startmenu/fin3.jpeg");//19
    texture.pushTexture("../Pic/Startmenu/story1.png");//20
    texture.pushTexture("../Pic/Startmenu/story2.png");//21
    texture.pushTexture("../Pic/Startmenu/story3.jpeg");//22
    texture.pushTexture("../Pic/Startmenu/story4.jpeg");//23

    texture.pushTexture("../Pic/Startmenu/logo.png");
}
int main()
{
    RenderWindow window (VideoMode(800.0f,700.f),"The Hole!", Style::Default);
    window.setPosition(Vector2i(600,200));

    //add Texture
    Ttexture texture;
    addTexture(texture);
    Map map;
    pair<int,int> position=make_pair(0,0);
    map.createMap();
    Player player;
    int level=1,heart=3, atfirst=0;
    bool win=0,die=0;
    //Make menu
    Menu menu(*texture.getTexture(8),*texture.getTexture(4),*texture.getTexture(9),window.getSize().x,window.getSize().y);
    int gamestart=0; //0 menu, 1 story, 2 chooseava, 3 play
    int charec=1;
    bool fade=0;
    bool intro=0;
    vector<RectangleShape> fin;

    while (window.isOpen())
    {
        Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == Event::Closed) window.close();
        }
        bool stay=0;

        window.clear();
        if (gamestart == 0 && Keyboard::isKeyPressed(Keyboard::Key::Space)) gamestart = 1;
            else
                if (gamestart == 2)
                {
                    window.setFramerateLimit(10);
                    if (Keyboard::isKeyPressed(Keyboard::Key::C)) gamestart = 3;
                    if (Keyboard::isKeyPressed(Keyboard::Key::A))
                    {
                        charec--;
                        if (charec==0) charec=1;
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
                        charec++;
                        if (charec == 5) charec = 4;
                    }
                }
        if (intro==0) {
            Clock clock;
            Texture texture1,texture2;
            texture1.loadFromFile("../Pic/Startmenu/logo2pixel.png");
            texture2.loadFromFile("../Pic/Startmenu/logo.png");
            while (1) {
                window.clear(Color::White);
                CircleShape fadein;
                fadein.setTexture(&texture2);
                fadein.setPosition(Vector2f(200,150));
                fadein.setRadius(200);
                window.draw(fadein);
                window.display();
                Time time=clock.getElapsedTime();
                if (time.asSeconds()>2) break;
            }
            clock.restart();
            while (1)
            {
                RectangleShape fadein;
                fadein.setTexture(&texture1);
                fadein.setPosition(Vector2f(0,150));
                fadein.setSize(Vector2f(800,400));
                window.draw(fadein);
                window.display();
                Time time = clock.getElapsedTime();
                if (time.asSeconds() > 2) break;
            }
            clock.restart();
            intro=1;
        }
        if (gamestart==0)
        {
            window.setFramerateLimit(60);
            charec=1;
            level=1;
            heart=3;
            atfirst=0;
            win=0;
            die=0;
            menu.update(0.1);
            window.draw(menu.getBackGround());
            window.draw(menu.getStartButton());
            window.draw(menu.getTheme());
            window.draw(menu.getText());
            window.draw(menu.getTitle());
        }
        if (gamestart==1)
        {
            window.clear();
            Texture texturee;
            RectangleShape sq;

            window.setFramerateLimit(10);
            int i=0;
            while (1)
            {
                window.clear();
                Text text,text1;
                Font font;
                font.loadFromFile("../Font/fonttext.otf");
                text1.setString("Press D to next");
                text1.setFont(font);
                text1.setCharacterSize(10);
                text1.setPosition(Vector2f(550,650));
                if (i==0)
                {
                    text.setString("You have a crush on a girl for a long time.\nOne day, you decided to confess to her.");
                    text.setCharacterSize(20);
                    text.setPosition(Vector2f(50,550));
                    text.setFont(font);

                    texturee.loadFromFile("../Pic/Startmenu/story1.png");
                    sq.setTexture(&texturee);
                    sq.setPosition(100,100);
                    sq.setSize(Vector2f(600,400));
                    sq.setFillColor(Color::White);
                    window.draw(sq);
                    window.draw(text);
                    window.draw(text1);
                    window.display();
                }
                if (i==1)
                {
                    text.setString("Unluckily, she denied you downrightly!!!");
                    text.setCharacterSize(20);
                    text.setPosition(Vector2f(50,550));
                    text.setFont(font);

                    texturee.loadFromFile("../Pic/Startmenu/story2.png");
                    sq.setTexture(&texturee);
                    sq.setPosition(100,100);
                    sq.setSize(Vector2f(600,400));
                    sq.setFillColor(Color::White);
                    window.draw(sq);
                    window.draw(text);
                    window.draw(text1);
                    window.display();
                }
                if (i==2)
                {
                    text.setString("She left with her Dino Boyfriend,\nand you turned out she just loves Dino.");
                    text.setCharacterSize(20);
                    text.setPosition(Vector2f(50,550));
                    text.setFont(font);

                    texturee.loadFromFile("../Pic/Startmenu/story3.jpeg");
                    sq.setTexture(&texturee);
                    sq.setPosition(100,100);
                    sq.setSize(Vector2f(600,400));
                    sq.setFillColor(Color::White);
                    window.draw(sq);
                    window.draw(text);
                    window.draw(text1);
                    window.display();
                }
                if (i==3)
                {
                    text.setString("To have her love, you tried your best to change who you are!");
                    text.setCharacterSize(20);
                    text.setPosition(Vector2f(50,550));
                    text.setFont(font);

                    texturee.loadFromFile("../Pic/Startmenu/story4.jpeg");
                    sq.setTexture(&texturee);
                    sq.setPosition(100,100);
                    sq.setSize(Vector2f(600,400));
                    sq.setFillColor(Color::White);
                    window.draw(sq);
                    window.draw(text);
                    window.draw(text1);
                    window.display();
                }
                if (i==4)
                {
                    Text text;
                    text.setString("TUTORIAL:\n\n\nUse A,W,S,D to move on the matrix.\nAvoid the black one.\nTry your best to reach the red one.\nYou have 3s to remember the map.\nThere are 100 level :< \nGood luck!!!");
                    text.setFont(font);
                    text.setPosition(50,100);
                    text.setCharacterSize(30);
                    window.draw(text);
                    window.display();
                }
                if (Keyboard::isKeyPressed(Keyboard::Key::D)) i++;
                if(i>5)
                {
                    gamestart++;
                    break;
                }
            }
        }
        if (gamestart==2)
        {
            Player player1, player2, player3,player4;
            player1.setPlayerTexture(*texture.getTexture(4));
            player2.setPlayerTexture(*texture.getTexture(5));
            player3.setPlayerTexture(*texture.getTexture(6));
            player4.setPlayerTexture(*texture.getTexture(7));

            player1.setPosition(Vector2f(150,250));
            player2.setPosition(Vector2f(300,250));
            player3.setPosition(Vector2f(450,250));
            player4.setPosition(Vector2f(600,250));

            Text text,text1,text2;
            text.setString("!CHOOSE YOUR NEW LOOK!");
            text1.setString("Press C to Choose");
            text2.setString("Use A,D to select your skin");
            Font font;
            font.loadFromFile("../Font/fonttext.otf");
            text.setFont(font);
            text1.setFont(font);
            text2.setFont(font);

            text.setCharacterSize(40);
            text1.setCharacterSize(20);
            text2.setCharacterSize(20);

            text.setPosition(150,200);
            text2.setPosition(150,400);
            text1.setPosition(150,450);

            text1.setFillColor(Color(0, 255, 255));
            text2.setFillColor(Color(48, 213, 200));

            if (charec==1) window.draw(player1.setBoder());
            if (charec==2) window.draw(player2.setBoder());
            if (charec==3) window.draw(player3.setBoder());
            if (charec==4) window.draw(player4.setBoder());

            window.draw(text);
            window.draw(text1);
            window.draw(text2);

            window.draw(player1.getPlayer());
            window.draw(player2.getPlayer());
            window.draw(player3.getPlayer());
            window.draw(player4.getPlayer());
        }
        if (gamestart==3)
        {
            window.setFramerateLimit(60);
            if (charec==1)
            {
                player.setPlayerTexture(*texture.getTexture(4));
                charec=100;
            }
            if (charec==2)
            {
                player.setPlayerTexture(*texture.getTexture(5));
                charec=100;
            }
            if (charec==3)
            {
                player.setPlayerTexture(*texture.getTexture(6));
                charec=100;
            }
            if (charec==4)
            {
                player.setPlayerTexture(*texture.getTexture(7));
                charec=100;
            }
            if (die)
            {
                die=0;
                atfirst=0;
                heart--;
            }
            if (heart==0)
            {
                Clock clock;
                Text gameover, comment;
                gameover.setString("Game Over!");
                comment.setString("<: You Chickun  :>");
                Font font;
                font.loadFromFile("../Font/fonttext.otf");
                gameover.setFont(font);
                comment.setFont(font);
                gameover.setPosition(250,300);
                comment.setPosition(250,350);
                gameover.setCharacterSize(50);
                comment.setCharacterSize(20);
                while (1)
                {
                    window.clear(Color::Black);
                    Time time=clock.getElapsedTime();
                    window.draw(gameover);
                    window.draw(comment);
                    window.display();
                    if (time.asSeconds()>=4) break;
                }
                gamestart=0;
                continue;
            }
            if (atfirst==0)
            {
                player.setPosition(level);
                atfirst=1;
                fade=0;
            }
            if (win==1)
            {
                level+=50;
                atfirst=0;
                win=0;
            }
            if (level>100)
            {
                gamestart=0;
                window.clear();
                Texture texturee;
                RectangleShape sq;

                window.setFramerateLimit(10);
                int i=0;
                while (1)
                {
                    window.clear();
                    Text text,text1;
                    Font font;
                    font.loadFromFile("../Font/fonttext.otf");
                    text1.setString("Press D to next");
                    text1.setFont(font);
                    text1.setCharacterSize(10);
                    text1.setPosition(Vector2f(550,650));
                    if (i==0)
                    {
                        text.setString("Now you become a STRONG AND BIG DINO!\nYou decide to confess to her again.");
                        text.setCharacterSize(20);
                        text.setPosition(Vector2f(50,550));
                        text.setFont(font);

                        texturee.loadFromFile("../Pic/Startmenu/fin1.jpeg");
                        sq.setTexture(&texturee);
                        sq.setPosition(100,100);
                        sq.setSize(Vector2f(600,400));
                        sq.setFillColor(Color::White);
                        window.draw(sq);
                        window.draw(text);
                        window.draw(text1);
                        window.display();
                    }
                    if (i==1)
                    {
                        text.setString("But... Your eyes meet and your heart skips a beat...");
                        text.setCharacterSize(20);
                        text.setPosition(Vector2f(50,550));
                        text.setFont(font);

                        texturee.loadFromFile("../Pic/Startmenu/fin2.jpeg");
                        sq.setTexture(&texturee);
                        sq.setPosition(100,100);
                        sq.setSize(Vector2f(600,400));
                        sq.setFillColor(Color::White);
                        window.draw(sq);
                        window.draw(text);
                        window.draw(text1);
                        window.display();
                    }
                    if (i==2)
                    {
                        text.setString("Then, 2 Dinos are happy together!  <3");
                        text.setCharacterSize(20);
                        text.setPosition(Vector2f(50,550));
                        text.setFont(font);

                        texturee.loadFromFile("../Pic/Startmenu/fin3.jpeg");
                        sq.setTexture(&texturee);
                        sq.setPosition(100,100);
                        sq.setSize(Vector2f(600,400));
                        sq.setFillColor(Color::White);
                        window.draw(sq);
                        window.draw(text);
                        window.draw(text1);
                        window.display();
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Key::D)) i++;
                    if(i>3)
                    {
                        gamestart=0;
                        break;
                    }
                }
                continue;
            }
            map.setMap(level);

            if (level>=1 && level<=20) map.setBackground(*texture.getTexture(1),window);
            if (level>=21 && level<=40) map.setBackground(*texture.getTexture(2),window);
            if (level>=41 && level<=60) map.setBackground(*texture.getTexture(3),window);
            if (level>=61 && level<=80) map.setBackground(*texture.getTexture(13),window);
            if (level>=81 && level<=100) map.setBackground(*texture.getTexture(14),window);

            Clock clock;
            while (fade==0)
            {
                Time time=clock.getElapsedTime();
                for(int i=1;i<=3;i++)
                {
                    if (i>heart) player.updateHeart(i,*texture.getTexture(10));
                    else player.updateHeart(i,*texture.getTexture(12));
                }
                window.draw(map.getBackgroundMap());
                for(int i=1;i<=3;i++) window.draw(player.getHeart(i));
                map.drawMap(window,*texture.getTexture(16),fade);
                window.display();
                if (time.asSeconds()>3) fade=1;
            }
            window.clear();
            for(int i=1;i<=3;i++)
            {
                if (i>heart) player.updateHeart(i,*texture.getTexture(10));
                else player.updateHeart(i,*texture.getTexture(12));
            }
            window.draw(map.getBackgroundMap());
            for(int i=1;i<=3;i++) window.draw(player.getHeart(i));
            map.drawMap(window,*texture.getTexture(16),fade);
            fin=map.getHole();
//            char trc='D';
            if (Keyboard::isKeyPressed(Keyboard::Key::D))
            {
                player.Update(5, 8, 0.1,1,level);
                player.move(1,0.0f);
                if (player.colliderect(fin))
                {
                    die=1;
                }
                stay = 1;
//                trc='D';
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::A))
            {
                player.Update(5, 8, 0.1,0,level);
                player.move(-1,0.0f);
                if (player.colliderect(fin))
                {
                    die=1;
                }
                stay = 1;
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::W))
            {
                player.Update(8, 10, 0.1,1,level);
                player.move(0.0,-1);
                if (player.colliderect(fin))
                {
                    die=1;
                }
                stay = 1;
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::S))
            {
                player.Update(8, 10, 0.1,1,level);
                player.move(0.0,1);
                if (player.colliderect(fin))
                {
                    die=1;
                }
                stay = 1;
            }
            if (stay==0)
            {
                player.Update(0,2,0.07,1,level);
            }
            if (die)
            {
                Clock clock;
                while (1)
                {
                    player.Update(14,16,0.07,1,level);
                    Time time=clock.getElapsedTime();
                    window.draw(player.getPlayer());
                    window.display();
                    if (time.asSeconds()>=2) break;
                }
                continue;
            }
            if (player.colliderect(map.getFin()))
            {
                Clock clock;
                while (1)
                {
                    Time time=clock.getElapsedTime();
                    if (time.asSeconds()>=0.3) break;
                }
                win=1;
            }
            window.draw(player.getPlayer());
        }
        window.display();
    }
    return 0;
}
