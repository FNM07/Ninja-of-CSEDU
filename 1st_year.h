#include <SFML/Graphics.hpp>
#include<time.h>
#include<iostream>
#include<stdio.h>
#include<string>

////level1 1////

using namespace std;
using namespace sf;



int lives = 4, flag = 0, flag5[5], flag6[5], upj[5], crash[5], jombie_flag[5], jcount[5], ccount[5], cxcount[5], pcount[5], mulcount[5], gm_over = 0;
int cdistance[10], pdistance[14], p1distance[14], muldistance[10], mul1distance[10], pyac[20], pyth[20], mx[20], jdistance[10], mdistance[10];
Sprite   ninja_star[40], sobstacle[20], python[8], playerImage, python1[8], cxImage[5], cImage[5], sgame_over, hit_image, multi[10], jombie[10], paused, tied_man;
String sentence, count_begin;
Font font;
Text text(sentence, font, 40);
Text text_begin(count_begin, font, 40);
int coin_sect[50];
int tx[20];


bool isCollide(Sprite  s1, Sprite s2)
{
	return s1.getGlobalBounds().intersects(s2.getGlobalBounds());
}



int  attack(Sprite star)
{
	int cj;
	for (cj = 0; cj <= 2; cj++)
	{
		if (isCollide(cImage[cj], star))
		{
			ccount[cj]++;
			if (ccount[cj] >= 2)
				cdistance[cj] = -2000;
			return 1;
		}

		if (isCollide(cxImage[cj], star))
		{
			cxcount[cj]++;
			if (cxcount[cj] >= 2)
				cdistance[cj] = -3000;
			return 1;
		}

	}

	for (cj = 0; cj <= 2; cj++)
	{
		if (isCollide(python[cj], star))
		{
			pcount[cj]++;
			if (pcount[cj] >= 2)
				pdistance[cj] = -1000;
			return 1;
		}

	}


	for (cj = 0; cj < 5; cj++)
	{
		if (isCollide(star, jombie[cj]))
		{
			jcount[cj]++;
			if (jcount[cj]>2)
				jdistance[cj] = -2500;
			return 1;
		}

	}
	for (cj = 0; cj < 16; cj++)
	{
		if (isCollide(sobstacle[cj], star))
		{

			return 1;
		}

	}

	for (cj = 0; cj < 4; cj++)
	{
		if (isCollide(multi[cj], star))
		{
			mulcount[cj]++;
			if (mulcount[cj] >= 2)
				muldistance[cj] = -1000;
			return 1;
		}
	}



	return 0;

}

void GAME_OVER(int count)
{


	int count1 = count;

	string str;
	while (count1 > 0)
	{
		int a;
		a = count1 % 10;
		count1 = count1 / 10;
		a = a + 48;
		char b = a;
		str = str + b;
	}

	reverse(str.begin(), str.end());

	if (gm_over == 0){
		sentence += str;
		if (count == 0) sentence += '0';
		gm_over = 1;
	}


	text.setString(sentence);
	text.setPosition(450, 50);
	window.draw(text);

	if (playerImage.getPosition().x < 60){
		text.setString("Re Admission :(");
		text.setPosition(450, 150);
		window.draw(text);
	}





}

