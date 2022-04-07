#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_video.h>
#include "Fonctions/image.h"
#include "Fonctions/text.h"
#include "Fonctions/son.h"
int main()
{
	if (SDL_Init(SDL_INIT_EVERYTHING)!=0)
		{
			printf("error ! %s",SDL_GetError());
		}
	TTF_Init();
	//Inisialisation des variables 
	int exit=1;
	int f=50;
	int play=0;
	int option=0;
	int game_end=0;
	int text_zone=-1;
	int i=0;
	int x_mouse,y_mouse;
	Text t;
	Mix_Music *music;
	Mix_Chunk *son = NULL ;
	image  back,background_option,background,background_2,new_game_1,new_game_2,option_1,option_2,resume_1,resume_2,exit_1,exit_2;
	SDL_Surface *screen,*screen2;
	SDL_Event event;
	//creating window
	screen=SDL_SetVideoMode(900,514,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
	if(screen==NULL)
		{
			printf("error ! %s",SDL_GetError());
		}
	init_bg(&background,"Images/menu1.jpg");
	init_bg(&background_2,"Images/img-1.png");
	init_bg(&background_option,"Images/backgroind-option.jpg");
	init_boutton(&new_game_1,"Images/start1.png",4,230);
	init_boutton(&option_1,"Images/settings1.png",4,280);
	init_boutton(&resume_1,"Images/credits1.png",4,330);
	init_boutton(&exit_1,"Images/quit1.png",4,380);
	init_boutton(&new_game_2,"Images/start2.png",4,230);
	init_boutton(&option_2,"Images/settings2.png",4,280);
	init_boutton(&resume_2,"Images/credits2.png",4,330);
	init_boutton(&exit_2,"Images/quit2.png",4,380);
	//initText(&t,150,200);
	son_continue("Son/music.mp3",music);
	display_image(background,screen);
	display_image(new_game_1,screen);
	display_image(option_1,screen);
	display_image(resume_1,screen);
	display_image(exit_1,screen);
	SDL_Flip(screen);
	while(game_end==0)
		{
			//last_val = i;
			SDL_PollEvent(&event);
			switch(event.type)
				{	
					case SDL_KEYDOWN :
						switch(event.key.keysym.sym) 
						{
						 
                                                case SDL_QUIT:
                                                     game_end = 0;
                                                      SDL_Quit();
                                                       break;
							
								case SDLK_DOWN	:
									if (i<4)
										i++;
									else
										i=1;
								break;
								case SDLK_UP :
									if (i>1)
										i--;
									else
										i=4;
								break;
								case SDLK_RETURN : 
										if(i==1){
								
										
												
										play=1;
										}
							
									if(i==2)
										{
									
											
										
						                           option=1;
						                           break;
						                           }
						                 
								
								case SDLK_ESCAPE : 
											
													game_end=1;
													i=-1;
													
												    
								break;
								   case SDLK_KP_MINUS:
                                                                           f=f-10;
                                                                          Mix_VolumeMusic(f);
                                                                        
                                                                    break;
                                                                    case SDLK_KP_PLUS:
                                                                          f=f+10;
                                                                          Mix_VolumeMusic(f);
                                                                       
                                                                         break;
                                                                         case SDLK_h:      
                                                                     Mix_HaltMusic();
                 
                                                                         break;
								   
								case SDLK_j:
                                                               son_continue("Son/music.mp3",music);
 
                                                                break;
                                                                case SDLK_f:
while(exit)
{SDL_WM_ToggleFullScreen(screen); 
if((event.type==SDL_KEYDOWN)&&(event.key.keysym.sym==SDLK_f))
{
exit=0;
}
}
game_end;
break;
case SDLK_r:
screen=SDL_SetVideoMode(900,514,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
game_end;

break;
								
							         }
									SDL_WaitEvent(&event);
									switch (i)
										{
											case 1 : 
												son_bref("Son/running.wav",son);
												display_image(new_game_2,screen);
												display_image(resume_1,screen);
												display_image(option_1,screen);
												display_image(exit_1,screen);
												SDL_Flip(screen);
												
												
												
											break;
											case 2 :
											
												son_bref("Son/running.wav",son);
												display_image(new_game_1,screen);
												display_image(option_2,screen);
												display_image(resume_1,screen);
										                display_image(exit_1,screen);
												SDL_Flip(screen);
												
											break;
											case 3 :
												son_bref("Son/running.wav",son);
												display_image(new_game_1,screen);
												display_image(option_1,screen);
												display_image(resume_2,screen);
												display_image(exit_1,screen);
												SDL_Flip(screen);
											break;
											case 4 :
												son_bref("Son/running.wav",son);
												display_image(new_game_1,screen);
												display_image(resume_1,screen);
												display_image(option_1,screen);
												display_image(exit_2,screen);
												SDL_Flip(screen);
											break;
										}
					break;
				  case SDL_MOUSEMOTION : 
						SDL_WaitEvent(&event);
						x_mouse=event.button.x;
						y_mouse=event.button.y;
						if((event.button.button==SDL_BUTTON_LEFT)&&(x_mouse>4 && x_mouse<204)&&(y_mouse>=230 && y_mouse<=275))
							{
								play=1;
							}
						 else if((event.button.button==SDL_BUTTON_LEFT)&&(x_mouse>=4 && x_mouse<=204)&&(y_mouse>=280 && y_mouse<=300))
							{
								option=1;
							}
						 else if((event.button.button==SDL_BUTTON_LEFT)&&(x_mouse>=4 && x_mouse<=204)&&(y_mouse>=330 && y_mouse<=385))
							{
								son_bref("Son/running.wav",son);
								display_image(new_game_1,screen);
								display_image(resume_2,screen);
								display_image(option_1,screen);
								display_image(exit_1,screen);
								SDL_Flip(screen);
							}
						 else if((event.button.button==SDL_BUTTON_LEFT)&&(x_mouse>=4 && x_mouse<=204)&&(y_mouse>=390 && y_mouse<=445))
							{
								son_bref("Son/running.wav",son);
								display_image(new_game_1,screen);
								display_image(resume_1,screen);
								display_image(option_1,screen);
								display_image(exit_2,screen);
								SDL_Flip(screen);
								game_end=1;
								
							}
						else
							{
								
								display_image(new_game_1,screen);
								display_image(resume_1,screen);
								display_image(option_1,screen);
								display_image(exit_1,screen);
								SDL_Flip(screen);
							}
					break;
				}
				while(option==1){
				SDL_SetVideoMode(900,516,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
				son_bref("Son/running.wav",son);
				display_image(option_2,screen);
			        display_image(background_option,screen);
			      
			       SDL_Flip(screen);
			      
			      }
			       while(play==1){
			       son_bref("Son/running.wav",son);
			       display_image(new_game_2,screen);
                              display_image(background_2,screen);
                             
			       SDL_Flip(screen);
                        	
                        	
				
			       }
			        
		} 
	libere_image(background);
	libere_image(new_game_1);
	libere_image(new_game_2);
	libere_image(exit_2);
	SDL_Quit();
	return 0;
	}
