#include <cmath>

#include "./catch/catch.hpp"
#include "../vector/vector.h"

TEST_CASE( "Vector.add() computes sum of vectors", "[Vector]" ) {
    const double xa = 1;
    const double ya = 1;
    const double za = 1;
    const double xb = 1;
    const double yb = 1;
    const double zb = 1;

    const Vector a(xa, ya, za);
    const Vector b(xb, yb, zb);
    const Vector sum = a.add(b);

    REQUIRE ( sum[0] == xa + xb );
    REQUIRE ( sum[1] == ya + yb );
    REQUIRE ( sum[2] == za + zb );
}

TEST_CASE( "Vector.subtract() computes difference of vectors", "[Vector]" ) {
    const double xa = 2;
    const double ya = 2;
    const double za = 2;
    const double xb = 1;
    const double yb = 1;
    const double zb = 1;

    const Vector a(xa, ya, za);
    const Vector b(xb, yb, zb);
    const Vector diff = a.subtract(b);

    REQUIRE ( diff[0] == xa - xb );
    REQUIRE ( diff[1] == ya - yb );
    REQUIRE ( diff[2] == za - zb );
}

TEST_CASE ( "Vector.multiply() computes product of vectors", "[Vector]" ) {
    const double xa = 2;
    const double ya = 2;
    const double za = 2;
    const double xb = 2;
    const double yb = 2;
    const double zb = 2;

    const Vector a(xa, ya, za);
    const Vector b(xb, yb, zb);
    const Vector product = a.multiply(b);

    REQUIRE ( product[0] == xa * xb );
    REQUIRE ( product[1] == ya * yb );
    REQUIRE ( product[2] == za * zb );
}

TEST_CASE ( "Vector.scale() creates a scaled vector", "[Vector]" ) {
    const double xa = 1;
    const double ya = 1;
    const double za = 1;
    const double scaleVal = 2;

    const Vector a(xa, ya, za);
    const Vector scaledVec = a.scale(scaleVal);

    REQUIRE ( scaledVec[0] == xa * scaleVal );
    REQUIRE ( scaledVec[1] == ya * scaleVal );
    REQUIRE ( scaledVec[2] == za * scaleVal );
}

TEST_CASE ( "Vector.dot() computes the dot product of two vectors", "[Vector]" ) {
    const double xa = 2;
    const double ya = 2;
    const double za = 2;
    const double xb = 2;
    const double yb = 2;
    const double zb = 2;

    const Vector a(xa, ya, za);
    const Vector b(xb, yb, zb);
    const double dotProduct = a.dot(b);

    REQUIRE ( dotProduct == xa*xb + ya*yb + za*zb );
}

TEST_CASE ( "Vector.len() computes the length of the vector", "[Vector]" ) {
    const double xa = 1;
    const double ya = 1;
    const double za = 1;
    
    const Vector a(xa, ya, za);
    const double length = a.len();

    REQUIRE ( length == std::sqrt(xa*xa + ya*ya + za*za) );
}

TEST_CASE ( "Vector.norm() computes the normalized vector", "[Vector]" ) {
    const double xa = 1;
    const double ya = 1;
    const double za = 1;
    
    const Vector a(xa, ya, za);
    const Vector normalized = a.norm();
    const double length = std::sqrt( normalized[0]*normalized[0] + normalized[1]*normalized[1] + normalized[2]*normalized[2] );

    // stubbed
    REQUIRE ( Approx( length ) == 1.0 );
}

TEST_CASE ( "Vector.reflect() computes the reflection vector", "[Vector]" ) {
    const double xa = 1;
    const double ya = 1;
    const double za = 1;
    const double xb = 2;
    const double yb = 2;
    const double zb = 2;
    
    const Vector a(xa, ya, za);
    const Vector b = Vector(xb, yb, zb).norm();
    const Vector reflection = a.reflect(b);

    // stubbed
    // r = d - 2(d dot n)n
    const Vector goalVector = a - 2 * (a.dot(b)) * b;
    REQUIRE( reflection[0] == goalVector[0] );
    REQUIRE( reflection[1] == goalVector[1] );
    REQUIRE( reflection[2] == goalVector[2] );
}