void level1(RenderWindow &window)
{

	window.setKeyRepeatEnabled(false);
	int i, xod = 2000, upward = 200, j, s, posx = 0, posy = 0, flag2 = 1, up = 0, fl = 0, ninja_starflag = 0, total_trans = 11, pys = 0, life_flag = 0,
		nsf = 0, ns = 0, star_num = 40, js = 0, ts = 0, flagjump = 0, player_height = 300, jump_flag = 0, firo = 0, fire_flag = 0, Anife_flag = 0, throw_flag = 0,
		sobstacle_index = 0, hole_flag = 0, holedex = 6, ms = 0, flag3 = 1, flag4 = 0, up1 = 0, flagf = 1, upf = 0;

	enum Task  { Run, Jump, Slide };
	int distance[16];
	distance[0] = 0;
	int  count = 0;




	//////Positioning everything on the co ordinates///////
	j = 2;
	for (i = 1; i < 16; i++)
	{
		if (i <= 5)
			distance[i] = distance[i - 1] + 1200 + rand() % 100;

		else
			distance[i] = distance[i - 1] + 1800 + rand() % 100;

		if (i == 1)
			cdistance[0] = distance[i] - 200;

		if (i == 2)
		{

			cdistance[1] = distance[i] - 400;
			cdistance[2] = distance[i] - 200;
		}

		else if (i == 3)
		{

			pdistance[0] = distance[i] - 200;
			p1distance[0] = distance[i] - 200;

		}
		else if (i == 4)
		{
			pdistance[1] = distance[i] - 300;
			p1distance[1] = distance[i] - 300;
		}
		if (i == 5)
		{
			pdistance[2] = distance[i] - 100;
			p1distance[2] = distance[i] - 100;
		}



		if (i == 6)
		{
			muldistance[0] = distance[i] - 500;
			muldistance[1] = distance[i] - 100;
			mul1distance[0] = distance[i] - 500;
			mul1distance[1] = distance[i] - 100;

		}

		if (i == 7)
		{
			muldistance[2] = distance[i] - 700;
			muldistance[3] = distance[i] - 200;
			mul1distance[2] = distance[i] - 700;
			mul1distance[3] = distance[i] - 200;

		}
		if (i == 8)
		{
			jdistance[0] = distance[i] - 700;
			jdistance[1] = distance[i] - 300;
		}

		if (i == 9)
		{
			jdistance[2] = distance[i] - 800;
			jdistance[3] = distance[i] - 600;
			jdistance[4] = distance[i] - 400;
			jdistance[5] = distance[i] - 200;


		}






	}




	Clock clock, clock2, begin_clock;
	float timer = 0, delay = 0.1, timer2 = 0;
	float frameCounter = 0, switchFrame = 100, frameSpeed = 500;


	window.setFramerateLimit(10);
	Vector2i source(0, Run);

	Texture pTexture, bart, tground, tobstacle, game_over, pcoins, b1Texture, paus, cTexture, elect, cxTexture, knifetx, pstar, firef, c_attack, fire, build, heart, jombiex, pythontexture, python1texture, mulTexture, hit;
	Sprite  bars, sground, sgame_over, b1Image, b2Image, player_heart, building1, building2, knife_effect, fire_flag_flag, cattack, fire_ball;
	Sprite  coins[100], electricity[12];


	if (!b1Texture.loadFromFile("MrShadow3.png"))
		cout << "Error could not load player image" << endl;

	b1Image.setTexture(b1Texture);
	b2Image.setTexture(b1Texture);

	build.loadFromFile("building.jpg");
	building1.setTexture(build);
	building2.setTexture(build);

	building1.setPosition(0, 450);
	building2.setPosition(1180, 450);

	paus.loadFromFile("Paused.jpg");
	paused.setTexture(paus);

	knifetx.loadFromFile("knife_effct.png");
	knife_effect.setTexture(knifetx);
	c_attack.loadFromFile("cattack.png");
	cattack.setTexture(c_attack);

	firef.loadFromFile("fire_flag.png");
	fire_flag_flag.setTexture(firef);

	fire.loadFromFile("fireball.png");
	fire_ball.setTexture(fire);
	hit.loadFromFile("got_hit.png");
	hit_image.setTexture(hit);

	heart.loadFromFile("player_heart.png");
	player_heart.setTexture(heart);


	jombiex.loadFromFile("jombie.png");
	for (i = 0; i < 10; i++)
	{
		jombie[i].setTexture(jombiex);
		jombie[i].setPosition(-1000, -1000);
	}


	cTexture.loadFromFile("c_language.png");
	for (i = 0; i < 3; i++)
	{
		cImage[i].setTexture(cTexture);
		cImage[i].setPosition(600 + cdistance[i], 292);
	}

	cxTexture.loadFromFile("c_language_attack.png");
	for (i = 0; i < 3; i++)
	{
		cxImage[i].setTexture(cxTexture);
		cxImage[i].setPosition(1200, 1200);
	}

	pythontexture.loadFromFile("c++.png");
	for (i = 0; i < 3; i++)
	{
		python[i].setTexture(pythontexture);
		python[i].setPosition(600 + pdistance[i], 292);
	}

	python1texture.loadFromFile("c1++.png");
	for (i = 0; i < 4; i++)
	{
		python1[i].setTexture(python1texture);
		python1[i].setPosition(600 + pdistance[i], 292);
	}

	mulTexture.loadFromFile("multimeter.png");
	for (i = 0; i < 4; i++)
		multi[i].setTexture(mulTexture);

	elect.loadFromFile("electricity.png");
	for (i = 0; i < 11; i++)
	{
		electricity[i].setTexture(elect);
		//electricity[i].setPosition(1000, 1000);

	}


	pstar.loadFromFile("ninja_star222.png");
	for (i = 0; i < 40; i++)
	{
		ninja_star[i].setTexture(pstar);
		ninja_star[i].setPosition(550, -50);
	}




	b2Image.setPosition(800, 0);


	if (!pTexture.loadFromFile("xyz.png"))
		cout << "Error could not load player image" << endl;
	playerImage.setTexture(pTexture);
	playerImage.setPosition(50, 300);

	game_over.loadFromFile("GAME_OVER.png");
	sgame_over.setTexture(game_over);
	sgame_over.setPosition(0, 0);
	tground.loadFromFile("ground.png");
	sground.setTexture(tground);





	tobstacle.loadFromFile("obstacle1.png");

	int t = 0;
	while (t < 16){
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				sobstacle[t].setTexture(tobstacle);
				sobstacle[t].setTextureRect(IntRect(4 + j * 194, 4 + i * 109, 195, 109));
				t++;
			}
		}
	}


	pcoins.loadFromFile("coin.png");
	for (i = 0; i < 50; i++)
		coins[i].setTexture(pcoins);



	font.loadFromFile("naruto.ttf");


	//text.setColor(Color(44, 127, 255));
	text.setStyle(Text::Bold);

	sentence = "Your CGPA is:   ";

	////THE REAL GAME START FROM HERE/////

	long long wait = 1;
	while (window.isOpen())
	{

		Event e;
		while (window.pollEvent(e))
		{

			switch (e.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				if (e.key.code == Keyboard::Up)
				{
					source.y = Jump;  j = 0;
				}
				else if (e.key.code == Keyboard::Down)
				{
					source.y = Slide; s = 0;
				}

				break;

			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
			wait++;



		if (wait % 2 == 0)
		{
			paused.setPosition(500, 200);
			window.draw(paused);
			window.display();
			window.clear();
		}


		if (wait % 2 == 1){
			if (flag == 0){




				window.draw(b1Image);
				b1Image.move(-10, 0);

				window.draw(b2Image);
				b2Image.move(-10, 0);

				window.draw(sground);

				window.draw(building1);
				building1.move(-10, 0);

				window.draw(building2);
				building2.move(-10, 0);







				//////features///////



				if (b1Image.getPosition().x + 800 < 0) b1Image.setPosition(800, 0);
				if (b2Image.getPosition().x + 800 < 0) b2Image.setPosition(800, 0);

				if (building1.getPosition().x < 0) building2.setPosition(building1.getPosition().x + 1100, 450);
				if (building2.getPosition().x < 0)building1.setPosition(building2.getPosition().x + 1100, 450);






				float time = clock.getElapsedTime().asMilliseconds();
				clock.restart();
				timer += time;



				timer2 = clock2.getElapsedTime().asMilliseconds();



				if (life_flag == 1 && timer2 > 500)
				{

					timer2 = 0;
					life_flag = 0;
					distance[sobstacle_index] = -1000;
					lives--;
					if (lives <= 0)
						life_flag = 1;
				}

				if (life_flag == 1)
				{


					if (lives <= 0)
					{

						if (flag3 == 1)
							up1 = up1 - 30;
						if (up1 <= -60) {
							flag4 = 1; flag3 = 0;
						}

						if (flag4 == 1)
							up1 = up1 + 50;

						hit_image.setPosition(playerImage.getPosition().x, 220 + up1);
						window.draw(hit_image);

						GAME_OVER(count);

					}
					else
					{
						hit_image.setPosition(playerImage.getPosition().x - 20, playerImage.getPosition().y - 10);
						window.draw(hit_image);
					}



				}


				player_heart.setTextureRect(IntRect(2, 2, lives * 65, 60));
				window.draw(player_heart);






				///JUMP////
				if (life_flag == 0)
				{
					if (source.y == Jump)
					{
						int  dif = 50;

						playerImage.setTextureRect(IntRect(j * 135, 136, 135, 115));
						if (j == 0) playerImage.setPosition(50, player_height - dif * 1);
						else if (j == 1) playerImage.setPosition(50, player_height - dif * 2);
						else if (j == 2) playerImage.setPosition(50, player_height - dif * 3);
						else if (j == 3) playerImage.setPosition(50, player_height - dif * 2);
						else if (j == 4) playerImage.setPosition(50, player_height - dif * 1);
						else if (j == 5)
							playerImage.setPosition(50, player_height - dif * 0);
						xod -= 20;

						window.draw(playerImage);
						j++;

						if (j >= 6)
						{

							source.x = 0;  source.y = Run;
						}



					}

					/////SLIDE//////
					else if (source.y == Slide)
					{
						playerImage.move(0, 2);
						int x1;
						if (s == 0)
							x1 = 50;
						if (s == 0)
						{
							playerImage.setTextureRect(IntRect(s * 145, 2 * 136, 145, 115));
							playerImage.setPosition(x1, playerImage.getPosition().y - 20);
						}

						else if (s == 4 || s == 5)
						{
							playerImage.setTextureRect(IntRect(s * 145, (2 * 136 + 30), 145, 80));
							playerImage.setPosition(x1, playerImage.getPosition().y + 20);
						}


						else{
							playerImage.setTextureRect(IntRect(s * 145, (2 * 136 + 55), 145, 60));
							playerImage.setPosition(x1, playerImage.getPosition().y + 35);
						}

						xod -= 30;
						window.draw(playerImage);
						s++;
						if (s >= 6)
						{
							source.x = 0;  source.y = Run;
						}
						playerImage.move(0, -2);

					}
					/////RUN////
					else if (source.y == Run){
						source.x++;
						if (source.x >= 6)
							source.x = 0;

						playerImage.setTextureRect(IntRect(source.x * 95, source.y, 95, 90));
						window.draw(playerImage);


					}
					///RUN END////
				}

				////Obstacles moving ////
				if (timer > 50 && !life_flag)
				{
					xod -= 25;
					timer = 0;
				}

				int c = 0;
				for (t = 0; t < 16; t++)
				{
					if (t % 2 == 0)
						sobstacle[t].setPosition(xod + distance[t], 292);
					else
						sobstacle[t].setPosition(xod + distance[t], 220);
					window.draw(sobstacle[t]);

					for (i = 0; i < 3; i++)
					{
						if (t != 7){
							if (t % 2 == 0)
								coins[c].setPosition(xod + distance[t] + i * 65, 220 + coin_sect[c]);
							if (t % 2 == 1)
								coins[c].setPosition(xod + distance[t] + i * 65, 339 + coin_sect[c]);

							window.draw(coins[c]);

							c++;
						}

					}



				}
				sground.setPosition(0, 400);
				if (sobstacle[15].getPosition().x + 196 <= 0)  xod = 600;




				//// Throwing Ninja star/////
				if (Keyboard::isKeyPressed(Keyboard::Space) && life_flag == 0)
				{
					ninja_starflag = 1;
					nsf = 0;
					ninja_star[ns].setPosition(playerImage.getPosition().x, playerImage.getPosition().y);
					ns++;

					if (ns > star_num) ninja_starflag = 0;
				}



				for (i = 0; i < ns && ninja_starflag == 1; i++)
				{
					if (ninja_star[i].getPosition().x - playerImage.getPosition().x < 20 && ninja_star[i].getPosition().x>0)
					{
						knife_effect.setPosition(playerImage.getPosition().x + 15, playerImage.getPosition().y - 10);
						window.draw(knife_effect);
					}
					if (ninja_star[ns - 1].getPosition().x <= 1000)
					{
						ninja_star[i].setTextureRect(IntRect(nsf * 60, 0, 60, 50));
						ninja_star[i].move(40, 0);
						nsf++;
						nsf = nsf % 4;

						window.draw(ninja_star[i]);
					}

				}


				//////throwing fire ball////

				fire_flag_flag.setPosition(xod + distance[7] + 80 + firo, 350);
				window.draw(fire_flag_flag);

				if (isCollide(fire_flag_flag, playerImage))
				{
					fire_flag = 1;
					firo = -9000;
				}


				if (fire_flag == 1){
					if (Keyboard::isKeyPressed(Keyboard::S) && throw_flag == 0 && life_flag == 0)
					{
						throw_flag = 1;
						fire_flag = 0;
						fire_ball.setPosition(playerImage.getPosition().x, playerImage.getPosition().y);
					}

					else if (throw_flag == 0)
					{
						if (flagf == 1)
							upf = upf - 20;
						if (upf <= -80) flagf = 0;

						if (flagf == 0)
							upf = upf + 20;
						if (upf >= 0) flagf = 1;

						fire_ball.setPosition(playerImage.getPosition().x, playerImage.getPosition().y - 180 + upf);
						window.draw(fire_ball);
					}

				}
				if (throw_flag == 1)
				{
					fire_ball.move(40, 0);
					window.draw(fire_ball);
					for (i = 0; i < 16; i++)
					{
						if (isCollide(fire_ball, sobstacle[i]))
						{
							throw_flag = 0;
							fire_ball.setPosition(-999, -888);

						}
					}
				}

				for (i = 0; i < 5; i++)
				{
					if (isCollide(jombie[i], fire_ball))
					{
						flag5[i] = 1;
						crash[i] = 1;
					}

					if (crash[i] == 1){

						if (flag5[i] == 1)
							upj[i] = upj[i] - 30;
						if (upj[i] <= -60) {
							flag6[i] = 1; flag5[i] = 0;
						}

						if (flag6[i] == 1)
							upj[i] = upj[i] + 50;


						jombie[i].setPosition(jombie[i].getPosition().x, 220 + upj[i]);
						window.draw(jombie[i]);


						jombie_flag[i] = 1;
					}

				}


				// C , python, multi, jomibe  Moving and attacking////
				if (flag2 == 1)
					up = up - 30;
				if (up <= -60) flag2 = 0;

				if (flag2 == 0)
					up = up + 30;
				if (up >= 0) flag2 = 1;

				for (i = 0; i < 3; i++)
				{



					if ((cImage[i].getPosition().x - playerImage.getPosition().x) < 500)
					{
						cImage[i].setPosition(-100, -100);
						cxImage[i].setPosition(xod - 30 + cdistance[i], 295 + up);
						cxImage[i].move(-80 - i * 20, 0);
						window.draw(cxImage[i]);

					}
					else{
						cImage[i].setPosition(xod + cdistance[i], 295 + up);
						cImage[i].move(-80 - i * 20, 0);
						window.draw(cImage[i]);
					}

					python[i].setPosition(xod + pdistance[i], 320 + up);
					python[i].move(-80 - i * 20, 0);
					window.draw(python[i]);


					if ((python[i].getPosition().x - playerImage.getPosition().x) < 850)
					{
						python1[i].setTextureRect(IntRect(2 + 55 * pys, 2, 55, 54));
						python1[i].setPosition(xod + p1distance[i] - pyac[i] * 30 + 80, 280);
						window.draw(python1[i]);

						if (pyth[i] == 0)
						{
							python1[i].setPosition(xod + p1distance[i] - pyac[i] * 30, 280);
							window.draw(python1[i]);

						}
						pyac[i]++;
					}

					else
					{
						python1[i].setTextureRect(IntRect(2, 2, 55, 54));
						python1[i].setPosition(xod + p1distance[i] + 40, 350 + up);
						python1[i].move(-80 - i * 20, 0);
						window.draw(python1[i]);

						python1[i].setTextureRect(IntRect(2, 2, 55, 54));
						python1[i].setPosition(xod + p1distance[i] + 130, 350 + up);
						python1[i].move(-80 - i * 20, 0);
						window.draw(python1[i]);
					}




				}


				for (i = 0; i < 5; i++)
				{
					if (jombie_flag[i] == 0){
						jombie[i].setTextureRect(IntRect(2 + 120 * (pys % 3), 2, 120, 105));
						jombie[i].setPosition(xod + jdistance[i], 292);
						window.draw(jombie[i]);
					}
					//-pyac[i] * 10 + 80

				}

				pys++;
				pys = pys % 6;








				for (i = 0; i < 4; i++)
				{
					multi[i].setTextureRect(IntRect(140 * ms + 4, 4, 140, 120));
					multi[i].setPosition(xod + muldistance[i], 292 + up);
					multi[i].move(-80 - i * 20, 0);
					window.draw(multi[i]);
					ms++;
					ms = ms % 3;

					if (multi[i].getPosition().x > 0 && multi[i].getPosition().x < 1200 || electricity[i].getPosition().x>0)
					{
						int mup = -20, mdown = 30;
						if (i % 2 == 0)   {
							mup = 70; mdown = 30;
						}

						electricity[i].setPosition(xod + mul1distance[i] - mx[i] * mdown, 292 + mup);
						window.draw(electricity[i]);
						mx[i]++;
					}
				}




				///// c , python, obstacles are getting attacked ////

				int stari, cj;

				for (i = 0; i < 40; i++)
				{

					cj = attack(ninja_star[i]);
					if (cj == 1)
						ninja_star[i].setPosition(-400, -100);

				}











				///Ground and train checking  and game over////
				int k, x1, y1, r1, r2, m1;
				for (k = 0; k < 16; k++)
				{
					x1 = playerImage.getPosition().x + 95;
					y1 = playerImage.getPosition().y;
					r1 = sobstacle[k].getPosition().x;
					r2 = sobstacle[k].getPosition().x + 130;
					m1 = sobstacle[k].getPosition().y;




					if (x1 >= r1 - 10 && playerImage.getPosition().x <= r2 && m1 - y1 >= 88)// here i have debugged from game over
					{
						if (jump_flag == 0){
							playerImage.setPosition(50, m1 - 95);
							source.y = Run;
							jump_flag = 1;
						}

						player_height = 300 - 100;
						break;

					}


					if (x1 >= r1 + 15 && playerImage.getPosition().x <= r2 && (m1 + 100 > y1) && life_flag == 0)
					{


						life_flag = 1;
						clock2.restart();
						sobstacle_index = k;


					}


				}


				for (i = 0; i < 5; i++)
				{
					if (isCollide(playerImage, jombie[i]))
					{
						jombie[i].setPosition(-1000, 0);
						jdistance[i] = -2500;
						life_flag = 1;
						clock2.restart();
					}
				}

				for (i = 0; i < 3; i++)
				{
					if (isCollide(playerImage, cxImage[i]))
					{

						cxImage[i].setPosition(-1000, 0);
						cdistance[i] = -1000;
						life_flag = 1;
						clock2.restart();
					}

					if (isCollide(python[i], playerImage))
					{
						python[i].setPosition(-1000, 0);
						pdistance[i] = -1000;
						life_flag = 1;
						clock2.restart();
					}

					if (isCollide(python1[i], playerImage))
					{
						p1distance[i] = -1000;
						life_flag = 1;
						clock2.restart();
					}

				}

				for (i = 0; i < 4; i++)
				{
					if (isCollide(playerImage, multi[i]))
					{
						muldistance[i] = -1000;
						life_flag = 1;
						clock2.restart();
					}

					if (isCollide(playerImage, electricity[i]))
					{

						cout << playerImage.getPosition().x + 95 - electricity[i].getPosition().x << endl;
						if (playerImage.getPosition().x + 95 - electricity[i].getPosition().x > 30 && playerImage.getPosition().x + 95 - electricity[i].getPosition().x < 95)
						{
							mul1distance[i] = -1000;
							life_flag = 1;
							clock2.restart();
						}
					}

				}





				if (k == 16) {
					jump_flag = 0;
					playerImage.setPosition(playerImage.getPosition().x, sground.getPosition().y - 95);
					player_height = 300;
				}
				if (playerImage.getPosition().x > 50) playerImage.move(-15, 0);





				//// Intersection checking with player and good things happen////
				for (i = 0; i < 50; i++)
				{
					if (isCollide(playerImage, coins[i]) == 1)
					{
						coin_sect[i] = -1000;
						count++;
						int count1 = count;


					}

				}


				if (sobstacle[9].getPosition().x < 0)
				{
					xod += 25;
					playerImage.move(55, 0);
					if (playerImage.getPosition().x > 1300)
						window.close();

				}


				float starting_pause = begin_clock.getElapsedTime().asSeconds();


				text_begin.setPosition(400, 200);
				if (starting_pause <= 2)
					text_begin.setString("First year in CSEDU");

				else if (starting_pause <= 3){
					text_begin.setString("1");
					text_begin.setPosition(500, 200);
				}


				else if (starting_pause <= 4)
				{
					text_begin.setString("2");
					text_begin.setPosition(500, 200);
				}

				else if (starting_pause <= 5)
				{
					text_begin.setString("3");
					text_begin.setPosition(500, 200);
				}

				else if (starting_pause <= 6 && starting_pause<7)
					text_begin.setString("Go!! Go!! Go!!");
				else text_begin.setPosition(-100, -100);


				if (playerImage.getPosition().x > 60)
				{

					text_begin.setPosition(500, 200);
					text_begin.setString("1st!!year!!Passed");
					window.draw(text_begin);


					GAME_OVER(count);

				}




				window.draw(text_begin);
				window.display();
				window.clear();

			}  ////flag ending bracket

		} /// wait ending bracket

	}
}


