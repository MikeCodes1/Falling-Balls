/*
 * Author:Eli Hall
 * Assignment Title: Falling Balls
 * Class Description: This class represents the font in the game.
 * Due Date: 12/6/2023
 * Date Created: 11/26/2023
 * Date Last Modified: 12/6/2023
 */
#include "Font.h"

Font::Font(){
    size = 10;

    loc.x = 225;
    loc.y = 335;

    _color.R = 100;
    _color.G = 100;
    _color.B = 100;
}

Font::Font(int s, point p, color c){
    size = s;
    loc.x = p.x;
    loc.y = p.y;
    _color = c;
}

void Font::setSize(int s){
    size = s;
}

void Font::setLoc(point p){
    loc.x = p.x;
    loc.y = p.y;
}

void Font::setColor(color c){
    _color = c;
}

void Font::PrintScore(SDL_Plotter& g, int s, bool ERASE){
    int score = s;
    int digits;
    ifstream inFile;
    point brush(loc.x, loc.y);
    bool draw;
    color col = _color;
    if(ERASE){
        col.R = 255;
        col.G = 255;
        col.B = 255;
    }

    if(s > 1){
        digits = log10(score) + 1;
    }
    else{
        digits = 1;
    }

    for(int h = 0; h < digits; h++){
        switch(s % 10){
            case 1: inFile.open("Text/1.txt");
                break;
            case 2: inFile.open("Text/2.txt");
                break;
            case 3: inFile.open("Text/3.txt");
                break;
            case 4: inFile.open("Text/4.txt");
                break;
            case 5: inFile.open("Text/5.txt");
                break;
            case 6: inFile.open("Text/6.txt");
                break;
            case 7: inFile.open("Text/7.txt");
                break;
            case 8: inFile.open("Text/8.txt");
                break;
            case 9: inFile.open("Text/9.txt");
                break;
            case 0: inFile.open("Text/0.txt");
                break;
        }

        for(int i = 0; i < 7; i++){
            for(int j = 0; j < 5; j++){
                inFile >> draw;
                if(draw){
                    for(int k = 0; k < size; k++){
                        for(int l = 0; l < size; l++){
                            g.plotPixel(brush.x, brush.y, col);
                            brush.x++;
                        }
                        brush.x -= size;
                        brush.y++;
                    }
                    brush.y -= size;
                }
                brush.x += size;
            }
            brush.x -= 5 * size;
            brush.y += size;
        }
        inFile.close();
        brush.x -= 4*(5*size)/3;
        brush.y -= 7*size;
        s /= 10;
    }
}

void Font::PrintText(SDL_Plotter& g, char text[], int n, bool ERASE){
    ifstream inFile;
    point brush(loc.x, loc.y);
    bool draw;
    color col = _color;

    for(int h = 0; h < n; h++){
        switch(toupper(text[h])){
            case ' ': inFile.open("Text/space.txt");
                break;
            case 'A': inFile.open("Text/A.txt");
                break;
            case 'C': inFile.open("Text/C.txt");
                break;
            case 'E': inFile.open("Text/E.txt");
                break;
            case 'G': inFile.open("Text/G.txt");
                break;
            case 'I': inFile.open("Text/I.txt");
                break;
            case 'K': inFile.open("Text/K.txt");
                break;
            case 'L': inFile.open("Text/L.txt");
                break;
            case 'M': inFile.open("Text/M.txt");
                break;
            case 'O': inFile.open("Text/0.txt");
                break;
            case 'P': inFile.open("Text/P.txt");
                break;
            case 'R': inFile.open("Text/R.txt");
                break;
            case 'S': inFile.open("Text/S.txt");
                break;
            case 'T': inFile.open("Text/T.txt");
                break;
            case 'V': inFile.open("Text/V.txt");
                break;
            case 'Y': inFile.open("Text/Y.txt");
                break;
        }

        for(int i = 0; i < 7; i++){
            for(int j = 0; j < 5; j++){
                inFile >> draw;
                if(draw){
                    for(int k = 0; k < size; k++){
                        for(int l = 0; l < size; l++){
                            g.plotPixel(brush.x, brush.y, col);
                            brush.x++;
                        }
                        brush.x -= size;
                        brush.y++;
                    }
                    brush.y -= size;
                }
                brush.x += size;
            }
            brush.x -= 5 * size;
            brush.y += size;
        }
        inFile.close();
        brush.x += 4*(5*size)/3;
        brush.y -= 7*size;
    }
}
