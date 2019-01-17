#include "world_canvas.h"
#include "agent.h"
#include <stdio.h>

CANVAS world_canvas_new(WORLD *wrld) {
    /* Truque para evitar avisos do compilador, visto que neste caso nao vamos
       precisar da variavel wrld. */
    wrld = wrld;

    return stdout;
}

void world_canvas_update(CANVAS cnvs, WORLD *wrld) {

    for (unsigned int y = 0; y < wrld->ydim; ++y) {
        for (unsigned int x = 0; x < wrld->xdim; ++x) {

            AGENT p = world_get(wrld, x, y);

            switch (p) {
                case NO_ONE:
                    printf(".");
                    break;
                case POLICE:
                    printf("P");
                    break;
                case THIEF:
                    printf("T");
                    break;
                case KILLER:
                    printf("K");
                    break;
                case VICTIM:
                    printf("V");
                    break;
                default:
                    /* So vai aqui em caso de erro */
                    fprintf((FILE *) cnvs, "x");
            }
        }
        fprintf((FILE *) cnvs, "\n");
    }
    fprintf((FILE *) cnvs, "\n");

}

void world_canvas_destroy(CANVAS cnvs) {

    /* Nada a fazer para este caso simples. Nao podemos "destruir" o stdout.
       Apenas usamos o mesmo truque para evitar avisos do compilador. */
    cnvs = cnvs;

}

