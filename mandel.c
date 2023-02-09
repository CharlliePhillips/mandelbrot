#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <SDL2/SDL.h>
int main(){
    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;

    int res = 3500;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(res,res,0,&window,&renderer);

    double complex z = 0;
    //char out[res][res];

    /*for(int i = 0; i < res; i++){
        for(int j = 0; j < res; j++){
            out[i][j] = ' ';
        }
    }*/
    for(double x = -2; x <= 2; x += .001){
        //printf("y iteration: %f\n",i);
        for(double y = -2; y <= 2; y += .001){
            z = 0;

            //printf("%f, ",x);
            //printf("%f",y);
            //printf("\n");
            int outX = (int)(res*(x));
            int outY = (int)(res*(y));
            outX = outX + res*2;
            outY = outY + res*2;
            outX = outX / 4;
            outY = outY / 4;
            if(outX > res){outX = res;}
            if(outY > res){outX = res;}
            if(outX < 0){outY = 0;}
            if(outY < 0){outY = 0;}
            for(int k = 0; k < 100; k++){
                z = z*z + x+y*I;
                if(cabs(z) > 2){
                    if(k < 10){SDL_SetRenderDrawColor(renderer,0,0,0,0);}
                    if(k > 10 && k < 20){SDL_SetRenderDrawColor(renderer,255,0,0,255);}
                    if(k > 20 && k < 30){SDL_SetRenderDrawColor(renderer,255,120,0,255);}
                    if(k > 30 && k < 40){SDL_SetRenderDrawColor(renderer,255,255,0,255);}
                    if(k > 40 && k < 50){SDL_SetRenderDrawColor(renderer,0,255,0,255);}
                    if(k > 50 && k < 60){SDL_SetRenderDrawColor(renderer,0,255,255,255);}
                    if(k > 60 && k < 70){SDL_SetRenderDrawColor(renderer,0,0,255,255);}
                    if(k > 70 && k < 80){SDL_SetRenderDrawColor(renderer,150,0,255,255);}
                    if(k > 80 && k < 90){SDL_SetRenderDrawColor(renderer,255,0,255,255);}
                    if(k > 90){SDL_SetRenderDrawColor(renderer,54,36,0,255);}
                    SDL_RenderDrawPoint(renderer,outX,outY);
                    //SDL_RenderPresent(renderer);
                    k = 100;
                }
            }
            if(cabs(z) < 2){
                    //printf("%f\n at: ",z);
                    
                    //out[outY][outX] = 'X';
                    SDL_SetRenderDrawColor(renderer,255,255,255,255);
                    SDL_RenderDrawPoint(renderer,outX,outY);
                    SDL_RenderPresent(renderer);
            }
        }
    }
    while (1) {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}