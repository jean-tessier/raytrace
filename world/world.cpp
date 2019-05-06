#include "world.h"

void World::addShape(std::shared_ptr<Shape const> shape)
{
    shapes.push_back(shape);
}

std::list<std::shared_ptr<Shape const>> World::getShapes() const
{
    return shapes;
}