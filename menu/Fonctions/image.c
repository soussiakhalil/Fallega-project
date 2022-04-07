#include "image.h"
void init_bg(image *background,char *name)
{
   background->img_url=IMG_Load(name);
   if(background->img_url==NULL)
   {
   printf("cannot load image");
   return ;
   }
   background->place_on_screen.x=0;
   background->place_on_screen.y=0;
   background->img_size.w=background->img_url->w;
   background->img_size.h=background->img_url->h;
   background->img_size.x=0;
   background->img_size.y=0;
    
   
}
void init_boutton(image *background,char *name,int x,int y)
{
background->img_url=IMG_Load(name);
   if(background->img_url==NULL)
   {
   printf("cannot load image");
   return ;
   }
   background->place_on_screen.x=x;
   background->place_on_screen.y=y;
   background->img_size.w=background->img_url->w;
   background->img_size.h=background->img_url->h;
   background->img_size.x=0;
   background->img_size.y=0;


}
void display_image(image background,SDL_Surface *screen)
{
 SDL_BlitSurface(background.img_url,&background.img_size,screen,&background.place_on_screen);
}
void libere_image(image background)
{
 SDL_FreeSurface(background.img_url);
}
