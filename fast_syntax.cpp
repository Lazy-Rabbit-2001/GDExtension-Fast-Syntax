#include "fast_syntax.hpp"

#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/script.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using GD = UtilityFunctions;
using Eg = Engine;
using Scr = Script;

namespace gde_fast_syntax {
    double get_delta(Node *node) {
        if (!UtilityFunctions::is_instance_valid(node)) {
            return 0.0;
        }
        return Engine::get_singleton()->is_in_physics_frame() ? node->get_physics_process_delta_time() : node->get_process_delta_time();
    }

    bool is_running_mode(Node *node) {
        if (!GD::is_instance_valid(node)) {
            return false;
        } else if (!node->is_inside_tree()) {
            return false;
        }

        bool game_mode = !Eg::get_singleton()->is_editor_hint();
        Ref<Script> script = Ref<Script>(node->get_script());
        bool script_tool_mode = GD::is_instance_valid(script) ? script->is_tool() : false;

        return game_mode || script_tool_mode;
    }

    bool is_collision_shape_showable(Node2D *node2d, Ref<Shape2D> &shape) {
        if (!GD::is_instance_valid(node2d)) {
            return false;
        } else if (!GD::is_instance_valid(shape)) {
            return false;
        } else if (!node2d->is_inside_tree()) {
            return false;
        }

        bool editor_mode = Eg::get_singleton()->is_editor_hint();
        bool debug_collision_shape = node2d->get_tree()->is_debugging_collisions_hint();

        return editor_mode || debug_collision_shape;
    }
}