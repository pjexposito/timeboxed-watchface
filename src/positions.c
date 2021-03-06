#include <pebble.h>
#include "positions.h"
#include "keys.h"


GPoint create_point(int x, int y) {
    struct GPoint point;
    point.x = x;
    point.y = y;
    return point;
}

static int get_pos(int alignment, int left_pos, int center_pos, int right_pos) {
    switch (alignment) {
        case GTextAlignmentLeft:
            return left_pos;
            break;
        case GTextAlignmentCenter:
            return center_pos;
            break;
        case GTextAlignmentRight:
            return right_pos;
            break;
    }
    return right_pos;
}

static void get_text_positions_blocko(GTextAlignment align, struct TextPositions* positions, int width, int height) {
    int midpoint = height / 2;
    positions->hours = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, 0)), PBL_IF_ROUND_ELSE(midpoint - 46, midpoint - 46));
    positions->date = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, -2)), PBL_IF_ROUND_ELSE(midpoint + 6, midpoint + 6));
    positions->alt_time = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, -2)), PBL_IF_ROUND_ELSE(midpoint - 46, midpoint - 46));
    positions->battery = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, -4)), PBL_IF_ROUND_ELSE(midpoint + 28, midpoint + 28));
    positions->bluetooth = create_point(PBL_IF_ROUND_ELSE(134, get_pos(align, -4, 126, 0)), PBL_IF_ROUND_ELSE(midpoint + 34, get_pos(align, midpoint - 24, midpoint + 34, midpoint - 24)));
    positions->updates = create_point(PBL_IF_ROUND_ELSE(120, get_pos(align, -4, 112, 0)), PBL_IF_ROUND_ELSE(midpoint + 34, get_pos(align, midpoint - 6, midpoint + 34, midpoint - 6)));
}

static void get_text_positions_blocko_big(GTextAlignment align, struct TextPositions* positions, int width, int height) {
    int midpoint = height / 2;
    positions->hours = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 2, 0)), PBL_IF_ROUND_ELSE(midpoint - 52, midpoint - 52));
    positions->date = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 1, -2)), PBL_IF_ROUND_ELSE(midpoint + 4, midpoint + 4));
    positions->alt_time = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 1, -2)), PBL_IF_ROUND_ELSE(midpoint - 50, midpoint - 50));
    positions->battery = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 1, -4)), PBL_IF_ROUND_ELSE(midpoint + 32, midpoint + 32));
    positions->bluetooth = create_point(PBL_IF_ROUND_ELSE(134, get_pos(align, -4, 126, 0)), PBL_IF_ROUND_ELSE(midpoint + 40, get_pos(align, midpoint - 30, midpoint + 40, midpoint - 30)));
    positions->updates = create_point(PBL_IF_ROUND_ELSE(120, get_pos(align, -4, 112, 0)), PBL_IF_ROUND_ELSE(midpoint + 40, get_pos(align, midpoint - 8, midpoint + 40, midpoint - 8)));
}

static void get_text_positions_system(GTextAlignment align, struct TextPositions* positions, int width, int height) {
    int midpoint = height / 2;
    positions->hours = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, 0)), PBL_IF_ROUND_ELSE(midpoint - 42, midpoint - 42));
    positions->date = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, -2)), PBL_IF_ROUND_ELSE(midpoint + 2, midpoint + 2));
    positions->alt_time = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, -2)), PBL_IF_ROUND_ELSE(midpoint - 50, midpoint - 50));
    positions->battery = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, -4)), PBL_IF_ROUND_ELSE(midpoint + 28, midpoint + 28));
    positions->bluetooth = create_point(PBL_IF_ROUND_ELSE(134, get_pos(align, -4, 126, 0)), PBL_IF_ROUND_ELSE(midpoint + 40, get_pos(align, midpoint - 30, midpoint + 40, midpoint - 30)));
    positions->updates = create_point(PBL_IF_ROUND_ELSE(120, get_pos(align, -4, 112, 0)), PBL_IF_ROUND_ELSE(midpoint + 40, get_pos(align, midpoint - 8, midpoint + 40, midpoint - 8)));
}

