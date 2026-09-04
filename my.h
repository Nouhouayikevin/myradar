/*
** EPITECH PROJECT, 2024
** my.h for the organize project
** File description:
** functions are implemented
*/

#ifndef _MY_H_
    #define _MY_H_
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/stat.h>
    #include <stdio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio/Sound.h>
    #include <SFML/Audio/SoundBuffer.h>
    #include <time.h>
    #include <math.h>
    #include <SFML/Audio.h>
    #define PLAN 20

typedef struct bttn {
    int play;
    int animate;
    sfRectangleShape *R;
    sfSprite *key;
    sfText *text;
    sfText *text1;
    sfFont *font;
    sfFont *font1;
    sfTexture *T;
    sfVector2f vecp;
    sfVector2f vec_s;
    sfIntRect rect;
    sfClock *c;
    sfEvent e;
    sfMusic *m;
}bttn_t;

typedef struct plane {
    bttn_t bt;
    int s_x;
    int s_y;
    int e_x;
    int e_y;
    int speed;
    int t;
    int id_bool;
    int domain;
    int crash;
    int arrival;
    int play;
    int sec;
    sfIntRect rt;
    sfRectangleShape *R;
} plane_t;

typedef struct tower_s {
    bttn_t bt;
    int pos_x;
    int pos_y;
    int r;
    int id_bool;
    sfCircleShape *C;
} tower_t;

typedef struct statistic {
    int compiled;
    int pressure;
    int safetime;
    int real_time;
    int connection;
    sfSprite *orage;
    sfTexture *texture;
    plane_t plane;
} stt_t;

typedef struct radar {
    int fps;
    int pause;
    stt_t bns;
    plane_t *plane;
    tower_t *tower;
    int nb_plane;
    int nb_tower;
    int flying;
    int crash;
    int S;
    int simulation;
    char *str;
    sfText *text;
    sfFont *font;
    sfMusic *m;
} radar_t;

