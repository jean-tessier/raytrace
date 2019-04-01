#include <cmath>

#include "./catch/catch.hpp"
#include "../tuple/tuple.h"

TEST_CASE( "Tuple.add() computes sum of Tuples", "[Tuple]" ) {
    const double xa = 1;
    const double ya = 1;
    const double za = 1;
    const double xb = 1;
    const double yb = 1;
    const double zb = 1;

    const Tuple a(xa, ya, za);
    const Tuple b(xb, yb, zb);
    const Tuple sum = a.add(b);

    REQUIRE ( sum[0] == xa + xb );
    REQUIRE ( sum[1] == ya + yb );
    REQUIRE ( sum[2] == za + zb );
}

TEST_CASE( "Tuple.subtract() computes difference of Tuples", "[Tuple]" ) {
    const double xa = 2;
    const double ya = 2;
    const double za = 2;
    const double xb = 1;
    const double yb = 1;
    const double zb = 1;

    const Tuple a(xa, ya, za);
    const Tuple b(xb, yb, zb);
    const Tuple diff = a.subtract(b);

    REQUIRE ( diff[0] == xa - xb );
    REQUIRE ( diff[1] == ya - yb );
    REQUIRE ( diff[2] == za - zb );
}

TEST_CASE ( "Tuple.multiply() computes product of Tuples", "[Tuple]" ) {
    const double xa = 2;
    const double ya = 2;
    const double za = 2;
    const double xb = 2;
    const double yb = 2;
    const double zb = 2;

    const Tuple a(xa, ya, za);
    const Tuple b(xb, yb, zb);
    const Tuple product = a.multiply(b);

    REQUIRE ( product[0] == xa * xb );
    REQUIRE ( product[1] == ya * yb );
    REQUIRE ( product[2] == za * zb );
}

TEST_CASE ( "Tuple.scale() creates a scaled Tuple", "[Tuple]" ) {
    const double xa = 1;
    const double ya = 1;
    const double za = 1;
    const double scaleVal = 2;

    const Tuple a(xa, ya, za);
    const Tuple scaledVec = a.scale(scaleVal);

    REQUIRE ( scaledVec[0] == xa * scaleVal );
    REQUIRE ( scaledVec[1] == ya * scaleVal );
    REQUIRE ( scaledVec[2] == za * scaleVal );
}

TEST_CASE ( "Tuple.dot() computes the dot product of two Tuples", "[Tuple]" ) {
    const double xa = 2;
    const double ya = 2;
    const double za = 2;
    const double xb = 2;
    const double yb = 2;
    const double zb = 2;

    const Tuple a(xa, ya, za);
    const Tuple b(xb, yb, zb);
    const double dotProduct = a.dot(b);

    REQUIRE ( dotProduct == xa*xb + ya*yb + za*zb );
}