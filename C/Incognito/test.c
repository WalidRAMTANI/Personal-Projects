#include <SDL2/SDL.h>
#include<stdio.h>
#include<stdlib.h>
#include <math.h>

// Function that draws a circle
void drawFilledCircle(SDL_Renderer *renderer, int centerX, int centerY, int radius) {
    /*
        a function who draws a filled circle, it takes the renderer, the coordinate of the center of the circle
            and the radius
    */
    for (int y = -radius; y <= radius; y++) {
        // calculate dx
        int dx = (int)sqrt(radius * radius - y * y);
        SDL_RenderDrawLine(renderer, centerX - dx, centerY + y, centerX + dx, centerY + y);
    }
}


#define TAILLE 5

void display_grid(int grid[TAILLE][TAILLE], SDL_Renderer *renderer){
    /*
        Display the a grid on terminal
        parametres :  a matrix of (Pion)
        return : void
    */
    int i, j;
    int case_taille = 100;
    for(i = 0; i < TAILLE; i++){
        printf("---------------------------------------------------------------------\n");
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(renderer, 0, i*case_taille, TAILLE * case_taille, i*case_taille);
        SDL_RenderDrawLine(renderer, i*case_taille, 0, i*case_taille, TAILLE * case_taille);
        for(j = 0; j < TAILLE; j++){
            if(grid[i][j] == 1){
                SDL_GetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
                drawFilledCircle(renderer, i*case_taille + 50, j*case_taille + 50, 50);
                printf("   |b|   ");
            }
            else if(grid[i][j] == 0){
                SDL_GetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
                drawFilledCircle(renderer, i*case_taille + 50, j*case_taille + 50, 50);

                printf("   |n|   ");
            }else{
                printf("   | |   ");
            }
        }
        printf("\n");
    }
    printf("---------------------------------------------------------------------\n");
}

int main(int argc, char* argv[]) {
    
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        SDL_Log("Problem while intialisation \n", SDL_GetError());
        SDL_Quit();
    }
    SDL_Window* window = NULL;
    SDL_Renderer* renderer= NULL;
    window = SDL_CreateWindow("INCOGNITO", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, TAILLE * 100, TAILLE * 100, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // RED
    int grid[][5] = {
        {1, 2, 0, 0, 0}, {1, 2, 0, 0, 0}, {1, 2, 0, 0, 0}, {1, 2, 0, 0, 0}, {1, 2, 0, 0, 0}
    };
    display_grid(grid, renderer);
    SDL_RenderPresent(renderer); // Mettre à jour l'écran

    SDL_Delay(5000); // Pause de 5 secondes

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
