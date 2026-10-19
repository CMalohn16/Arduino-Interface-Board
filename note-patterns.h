
#include "note.h"

#define END_SONG 0.00
#define C_FLAT3 123.47
#define C3 130.81
#define C_SHARP3 138.59
#define D_FLAT3 138.59
#define D3 146.83
#define D_SHARP3 155.56
#define E_FLAT3 155.56
#define E3 164.81
#define E_SHARP3 174.61
#define F_FLAT3 164.81
#define F3 174.61
#define F_SHARP3 185.00
#define G_FLAT3 185.00
#define G3 196.00
#define G_SHARP3 207.65
#define A_FLAT3 207.65
#define A3 220.00
#define A_SHARP3 233.08
#define B_FLAT3 233.08
#define B3 246.94
#define B_SHARP3 261.63

#define C_FLAT4 C_FLAT3 * 2
#define C4 C3 * 2
#define C_SHARP4 C_SHARP3 * 2
#define D_FLAT4 D_FLAT3 * 2
#define D4 D3 * 2
#define D_SHARP4 D_SHARP3 * 2
#define E_FLAT4 E_FLAT3 * 2
#define E4 E3 * 2
#define E_SHARP4 E_SHARP3 * 2
#define F_FLAT4 F_FLAT3 * 2
#define F4 F3 * 2
#define F_SHARP4 F_SHARP3 * 2
#define G_FLAT4 G_FLAT3 * 2
#define G4 G3 * 2
#define G_SHARP4 G_SHARP3 * 2
#define A_FLAT4 A_FLAT3 * 2
#define A4 A3 * 2
#define A_SHARP4 A_SHARP3 * 2
#define B_FLAT4 B_FLAT3 * 2
#define B4 B3 * 2
#define B_SHARP4 B_SHARP3 * 2

#define C5 C3 * 4

#define STARTUP (double[]){C4, D3, C3, END_SONG}
#define ZELDA (double[]){G4, F_SHARP4, D_SHARP4, A3, G_SHARP3, E4, G_SHARP4, C5, END_SONG}
#define SCALE (double[]){C3, D3, E3, F3, G3, A3, B3, C3, END_SONG}