static void get_text_positions_archivo(GTextAlignment align, struct TextPositions* positions, int width, int height) {
    int midpoint = height / 2;
    positions->hours = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, 0)), PBL_IF_ROUND_ELSE(midpoint - 44, midpoint - 44));
    positions->date = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, -2)), PBL_IF_ROUND_ELSE(midpoint + 8, midpoint + 8));
    positions->alt_time = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, -2)), PBL_IF_ROUND_ELSE(midpoint - 48, midpoint - 48));
    positions->battery = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, -4)), PBL_IF_ROUND_ELSE(midpoint + 34, midpoint + 34));
    positions->bluetooth = create_point(PBL_IF_ROUND_ELSE(134, get_pos(align, -4, 126, 0)), PBL_IF_ROUND_ELSE(midpoint + 40, get_pos(align, midpoint - 30, midpoint + 40, midpoint - 30)));
    positions->updates = create_point(PBL_IF_ROUND_ELSE(120, get_pos(align, -4, 112, 0)), PBL_IF_ROUND_ELSE(midpoint + 40, get_pos(align, midpoint - 8, midpoint + 40, midpoint - 8)));
}

static void get_text_positions_din(GTextAlignment align, struct TextPositions* positions, int width, int height) {
    int midpoint = height / 2;
    positions->hours = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, 0)), PBL_IF_ROUND_ELSE(midpoint - 45, midpoint - 45));
    positions->date = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, -2)), PBL_IF_ROUND_ELSE(midpoint + 8, midpoint + 8));
    positions->alt_time = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, -2)), PBL_IF_ROUND_ELSE(midpoint - 52, midpoint - 52));
    positions->battery = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, -4)), PBL_IF_ROUND_ELSE(midpoint + 32, midpoint + 32));
    positions->bluetooth = create_point(PBL_IF_ROUND_ELSE(134, get_pos(align, -4, 126, 0)), PBL_IF_ROUND_ELSE(midpoint + 40, get_pos(align, midpoint - 30, midpoint + 40, midpoint - 30)));
    positions->updates = create_point(PBL_IF_ROUND_ELSE(120, get_pos(align, -4, 112, 0)), PBL_IF_ROUND_ELSE(midpoint + 40, get_pos(align, midpoint - 8, midpoint + 40, midpoint - 8)));
}

static void get_text_positions_prototype(GTextAlignment align, struct TextPositions* positions, int width, int height) {
    int midpoint = height / 2;
    positions->hours = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, 0)), PBL_IF_ROUND_ELSE(midpoint - 40, midpoint - 40));
    positions->date = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, -2)), PBL_IF_ROUND_ELSE(midpoint + 8, midpoint + 8));
    positions->alt_time = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, -2)), PBL_IF_ROUND_ELSE(midpoint - 46, midpoint - 46));
    positions->battery = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, -4)), PBL_IF_ROUND_ELSE(midpoint + 30, midpoint + 30));
    positions->bluetooth = create_point(PBL_IF_ROUND_ELSE(134, get_pos(align, -2, 126, -2)), PBL_IF_ROUND_ELSE(midpoint + 34, get_pos(align, midpoint - 24, midpoint + 34, midpoint - 24)));
    positions->updates = create_point(PBL_IF_ROUND_ELSE(120, get_pos(align, -2, 112, -2)), PBL_IF_ROUND_ELSE(midpoint + 34, get_pos(align, midpoint - 6, midpoint + 34, midpoint - 6)));
}

static void get_text_positions_leco(GTextAlignment align, struct TextPositions* positions, int width, int height) {
    int midpoint = height / 2;
    positions->hours = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, 0)), PBL_IF_ROUND_ELSE(midpoint - 38, midpoint - 38));
    positions->date = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, -2)), PBL_IF_ROUND_ELSE(midpoint + 9, midpoint + 9));
    positions->alt_time = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, -2)), PBL_IF_ROUND_ELSE(midpoint - 43, midpoint - 43));
    positions->battery = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, -4)), PBL_IF_ROUND_ELSE(midpoint + 31, midpoint + 31));
    positions->bluetooth = create_point(PBL_IF_ROUND_ELSE(134, get_pos(align, -4, 126, -2)), PBL_IF_ROUND_ELSE(midpoint + 34, get_pos(align, midpoint - 26, midpoint + 34, midpoint - 26)));
    positions->updates = create_point(PBL_IF_ROUND_ELSE(120, get_pos(align, -4, 112, -2)), PBL_IF_ROUND_ELSE(midpoint + 34, get_pos(align, midpoint - 8, midpoint + 34, midpoint - 8)));
}

