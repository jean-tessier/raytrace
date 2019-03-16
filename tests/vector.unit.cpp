#include "../vector/vector.h"

TEST_CASE( "Vector.add() computes sum of vectors", "[Vector]" ) {
    const double xa = 1;
    const double ya = 1;
    const double za = 1;
    const double xb = 1;
    const double yb = 1;
    const double zb = 1;

    Vector a(xa, ya, za);
    Vector b(xb, yb, zb);
    Vector sum = a.add(b);

    REQUIRE ( sum[0] == xa + xb );
    REQUIRE ( sum[1] == ya + yb );
    REQUIRE ( sum[2] == za + zb );
}