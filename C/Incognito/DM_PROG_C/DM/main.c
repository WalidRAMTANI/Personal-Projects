#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <SDL2/SDL.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define TAILLE 5
#define N  ((TAILLE - 1) * (TAILLE - 2) / 2 - 1)
#define taille_case 100

typedef enum _couleur {
    BLANC, 
    NOIR
    } Couleur;


typedef enum _type{
    CHEVALIER, 
    ESPION
    } Type; 


typedef struct _pion {
    Type type ;
    Couleur couleur ;
} Pion ;


typedef struct {
    int x , y ;
} Case , Direction; 


typedef struct _jeu {
    Pion *plateau [ TAILLE ] [ TAILLE ] ;
    Couleur joueur ;
} Jeu ;


typedef struct _mouvement {
    Case depart;
    Case arrivee;
} Mouvement;




void implement_grid(Pion *grid[TAILLE][TAILLE],  Case espion_w, Case espion_b){
    /*
        Initialises the starting grid with each team's pieces

        Parameters: 
            a matrix of Pion, 
            the coordinate of the white spy, 
            the coordinate of the black spy

        Returns:
            void
    */
    int i = 0, j = 0;
    // taille_temp is the number of lines that we need to fill up N+1 values
    int taille_temp = TAILLE - (-1 + sqrt(1+ 8 * (N+1))) / 2;
    // declare two variables which refers to the spys
    for(i = 0; i < TAILLE; i++){
        for(j = 0; j < TAILLE; j++){
            // initialise the spy and the knights of the white player
            if(i <= taille_temp && j >= taille_temp + i && j - i < TAILLE - 1){
                // see if the current case is a spy
                if(espion_b.x == i && espion_b.y == j){
                    Pion p1 = {ESPION, NOIR};
                    grid[i][j] = malloc(sizeof(Pion));
                    *grid[i][j] = p1;
                    // add the coordinates to the file
                    // fprintf(incognito, "B %c%d\n", table_charac[j], i + 1);
                
                }
                // the case is a knight
                else{
                    Pion p1 = {CHEVALIER, NOIR};
                    grid[i][j] = malloc(sizeof(Pion));

                    *grid[i][j] = p1;
                }

            }else
                // initialise the spy and the knights of the black player
                if(i >= taille_temp && i - j >= taille_temp && i - j < TAILLE - 1){
                    if(espion_w.x == i && espion_w.y == j){
                        Pion p1 = {ESPION, BLANC};
                        grid[i][j] = malloc(sizeof(Pion));
                        *grid[i][j] = p1;
                        // add the coordinates to the file
                        // fprintf(incognito, "N %c%d\n", table_charac[j], i+1);
                    }
                // the case is a knight
                    else{
                        Pion p1 = {CHEVALIER, BLANC};
                        grid[i][j] = malloc(sizeof(Pion));
                        *grid[i][j] = p1;
                    }
                }
                // the case(box) is NULL
                else{
                    grid[i][j] = NULL;
                }

        }
    }

}



void draw_filled_circle(SDL_Renderer *renderer, int centerX, int centerY, int radius) {
    /*
        Draws a filled circle on the SDL window

        Parameters: 
            SDL_Renderer,
            x coordinate of the center,
            y coordinate of the center,
            radius of the circle

        Returns: 
            void
    */
    for (int y = -radius; y <= radius; y++) {
        // calculate dx
        int dx = (int)sqrt(radius * radius - y * y);
        SDL_RenderDrawLine(renderer, centerX - dx, centerY + y, centerX + dx, centerY + y);
    }
}