static void get_text_positions_konstruct(GTextAlignment align, struct TextPositions* positions, int width, int height) {
    int midpoint = height / 2;
    positions->hours = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, 0)), PBL_IF_ROUND_ELSE(midpoint - 24, midpoint - 24));
    positions->date = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, -2)), PBL_IF_ROUND_ELSE(midpoint + 10, midpoint + 10));
    positions->alt_time = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, -2)), PBL_IF_ROUND_ELSE(midpoint - 33, midpoint - 33));
    positions->battery = create_point(PBL_IF_ROUND_ELSE(0, get_pos(align, 2, 0, -4)), PBL_IF_ROUND_ELSE(midpoint + 28, midpoint + 28));
    positions->bluetooth = create_point(PBL_IF_ROUND_ELSE(134, get_pos(align, -4, 126, -2)), PBL_IF_ROUND_ELSE(midpoint + 40, get_pos(align, midpoint - 30, midpoint + 40, midpoint - 30)));
    positions->updates = create_point(PBL_IF_ROUND_ELSE(120, get_pos(align, -4, 112, -2)), PBL_IF_ROUND_ELSE(midpoint + 40, get_pos(align, midpoint - 8, midpoint + 40, midpoint - 8)));
}

void get_text_positions(int selected_font, GTextAlignment alignment, struct TextPositions* positions, int width, int height) {
    switch(selected_font) {
        case BLOCKO_FONT:
            get_text_positions_blocko(alignment, positions, width, height);
            break;
        case BLOCKO_BIG_FONT:
            get_text_positions_blocko_big(alignment, positions, width, height);
            break;
        case SYSTEM_FONT:
            get_text_positions_system(alignment, positions, width, height);
            break;
        case ARCHIVO_FONT:
            get_text_positions_archivo(alignment, positions, width, height);
            break;
        case DIN_FONT:
            get_text_positions_din(alignment, positions, width, height);
            break;
        case PROTOTYPE_FONT:
            get_text_positions_prototype(alignment, positions, width, height);
            break;
        case LECO_FONT:
            get_text_positions_leco(alignment, positions, width, height);
            break;
        case KONSTRUCT_FONT:
            get_text_positions_konstruct(alignment, positions, width, height);
            break;
        default:
            get_text_positions_blocko(alignment, positions, width, height);
    }
};

static GPoint get_weather_positions(int mode, int font, int width, int height) {
    // weather condition
    switch (mode) {
        case MODE_NORMAL:
            switch(font) {
                case BLOCKO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-14, 0), 0);
                case BLOCKO_BIG_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-14, 0), 0);
                case SYSTEM_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-14, 0), 0);
                case ARCHIVO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-14, 0), 0);
                case DIN_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-14, 0), 0);
                case PROTOTYPE_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-16, 0), 0);
                case LECO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-16, 0), 0);
                case KONSTRUCT_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-16, 0), 0);
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};

static GPoint get_temp_positions(int mode, int font, int width, int height) {
    // current temperature
    switch (mode) {
        case MODE_NORMAL:
            switch(font) {
                case BLOCKO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(16, 38), 3);
                case BLOCKO_BIG_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(16, 38), 3);
                case SYSTEM_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(16, 38), 3);
                case ARCHIVO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(16, 38), 3);
                case DIN_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(16, 38), 3);
                case PROTOTYPE_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(18, 40), 3);
                case LECO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(15, 39), 5);
                case KONSTRUCT_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(15, 39), 9);
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};

