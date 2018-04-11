// Anda tidak perlu melakukan perubahan pada file ini untuk memenuhi spek
// wajib. Namun, hal tersebut diperbolehkan.
#include "oop.hpp"

#include <map>
#include <iostream>
#include <chrono>
#include <SDL2/SDL2_rotozoom.h>

using namespace std::chrono;

high_resolution_clock::time_point start = high_resolution_clock::now();

double time_since_start()
{
    high_resolution_clock::time_point now = high_resolution_clock::now();
        return duration_cast<duration<double>>(now - start).count();
}

SDL_Window* sdlWindow;
std::map<std::string, SDL_Surface*> loadedSurfaces;
std::map<int, TTF_Font*> loadedFontSizes;
SDL_Surface* gScreenSurface = NULL;

/*
0: left mouse down
1: left mouse
2: left mouse up
3: right mouse down
4: right mouse
5: right mouse up
*/
char mouse_state[6] = {0, 0, 0, 0, 0, 0};
int mouse_pos[2] = {0, 0};

bool init()
{
    bool success = true;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {

        if(TTF_Init() == -1) {
            printf("TTF_Init: %s\n", TTF_GetError());
            success = false;
        }
        sdlWindow = SDL_CreateWindow( "ArkavQuarium", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( sdlWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            gScreenSurface = SDL_GetWindowSurface( sdlWindow );
        }
    }

    return success;
}

void close()
{
    for (auto const& x : loadedSurfaces)
    {
        SDL_FreeSurface( x.second );
    }

    for (auto const& x : loadedFontSizes)
    {
        TTF_CloseFont( x.second );
    }

    SDL_DestroyWindow( sdlWindow );
    sdlWindow = NULL;

    SDL_Quit();
}

SDL_Surface* loadSurface( std::string path )
{
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }

    return loadedSurface;
}

void draw_image(std::string filename, int x, int y) {
    if (loadedSurfaces.count(filename) < 1) {
        loadedSurfaces[filename] = loadSurface(filename);
    }

    SDL_Surface* s = loadedSurfaces[filename];

    SDL_Rect dest;
    dest.x = x - s->w/2;
    dest.y = y - s->h/2;
    dest.w = s->w;
    dest.h = s->h;
    SDL_BlitSurface(s, NULL, gScreenSurface, &dest);
}

void draw_text(std::string text, int font_size, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    if (loadedFontSizes.count(font_size) < 1) {
        loadedFontSizes[font_size] = TTF_OpenFont(FONT_NAME, font_size);
    }

    TTF_Font* font = loadedFontSizes[font_size];
    SDL_Surface* result = TTF_RenderText_Blended(font, text.c_str(), {r, g, b});
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = result->w;
    dest.h = result->h;
    SDL_BlitSurface(result, NULL, gScreenSurface, &dest);
    SDL_FreeSurface(result);
}

void clear_screen() {
    SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format, 255, 255, 255));
}

void update_screen() {
    SDL_UpdateWindowSurface(sdlWindow);
}

bool quit = false;
std::set<SDL_Keycode> pressedKeys;
std::set<SDL_Keycode> tappedKeys;

void handle_input() {
    SDL_Event e;
    mouse_state[2]=0;
    if (!tappedKeys.empty()) tappedKeys.clear();
    while( SDL_PollEvent( &e ) != 0 ) {
        if ( e.type == SDL_QUIT ) {
            quit = true;
        } else if (e.type == SDL_KEYDOWN && !e.key.repeat) {
            pressedKeys.insert(e.key.keysym.sym);
            tappedKeys.insert(e.key.keysym.sym);
        } else if (e.type == SDL_KEYUP) {
            pressedKeys.erase(e.key.keysym.sym);
        } else if (e.type == SDL_MOUSEBUTTONDOWN) {
            switch (e.button.button)
            {
                case SDL_BUTTON_LEFT:
                    if (!mouse_state[0]) {
                        mouse_state[2] = 1;
                    }
                    mouse_state[0] = 1;
                    break;
                case SDL_BUTTON_RIGHT:
                    if (!mouse_state[1]) {
                        mouse_state[3] = 1;
                    }
                    mouse_state[1] = 1;
                    break;
            }
        } else if (e.type == SDL_MOUSEBUTTONUP) {
            switch (e.button.button)
            {
                case SDL_BUTTON_LEFT:
                    if (mouse_state[0]) {
                        mouse_state[4] = 1;
                    }
                    mouse_state[0] = 0;
                    break;
                case SDL_BUTTON_RIGHT:
                    if (mouse_state[1]) {
                        mouse_state[5] = 1;
                    }
                    mouse_state[1] = 0;
                    break;
            }
        } else if (e.type == SDL_MOUSEMOTION) {
            mouse_pos[0] = e.motion.x;
            mouse_pos[1] = e.motion.y;
        }
    }
}

bool quit_pressed() {
    return quit;
}

const std::set<SDL_Keycode>& get_pressed_keys() {
    return pressedKeys;
}

const std::set<SDL_Keycode>& get_tapped_keys() {
    return tappedKeys;
}


int get_mouse_pos_x() {
    return mouse_pos[0];
}

int get_mouse_pos_y() {
    return mouse_pos[1];
}

bool get_mouse_button_down(int button) {
    if (button == 0) {
        return mouse_state[2];
    } else if (button == 1) {
        return mouse_state[3];
    }
    return 0;
}

bool get_mouse_button(int button) {
    if (button == 0) {
        return mouse_state[0] && !mouse_state[2];
    } else if (button == 1) {
        return mouse_state[1] && !mouse_state[3];
    }
    return 0;
}

bool get_mouse_button_up(int button) {
    if (button == 0) {
        return mouse_state[4];
    } else if (button == 1) {
        return mouse_state[5];
    }
    return 0;
}
