#include <inttypes.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define u8 uint8_t


typedef struct coord {
    u8 x;
    u8 y;
} Coord;

bool can_king_descend_to(const Coord from, const Coord to);
void input_coord(const char* restrict, Coord* restrict);

int main(void)
{
    Coord from = {.x = 0, .y = 0};
    Coord to = {.x = 0, .y = 0};

    input_coord("Enter x1, y1: ", &from);
    input_coord("Enter x2, y2: ", &to);

    if (can_king_descend_to(from, to)) {
        puts("OK");
    } else {
        puts("NO");
    }

    return EXIT_SUCCESS;
}

bool can_king_descend_to(const Coord from, const Coord to)
{
    u8 x1 = from.x;
    u8 y1 = from.y;
    u8 x2 = to.x;
    u8 y2 = to.y;

    return abs(x1 - x2) <= 1 and abs(y1 - y2) <= 1;
}

void input_coord(const char* restrict prompt, Coord* restrict pack)
{
    printf("%s", prompt);
    scanf("%" SCNu8 " %" SCNu8, &pack->x, &pack->y);
}
