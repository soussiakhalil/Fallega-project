#ifndef IMAGE_H
#define IMAGE_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
typedef struct {
        SDL_Rect place_on_screen,img_size;
        SDL_Surface *img_url;
}image;
void init_bg(image *backgroud,char *name);
void init_boutton(image *background,char *name,int x,int y);
void display_image(image background,SDL_Surface *screen);
void libere_image(image background);
#endif
