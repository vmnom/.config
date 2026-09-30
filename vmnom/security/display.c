#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH  320
#define HEIGHT 240

typedef struct {
    uint8_t r, g, b, a;
} pixel_t;

static pixel_t framebuffer[HEIGHT][WIDTH];

static void clear_framebuffer(void)
{
    memset(framebuffer, 0, sizeof(framebuffer));
}

static void set_pixel(int x, int y, pixel_t color)
{
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;

    framebuffer[y][x] = color;
}

static void draw_rect(
    int x,
    int y,
    int width,
    int height,
    pixel_t color)
{
    for (int py = y; py < y + height; py++)
        for (int px = x; px < x + width; px++)
            set_pixel(px, py, color);
}

/*
 * This represents the trusted renderer.
 *
 * In a real implementation, the scene would first be
 * authenticated and decrypted.
 */
static void render_scene(const uint8_t *scene, size_t size)
{
    /*
     * Example scene format:
     *
     * byte 0: command
     * byte 1: x
     * byte 2: y
     * byte 3: width
     * byte 4: height
     * byte 5: R
     * byte 6: G
     * byte 7: B
     */

    if (size < 8)
        return;

    if (scene[0] == 1) {
        pixel_t color = {
            .r = scene[5],
            .g = scene[6],
            .b = scene[7],
            .a = 255
        };

        draw_rect(
            scene[1],
            scene[2],
            scene[3],
            scene[4],
            color
        );
    }
}

int main(void)
{
    clear_framebuffer();

    /*
     * Normally this would come from the network:
     *
     * encrypted_scene
     *       ↓
     * authenticate
     *       ↓
     * decrypt
     *       ↓
     * scene
     *
     * Here we use a plaintext scene only to demonstrate
     * the rendering part.
     */

    uint8_t scene[] = {
        1,      // DRAW_RECT
        50,     // x
        40,     // y
        100,    // width
        80,     // height
        255,    // R
        0,      // G
        0       // B
    };

    render_scene(scene, sizeof(scene));

    /*
     * framebuffer now contains reconstructed pixels.
     */

    printf(
        "Pixel at (50,40): "
        "R=%u G=%u B=%u A=%u\n",
        framebuffer[40][50].r,
        framebuffer[40][50].g,
        framebuffer[40][50].b,
        framebuffer[40][50].a
    );

    return 0;
}
