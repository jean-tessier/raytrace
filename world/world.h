#ifndef __WORLD_H__
#define __WORLD_H__

#include <list>
#include <memory>

#include "../shape/shape.h"

class World
{
public:
    World() {}

    void addShape(std::shared_ptr<Shape const> shape);

    std::list<std::shared_ptr<Shape const>> getShapes() const;

    World(const World&) = delete;
    World(World&&) = delete;
    World& operator=(const World&) = delete;
    World& operator=(World&&) = delete;
private:
    std::list<std::shared_ptr<Shape const>> shapes;
};

#endif // __WORLD_H__