typedef struct menu {
    bttn_t A;
    bttn_t B;
    bttn_t C;
    bttn_t D;
    bttn_t E;
    bttn_t F;
} menu_t;
int parse_bns(char *str, radar_t *rdr);
void free_radar(radar_t *rdr);
void set_text_e_4(int i, char *choice[], menu_t *menu);
void set_text_e_3(menu_t *menu, radar_t *r);
void set_text_e_2(menu_t *menu, radar_t *r);
void set_text_e_1(menu_t *menu, radar_t *r);
void checker_result(sfRenderWindow *win, radar_t *r);
void destroy_bns_plane(radar_t *rdr);
void display_bns_plane(sfRenderWindow *win, radar_t *rdr);
sfRenderWindow *init_win(void);
void pos_updt_menu(bttn_t *obj);
void destroy_menu(menu_t *mn);
int get_time_elapsed(sfClock *clock);
void guide(sfRenderWindow *win, radar_t *r);
void monitoring(radar_t *rdr, bttn_t *night);
void music_event_menu(radar_t *r);
void menu_animation(bttn_t *bird, double timelaspe, sfClock *clock);
void random_display(sfRenderWindow *win, menu_t *mn, int i);
void plane_in_domain15_with_others(int i, radar_t *rdr);
void plane_in_domain14_with_others(int i, radar_t *rdr);
void plane_in_domain13_with_others(int i, radar_t *rdr);
void plane_in_domain12_with_others(int i, radar_t *rdr);
void plane_in_domain11_with_others(int i, radar_t *rdr);
void plane_in_domain10_with_others(int i, radar_t *rdr);
void plane_in_domain9_with_others(int i, radar_t *rdr);
void plane_in_domain8_with_others(int i, radar_t *rdr);
void plane_in_domain7_with_others(int i, radar_t *rdr);
void plane_in_domain6_with_others(int i, radar_t *rdr);
void plane_in_domain5_with_others(int i, radar_t *rdr);
void plane_in_domain4_with_others(int i, radar_t *rdr);
void plane_in_domain3_with_others(int i, radar_t *rdr);
void plane_in_domain2_with_others(int i, radar_t *rdr);
void plane_in_domain1_with_others(int i, radar_t *rdr);
void init_rect(plane_t *plane, sfVector2f p, sfVector2f s);
int number_plane(char **t);
int number_tower(char **t);
void travelling_bns_plane(plane_t *plane);
void crash_with_domain1(int i, radar_t *rdr);
void crash_with_domain2(int i, radar_t *rdr);
void crash_with_domain3(int i, radar_t *rdr);
void domaine1(plane_t *plane);
void domaine2(plane_t *plane);
void domaine3(plane_t *plane);
void domaine4(plane_t *plane);
void plane_rotation(plane_t *plane);
void off_the_sprite(radar_t *rdr, sfRenderWindow *win, int i);
void principal_init(bttn_t *mn, bttn_t *night, radar_t *r);
void destroy2(bttn_t *night, radar_t *rdr, bttn_t *mn);
void animation(bttn_t *bird, double timelaspe, sfClock *clock);
void animate0(bttn_t *obj);
void animate1(bttn_t *obj);
void animate2(bttn_t *obj);
void draw_crashing_planes(sfRenderWindow *window, radar_t *r);
char *the_print_fly_plane(radar_t *rdr);
void draw_flying_planes(sfRenderWindow *window, radar_t *r, bttn_t *mn);
void travel_plane(plane_t *plane);
void plane_set_texture(plane_t *plane);
void tower_set_texture(tower_t *tower);
char **my_str_to_word_array(char *s, char c);
void my_putstr(char *s);
void my_putchar(char c);
void affiche_tab(char **tab);
void my_put(char *s);
void my_putnbr(int nbr);
int my_strcmp(char *s1, char *s2);
int my_strlen(char *s);
int help(int ac, char **av);
int my_getnbr(char *s);
void my_putnbr(int nbr);
int my_getnbr(char *s);
char **read_line(char *filepath);
int error_in_parse(char **T);
int parse(char *str, radar_t *rdr);
sfSprite *sp_creator(char *filename, sfVector2f p, sfVector2f s, float a);
void page_debut(sfRenderWindow *window, radar_t *rdr);
sfRenderWindow *init_win(void);
void close_win(sfRenderWindow *window, radar_t *rdr, bttn_t *m, bttn_t *mn);
void init_main(bttn_t *mn);
void init_travels(radar_t *rdr);
void free_tab(char **t);
void travelling_plane(plane_t *plane);
sfCircleShape *create_circle(sfVector2f position, float radius);
void clock_for_departure(plane_t *plane);
void get_plane_info2(plane_t *plane);
void rect_color_change(radar_t *rdr);
char *time_to_str(bttn_t *mn);
int nbrlen(int nb);
void draw_time(sfRenderWindow *window, bttn_t *mn);
void init_night(bttn_t *mn);
void pos_updt(bttn_t *obj);
void sim_night(bttn_t *obj);
char *reverse_string(char *str);
float cod_to_angle(sfVector2f *start, sfVector2f *end);
char *reverse_string(char *str);
void echange(char *s, char *p1);
char *my_strcat(char *dest, char const *src);
char *int_to_str(int nb);
int nbrlen(int nb);
void verif_crash_plane(radar_t *rdr);
int intersects(plane_t *p1, plane_t *p2);
sfVector2f *get_rect_corners(sfRectangleShape *rect);
void flying_planes(radar_t *rdr);
char *my_strdump(char *s);
void event_on_sprite(sfRenderWindow *window, radar_t *rdr, bttn_t *mn,
    bttn_t *n);
void bns_plane_in_domain1_with_others(radar_t *rdr);
void bns_plane_in_domain2_with_others(radar_t *rdr);
void bns_plane_in_domain3_with_others(radar_t *rdr);
void bns_plane_in_domain4_with_others(radar_t *rdr);
void bns_plane_in_domain5_with_others(radar_t *rdr);
void bns_plane_in_domain6_with_others(radar_t *rdr);
void bns_plane_in_domain7_with_others(radar_t *rdr);
void bns_plane_in_domain8_with_others(radar_t *rdr);
void bns_plane_in_domain9_with_others(radar_t *rdr);
void bns_plane_in_domain10_with_others(radar_t *rdr);
void bns_plane_in_domain11_with_others(radar_t *rdr);
void bns_plane_in_domain12_with_others(radar_t *rdr);
void bns_plane_in_domain13_with_others(radar_t *rdr);
void bns_plane_in_domain14_with_others(radar_t *rdr);
static void bns_plane_in_domain15_with_others(radar_t *rdr);
static void bns_plane_in_domain16_with_others(radar_t *rdr);
void pause_window(sfRenderWindow *win, sfEvent *e, radar_t *rdr, bttn_t *mn);
void menu_initialisation(menu_t *menu);
void menu(sfRenderWindow *win, radar_t *r);
void verif_bns_crash(radar_t *rdr);
void menu2(sfRenderWindow *win, radar_t *r, menu_t *menu);
void random_slide(sfRenderWindow *win, menu_t *mn);
#endif