static GPoint get_tempmin_positions(int mode, int font, int width, int height) {
    // min temperature
    switch (mode) {
        case MODE_NORMAL:
            switch(font) {
                case BLOCKO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(70, 12), 3);
                case BLOCKO_BIG_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(70, 12), 3);
                case SYSTEM_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(70, 12), 3);
                case ARCHIVO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(70, 12), 3);
                case DIN_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(70, 12), 3);
                case PROTOTYPE_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(70, 12), 3);
                case LECO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(68, 10), 5);
                case KONSTRUCT_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(68, 10), 9);
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};

static GPoint get_tempminicon_positions(int mode, int font, int width, int height) {
    // min temperature
    switch (mode) {
        case MODE_NORMAL:
            switch(font) {
                case BLOCKO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(60, 2), 4);
                case BLOCKO_BIG_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(60, 2), 4);
                case SYSTEM_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(60, 2), 4);
                case ARCHIVO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(60, 2), 4);
                case DIN_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(60, 2), 4);
                case PROTOTYPE_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(60, 2), 4);
                case LECO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(59, 1), 3);
                case KONSTRUCT_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(59, 1), 5);
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};

static GPoint get_tempmax_positions(int mode, int font, int width, int height) {
    // max temperature
    switch (mode) {
        case MODE_NORMAL:
            switch(font) {
                case BLOCKO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(108, 45), 3);
                case BLOCKO_BIG_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(108, 45), 3);
                case SYSTEM_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(108, 45), 3);
                case ARCHIVO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(108, 45), 3);
                case DIN_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(108, 45), 3);
                case PROTOTYPE_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(108, 45), 3);
                case LECO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(108, 45), 5);
                case KONSTRUCT_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(108, 45), 9);
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};

static GPoint get_tempmaxicon_positions(int mode, int font, int width, int height) {
    // max temperature
    switch (mode) {
        case MODE_NORMAL:
            switch(font) {
                case BLOCKO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(98, 35), 4);
                case BLOCKO_BIG_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(98, 35), 4);
                case SYSTEM_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(98, 35), 4);
                case ARCHIVO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(98, 35), 4);
                case DIN_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(98, 35), 4);
                case PROTOTYPE_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(98, 35), 4);
                case LECO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(99, 36), 3);
                case KONSTRUCT_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(99, 36), 5);
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};

