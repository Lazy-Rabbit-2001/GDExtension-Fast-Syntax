#pragma once

#ifndef GDEXTENSION_FAST_SYNTAX
#define GDEXTENSION_FAST_SYNTAX

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/shape2d.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/node2d.hpp>

using namespace godot;

namespace gde_fast_syntax {
    bool is_running_mode(Node *node);
    bool is_collision_shape_showable(Node2D *node2d, Ref<Shape2D> &shape);
}

#endif