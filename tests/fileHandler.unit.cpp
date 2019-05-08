#include "./catch/catch.hpp"

#include <fstream>

#include "../fileHandler/fileHandler.h"

TEST_CASE ( "FileHandler parses planes from files successfully", "[FileHandler]" )
{
    const std::string testFileName{"./tests/exampleFiles/planeExample.txt"};
    std::ifstream inputStream(testFileName);
    
    std::shared_ptr<Shape const> shape = FileHandler::parsePlaneFromStream(inputStream);
    std::shared_ptr<Plane const> castedShape = std::dynamic_pointer_cast<Plane const>(shape);

    inputStream.close();

    REQUIRE ( castedShape != nullptr );
    REQUIRE ( castedShape->GetPointOnPlane() == Tuple{0, 0, 3});
    REQUIRE ( castedShape->GetNormal() == Vector{1, 0, 1} );
    REQUIRE ( castedShape->getColor() == Tuple{0, 255, 0} );
}

TEST_CASE ( "FileHandler parses spheres from files successfully", "[FileHandler]" )
{
    const std::string testFileName{"./tests/exampleFiles/sphereExample.txt"};
    std::ifstream inputStream(testFileName);
    
    std::shared_ptr<Shape const> shape = FileHandler::parseSphereFromStream(inputStream);
    std::shared_ptr<Sphere const> castedShape = std::dynamic_pointer_cast<Sphere const>(shape);

    inputStream.close();

    REQUIRE ( castedShape != nullptr );
    REQUIRE ( castedShape->GetCenter() == Tuple{0, 0, 3} );
    REQUIRE ( castedShape->GetRadius() == 1.337 );
    REQUIRE ( castedShape->getColor() == Tuple{0, 255, 0} );
}

TEST_CASE ( "FileHandler parses camera from file successfully", "[FileHandler]" )
{
    const std::string testFileName{"./tests/exampleFiles/cameraExample.txt"};
    std::ifstream inputStream(testFileName);

    std::shared_ptr<Camera const> camera = FileHandler::parseCameraFromStream(inputStream);
    
    inputStream.close();

    REQUIRE( !camera == false );
    const Tuple *const bounds = camera->GetViewportBounds();
    REQUIRE( camera->GetPosition() == Tuple{0, 0, 0});
    REQUIRE( bounds[0] == Tuple{-1, -1, 1} );
    REQUIRE( bounds[1] == Tuple{1, 1, 1} );
}

TEST_CASE ( "FileHandler parses world from file successfully", "[FileHandler]" )
{
    const std::string testFileName{"./tests/exampleFiles/worldExample.txt"};

    std::shared_ptr<World> world = FileHandler::loadWorldFromFile(testFileName);

    REQUIRE ( world != nullptr );

    std::list<std::shared_ptr<Shape const>> shapes = world->getShapes();

    unsigned int sphereCount = 0;
    unsigned int planeCount = 0;
    const unsigned int expectedSphereCount = 1;
    const unsigned int expectedPlaneCount = 1;
    for (const auto &shape : shapes)
    {
        std::shared_ptr<Sphere const> castedSphere = std::dynamic_pointer_cast<Sphere const>(shape);
        std::shared_ptr<Plane const> castedPlane = std::dynamic_pointer_cast<Plane const>(shape);

        if (castedSphere != nullptr)
        {
            REQUIRE(castedSphere->GetCenter() == Tuple{0, 0, 3});
            REQUIRE(castedSphere->GetRadius() == 1.337);
            REQUIRE(castedSphere->getColor() == Tuple{0, 255, 0});
            ++sphereCount;
        }
        else if (castedPlane != nullptr)
        {
            REQUIRE ( castedPlane->GetPointOnPlane() == Tuple{0, 0, 3});
            REQUIRE ( castedPlane->GetNormal() == Vector{1, 0, 1} );
            REQUIRE ( castedPlane->getColor() == Tuple{0, 255, 0} );
            ++planeCount;
        }
    }

    REQUIRE ( sphereCount == expectedSphereCount );
    REQUIRE ( planeCount == expectedPlaneCount );
}