void display_grid_graph(Pion *grid[TAILLE][TAILLE], SDL_Renderer *renderer) {
    /*
        Displays a grid and pieces on the SDL window

        Parameters: 
            a matrix of Pion and SDL_Renderer

        Returns: 
            void
    */
    
    SDL_Surface *castle = SDL_LoadBMP("DM/castle.bmp"); // Load the image
    if (!castle) {
        printf("Issue loading the image: %s\n", SDL_GetError());
        return;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, castle);
    SDL_FreeSurface(castle);  // Free the surface after creating the texture

    if (!texture) {
        printf("Failed to create texture from surface: %s\n", SDL_GetError());
        return;
    }

    SDL_Rect rect_castle1 = { taille_case * (TAILLE - 1), 0, taille_case, taille_case };
    SDL_Rect rect_castle2 = { 0, taille_case * (TAILLE - 1), taille_case, taille_case };
    SDL_SetRenderDrawColor(renderer, 0, 165, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    for (int i = 0; i < TAILLE; i++) {
        // Draw grid lines
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(renderer, 0, i * taille_case, TAILLE * taille_case, i * taille_case);
        SDL_RenderDrawLine(renderer, i * taille_case, 0, i * taille_case, TAILLE * taille_case);

        for (int j = 0; j < TAILLE; j++) {
            // Draw the pieces
            if (grid[i][j]) {
                if (grid[i][j]->couleur == BLANC) {
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                } else if (grid[i][j]->couleur == NOIR) {
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                }
                draw_filled_circle(renderer, j * taille_case + taille_case / 2, i * taille_case + taille_case / 2, taille_case / 2);
            }
        }
    }

    SDL_RenderCopy(renderer, texture, NULL, &rect_castle1);  // Draw the texture 
    SDL_RenderCopy(renderer, texture, NULL, &rect_castle2);  // Draw the texture 
    SDL_RenderPresent(renderer);  // Show everything on the screen

    SDL_DestroyTexture(texture);  // Free the texture at 
}




void display_grid(Pion *grid[TAILLE][TAILLE]){
    /*
        Displays the grid in the terminal

        Parameters: 
            a matrix of Pion

        Returns: 
            void
    */
    int i, j;
    for(i = 0; i < TAILLE; i++){
        printf("---------------------------------------------------------------------\n");
        for(j = 0; j < TAILLE; j++){
            if(grid[i][j] && grid[i][j]->couleur == BLANC){
                printf("   |b|   ");
            }
            else if(grid[i][j] && grid[i][j]->couleur == NOIR){
                printf("   |n|   ");
            }else{
                printf("   | |   ");
            }
        }
        printf("\n");
    }
    printf("---------------------------------------------------------------------\n");
}



int move_piece(Pion *grid[TAILLE][TAILLE], Mouvement move, Couleur player){
    /*
        Moves a piece from one box to another

        Parameters: 
            a matrix of Pion,
            a Mouvement, 
            the current player

        Returns:
            0: when the move is successful
            1: when there are pawns blocking the way
            2: when the player tries to move a pawn to his own castle
            3: when the player tries to move a piece that is not his
            4: when the player tries to move an empty box
            -1: when the move is not allowed
    */
    int i = 0, can_move=-1;
    int step_x, step_y;
    // check if the selected case is valid
    if(grid[move.depart.x][move.depart.y] == NULL) return 4;
    // check if we didn't choose to go to our castle
    if((player == 1 && move.arrivee.x == 0 && move.arrivee.y == TAILLE - 1) || (player == 0 && move.arrivee.x == TAILLE - 1 && move.arrivee.y == 0)) return 2;
    // check if the selected case is the player pion
    if(grid[move.depart.x][move.depart.y]->couleur == player){
        if(move.depart.x >= move.arrivee.x){
            step_x = -1;
        }else{
            step_x = 1;
        }
        if(move.depart.y >= move.arrivee.y){
            step_y = -1;
        }else{
            step_y = 1;
        }
        // it means our two points are in the same line
        if(move.depart.x == move.arrivee.x){
            for(i = 1; i <= abs(move.depart.y - move.arrivee.y); i++){
                    if(grid[move.depart.x][move.depart.y + i*step_y] != NULL){
                            return 1;
                        }
            }
            can_move = 0;
                // it means our two points are in the same column
        }else if(move.depart.y == move.arrivee.y){
                for(i = 1; i <= abs(move.depart.x - move.arrivee.x); i++){
                    if(grid[move.depart.x + i * step_x][move.depart.y] != NULL){
                            return 1;
                        }
                }
                can_move = 0;
                // it means our two points make a diagonale
            }else if(abs(move.depart.x - move.arrivee.x) == abs(move.depart.y - move.arrivee.y)){
                for(i = 1; i <= abs(move.depart.x - move.arrivee.x); i++){
                    if(grid[move.depart.x + i * step_x][move.depart.y + i*step_y] != NULL){
                            return 1;
                        }
                    }
                
                can_move = 0;
                }
            if(grid[move.depart.x][move.depart.y] != NULL && can_move == 0){
                return 0;
            }else{
                return -1;
            }

    }
    else{
        return 3;
    }
}




int interrogate_piece(Pion *grid[TAILLE][TAILLE], Couleur player, Case interrogator, Direction questioned){
    /*
        Interrogates a piece

        Parameters: 
            a matrix of Pion (the grid),
            the current player, 
            the coordinate of the interrogator, 
            the direction of the questioned piece

        Returns:
            0: when the current player (a knight) interrogates another knight
            1: when the two cases are not adjacent
            -1: when the current player interrogates a spy
            -2: when the current player interrogates a knight with his spy
            3: when it is not the right player
            4: when the two cases are not valid
    */

    // check if the selected cases are valid
    if(grid[interrogator.x][interrogator.y] != NULL && grid[questioned.x][questioned.y] != NULL){
        // check if the selected cases are adjacents
        if((abs(interrogator.x - questioned.x) == 1 && interrogator.y == questioned.y) || (abs(interrogator.y - questioned.y) == 1 && interrogator.x == questioned.x)){
            // check if the player the choose the wrong pion
            if(grid[interrogator.x][interrogator.y]->couleur == player && grid[questioned.x][questioned.y]->couleur != player){
                // check if the enemy's pawn is a knight or a spy
                // KNIGHT VS KNIGHT
                if(grid[questioned.x][questioned.y]->type == CHEVALIER && grid[interrogator.x][interrogator.y]->type == CHEVALIER){
                    grid[interrogator.x][interrogator.y] = NULL;
                    return 0;
                }
                // KNIGHT || SPY VS SPY
                else if(grid[questioned.x][questioned.y]->type == ESPION){
                    grid[questioned.x][questioned.y] = NULL;
                    // à modifier
                    // gagnant
                    return -1;

                }
                // SPY VS KNIGHT
                else if(grid[questioned.x][questioned.y]->type == CHEVALIER && grid[interrogator.x][interrogator.y]->type == ESPION){
                    // gagnant
                    grid[interrogator.x][interrogator.y] = NULL;
                    return -2;
                }
            }else{
                // it is not the right player
                return 3;
            }
        }else{
            // the selected cases are not adjascent
            return 1;
        }
    }else{
        // the selected cases are not valid
        return 4;
    }
    // we do a return to avoid warnings
    return 0;
}




int decide_in_castle(Pion *grid[TAILLE][TAILLE] , Mouvement move, Couleur player){
    /*
        Checks if a player tries to move a piece to a castle

        Parameters: 
            a matrix of Pion (the grid),
            the current player, 
            the coordinate of the move

        Returns:
            0: when the player tries to move a piece to a castle in the orthogonale way or when the pawn is not moving to a castle
            1: when the player tries to move a piece to a castle but not in the orthogonale way
    */
    // check the player playing
    if(player == 1){
        // check if the boxe we want to go is the castle
        if(move.arrivee.x == TAILLE - 1 && move.arrivee.y == 0){
            // check if we access to the boxe in an orthogonale way
            if(move.depart.x == move.arrivee.x || move.depart.y == move.arrivee.y){
                return 0;
            }
            return 1;

        }
    }
    else if(player == 0){
        // check if the boxe we want to go is the castle
        if(move.arrivee.x == 0 && move.arrivee.y == TAILLE - 1){
            // check if we access to the boxe in an orthogonale way
            if(move.depart.x == move.arrivee.x || move.depart.y == move.arrivee.y){
                return 0;
            }
            return 1;

        }

    }
    return 0;
}


int is_win(Pion *grid[TAILLE][TAILLE], Mouvement move, Couleur player){
    /*
        Checks if a player has won the game

        Parameters: 
            a matrix of Pion (the grid),
            the current player, 
            the coordinate of the move

        Returns:
            0: the player has entered a castle with a spy
            1: when the player has just made a normal move (not entering a castle)
            2: when the player has moved a knight to a castle
    */
    if (player == 0){
        if(move.arrivee.x == 0 && move.arrivee.y == TAILLE - 1){
            // check if the boxe is a spy
            if(grid[move.depart.x][move.depart.y]->type == ESPION) return 0;
            return 2;
        }
    }else{
        if(move.arrivee.x == TAILLE - 1 && move.arrivee.y == 0){
            // check if the boxe is a spy
            if(grid[move.depart.x][move.depart.y]->type == ESPION) return 0;
            return 2;
        }
    }
    return 1;
}



void fill_table(char table_charac[TAILLE]){
    /*
        Fills a table of letters from a to (a + TAILLE - 1)

        Parameters:
            a table of letters (its size is equal to TAILLE)

        Returns:
            void
    */
    for(int i = 0; i < TAILLE ; i++){
        table_charac[i] = (char)(i + 97);
    }
}

int search_in_table_char(char table_char[TAILLE], char c){
    /*
        Returns the index of a letter given by the variable c in the table of letters

        Parameters: 
            table of letters, 
            a letter

        Returns:
            the index of the letter in the table
    */
    for(int i = 0; i< TAILLE; i++){
        if(table_char[i] == c){
            return i;
        }
    }
    return 1;
}

void update_player(char *p, Couleur player){
    /*
        Gives the letter of the player

        Parameters: 
            a pointer to a character, 
            the current player

        Returns:
            void
    */
    if(player == 0){
        *p = 'B';
    }else{
        *p = 'N';
    }
}



void read_file(FILE *incognito, Jeu *game, char table_char[TAILLE]){
    /*
        Reads a file (game progress) and executes the the movements given by the information in the file

        Parameters: 
            a FILE, 
            a Jeu, 
            a table of letters

        Returns:
            void
    */

    // declare a variable player which is a character from the FILE, choice : 'D' || 'I', c1, c2 temporary character
    char player, choice, c1, c2;
    // declare a variable gamer which's value is the color of the player
    char gamer[10];
    // declare a variable that indicates to us if we're in a castle, and another one which indicates if we succeded moving
    int move_castle, error;
    // declare a move
    Mouvement move;
    // retrieve the first player from the FILE
    fscanf(incognito, "%c\n", &player);
    if(player ==  'B'){
        game->joueur = BLANC;
    }else{
        game->joueur = NOIR;
    }

    if(game->joueur == 0) strcpy(gamer, "White");
    else strcpy(gamer, "Black");

    // loop which stops at the of the FILE
    while (fscanf(incognito, "%c %c%d->%c%d\n", &choice, &c1, &move.depart.x, &c2, &move.arrivee.x) != EOF)
    {
        // move.depart.x is the line of the box depart we do -1 because we start at 1
        move.depart.x --;
        // move.arrivee.x is the line of the box arrivee we do -1 because we start at 1
        move.arrivee.x --;
        // convert the letter of the column of the box to a number
        move.depart.y = search_in_table_char(table_char, c1);
        move.arrivee.y = search_in_table_char(table_char, c2);
        // if the choice was deplacement
        if(choice == 'D'){        
            // check if we're inside a castle
            move_castle = decide_in_castle(game->plateau, move, game->joueur);
                // we're not inside a castle
                if(move_castle == 0){
                    // try to move a box
                    error = move_piece(game->plateau, move, game->joueur);
                    switch (error)
                    {
                    // we succeded
                    case 0:
                    // check if we won or not
                        move_castle = is_win(game->plateau, move, game->joueur);
                        // we won
                        if(move_castle == 0){
                            printf("Bravo, Winner is : %s\n", gamer);
                            fclose(incognito);
                        // the pawn was a knight
                        }else if(move_castle == 2){
                            printf("The questionned pawn is not the spy so your own pawn got poisoned...\n");
                            game->plateau[move.depart.x][move.depart.y] = NULL;
                        }
                        // make the move by changing the coordinate
                        game->plateau[move.arrivee.x][move.arrivee.y] = game->plateau[move.depart.x][move.depart.y];
                        game->plateau[move.depart.x][move.depart.y] = NULL;
                        printf("Player %s, your move is executed..\n", gamer);
                        break;
                    case 1:
                        printf("Illegal move: there are squares that block it.\n");
                        break;
                    case 2:
                        printf("Illegal move: a player cannot bring a pawn to his castle.\n");
                        break;
                    case 3:
                        printf("Illegal move: the selected pawn is not yours.\n");
                        break;
                    case 4:
                        printf("Illegal move: the box is empty\n");
                        break;
                    default:
                        printf("This move is not tolerated.\n");
                        break;
                    }
                }
                else{
                    printf("This move is not tolerated\n");
                    error = 1;
                }
        }
        // if choice is Interrogation
        else if(choice == 'I'){
                // make an interrogation
                error = interrogate_piece(game->plateau, game->joueur, move.depart, move.arrivee);
                //display something depending on the result of the interrogation
                switch (error)
                {
                    // interrogation succeded
                case 0:
                    printf("%s player, you didn't find your opponent's spy...\nAnd on top of that, your knight got poisoned... \n", gamer);
                    break;
                case 1:
                    printf("Interrogation not tolerated because the cases are not adjascent.\n");
                    break;
                // interrogated a spy so won
                case -1:
                    printf("%s player, you interrogated a spy...\n", gamer);
                    printf("Bravo, Winner is : %s\n", gamer);
                    fclose(incognito);
                    break;
                // interrogated a knight with your spy so you lose
                case -2:
                    printf("%s player, you interrogated a knight with your spy...\n", gamer);
                    printf("Bravo, Winner is : %s\n", (game->joueur == 0)?"Black": "White");
                    fclose(incognito);
                    break;
                case 3:
                    printf("Interrogation not tolerated : the player selectionned the wrong pawn.\n");
                    break;
                case 4:
                    printf("Interogation not tolerated because the two cases are empty.\n");
                    break;
                default:
                    printf("The move is not tolerated.\n");
                    break;
                }
            }
            // check if the move is valid then we give the turn to the other player
            if(error == 0){
                game->joueur = (game->joueur + 1)%2;
                if(game->joueur ==  0){
                    strcpy(gamer, "White");
                }else{
                    strcpy(gamer, "Black");
                
            }   
            }

    }
}   

int main(int argc, char **argv){
    // declare terminal variables
    // the file w'll construct
    FILE *incoginito_write  = NULL;
    // the file w'll read
    FILE *incoginito_read = NULL;
    // variable that means w'll do a graphic display
    int *graphic_display = NULL;
    // variable that means w'll do a ascii display
    int *ascii_display = NULL;
    // declare the window and container
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    
    // check the argument typed on the terminal
    for(int i = 0; i < argc; i++){
        // case of the ascii display
        if(strcmp(argv[i], "-a") == 0){ 
            ascii_display = malloc(sizeof(int));
            *ascii_display = 1;

        // case of the graphic display
        }else if(strcmp(argv[i], "-g") == 0){
            graphic_display = malloc(sizeof(int));
            *graphic_display = 1;
            // initialise the sdl window
            SDL_Init(SDL_INIT_VIDEO);
            // create the window
            window = SDL_CreateWindow("INCOGNITO", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, TAILLE * taille_case, TAILLE * taille_case, 0);
            // create the renderer
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

            // case of file saving
        }else if(strcmp(argv[i], "-s") == 0){
            incoginito_write = fopen(*(argv + i + 1), "w");
            // case of file loading
        }else if(strcmp(argv[i], "-c") == 0){
            incoginito_read = fopen(*(argv + i + 1), "r");
        }
    }
    // display default is ascii
    if(graphic_display == NULL && ascii_display == NULL){
        ascii_display = malloc(sizeof(int));
            *ascii_display = 1;
    }
    // check if we do both read and save movements
    // copy the content of the the first file to the second
    if(incoginito_read != NULL && incoginito_write != NULL){
        char choice, p, c;
        int a, b, n;
        fscanf(incoginito_read, "%c %c%d\n", &p, &c, &n);
        fprintf(incoginito_write, "%c %c%d\n", p, c, n);
        fscanf(incoginito_read, "%c %c%d\n", &p, &c, &n);
        fprintf(incoginito_write, "%c %c%d\n", p, c, n);
        fscanf(incoginito_read, "%c\n", &p);
        fprintf(incoginito_write, "%c\n", p);
        while (fscanf(incoginito_read, "%c %c%d->%c%d\n", &choice, &c, &a, &p, &b) != EOF){
            fprintf(incoginito_write, "%c %c%d->%c%d\n", choice, c, a, p, b);
        }
        rewind(incoginito_read);

    }
    // create game variable
    Jeu game = {};
    // create mouvement variable
    Mouvement move;
    // variable to decide when a game ends, to define if there are no problems on our movements, decide if we're inside a castle
    int game_on = 1, error, move_castle;
    // random numbers to define the position of the spys
    srand(time(NULL));
    int sb = rand() % N;
    int sw = rand() % N;
    // declare a player variable
    char player[10];
    // declare a player variable for the file
    char p, choice, c;
    // a table of characters for the index of columns
    char table_charac[TAILLE];
    
    // fill the table with letters
    fill_table(table_charac);
    int taille_temp = TAILLE - (-1 + sqrt(1+ 8 * (N+1))) / 2;
    // declare the two spys
    Case spy_black, spy_white;
    // transform the randoms integers into coordinate
    if(incoginito_read == NULL){
        for(int i = 0; i < TAILLE; i++){
            for(int j = 0; j < TAILLE; j++){
                // to have access to the lower part of the grid wher ewe have the white player
                if(i <= taille_temp && j >=  taille_temp + i && j - i < TAILLE - 1){
                    if(sb == 0){
                        spy_black.x = i;
                        spy_black.y = j;
                        c = table_charac[j];
                        if(incoginito_write != NULL)
                            fprintf(incoginito_write, "N %c%d\n", c, i+1);
                        sb--;
                    }else{
                        sb--;
                    }
                }  
                // to have access to the lower part of the grid wher ewe have the black player 
                if(i >= taille_temp && i - j >= taille_temp && i - j < TAILLE - 1){
                    if(sw == 0){
                        spy_white.x = i;
                        spy_white.y = j;
                        c = table_charac[j];
                        if(incoginito_write != NULL)
                            fprintf(incoginito_write, "B %c%d\n", c, i+1);
                        sw--;
                    }else{
                        sw--;  
                    }

                }
            }
        }
    }    
    
    if(incoginito_read != NULL){
        fscanf(incoginito_read, "%c %c%d\n", &p, &c, &spy_white.x);
        // move.depart.x is the line of the box depart we do -1 because we start at 1
        spy_white.x --;
        // convert the letter of the column of the box to a number
        spy_white.y = search_in_table_char(table_charac, c);
        fscanf(incoginito_read, "%c %c%d\n", &p, &c, &spy_black.x);
        // move.depart.x is the line of the box depart we do -1 because we start at 1
        spy_black.x--;
        // convert the letter of the column of the box to a number
        spy_black.y = search_in_table_char(table_charac, c);    
    }    
    // initialise the grid
    game.joueur = rand() % 2;;
    implement_grid(game.plateau, spy_white, spy_black);
    update_player(&p, game.joueur);
    if(incoginito_read == NULL && incoginito_write != NULL){
        fprintf(incoginito_write, "%c\n", p);
    } 
    printf("Welcome to Incognito\n");
    // read the CHARGED FILE to continue a game
    if(incoginito_read != NULL)
        read_file(incoginito_read, &game, table_charac);
    // display the grid
    if(ascii_display != NULL)
        display_grid(game.plateau);
    else
        // graphic display
        display_grid_graph(game.plateau, renderer);
        
    printf("Reminder: (0, 0) denotes the upper left corner and (%d, %d) the lower right corner\n", TAILLE - 1, TAILLE - 1);
    // update a player
    update_player(&p, game.joueur);
    if(game.joueur == 0) strcpy(player, "White");
    else strcpy(player, "Black");
    while(game_on){
        do{
        printf("Player %s, do you want to make a move or a query? ('d' or 'i' or 'E' to exit)\n", player);
        scanf(" %c", &choice);
        }while (choice != 'd' && choice != 'i' && choice != 'E');
        if(choice == 'd'){
            do{
                printf("Which move for player %s?\n Entered in the form (a, b) --> (c, d).\n", player);
                scanf(" (%d, %d) --> (%d, %d)", &move.depart.x, &move.depart.y, &move.arrivee.x, &move.arrivee.y);
                // check if we're inside of a castle
                move_castle = decide_in_castle(game.plateau, move, game.joueur);
                // we're not inside a castle
                if(move_castle == 0){
                    // try to move a box
                    error = move_piece(game.plateau, move, game.joueur);
                    // we succeded
                    switch (error)
                    {
                    case 0:
                    // check if we won or not
                        move_castle = is_win(game.plateau, move, game.joueur);
                        // we won
                        if(move_castle == 0){
                            update_player(&p, game.joueur);
                            printf("Bravo, Winner is : %s\n", player);
                            game_on = 0;
                        // the pawn was a knight
                        }else if(move_castle == 2){
                            printf("The pawn can't enter the castle...\n");
                            game.plateau[move.depart.x][move.depart.y] = NULL;
                        }
                        // make the move by changing the coordinate
                        game.plateau[move.arrivee.x][move.arrivee.y] = game.plateau[move.depart.x][move.depart.y];
                        game.plateau[move.depart.x][move.depart.y] = NULL;
                        printf("Player %s, your move is executed..\n", player);
                        break;
                    case 1:
                        printf("Illegal move: there are squares that block it.\n");
                        break;
                    case 2:
                        printf("Illegal move: a player cannot bring a pawn to his castle.\n");
                        break;
                    case 3:
                        printf("Illegal move: selected pawn is not yours.\n");
                        break;
                    case 4:
                        printf("Illegal move: the box is empty\n");
                        break;
                    default:
                        printf("The move is not tolerated.\n");
                        break;
                    }
                }
                else{
                    printf("This move is not tolerated\n");
                    error = 1;
                }
                // add it to the FILE
                if(incoginito_write != NULL){
                    fprintf(incoginito_write, "D %c%d->%c%d\n", table_charac[move.depart.y], 
                                move.depart.x + 1, table_charac[move.arrivee.y], move.arrivee.x + 1);
                
                    // at the end of the game we add the winner to the FILE
                    if(game_on == 0){
                        fprintf(incoginito_write, "%c\n", p);
                }
                }
            }while(error != 0);

        }
        // make an interrogation
        else if(choice == 'i'){
            do{
                printf("Which %s pawn is the interrogator?\nEntered as (a, b)\n", player);
                scanf(" (%d, %d)", &move.depart.x, &move.depart.y);
                printf("Which pawn is being questioned?\n");
                scanf(" (%d, %d)", &move.arrivee.x, &move.arrivee.y);
                // make an interrogation
                error = interrogate_piece(game.plateau, game.joueur, move.depart, move.arrivee);
                //display something depending on the result of the interrogation
                switch (error)
                {
                    // interrogation succeded
                case 0:
                    printf("%s player, you didn't find your opponent's spy...\nAnd on top of that, your knight got poisoned... \n", player);
                    break;
                case 1:
                    printf("Interrogation not tolerated because the cases are not adjascent.\n");
                    break;
                // interrogated a spy so won
                case -1:
                    printf("%s player, you interrogated a spy...\n", player);
                    game_on = 0;
                    update_player(&p, game.joueur);
                    printf("Bravo, Winner is : %s\n", player);
                    break;
                // interrogated a knight with your spy so you lose
                case -2:
                    update_player(&p, (game.joueur + 1) % 2);
                    printf("%s player, you interrogated a knight with your spy...\n", player);
                    printf("Bravo, Winner is : %s\n", (game.joueur == 0)?"Black": "White");
                    game_on = 0;
                    break;
                case 3:
                    printf("Interrogation not tolerated : the player selectionned the wrong pions.\n");
                    break;
                case 4:
                    printf("Interogation not tolerated because the two cases are empty.\n");
                    break;
                default:
                    printf("The movet is not tolerated.\n");
                    break;
                }
                if(incoginito_write != NULL){
                    // add it to the FILE
                    fprintf(incoginito_write, "I %c%d->%c%d\n", table_charac[move.depart.y], 
                                    move.depart.x + 1, table_charac[move.arrivee.y], move.arrivee.x + 1);
                    // at the end of the game we add the winner to the FILE
                    if(game_on == 0){
                        fprintf(incoginito_write, "%c\n", p);
                    }
                }
                
            }while(error == 3 ||error == 1 ||error == 4);

        }
        // Exit the game
        else{
            game_on = 0;
        }
        if(ascii_display != NULL)
            display_grid(game.plateau);
        else
            // graphic display
            display_grid_graph(game.plateau, renderer);

        game.joueur = (game.joueur + 1) % 2;
        // tgive the turn to the other player
        if(game.joueur == 0) strcpy(player, "White");
        else strcpy(player, "Black");
    }


    // display the grid and close the FILE
    if(ascii_display != NULL)
        display_grid(game.plateau);
    else
        // graphic display
        display_grid_graph(game.plateau, renderer);
    // close files
    if(incoginito_read != NULL)
        fclose(incoginito_read);
    if(incoginito_write != NULL)
        fclose(incoginito_write);
    // destroy the renderer and the window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    // close the window
    SDL_Quit();
    // free the space in memory
    free(ascii_display);
    free(graphic_display);
    return 0;
}