#if defined(PBL_HEALTH)
static GPoint get_steps_positions(int mode, int font, int width, int height) {
    // steps
    switch (mode) {
        case MODE_NORMAL:
            switch(font) {
                case BLOCKO_FONT:
                    return create_point(0, 3);
                case BLOCKO_BIG_FONT:
                    return create_point(0, 3);
                case SYSTEM_FONT:
                    return create_point(0, 3);
                case ARCHIVO_FONT:
                    return create_point(0, 3);
                case DIN_FONT:
                    return create_point(0, 3);
                case PROTOTYPE_FONT:
                    return create_point(0, 3);
                case LECO_FONT:
                    return create_point(0, 5);
                case KONSTRUCT_FONT:
                    return create_point(0, 9);
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};

static GPoint get_dist_positions(int mode, int font, int width, int height) {
    // distance
    switch (mode) {
        case MODE_NORMAL:
            switch(font) {
                case BLOCKO_FONT:
                    return create_point(0, 3);
                case BLOCKO_BIG_FONT:
                    return create_point(0, 3);
                case SYSTEM_FONT:
                    return create_point(0, 3);
                case ARCHIVO_FONT:
                    return create_point(0, 3);
                case DIN_FONT:
                    return create_point(0, 3);
                case PROTOTYPE_FONT:
                    return create_point(0, 3);
                case LECO_FONT:
                    return create_point(0, 5);
                case KONSTRUCT_FONT:
                    return create_point(0, 9);
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};

static GPoint get_cal_positions(int mode, int font, int width, int height) {
    // calories
    switch (mode) {
        case MODE_NORMAL:
            switch(font) {
                case BLOCKO_FONT:
                    return create_point(0, 3);
                case BLOCKO_BIG_FONT:
                    return create_point(0, 3);
                case SYSTEM_FONT:
                    return create_point(0, 3);
                case ARCHIVO_FONT:
                    return create_point(0, 3);
                case DIN_FONT:
                    return create_point(0, 3);
                case PROTOTYPE_FONT:
                    return create_point(0, 3);
                case LECO_FONT:
                    return create_point(0, 5);
                case KONSTRUCT_FONT:
                    return create_point(0, 9);
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};

static GPoint get_sleep_positions(int mode, int font, int width, int height) {
    // sleep
    switch (mode) {
        case MODE_NORMAL:
            switch(font) {
                case BLOCKO_FONT:
                    return create_point(0, 3);
                case BLOCKO_BIG_FONT:
                    return create_point(0, 3);
                case SYSTEM_FONT:
                    return create_point(0, 3);
                case ARCHIVO_FONT:
                    return create_point(0, 3);
                case DIN_FONT:
                    return create_point(0, 3);
                case PROTOTYPE_FONT:
                    return create_point(0, 3);
                case LECO_FONT:
                    return create_point(0, 5);
                case KONSTRUCT_FONT:
                    return create_point(0, 9);
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};

static GPoint get_deep_positions(int mode, int font, int width, int height) {
    // deep sleep
    switch (mode) {
        case MODE_NORMAL:
            switch(font) {
                case BLOCKO_FONT:
                    return create_point(0, 3);
                case BLOCKO_BIG_FONT:
                    return create_point(0, 3);
                case SYSTEM_FONT:
                    return create_point(0, 3);
                case ARCHIVO_FONT:
                    return create_point(0, 3);
                case DIN_FONT:
                    return create_point(0, 3);
                case PROTOTYPE_FONT:
                    return create_point(0, 3);
                case LECO_FONT:
                    return create_point(0, 5);
                case KONSTRUCT_FONT:
                    return create_point(0, 9);
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};

static GPoint get_active_positions(int mode, int font, int width, int height) {
    // active time
    switch (mode) {
        case MODE_NORMAL:
            switch(font) {
                case BLOCKO_FONT:
                    return create_point(0, 3);
                case BLOCKO_BIG_FONT:
                    return create_point(0, 3);
                case SYSTEM_FONT:
                    return create_point(0, 3);
                case ARCHIVO_FONT:
                    return create_point(0, 3);
                case DIN_FONT:
                    return create_point(0, 3);
                case PROTOTYPE_FONT:
                    return create_point(0, 3);
                case LECO_FONT:
                    return create_point(0, 5);
                case KONSTRUCT_FONT:
                    return create_point(0, 9);
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};

static GPoint get_heart_positions(int mode, int font, int width, int height) {
    // heart
    switch (mode) {
        case MODE_NORMAL:
            switch(font) {
                case BLOCKO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(96, 32), 3);
                case BLOCKO_BIG_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(96, 32), 3);
                case SYSTEM_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(96, 32), 3);
                case ARCHIVO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(96, 32), 3);
                case DIN_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(96, 32), 3);
                case PROTOTYPE_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(96, 32), 3);
                case LECO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(96, 32), 5);
                case KONSTRUCT_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(96, 32), 9);
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};

static GPoint get_heart_icon_positions(int mode, int font, int width, int height) {
    // heart icon
    switch (mode) {
        case MODE_NORMAL:
            switch(font) {
                case BLOCKO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(64, 4), 4);
                case BLOCKO_BIG_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(64, 4), 5);
                case SYSTEM_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(64, 4), 5);
                case ARCHIVO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(64, 4), 5);
                case DIN_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(64, 4), 6);
                case PROTOTYPE_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(64, 4), 4);
                case LECO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(64, 4), 5);
                case KONSTRUCT_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(64, 4), 6);
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};
#endif

static GPoint get_speed_positions(int mode, int font, int width, int height) {
    // wind speed
    switch (mode) {
        case MODE_NORMAL:
            switch(font) {
                case BLOCKO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(56, 6), 3);
                case BLOCKO_BIG_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(56, 6), 3);
                case SYSTEM_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(56, 6), 3);
                case ARCHIVO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(56, 6), 3);
                case DIN_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(56, 6), 3);
                case PROTOTYPE_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(56, 6), 3);
                case LECO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(56, 6), 5);
                case KONSTRUCT_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(56, 6), 9);
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};

