#include <stdio.h>
#define SCREEN_WIDTH 12
#define SCREEN_HEIGHT 10
#define PIXEL_COUNT (SCREEN_WIDTH * SCREEN_HEIGHT)
enum RectColor
{
    MARK_EMPTY = 0,
    MARK_X,
    MARK_O,
    MARK_MONKEY,
    MARK_EIGHT,
    MARK_NINE,
    MARK_SEVEN,
};
struct Rectangle
{
    int pos_y;
    int pos_x;
    int height;
    int width;
    enum RectColor color;
};

void draw_rectangle(int pos_x, int pos_y, int width, int height, enum RectColor color, int pixels_array[])
{
    
    for(int y = pos_y; y < pos_y + height; y++)
    {
        
        for(int x = pos_x; x < pos_x + width; x++) 
        {
            int index = y * SCREEN_WIDTH + x;  
            pixels_array[index] = color;         
            
        }
       
    }
}

void draw_rectangle2(struct Rectangle rect, int pixels_array[])
{
    
    for(int y = rect.pos_y; y < rect.pos_y + rect.height; y++)
    {
        
        for(int x = rect.pos_x; x < rect.pos_x + rect.width; x++) 
        {
            int index = y * SCREEN_WIDTH + x;  
            pixels_array[index] = rect.color;         
            
        }
       
    }
}

int main()
{
    const int ARRAY_LENGTH = SCREEN_WIDTH * SCREEN_HEIGHT;
    int pixels [PIXEL_COUNT] = {0};
    pixels [4] = MARK_O;

    int p1x = 2;
    int p1y = 1;
    pixels[ p1y * SCREEN_WIDTH + p1x ] = MARK_X;

    struct Rectangle rect1;
    rect1.pos_x = 5;
    rect1.pos_y = 1;
    rect1.width = 4;
    rect1.height = 3;
    rect1.color = MARK_MONKEY;
    draw_rectangle2(rect1, pixels);
   
    struct Rectangle rect2;
    rect2.pos_x = 0;
    rect2.pos_y = 3;
    rect2.width = 1;
    rect2.height = 7;
    rect2.color = MARK_EIGHT;
    draw_rectangle2(rect2, pixels);
    
    struct Rectangle rect3;
    rect3.pos_x = 2;
    rect3.pos_y = 5;
    rect3.width = 10;
    rect3.height = 5;
    rect3.color = MARK_SEVEN;
    draw_rectangle2(rect3, pixels);

    struct Rectangle rect0;
    rect0.pos_y = 4;
    rect0.pos_x = 4;
    rect0.width = 3;
    rect0.height = 3;
    rect0.color = MARK_NINE;

    draw_rectangle2(rect0, pixels);
   
    for(int i = 0; i < ARRAY_LENGTH; i = i + 1 )
    {
        if( i<10)
        {
            printf(" %i ", i);
        }
        else if(i>=10)
        {
            printf("%i ", i);
        }
    }
    printf("\n");
    
    for(int y = 0; y < SCREEN_HEIGHT; y++)  
    {
        for(int x = 0; x < SCREEN_WIDTH; x++) 
        {
             int index = y * SCREEN_WIDTH + x;
            switch( pixels[index] )
            {
                case MARK_EMPTY: {
                    printf("[ ]");
                } break;
                case MARK_X: {
                    printf("[X]");
                } break;
                case MARK_O: {
                    printf("[O]");
                } break;
                case MARK_MONKEY: {
                    printf("[@]");
                } break;
                case MARK_EIGHT: {
                    printf("[8]");
                } break;
                case MARK_NINE: {
                    printf("[9]");
                } break;
                case MARK_SEVEN: {
                    printf("[7]");
                } break;
            }

        }
        printf("\n");
    }
}