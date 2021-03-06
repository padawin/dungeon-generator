#include <stdint.h>

#define DUNGEON_INCLUDED

#define BIT_USED_ROOM   0x01
#define BIT_ENTRANCE    0x02
#define BIT_DOOR_NORTH  0x04
#define BIT_DOOR_EAST   0x08
#define BIT_DOOR_SOUTH  0x10
#define BIT_DOOR_WEST   0x20
#define BIT_STAIR_BELOW 0x40
#define BIT_STAIR_UP    0x80

#define VISUAL_DISPLAY_MODE 0x01

#define IS_USED(room) ((room & BIT_USED_ROOM) == BIT_USED_ROOM)
#define IS_ENTRANCE(room) ((room & BIT_ENTRANCE) == BIT_ENTRANCE)
#define HAS_NORTH_DOOR(room) ((room & BIT_DOOR_NORTH) == BIT_DOOR_NORTH)
#define HAS_WEST_DOOR(room) ((room & BIT_DOOR_WEST) == BIT_DOOR_WEST)
#define HAS_SOUTH_DOOR(room) ((room & BIT_DOOR_SOUTH) == BIT_DOOR_SOUTH)
#define HAS_EAST_DOOR(room) ((room & BIT_DOOR_EAST) == BIT_DOOR_EAST)

// Grid cell: int:
// bit 0: 1 if there is a door leading to the outside, 0 else
// bits 1 to 4: 1 if there is a door leading to the next cell, 0 else
//      bit 1: north
//      bit 2: east
//      bit 3: south
//      bit 4: west
// bits 5: 1 if there is a stair leading to the floor below, 0 else
// bits 6: 1 if there is a stair leading to the floor below, 0 else
typedef struct {
	uint8_t* grid;
	int entrance;
	int width;
	int height;
} s_dungeon;

void generate_dungeon(s_dungeon *d);
void display_dungeon(s_dungeon *d, int options);

/*
 * Private signatures for test uses
 */

#if defined(TEST_DUNGEON)
#include <stdbool.h>

bool room_has_door(s_dungeon *dungeon, int room, int direction);
int get_neighbour_room_index(s_dungeon *dungeon, int current_room, int direction);
int get_opposite_direction_bit(int direction);

#endif