static GPoint get_direction_positions(int mode, int font, int width, int height) {
    // wind direction
    switch (mode) {
        case MODE_NORMAL:
            switch(font) {
                case BLOCKO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(56, 4), 3);
                case BLOCKO_BIG_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(56, 4), 3);
                case SYSTEM_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(56, 4), 3);
                case ARCHIVO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(56, 4), 3);
                case DIN_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(56, 4), 3);
                case PROTOTYPE_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(56, 4), 3);
                case LECO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(56, 4), 5);
                case KONSTRUCT_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(56, 4), 5);
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};

static GPoint get_wind_unit_positions(int mode, int font, int width, int height) {
    // wind unit
    switch (mode) {
        case MODE_NORMAL:
            switch(font) {
                case BLOCKO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(100, 48), 1);
                case BLOCKO_BIG_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(100, 48), 3);
                case SYSTEM_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(100, 48), 3);
                case ARCHIVO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(100, 48), 2);
                case DIN_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(100, 48), 3);
                case PROTOTYPE_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(100, 48), 1);
                case LECO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(100, 48), 1);
                case KONSTRUCT_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(100, 48), 2);
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};

static GPoint get_sunrise_positions(int mode, int font, int width, int height) {
    // sunrise
    switch (mode) {
        case MODE_NORMAL:
            switch(font) {
                case BLOCKO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(86, 22), 3);
                case BLOCKO_BIG_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(86, 22), 3);
                case SYSTEM_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(86, 22), 3);
                case ARCHIVO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(86, 22), 3);
                case DIN_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(86, 22), 3);
                case PROTOTYPE_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(86, 22), 3);
                case LECO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(86, 22), 5);
                case KONSTRUCT_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(86, 22), 9);
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};

static GPoint get_sunrise_icon_positions(int mode, int font, int width, int height) {
    // sunrise icon
    switch (mode) {
        case MODE_NORMAL:
            switch(font) {
                case BLOCKO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(60, 0), 3);
                case BLOCKO_BIG_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(60, 0), 4);
                case SYSTEM_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(60, 0), 4);
                case ARCHIVO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(60, 0), 4);
                case DIN_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(60, 0), 5);
                case PROTOTYPE_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(60, 0), 3);
                case LECO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(60, 0), 4);
                case KONSTRUCT_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(60, 0), 5);
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};

static GPoint get_sunset_positions(int mode, int font, int width, int height) {
    // sunset
    switch (mode) {
        case MODE_NORMAL:
            switch(font) {
                case BLOCKO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-86, -24), 3);
                case BLOCKO_BIG_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-86, -24), 3);
                case SYSTEM_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-86, -24), 3);
                case ARCHIVO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-86, -24), 3);
                case DIN_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-86, -24), 3);
                case PROTOTYPE_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-86, -24), 3);
                case LECO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-86, -24), 5);
                case KONSTRUCT_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-86, -24), 9);
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};

static GPoint get_sunset_icon_positions(int mode, int font, int width, int height) {
    // sunset icon
    switch (mode) {
        case MODE_NORMAL:
            switch(font) {
                case BLOCKO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-60, -4), 3);
                case BLOCKO_BIG_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-60, -4), 4);
                case SYSTEM_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-60, -4), 4);
                case ARCHIVO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-60, -4), 4);
                case DIN_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-60, -4), 5);
                case PROTOTYPE_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-60, -4), 3);
                case LECO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-60, -4), 4);
                case KONSTRUCT_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(-60, -4), 5);
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};

GPoint get_slot_positions(int mode, int slot, int width, int height) {
    switch (mode) {
        case MODE_NORMAL:
            switch(slot) {
                case SLOT_A:
                    return create_point(2, 0);
                case SLOT_B:
                    return create_point(PBL_IF_ROUND_ELSE(0, width / 2), PBL_IF_ROUND_ELSE(18, 0));
                case SLOT_C:
                    return create_point(2, PBL_IF_ROUND_ELSE(136, height - 26));
                case SLOT_D:
                    return create_point(PBL_IF_ROUND_ELSE(0, width / 2), PBL_IF_ROUND_ELSE(152, height - 26));
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};

static GPoint get_degrees_positions(int mode, int font, int width, int height) {
    // compass degrees
    switch (mode) {
        case MODE_NORMAL:
            switch(font) {
                case BLOCKO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(82, 30), 3);
                case BLOCKO_BIG_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(82, 30), 3);
                case SYSTEM_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(82, 30), 3);
                case ARCHIVO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(82, 30), 3);
                case DIN_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(82, 30), 3);
                case PROTOTYPE_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(82, 30), 3);
                case LECO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(82, 30), 5);
                case KONSTRUCT_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(82, 30), 9);
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};

