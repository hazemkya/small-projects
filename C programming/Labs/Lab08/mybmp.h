#pragma pack(2)
#if !defined MYBMP
#define MYBMP

typedef enum { cRED , cGREEN , cBLUE } Channel;

typedef struct {
  char format[2];       /* always BM */
  int file_size;        /* full size of the file including header */
  int reserved1;        /* set to 0 */
  int pixel_offset;     /* where pixels data start */
} FileHead;             /* total size: 14 bytes */

typedef struct {
  int reserved2;        /* set to 40 */
  int image_width;  
  int image_height;
  short reserved3;      /* set to 1 */
  short bits_per_pixel; /* set to 24 */ 
  int compression;      /* set to 0 */
  int raw_pixel_size;   /* image_height * (image_width * 3 + delta) */
  int h_resolution;     /* set to 2835 */
  int v_resolution;     /* set to 2835 */
  int num_of_colors;    /* set to 0 */   
  int important_colors; /* set to 0 */
} ImageHead;            /* total size: 40 bytes */

typedef struct {
  char blue;
  char green;
  char red;
} Pixel; /* total size: 3 bytes */

Pixel** load_image(char*, FileHead*, ImageHead*);

void make_grey(Pixel**, int, int, Channel);

void redify(Pixel**, int, int);

void hmirror(Pixel**, int, int);

int save_image(char* , FileHead*, ImageHead*, Pixel** );

#endif