#include <nodes/fmod_event_emitter_2d.h>

using namespace godot;

void FmodEventEmitter2D::update_in_valid_viewport_impl(const Ref<FmodEvent>& p_event) const {
    bool shares_space = false;
    for (int i = 0; i < FmodServer::get_singleton()->get_valid_viewports_number(); ++i) {
        if (FmodServer::get_singleton()->get_valid_viewport(i) == get_viewport()) {
            shares_space = true;
            break;
        }
    }
    if (shares_space) {
        p_event->set_volume(get_volume());
    } else {
        p_event->set_volume(0.0);
    }
}

void FmodEventEmitter2D::set_space_attribute_impl(const Ref<FmodEvent>& p_event) const {
    p_event->set_2d_attributes(get_global_transform());
}

void FmodEventEmitter2D::_ready() {
    FmodEventEmitter<FmodEventEmitter2D, Node2D>::_ready();
}

void FmodEventEmitter2D::_process(double delta) {
    FmodEventEmitter<FmodEventEmitter2D, Node2D>::_process(delta);
}

void FmodEventEmitter2D::_notification(int p_what) {
    FmodEventEmitter<FmodEventEmitter2D, Node2D>::_notification(p_what);
}

void FmodEventEmitter2D::_exit_tree() {
    FmodEventEmitter<FmodEventEmitter2D, Node2D>::_exit_tree();
}

void FmodEventEmitter2D::_bind_methods() {
    FmodEventEmitter<FmodEventEmitter2D, Node2D>::_bind_methods();
}

void FmodEventEmitter2D::free_impl() {
    queue_free();
}