static GPoint get_compass_positions(int mode, int font, int width, int height) {
    // compass arrow
    switch (mode) {
        case MODE_NORMAL:
            switch(font) {
                case BLOCKO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(60, 8), 3);
                case BLOCKO_BIG_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(60, 8), 3);
                case SYSTEM_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(60, 8), 3);
                case ARCHIVO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(60, 8), 3);
                case DIN_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(60, 8), 3);
                case PROTOTYPE_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(60, 8), 3);
                case LECO_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(60, 8), 5);
                case KONSTRUCT_FONT:
                    return create_point(PBL_IF_ROUND_ELSE(60, 8), 5);
            }
            break;
        default:
            return create_point(0, 0);
    }

    return create_point(0, 0);
};

GPoint get_pos_for_item(int slot, int item, int mode, int font, int width, int height) {
    if (slot == -1) {
        return create_point(0, 0);
    }
    GPoint slot_pos = get_slot_positions(mode, slot, width, height);
    GPoint item_pos;
    switch (item) {
        case WEATHER_ITEM:
            item_pos = get_weather_positions(mode, font, width, height);
            break;
        case TEMP_ITEM:
            item_pos = get_temp_positions(mode, font, width, height);
            break;
        case TEMPMIN_ITEM:
            item_pos = get_tempmin_positions(mode, font, width, height);
            break;
        case TEMPMAX_ITEM:
            item_pos = get_tempmax_positions(mode, font, width, height);
            break;
        #if defined(PBL_HEALTH)
        case STEPS_ITEM:
            item_pos = get_steps_positions(mode, font, width, height);
            break;
        case DIST_ITEM:
            item_pos = get_dist_positions(mode, font, width, height);
            break;
        case CAL_ITEM:
            item_pos = get_cal_positions(mode, font, width, height);
            break;
        case SLEEP_ITEM:
            item_pos = get_sleep_positions(mode, font, width, height);
            break;
        case DEEP_ITEM:
            item_pos = get_deep_positions(mode, font, width, height);
            break;
        case ACTIVE_ITEM:
            item_pos = get_active_positions(mode, font, width, height);
            break;
        case HEART_ITEM:
            item_pos = get_heart_positions(mode, font, width, height);
            break;
        case HEARTICON_ITEM:
            item_pos = get_heart_icon_positions(mode, font, width, height);
            break;
        #endif
        case SPEED_ITEM:
            item_pos = get_speed_positions(mode, font, width, height);
            break;
        case DIRECTION_ITEM:
            item_pos = get_direction_positions(mode, font, width, height);
            break;
        case WIND_UNIT_ITEM:
            item_pos = get_wind_unit_positions(mode, font, width, height);
            break;
        case TEMPMINICON_ITEM:
            item_pos = get_tempminicon_positions(mode, font, width, height);
            break;
        case TEMPMAXICON_ITEM:
            item_pos = get_tempmaxicon_positions(mode, font, width, height);
            break;
        case SUNRISE_ITEM:
            item_pos = get_sunrise_positions(mode, font, width, height);
            break;
        case SUNSET_ITEM:
            item_pos = get_sunset_positions(mode, font, width, height);
            break;
        case SUNRISEICON_ITEM:
            item_pos = get_sunrise_icon_positions(mode, font, width, height);
            break;
        case SUNSETICON_ITEM:
            item_pos = get_sunset_icon_positions(mode, font, width, height);
            break;
        case DEGREES_ITEM:
            item_pos = get_degrees_positions(mode, font, width, height);
            break;
        case COMPASS_ITEM:
            item_pos = get_compass_positions(mode, font, width, height);
            break;
    }
    return create_point(slot_pos.x + item_pos.x, slot_pos.y + item_pos.y);
}
