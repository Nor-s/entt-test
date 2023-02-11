#include <iostream>
#include <entt/entt.hpp>
#include "components/transform.h"

struct position
{
    float x;
    float y;
};

struct velocity
{
    float dx;
    float dy;
};

void update(entt::registry &registry)
{
    registry.view<transform>().each([](transform &t)
                                    {
        t.x += 1.f;
        t.y += 1.f;
        t.z += 1.f; });

    auto view = registry.view<transform>();
    auto view2 = registry.view<const position, velocity>();

    // use a callback
    view.each([](const auto &pos, auto &vel) { /* ... */ });

    // use a range-for
    for (auto [entity, pos, vel] : view2.each())
    {
        // ...
        std::cout << pos.x << " " << vel.dy << std::endl;
    }
    for (auto entity : view)
    {
        auto &tf = view.get<transform>(entity);
        std::cout << tf.x << " " << tf.y << std::endl;
    }
}

int main()
{
    entt::registry registry;
    for (auto i = 0; i < 10; ++i)
    {
        const auto entity = registry.create();
        registry.emplace<transform>(entity, i * 1.f, i * 2.f, i * 3.f);
        registry.emplace<position>(entity, i * 1.f, i * 1.f);
        if (i % 2 == 0)
        {
            registry.emplace<velocity>(entity, i * .1f, i * .1f);
        }
    }
    update(registry);
}